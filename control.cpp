#include "control.h"
#include <string.h>



Control::Control()
{
    mm = new mutex();
    //th = new thread(&Control::process, this);
    cvi = new condition_variable();
    cvo = new condition_variable();
}

Control::~Control()
{
    delete mm;
    delete th;
    delete cvi;
    delete cvo;

}

void Control::start()
{
    if ( this->state ) {
        return;
    }

    {
        unique_lock<mutex> lk(*mm);
        this->state = true;
        this->allow_convert = false;
        this->allow_sink = false;
    }
    delete th;
    th = new thread(&Control::process, this);
    th->detach();
}

void Control::stop()
{
    if ( ! this->state ) {
        return;
    }

    {
        unique_lock<mutex> lk(*mm);
        this->state = false;
        this->allow_convert = true;
        this->allow_sink = true;
        cvi->notify_all();
        cvo->notify_all();
    }
}

bool Control::is_started()
{
    return this->state;
}



void Control::process()
{
    while (this->state){

        unique_lock<mutex> lk(*mm);

        while( ! allow_convert ){
            cvi->wait(lk);
        }
        allow_convert = false;

        if( ! this->state ){
            lk.unlock();
            allow_sink = true;
            break;
        }

        while ( ! this->inp_chars.empty() ) {
            char tmp = inp_chars.front();
            inp_chars.pop_front();
            char * out = const_cast<char*>(this->converter.convert(tmp));
            while( *out != '\0' ){
                out_chars.push_back(*out);
                out++;
            }
        }

        lk.unlock();
        this->allow_sink = true;
        cvo->notify_all();
    }
}


bool Control::source( const char * input )
{

    if ( this->state ){

        list<char> tmp;
        char * in = const_cast<char*>(input);

        while( *in != '\0' ){
            // this->inp_chars.emplace_back(*in);
            tmp.emplace_back(*in);
            in++;
        }

        {
            unique_lock<mutex> lk(*mm);
            allow_convert = true;
            cvi->notify_one();
            this->inp_chars = move(tmp);
        }
        
    }

    return this->state;
}



string Control::sink( )
{

    string output;

    if ( this->state ){

        {
            unique_lock<mutex>  lk(*mm);
            while(!allow_sink){
                cvo->wait(lk);
            }
            allow_sink = false;
        }

        list<char> out = move(this->out_chars);
        output = string(out.begin(), out.end());
    }

    return move(output);
}



