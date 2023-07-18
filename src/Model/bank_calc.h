#ifndef BANK_CALC_H_
#define BANK_CALC_H_

#include "../Controller/data_types.h"

namespace s21 {

class Credit : protected CreditConditions {
 public:
  Credit() = default;
  ~Credit() = default;

  Credit(const CreditConditions& conds);
  Credit(CreditConditions&& conds) noexcept;

  void SetConditions(const CreditConditions& conds);
  void SetConditions(CreditConditions&& conds) noexcept;

  CreditData& GetData() noexcept;
  void CalcCredit();

 private:
  CreditData m_data{};
};

class Deposit : protected DepositConditions {
 public:
  Deposit() = default;
  ~Deposit() = default;

  Deposit(const DepositConditions& conds);
  Deposit(DepositConditions&& conds) noexcept;

  void SetConditions(const DepositConditions& conds);
  void SetConditions(DepositConditions&& conds) noexcept;

  DepositData& GetData() noexcept;
  void CalcDeposit();

 private:
  void AddReplenishment(const QDate& start, const QDate& finish,
                        const UserTransaction& u_transaction);
  void MakeDeposit();
  DepositData m_data{};
};

inline Credit::Credit(const CreditConditions& conds)
    : CreditConditions(conds) {}

inline Credit::Credit(CreditConditions&& conds) noexcept
    : CreditConditions(conds) {}

inline void Credit::SetConditions(const CreditConditions& conds) {
  *this = conds;
}

inline void Credit::SetConditions(CreditConditions&& conds) noexcept {
  *this = std::move(conds);
}

inline CreditData& Credit::GetData() noexcept { return m_data; }

inline Deposit::Deposit(const DepositConditions& conds)
    : DepositConditions(conds) {}

inline Deposit::Deposit(DepositConditions&& conds) noexcept
    : DepositConditions(std::move(conds)) {}

inline void Deposit::SetConditions(const DepositConditions& conds) {
  *this = conds;
}

inline void Deposit::SetConditions(DepositConditions&& conds) noexcept {
  *this = std::move(conds);
}

inline DepositData& Deposit::GetData() noexcept { return m_data; }

}  // namespace s21

#endif  // BANK_CALC_H_
