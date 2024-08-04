#include <iostream>

#include "conv.h"

using namespace std;

int main(){

    cout << "Hello, test-task1" << endl;

    Conv c = Conv();

    cout << 'e'  << endl;

    unsigned char t[] = {

                    //          00
        0b00011100, //    7
        0b00101000, //   10
        0b00111100, //   15

                    //          01
        0b00011001, //    6
        0b01000001, //   16
        (unsigned char) 0b11110101, //   -3
        (unsigned char) 0b10111101, //  -17

                    //          10
        0b00000010, //   "a"
        0b01100110, //   "z"
        0b01101010, //   ""

                    //          11
        (unsigned char)0b11111111  //   ""

    };

    for (auto r : t ){
        cout << '[' << c.read(r) << ']' << endl;
    }
}
