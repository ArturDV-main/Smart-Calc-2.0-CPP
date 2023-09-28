#include <iostream>
#include <string>

#include "../s21_calc_valid_model.h"
#include "gtest/gtest.h"

TEST(ValidTest, ValidationEqual) {
  s21::CalcValid valid;
  std::string str("2+2*2-2*2/2");
  bool val = valid.ValidationEqual(str);
  EXPECT_TRUE(val);
  std::string str2;
  EXPECT_FALSE(valid.ValidationEqual(str2));
}

TEST(ValidTest, Simple) {
  s21::CalcValid valid;
  std::string str("2+2*2-2*2/2");
  bool val = valid.ValidationEqual(str);
  EXPECT_TRUE(val);
  std::string str2;
  EXPECT_FALSE(valid.ValidationEqual(str2));
}

TEST(ValidTest, Reset) {
  s21::CalcValid valid;
  std::string str("V");
  EXPECT_FALSE(valid.ValidationEqual(str));
}
