#include <gtest/gtest.h>

#include "hello.h"
#include "PriceCalculator.h"
using namespace PriceCal;


TEST(PriceCalculator, return_100_when_given_100_NONE_DISCOUNT)
{
    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.AcceptPrice(100, DiscountType::NONE_DISCOUNT);
    
    // then
    EXPECT_DOUBLE_EQ(100, cash);
}

TEST(PriceCalculator, return_81_when_given_90_PERCENT_DISCOUNT)
{
    
    // given
    PriceCalculator priceCalculator;
    
    // when
    double cash = priceCalculator.AcceptPrice(90, DiscountType::PERCENT_DISCOUNT);
    
    // then
    EXPECT_DOUBLE_EQ(81, cash);
}

TEST(PriceCalculator, return_90_when_given_90_CASH_DISCOUNT)
{

    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.AcceptPrice(90, DiscountType::CASH_DISCOUNT);

    // then
    EXPECT_DOUBLE_EQ(90, cash);
}

TEST(PriceCalculator, return_80_when_given_100_CASH_DISCOUNT)
{

    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.AcceptPrice(100, DiscountType::CASH_DISCOUNT);

    // then
    EXPECT_DOUBLE_EQ(80, cash);
}

TEST(PriceCalculator, return_528_when_given_648_CASH_DISCOUNT)
{

    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.AcceptPrice(648, DiscountType::CASH_DISCOUNT);

    // then
    EXPECT_DOUBLE_EQ(588, cash);
}