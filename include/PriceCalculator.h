#pragma once

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
    };
    class Normal final
    {
    public:
        double AcceptCash(const double money) const noexcept{
            return money;
        }
    };
    class PercentOff final
    {
    public:
        double AcceptCash(const double money) const noexcept{
            return money * 0.9;
        }
    };
    class CashBack final
    {
    public:
        double AcceptCash(const double money) const noexcept{
            return money - ((int)(money/100)) * 20;
        }
    };
} // namespace PriceCalc