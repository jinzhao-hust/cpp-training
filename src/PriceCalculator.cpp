#include "PriceCalculator.h"

namespace PriceCal{
    double PriceCalculator::AcceptPrice(const double price, const DiscountType type) const noexcept
    {
        double finalPrice;
        int cashBackCount = 0;
        int cashBackNum = 20;
        switch (type)
        {
        case DiscountType::NONE_DISCOUNT:
            finalPrice = price;
            return finalPrice;
            break;
        case DiscountType::PERCENT_DISCOUNT:
            finalPrice = price * 0.9;
            return finalPrice;
        case DiscountType::CASH_DISCOUNT:
            cashBackCount = price / 100;
            finalPrice = price - cashBackCount * cashBackNum;
            return finalPrice;
        default:
            break;
        }
        return 0;
    }
}