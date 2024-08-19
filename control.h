#pragma once
#include <istream>
#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>

#include "conv.h"



using namespace std;

class ISource{                                 // input
public:
    virtual bool source( const char * ) = 0;
};

class ISink{                                   // output
public:
    virtual string sink(  ) = 0;

};



class Control : ISource, ISink {

    Conv converter = Conv();

    list<char> inp_chars;
    list<char> out_chars;

    // bool state = false;
    // void process ();

    mutex * mm = nullptr;
    thread * th = nullptr;
    condition_variable * cvi = nullptr;
    condition_variable * cvo = nullptr;

public:
    Control();
    ~Control();
    void start();
    void stop();
    bool is_started();

    virtual bool source( const char * );
    virtual string sink(  );

    void process ();
    bool state = false;

    bool allow_convert = false;
    bool allow_sink = false;
};


