#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <unistd.h>

#include "conv.h"
#include "control.h"




using namespace std;

void demo(){

    cout << "==== ==== ==== ==== ==== ==== ====" << endl
         << "==== Demo conv.cpp  ==== ==== ====" << endl
         << "==== ==== ==== ==== ==== ==== ====" << endl;

    Conv c = Conv();

    unsigned char t[] = {

        //00
        0b00'000111, //    7
        0b00'001010, //   10
        0b00'001111, //   15

        //01
        0b01'000110, //    6
        0b01'010000, //   16
        0b01'111101, //   -3
        0b01'101111, //  -17
        0b01'011111, //   31
        0b01'100010, //  -30
        0b01'100001, //  -31
        0b01'100000, //  -32

        //10
        0b10'000000, //   "a"
        0b10'011001, //   "z"
        0b10'011010, //   ""

        //11
        0b11'111111  //   ""

    };

    for ( auto r : t ){
        cout 
            << "(" << setw(2) << setfill('0') << hex << (int)r 
            << dec << ")(" << std::bitset<8>(r) << ") -> ["
             << c.convert(r)
            << "]" << endl;
    }

    cout << "==== ==== ==== ==== ==== ==== ====" << endl << endl;

}

void demo2(){

    cout << "==== ==== ==== ==== ==== ==== ====" << endl
         << "==== Demo control.cpp    ==== ====" << endl
         << "==== ==== ==== ==== ==== ==== ====" << endl;

    Control c = Control();
    bool res = false;
    string ou;

    // stop
    cout << " 1. Not started, state(" << c.state << ")" << endl;
    cout << "    pattern 'ABCDE' -> '12345'" << endl;
    res = c.source("ABCDE");
    ou = c.sink();
    cout << "    res(" << res << "), sink: [" << ou << "]" << endl;

    // start
    c.start();
    cout << " 2. Started, state(" << c.state << ")" << endl;
    cout << "    pattern 'ABCDE' -> '12345'" << endl;
    res = c.source("ABCDE");
    ou = c.sink();
    cout << "    res(" << res << "), sink: [" << ou << "]" << endl;

    // stop and start again
    cout << " 3. Restart" << endl;
    c.stop();
    cout << "    state(" << c.state << ")" << endl;
    c.start();
    cout << "    state(" << c.state << ")" << endl;
    cout << "    pattern 'ABCDE' -> '12345'" << endl;
    res = c.source("ABCDE");
    ou = c.sink();
    cout << "    res(" << res << "), sink: [" << ou << "]" << endl;

    // send pattrn twice without read
    cout << " 4. Source twice" << endl;
    cout << "    pattern '78' -> '5556'" << endl;
    res = c.source("G456"); 
    cout << "    pattern 'G456' -> '7525354'" << endl;
    res = c.source("G456"); 
    ou = c.sink();
    cout << "    res(" << res << "), sink: [" << ou << "]" << endl;

    c.stop();

    cout << "==== ==== ==== ==== ==== ==== ====" << endl << endl;
}

void the_end(){
    cout << "==== ==== ==== ==== ==== ==== ====" << endl
         << "==== The End   ==== ==== ==== ====" << endl
         << "==== ==== ==== ==== ==== ==== ====" << endl;
}

int main(){

    cout << "Hello, test-task1" << endl << endl;

    demo();

    demo2();

    the_end();

 }
