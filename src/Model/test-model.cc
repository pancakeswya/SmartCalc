#include <gtest/gtest.h>

#include "model.h"

TEST(SmartCalculator, TestOperation) {
  Model m;
  std::string str = "4 + 9 + 7 + 9";
  m.CalcExpression(str);
  EXPECT_EQ(m.GetExpressionAns(), 29);
}

TEST(SmartCalculator, TestOperation1) {
  Model m;
  std::string str = "4 + 9 / 2 * 67787";
  m.CalcExpression(str);
  EXPECT_EQ(m.GetExpressionAns(), 305045.5);
}

TEST(SmartCalculator, TestFunc) {
  Model m;
  std::string str = "(4^acos(2/4))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 4.27047);
}

TEST(SmartCalculator, TestFunc1) {
  Model m;
  std::string str = "(tan(2*2))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1.1578213);
}

TEST(SmartCalculator, TestFunc2) {
  Model m;
  std::string str = "(4^acos(2/4)/tan(2*2))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 3.6883678);
}

TEST(SmartCalculator, TestFunc3) {
  Model m;
  std::string str = "(4^acos(2/4)/tan(2*2)/5^acos(2/4))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.68371409);
}

TEST(SmartCalculator, TestFunc4) {
  Model m;
  std::string str = "(4^acos(2/4)/tan(2*2)/5^acos(2/4)/tan(tan(tan(2*2))))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), -0.58934796);
}

TEST(SmartCalculator, TestFunc5) {
  Model m;
  std::string str = "3^cos(0.5)/5";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.52449733);
}

TEST(SmartCalculator, TestFunc6) {
  Model m;
  std::string str = "3^cos(0.5)/sqrt(25)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.52449733);
}

TEST(SmartCalculator, TestFunc7) {
  Model m;
  std::string str = "log(10)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1);
}

TEST(SmartCalculator, TestFunc8) {
  Model m;
  std::string str = "1+2*(3^sin(0.4))^3*2+1";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 16.436413);
}

TEST(SmartCalculator, TestFunc9) {
  Model m;
  std::string str = "ln(10)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 2.3025851);
}

TEST(SmartCalculator, TestFunc10) {
  Model m;
  std::string str = "1+2*sin(0.4)^3*2+1";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 2.236216);
}

TEST(SmartCalculator, TestFunc11) {
  Model m;
  std::string str = "1+2*sin(0.4)^56*2+1";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 2);
}
TEST(SmartCalculator, TestFunc12) {
  Model m;
  std::string str = "acos(-0.5)+asin(-0.5)+atan(0.1)*cos(30)*sin(20)*tan(45)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1.5935309);
}

TEST(SmartCalculator, TestFunc13) {
  Model m;
  std::string str = "(-5)^(-4)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.0016);
}

TEST(SmartCalculator, TestFunc14) {
  Model m;
  std::string str = "-4+5";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}