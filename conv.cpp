#include "conv.h"



const char * Conv::read(const char in)
{
    this->type = in & 0b11;
    
    switch ( this->type )
    {
        case 0b00:                                           // unsigned int

            this->data.uns = in >> 2;

            sprintf(this->out, "%d", (char)this->data.uns);

            break;

        case 0b01:                                            //  signed int

            this->data.sig = in >> 2;

            sprintf(this->out, "%d", this->data.sig);

            break;

        case 0b10:                                            // alpha: a, b, ...

            this->data.uns = in >> 2;

            if ( this->data.uns > 25 ){
                *this->out = '\0';
            } 
            else{
                this->out[0] = this->data.uns + 0x61;
                this->out[1] = '\0';
            }

            break;

        default:

            *this->out = '\0';

    }

    return this->out;

}
