#ifndef PRICE_CACULATOR_H_
#define PRICE_CACULATOR_H_
namespace PriceCal{
    enum class DiscountType
    {
        NONE_DISCOUNT,
        PERCENT_DISCOUNT,
        CASH_DISCOUNT
    };

    class PriceCalculator final
    {
    public:
        double AcceptPrice(const double price, const DiscountType type) const noexcept;
    };
}
#endif