#ifndef SMARTCALC_V2_SRC_MODEL_BANK_CALC_H_
#define SMARTCALC_V2_SRC_MODEL_BANK_CALC_H_

#include "types/data_types.h"

namespace s21 {

class Credit {
 public:
  Credit() = default;
  explicit Credit(CreditConditions conds);

  ~Credit() = default;

  void SetConditions(CreditConditions conds);
  CreditData& GetData() noexcept;
  void CalcCredit();
  void Clear() noexcept;

 private:
  CreditData data_{};
  CreditConditions conds_{};
};

class Deposit {
 public:
  Deposit() = default;
  explicit Deposit(DepositConditions conds);

  ~Deposit() = default;

  void SetConditions(DepositConditions conds);
  DepositData& GetData() noexcept;
  void CalcDeposit();
  void Clear() noexcept;

 private:
  void AddReplenishment(const QDate& start, const QDate& finish,
                        const UserTransaction& u_transaction);
  void MakeDeposit();
  DepositData data_{};
  DepositConditions conds_{};
};

inline Credit::Credit(CreditConditions conds) : conds_(conds) {}

inline void Credit::SetConditions(CreditConditions conds) { conds_ = conds; }

inline CreditData& Credit::GetData() noexcept { return data_; }

inline void Credit::Clear() noexcept { data_ = {}; }

inline Deposit::Deposit(DepositConditions conds) : conds_(std::move(conds)) {}

inline void Deposit::SetConditions(DepositConditions conds) {
  conds_ = std::move(conds);
}

inline DepositData& Deposit::GetData() noexcept { return data_; }

inline void Deposit::Clear() noexcept { data_ = {}; }

}  // namespace s21

#endif  // SMARTCALC_V2_SRC_MODEL_BANK_CALC_H_
