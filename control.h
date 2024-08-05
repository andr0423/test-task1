#pragma once
#include <istream>
#include "conv.h"

class ISink{
public:
    virtual void sink(const char) = 0;
};

class ISource{
public:
    virtual const char * source() = 0;
};

class Control : ISink, ISource {
    bool state = false;
    char inp_char = '\0';
    char out_chars[4] = {};
    Conv converter = Conv();

public:
    Control();
    ~Control();
    void start();
    void stop();
    bool is_started();
    char get_input();
    virtual void sink(const char);
    virtual const char * source();

    friend std::istream & operator>> ( std::istream& is, Control& input )
    {
        char t;
        is >> t;
        input.sink(t);
        return is;
    }

    friend std::ostream & operator<< ( std::ostream & os, Control& output )
    {
        const char * tmp = output.source();
        while(*(tmp)){
            os << *tmp;
            tmp++;
        }
        return os;
    }

};


