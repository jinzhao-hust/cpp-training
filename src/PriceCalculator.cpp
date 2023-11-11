#include "PriceCalculator.h"

namespace PriceCal{
    double PriceCalculator::AcceptPrice(const double price, const DiscountType type) const noexcept
    {
        double finalPrice;
        switch (type)
        {
        case DiscountType::NONE_DISCOUNT:
            finalPrice = price;
            return finalPrice;
            break;
        default:
            break;
        }
        return 0;
    }
}