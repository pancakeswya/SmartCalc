#include <gtest/gtest.h>

#include <stdexcept>

#include "model.h"

TEST(SmartCalculator, TestOperation) {
  s21::Model m;
  std::string_view str = "4 + 9 + 7 + 9";
  m.CalcExpression(str);
  EXPECT_EQ(m.GetExpressionAns(), 29);
}

TEST(SmartCalculator, TestOperation1) {
  s21::Model m;
  std::string_view str = "4 + 9 / 2 * 67787";
  m.CalcExpression(str);
  EXPECT_EQ(m.GetExpressionAns(), 305045.5);
}

TEST(SmartCalculator, TestFunc) {
  s21::Model m;
  std::string_view str = "(4^acos(2/4))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 4.27047);
}

TEST(SmartCalculator, TestFunc1) {
  s21::Model m;
  std::string_view str = "(tan(2*2))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1.1578213);
}

TEST(SmartCalculator, TestFunc2) {
  s21::Model m;
  std::string_view str = "(4^acos(2/4)/tan(2*2))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 3.6883678);
}

TEST(SmartCalculator, TestFunc3) {
  s21::Model m;
  std::string_view str = "(4^acos(2/4)/tan(2*2)/5^acos(2/4))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.68371409);
}

TEST(SmartCalculator, TestFunc4) {
  s21::Model m;
  std::string_view str =
      "(4^acos(2/4)/tan(2*2)/5^acos(2/4)/tan(tan(tan(2*2))))";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), -0.58934796);
}

TEST(SmartCalculator, TestFunc5) {
  s21::Model m;
  std::string_view str = "3^cos(0.5)/5";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.52449733);
}

TEST(SmartCalculator, TestFunc6) {
  s21::Model m;
  std::string_view str = "3^cos(0.5)/sqrt(25)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.52449733);
}

TEST(SmartCalculator, TestFunc7) {
  s21::Model m;
  std::string_view str = "log(10)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1);
}

TEST(SmartCalculator, TestFunc8) {
  s21::Model m;
  std::string_view str = "1+2*(3^sin(0.4))^3*2+1";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 16.436413);
}

TEST(SmartCalculator, TestFunc9) {
  s21::Model m;
  std::string_view str = "ln(10)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 2.3025851);
}

TEST(SmartCalculator, TestFunc10) {
  s21::Model m;
  std::string_view str = "1+2*3^sin(0.4)^3*2+1";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 6.268113);
}

TEST(SmartCalculator, TestFunc11) {
  s21::Model m;
  std::string_view str = "1+2*sin(0.4)^56*2+1";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 2);
}
TEST(SmartCalculator, TestFunc12) {
  s21::Model m;
  std::string_view str =
      "acos(-0.5)+asin(-0.5)+atan(0.1)*cos(30)*sin(20)*tan(45)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1.5935309);
}

TEST(SmartCalculator, TestFunc13) {
  s21::Model m;
  std::string_view str = "(-5)^(-4)";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 0.0016);
}

TEST(SmartCalculator, TestFunc14) {
  s21::Model m;
  std::string_view str = "-4+5";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1);
}

TEST(SmartCalculator, TestFunc15) {
  s21::Model m;
  std::string_view str = "+4+5";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 9);
}

TEST(SmartCalculator, TestFunc16) {
  s21::Model m;
  std::string_view str = "x^x";
  m.CalcEquation(str, 3);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 27);
}

TEST(SmartCalculator, TestFunc17) {
  s21::Model m;
  std::string_view str = "3 mod 2";
  m.CalcExpression(str);
  EXPECT_FLOAT_EQ(m.GetExpressionAns(), 1);
}

TEST(SmartCalculator, TestFunc18) {
  s21::Model m;
  s21::GraphConditions gc = {"x^3", 10, -10, 10, -10, false};
  m.CalcGraph(gc);
  auto& data = m.GetGraphData();
  EXPECT_FLOAT_EQ(data.xy[0].first[0], -10);
  EXPECT_FLOAT_EQ(data.xy[0].second[0], -1000);
  EXPECT_FLOAT_EQ(data.xy.begin()->first.back(), 10);
  EXPECT_FLOAT_EQ(data.xy.begin()->second.back(), 1000);
  EXPECT_EQ(data.x_min, -10);
  EXPECT_EQ(data.x_max, 10);
  EXPECT_EQ(data.y_min, -10);
  EXPECT_EQ(data.y_max, 10);
}

TEST(SmartCalculator, TestFunc19) {
  s21::Model m;
  s21::GraphConditions gc = {"1/x", 0, -10, 0, -10, true};
  m.CalcGraph(gc);
  auto& data = m.GetGraphData();
  EXPECT_FLOAT_EQ(data.xy[0].first[0], -10);
  EXPECT_FLOAT_EQ(data.xy[0].second[0], -0.1);
  EXPECT_FLOAT_EQ(data.xy.begin()->first.back(), -0.0099999998);
  EXPECT_FLOAT_EQ(data.xy.begin()->second.back(), -100);
  EXPECT_EQ(data.x_min, -10);
  EXPECT_EQ(data.x_max, 0);
  EXPECT_EQ(data.y_min, -100);
  EXPECT_EQ(data.y_max, -0.1);
}

TEST(SmartCalculator, TestFunc20) {
  s21::Model m;
  std::string_view str = "((1)";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc21) {
  s21::Model m;
  std::string_view str = "(1+3))";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc22) {
  s21::Model m;
  std::string_view str = "1 + 4 5";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc23) {
  s21::Model m;
  std::string_view str = "1 + 4_faf5";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc24) {
  s21::Model m;
  std::string_view str = "1 +* 4";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc25) {
  s21::Model m;
  std::string_view str = "3 mid 2";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc26) {
  s21::Model m;
  std::string_view str = "1 + 4 *";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc27) {
  s21::Model m;
  std::string_view str = "1 + san(5)";
  EXPECT_THROW(m.CalcExpression(str), std::invalid_argument);
}

TEST(SmartCalculator, TestFunc28) {
  s21::Model m;
  s21::CreditConditions cc = {1000000, 13.4, 12, true, true};
  m.CalcCredit(cc);
  auto& data = m.GetCreditData();
  EXPECT_FLOAT_EQ(data.total, 2015241.1);
  EXPECT_FLOAT_EQ(data.overpay, 1015241.1);
  EXPECT_FLOAT_EQ(data.payment[0], 13994.73);
}

TEST(SmartCalculator, TestFunc29) {
  s21::Model m;
  s21::CreditConditions cc = {1000000, 13.4, 12, false, false};
  m.CalcCredit(cc);
  auto& data = m.GetCreditData();
  EXPECT_FLOAT_EQ(data.total, 1072583.4);
  EXPECT_FLOAT_EQ(data.overpay, 72583.336);
  EXPECT_FLOAT_EQ(data.payment[4], 90777.781);
}

TEST(SmartCalculator, TestFunc30) {
  s21::Model m;
  s21::DepositConditions dc = {
      true,
      1,
      120,
      0,
      13,
      8.5,
      1000000,
      13.4,
      0,
      {2023, 8, 13},
      {{{2023, 8, 13}, 5000, 1}, {{2024, 4, 5}, 10000, 1}},
      {{{2023, 12, 12}, 4000, 0}}};
  m.CalcDeposit(dc);
  auto& data = m.GetDepositData();
  EXPECT_EQ(data.replen[0].first, QDate(2023, 9, 13));
  EXPECT_EQ(data.replen[0].second, 5000);
  EXPECT_EQ(data.pay_dates[0], QDate(2023, 8, 14));
  EXPECT_FLOAT_EQ(data.payment.back(), 2684.26);
  EXPECT_FLOAT_EQ(data.tax.back(), 63745.355);
  EXPECT_EQ(data.start_date, QDate(2023, 8, 13));
  EXPECT_EQ(data.finish_date, QDate(2033, 8, 13));
  EXPECT_FLOAT_EQ(data.eff_rate, 45.895149);
  EXPECT_FLOAT_EQ(data.perc_sum, 4593287);
  EXPECT_FLOAT_EQ(data.tax_sum, 479714.41);
  EXPECT_FLOAT_EQ(data.total, 7319287);
}

TEST(SmartCalculator, TestFunc31) {
  s21::Model m;
  s21::DepositConditions dc = {
      false,
      0,
      120,
      2,
      13,
      8.5,
      1000000,
      13.4,
      0,
      {2023, 8, 13},
      {{{2023, 8, 13}, 5000, 2}, {{2024, 4, 5}, 10000, 1}},
      {{{2023, 12, 12}, 4000, 0}}};
  m.CalcDeposit(dc);
  auto& data = m.GetDepositData();
  EXPECT_EQ(data.replen[0].first, QDate(2023, 10, 13));
  EXPECT_EQ(data.replen[0].second, 5000);
  EXPECT_EQ(data.pay_dates[0], QDate(2023, 9, 13));
  EXPECT_FLOAT_EQ(data.payment.back(), 10330.85);
  EXPECT_EQ(data.tax.empty(), true);
  EXPECT_EQ(data.start_date, QDate(2023, 8, 13));
  EXPECT_EQ(data.finish_date, QDate(2023, 12, 11));
  EXPECT_FLOAT_EQ(data.eff_rate, 0);
  EXPECT_FLOAT_EQ(data.perc_sum, 44163.102);
  EXPECT_FLOAT_EQ(data.tax_sum, 0);
  EXPECT_FLOAT_EQ(data.total, 1005000);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}