#include "PriceCalculator.h"

#include <cmath>
#include <iostream>
#include <memory>
#include <unordered_map>
namespace PriceCalc
{
    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        // TODO 修改为map在整个声明周期只生成一次，也就是在这个test期间只生成一次，而PriceCalculator则可能生成多次
        // 可以使用static，也可以使用工厂模式的单体类实现。
        std::unordered_map<DiscountType, std::unique_ptr<Discount>> discountMap;
        discountMap.emplace(DiscountType::CASH_NORMAL,std::make_unique<Normal>());
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, std::make_unique<PercentOff>(0.9));
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, std::make_unique<PercentOff>(0.8));
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, std::make_unique<PercentOff>(0.7));
        discountMap.emplace(DiscountType::CASH_BACK, std::make_unique<CashBack>(100.0, 20.0));
        return discountMap.find(discountType)->second->AcceptCash(money);
        // std::unique_ptr<Discount> discount;
        // switch (discountType)
        // {
        // case DiscountType::CASH_NORMAL:
        //     discount = std::make_unique<Normal>();
        //     break;

        // case DiscountType::CASH_PERCENTOFF_10:
        //     discount = std::make_unique<PercentOff>(0.9);
        //     break;

        // case DiscountType::CASH_PERCENTOFF_20:
        //     discount = std::make_unique<PercentOff>(0.8);
        //     break;

        // case DiscountType::CASH_PERCENTOFF_30:
        //     discount = std::make_unique<PercentOff>(0.7);
        //     break;

        // case DiscountType::CASH_BACK:
        //     discount= std::make_unique<CashBack>(100.0,20.0);
        //     break;

        // default:
        //     break;
        // }
        // cash = discount->AcceptCash(money);
        // return cash;
    }
    
} // namespace PriceCalc