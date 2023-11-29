#pragma once
#include <cmath>
#include <memory>
#include <unordered_map>
#include <iostream>
#include <functional>
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
    // TODO 将声明和实现拆分，注意命令规范和提交记录。
    // TODO 尝试使用新方法，使得添加新的折扣策略时的方法相对简单。
    class PriceCalculator final
    {
    public:
        PriceCalculator(const PriceCalculator &) = delete;
        PriceCalculator &operator=(const PriceCalculator &) = delete;
        static PriceCalculator& GetInstance();
        double AcceptCash(const DiscountType discountType, const double money) const noexcept;
    private:
        class Normal final
        {
        public:
            double AcceptCash(const double money) const noexcept;
            virtual ~Normal();
        };

        class PercentOff final
        {
        private:
            double discountRate = 1;
        public:
            explicit PercentOff(double rate);
            virtual ~PercentOff();
            double AcceptCash(const double money) const noexcept;
        };
        class CashBack final
        {
            double threshold = 100.0;
            double cashback = 20.0;

        public:
            explicit CashBack(double threshold, double cashback);
            virtual ~CashBack();
            double AcceptCash(const double money) const noexcept;
        };
        // 折扣方法表
        std::unordered_map<DiscountType, std::function<double(double)>> discountMap;
        // 添加私有成员，使内部类实例的声明周期和PriceCalculator保持一致
        Normal normal;
        PercentOff percentOff10;
        PercentOff percentOff20;
        PercentOff percentOff30;
        CashBack cashBack;
        // 将构造函数声明为私有避免用户自己创建实例
        PriceCalculator()
            : percentOff10(0.9), percentOff20(0.8), percentOff30(0.7), cashBack(100.0, 20.0)
        {
            std::cout << "Constructor is called" << std::endl;
            discountMap.emplace(DiscountType::CASH_NORMAL, [this](double money)
                                { return normal.AcceptCash(money); });
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, [this](double money)
                                { return percentOff10.AcceptCash(money); });
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, [this](double money)
                                { return percentOff20.AcceptCash(money); });
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, [this](double money)
                                { return percentOff30.AcceptCash(money); });
            discountMap.emplace(DiscountType::CASH_BACK, [this](double money)
                                { return cashBack.AcceptCash(money); });
        }
    };
} // namespace PriceCalc