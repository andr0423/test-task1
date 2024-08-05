#pragma once
#include <iostream>


class Conv
{
    union dataVar {
        unsigned char uns;
                 char sig;

    };

    dataVar data;
    unsigned char type;

    char out[4]{};

public:

    const char * read(const char);

};
