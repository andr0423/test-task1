//#include <iostream>
#include <bitset>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//#include "../conv.h"
#include "../conv.cpp"
//#include "../control.h"
#include "../control.cpp"

using namespace std;



typedef struct tdataconv {
  unsigned char in;
  const char * out;
} tdcnv;

TEST(TestGroup_CONV, Subtest_Conv){
  Conv tc = Conv();

  tdcnv test_chars[] = {

    //  00
    { 0b00'000111,   "7" },
    { 0b00'001010,  "10" },
    { 0b00'001111,  "15" },

    //  01
    { 0b01'000110,   "6" },
    { 0b01'010000,  "16" },
    { 0b01'111101,  "-3" },
    { 0b01'101111, "-17" },
    { 0b01'011111,  "31" },

    { 0b01'100010, "-30" },
    { 0b01'100001, "-31" },
    { 0b01'100000, "-32" },

    //  10
    { 0b10'000000,   "a" },
    { 0b10'011001,   "z" },
    { 0b10'011010,    "" },

    //  11
    { 0b11'111111 ,   "" }

  };

  string cur_str;
  string exp_str;
  for (auto td : test_chars){
    cur_str = const_cast<char*>(tc.convert(td.in));
    exp_str = td.out;
    EXPECT_EQ(cur_str, exp_str) 
        << " == " << std::bitset<8>( td.in ) 
        << ", e:'" << exp_str 
        << "', c:'" << cur_str <<"' == " ;
    
  }

  ASSERT_STRNE("1", test_chars[10].out);
}



typedef struct tdatacontrol {
  const char * in;
  string exp;
} tdcntrl;

TEST(TestGroup_CNTRL, Subtest_Control){
  Control tcl = Control();

  tdcntrl test_strings[] = {
    { "ABCDE"  , "12345" },
    { "F01234" , "64849505152" },
    { "G56789" , "75354555657" },
    { "Po_az"  , "16-1731-31-6" }
    //,{ ":\xffZ" , "5826"         }

  };

  tcl.start();
  EXPECT_TRUE( tcl.is_started() ) << " wtf["<< tcl.state <<"]";

  string cur_str;
  string exp_str;
  bool res;
  for ( auto ts : test_strings ){
    res = tcl.source(ts.in);
    cur_str = tcl.sink();
    exp_str = ts.exp;
    EXPECT_TRUE(res);
    EXPECT_EQ(cur_str, exp_str) << "in["<< hex << ts.in <<"], exp[" << ts.exp << "], cur[" << cur_str << "]";
  }
  tcl.stop();

}



// TEST(TestGroup_CNTRL, Subtest_Start){
//   Control tcs = Control();
//   bool res;
//   string out; 

//   tcs.start();
//   EXPECT_EQ( tcs.is_started(), true );
//   res = tcs.source(":\xffZ");
//   out = tcs.sink(); 
//   EXPECT_EQ(out, "5826");

//   tcs.stop();
//   EXPECT_EQ( tcs.is_started(), false );
//   res = tcs.source(":\xffZ");
//   out = tcs.sink();
//   EXPECT_EQ(out, "");

//   tcs.stop();
// }



int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}


