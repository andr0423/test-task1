#pragma once
#include <iostream>


class Conv
{
    union {
        unsigned char uns;
                 char sig;

    } data;

    char out[4]{};

public:

    const char * convert(const char);

};
