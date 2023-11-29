#pragma once
#include <cmath>
#include <memory>
#include <unordered_map>
#include <iostream>
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
        class Discount
        {
        public:
            virtual double AcceptCash(const double money) const noexcept = 0;
            virtual ~Discount();
        };
        class Normal final : public Discount
        {
        public:
            double AcceptCash(const double money) const noexcept override;
            virtual ~Normal();
        };

        class PercentOff final : public Discount
        {
        private:
            double discountRate = 1;
        public:
            explicit PercentOff(double rate);
            virtual ~PercentOff();
            double AcceptCash(const double money) const noexcept override;
        };
        class CashBack final : public Discount
        {
            double threshold = 100.0;
            double cashback = 20.0;

        public:
            explicit CashBack(double threshold, double cashback);
            virtual ~CashBack();
            double AcceptCash(const double money) const noexcept override;
        };
        // 折扣方法表
        std::unordered_map<DiscountType, std::unique_ptr<Discount>> discountMap;
        // 将构造函数声明为私有避免用户自己创建实例
        PriceCalculator()
        {
            std::cout << "Constructor is called" << std::endl;
            discountMap.emplace(DiscountType::CASH_NORMAL, std::make_unique<Normal>());
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, std::make_unique<PercentOff>(0.9));
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, std::make_unique<PercentOff>(0.8));
            discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, std::make_unique<PercentOff>(0.7));
            discountMap.emplace(DiscountType::CASH_BACK, std::make_unique<CashBack>(100.0, 20.0));
        }
    };
} // namespace PriceCalc