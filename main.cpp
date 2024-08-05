#include <iostream>
#include <sstream>
#include <bitset>
#include <iomanip>

#include "conv.h"
#include "control.h"



using namespace std;

void demo(){

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

    for (auto r : t ){
        cout << "(" << setw(2) << setfill('0') << hex << (int)r << dec << ")(" << std::bitset<8>(r) << ") -> [" << c.read(r) << "]" << endl;
    }
}

int main(){

    cout << "Hello, test-task1" << endl;

    cout << "==== ==== ==== ==== ==== ====" << endl
         << "==== Demo conv.cpp  ==== ====" << endl
         << "==== ==== ==== ==== ==== ====" << endl;

    demo();

    cout << "==== ==== ==== ==== ==== ====" << endl;

    Control c = Control();
    cout << c.is_started() << endl;
    c.start();
    cout << c.is_started() << endl;
    c.stop();
    cout << c.is_started() << endl;

    char tmp_char = 0b01100110;

    c.sink(tmp_char);
    cout << c << endl;

    cout << "==== ==== ==== ==== ==== ====" << endl;

    istringstream iss(
        " !\"#$%&'-./" 
        "0123456789"
        ":;<=>?@"
        "ABCDEFGHGIJKLMNOPQRSTUVWXYZ"
        "[\\]^_`"
        "abcdefghijklmnopqastuvwxyz"
        "{|}~"
        )
        ;
    ostringstream oss;

    while (not iss.eof()){
        iss >> c;
        cout << "\t(" << c.get_input() << ")"
             << "("<< std::bitset<8>(c.get_input()) << ") -> ["
             << c
             << "]" << endl;
    }

    cout << "==== ==== ==== ==== ==== ====" << endl;
    cout << "==== ====  The End  ==== ====" << endl;
    cout << "==== ==== ==== ==== ==== ====" << endl;
 }
