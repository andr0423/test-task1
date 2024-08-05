#include <iostream>
#include <sstream>
#include "conv.h"
#include "control.h"
#include <bitset>

using namespace std;

void demo(){

    Conv c = Conv();

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
        0b01100110, //102:f -   "z"
        0b01101010, //   ""

                    //          11
        (unsigned char)0b11111111  //   ""

    };

    for (auto r : t ){
        cout << '[' << c.read(r) << ']' << endl;
    }
}

int main(){

    cout << "Hello, test-task1" << endl;

    cout << "==== ==== ==== ==== ==== ====" << endl;
    cout << "==== Demo conv.cpp  ==== ====" << endl;

    demo();

    cout << "==== ==== ==== ==== ==== ====" << endl;

    Control c = Control();
    cout << c.is_started() << endl;
    c.start();
    cout << c.is_started() << endl;
    c.stop();
    cout << c.is_started() << endl;

    char tmp_char = 0b01100110;  // "f"(102) -> "z"(25) : type "2"(0b10)

    c.sink(tmp_char);
    cout << c << endl;

    cout << "==== ==== ==== ==== ==== ====" << endl;

    // istringstream iss("");
    // for (int i = 1; i<254; i++){
    //     if ((unsigned char)i == '.'){
    //         continue;
    //     }
    //     iss.putback((unsigned char)i);
    // }
    // char t2;
    // while (iss >> t2){
    //     cout << t2 << endl;
    // }
    // iss.putback('.');

    //"abcdefghijklmnopqastuvwxyz";
    istringstream iss("0123456789ABCDEFGHGIJKLMNOPQRSTUVWXYZabcdefghijklmnopqastuvwxyz.");
    ostringstream oss;

    // while (c.get_input() != '.' ){
    while (not iss.eof()){
        iss >> c;
        cout << "\t(" << c.get_input() << ")("<< std::bitset<8>(c.get_input())<< ") -> [";
        cout << c;
        cout << "]" << endl;
    }

     cout << "==== ==== ==== ==== ==== ====" << endl;
     cout << "==== ====  The End  ==== ====" << endl;
    
    // cout << endl << oss.str();
    
 }
