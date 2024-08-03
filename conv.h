#pragma once



class Conv
{
    unsigned char data;
    unsigned char type;

    char out[4]{};

public:

    const char * read(const char);

};
