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
}
