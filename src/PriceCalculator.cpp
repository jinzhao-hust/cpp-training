#include "PriceCalculator.h"

#include <cmath>
#include <iostream>
#include <memory>
namespace PriceCalc
{
    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        double cash = 0.0;
        std::unique_ptr<Discount> discount;
        switch (discountType)
        {
        case DiscountType::CASH_NORMAL:
            discount = std::make_unique<Normal>();
            break;

        case DiscountType::CASH_PERCENTOFF_10:
            discount = std::make_unique<PercentOff>(0.9);
            break;

        case DiscountType::CASH_PERCENTOFF_20:
            discount = std::make_unique<PercentOff>(0.8);
            break;

        case DiscountType::CASH_PERCENTOFF_30:
            discount = std::make_unique<PercentOff>(0.7);
            break;

        case DiscountType::CASH_BACK:
            discount= std::make_unique<CashBack>(100.0,20.0);
            break;

        default:
            break;
        }
        cash = discount->AcceptCash(money);
        return cash;
    }
    
} // namespace PriceCalc