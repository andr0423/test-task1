#include "conv.h"



const char * Conv::read(const char in)
{
    this->type = in & 0b11;
    
    switch ( this->type )
    {
        case 0b00:                                           // unsigned int

            this->data = in >> 2;

            if ( this->data < 10 ) {
                this->out[0] = this->data + 0x30;
                this->out[1] = '\0';
            } else {
                this->out[0] = (this->data / 10 ) % 10 + 0x30;
                this->out[1] = this->data % 10         + 0x30;
                this->out[2] = '\0';
            }

            //sprintf(this->out, "%d", this->data);

            break;

        case 0b01:                                            //   signed int

            this->data = in >> 2;

            if ( this->data & 0b00100000 ){
                this->data |= 0b11000000;
                this->data -= 1;
                this->data = ~this->data;

                this->out[0] = '-';
                if ( this->data < 10 ) {
                    this->out[1] = this->data              + 0x30;
                    this->out[2] = '\0';
                } else {
                    this->out[1] = (this->data / 10 ) % 10 + 0x30;
                    this->out[2] = this->data % 10         + 0x30;
                    this->out[3] = '\0';  
                }

            }else{
                if ( this->data < 10 ) {
                    this->out[0] = this->data              + 0x30;
                    this->out[1] = '\0';
                } else {
                    this->out[0] = (this->data / 10 ) % 10 + 0x30;
                    this->out[1] = this->data % 10         + 0x30;
                    this->out[2] = '\0';
                }
            }

            //sprintf(this->out, "%d", this->data);

            break;

        case 0b10:                                            // alpha a, b, ...

            this->data = in >> 2;

            if ( this->data > 25 ){
                *this->out = '\0';
            } 
            else{
                this->out[0] = this->data + 0x61;
                this->out[1] = '\0';
            }

            break;

        default:

            *this->out = '\0';

    }

    return this->out;

}
