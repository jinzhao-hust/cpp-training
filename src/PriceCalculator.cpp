#include "PriceCalculator.h"
namespace PriceCalc
{
    
    // Normal成员函数实现

    PriceCalculator::Normal::~Normal(){}

    double PriceCalculator::Normal::AcceptCash(const double money) const noexcept
    {
        return money;
    }

    // PercentOff成员函数实现

    PriceCalculator::PercentOff::PercentOff(double rate) : discountRate(rate) {}

    PriceCalculator::PercentOff::~PercentOff(){}

    double PriceCalculator::PercentOff::AcceptCash(const double money) const noexcept
    {
        return money * discountRate;
    }

    // CashBack成员函数实现

    PriceCalculator::CashBack::CashBack(double threshold, double cashback) : threshold(threshold), cashback(cashback){}
    
    PriceCalculator::CashBack::~CashBack(){};

    double PriceCalculator::CashBack::AcceptCash(const double money) const noexcept
    {
        return money - floor(money / threshold) * cashback;
    }
    // PriceCalculator成员函数实现
    
    // 获取单例
    PriceCalculator& PriceCalculator::GetInstance()
    {
        static PriceCalculator priceCalculator;
        return priceCalculator;
    }
    
    // 价格计算
    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        // TODO 修改为map在整个声明周期只生成一次，也就是在这个test期间只生成一次，而PriceCalculator则可能生成多次
        // 可以使用static，也可以使用工厂模式的单体类实现。
        // 打印地址
        std::cout<<this<<std::endl;
        std::cout<<&(this->discountMap)<<std::endl;
        double result = this->discountMap.at(discountType)(money);
        return result;
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