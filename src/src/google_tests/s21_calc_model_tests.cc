#include <iostream>

#include "../s21_calc_model.h"
#include "gtest/gtest.h"

TEST(CalcTest, GetData) {
  s21::CalcModel a;
  EXPECT_EQ(a.GetData(), 0);
}

TEST(CalcTest, Simple) {
  s21::CalcModel a;
  EXPECT_EQ(a.StartCalc("2+2", 0), 4);
  EXPECT_EQ(a.StartCalc("0.2/2", 0), 0.1);
}

TEST(CalcTest, Reset) {
  s21::CalcModel a;
  EXPECT_EQ(a.StartCalc("2+2", 0), 4);
  a.Reset();
  EXPECT_EQ(a.GetData(), 0);
}