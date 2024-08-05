#include "conv.h"



const char * Conv::read(const char in)
{

    switch ( in & 0b1100'0000 )
    {
        case 0b00'000000:                             // unsigned int

            this->data.uns = in & 0b0011'1111;

            sprintf(this->out, "%d", this->data.uns);

            break;

        case 0b01'000000:                             //  signed int

            this->data.sig = in & 0b00'111111;

            if( this->data.sig  & 0b00'100000 ){
                this->data.sig |= 0b11'000000;
            }
            sprintf(this->out, "%d", this->data.sig);

            break;

        case 0b10'000000:                             // alpha: a, b, ...

            this->data.uns = in & 0b0011'1111;

            this->data.uns = this->data.uns > 25 ? '\0' : this->data.uns + 0x61 ;
            sprintf( this->out, "%c", this->data.uns );

            break;

        default:

            *this->out = '\0';

    }

    return this->out;

}
