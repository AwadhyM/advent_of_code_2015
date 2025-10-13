#include "utils.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(singleDigits, BasicAssertions) {
  EXPECT_EQ(to_num('1'), 1);
  EXPECT_EQ(to_num('2'), 2);
  EXPECT_EQ(to_num('3'), 3);
  EXPECT_EQ(to_num('4'), 4);
  EXPECT_EQ(to_num('5'), 5);
  EXPECT_EQ(to_num('6'), 6);
  EXPECT_EQ(to_num('7'), 7);
  EXPECT_EQ(to_num('8'), 8);
  EXPECT_EQ(to_num('9'), 9);
}

TEST(nonNumbers, ThrowsInvalidArgument) {
  for (int i = 0; i <= 127; ++i) {
    char c = static_cast<unsigned char>(i);
    if (!std::isdigit(static_cast<unsigned char>(c))) {
      EXPECT_THROW(to_num(c), std::invalid_argument);
    }
  }
}
