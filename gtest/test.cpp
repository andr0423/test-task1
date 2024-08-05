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

                          // 00
    {0b00011100,   "7"},
    {0b00101000,  "10"},
    {0b00111100,  "15"},

                          // 01
    {0b00011001,   "6"},
    {0b01000001,  "16"},
    {0b11110101,  "-3"},
    {0b10111101, "-17"},
    {0b01111101,  "31"},
    {0b11111101, "-31"},
    {0b10000001, "-32"},

                          // 10
    {0b00000010,   "a"},
    {0b01100110,   "z"},
    {0b01101010,    ""},

                          // 11
    {0b11111111 ,   ""}
  };

  char * to;
  for (auto td : test_data){
    to = const_cast<char*>(tc.read(td.in));
    EXPECT_EQ(*to, *td.out) << " == " << std::bitset<8>( td.in ) << ", e:" << td.out << ", c:" << to <<" == " ;
  }

  ASSERT_STRNE("1", test_data[10].out);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}


