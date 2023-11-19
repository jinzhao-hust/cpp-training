#pragma once
#include <cmath>
enum class DiscountType
{
    CASH_NORMAL,
    CASH_PERCENTOFF_10,
    CASH_PERCENTOFF_20,
    CASH_PERCENTOFF_30,
    CASH_BACK,
};

namespace PriceCalc
{
    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const noexcept;
    private:
        class Discount
        {
        public:
            virtual double AcceptCash(const double money) const noexcept = 0;
            virtual ~Discount();
        };
        
        class Normal final : public Discount
        {
        public:
            double AcceptCash(const double money) const noexcept override
            {
                return money;
            }
            virtual ~Normal();
        };

        class PercentOff final : public Discount
        {
        private:
            double discountRate = 1;
        public:
            explicit PercentOff(double rate) : discountRate(rate){};
            virtual ~PercentOff();
            double AcceptCash(const double money) const noexcept override
            {
                return money * discountRate;
            }
        };
        class CashBack final : public Discount
        {
            double threshold = 100.0;
            double cashback = 20.0;

        public:
            explicit CashBack(double threshold, double cashback): threshold(threshold), cashback(cashback){};
            virtual ~CashBack();
            double AcceptCash(const double money) const noexcept override
            {
                return money - floor(money/threshold) * cashback;
            }
        };
    };
} // namespace PriceCalc