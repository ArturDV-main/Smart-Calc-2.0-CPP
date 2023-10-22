#include <iostream>

#include "../s21_calc_model.h"
#include "gtest/gtest.h"

TEST(CalcTest, GetDataCalc) {
  s21::CalcModel a;
  EXPECT_EQ(a.GetData(), 0);
}

TEST(CalcTest, SimpleCalc) {
  s21::CalcModel a;
  a.StartCalc("2+2", 0);
  EXPECT_EQ(a.GetData(), 4);
  a.StartCalc("0.2/2", 0);
  EXPECT_EQ(a.GetData(), 0.1);
  a.StartCalc("@(0)+A(0)*B(0)", 0);
  EXPECT_EQ(a.GetData(), 1);
  a.StartCalc("C(1)-B(1)+E(1)", 0);
  EXPECT_DOUBLE_EQ(a.GetData(), -0.77200956125745379);
}

TEST(CalcTest, ResetCalc) {
  s21::CalcModel a;
  a.StartCalc("2+2", 0);
  EXPECT_EQ(a.GetData(), 4);
  a.Reset();
  EXPECT_EQ(a.GetData(), 0);
}