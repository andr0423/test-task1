//#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../conv.h"
#include "../conv.cpp"
#include <bitset>

using namespace std;

typedef struct tdada {
  unsigned char in;
  const char * out;
} td;

TEST(TestGroupName, Subtest_Conv){
  Conv tc = Conv();

  td test_data[] = {

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
  for (auto td : test_data){
    cur_str = const_cast<char*>(tc.read(td.in));
    exp_str = td.out;
    EXPECT_EQ(cur_str, exp_str) << " == " << std::bitset<8>( td.in ) << ", e:'" << exp_str << "', c:'" << cur_str <<"' == " ;
    
  }

  ASSERT_STRNE("1", test_data[10].out);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}


