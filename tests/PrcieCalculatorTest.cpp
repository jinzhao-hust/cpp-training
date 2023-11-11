#include <gtest/gtest.h>

#include "hello.h"
#include "PriceCalculator.h"
using namespace PriceCal;


TEST(PriceCalculator, return_100_when_given_100)
{
    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.AcceptPrice(100, DiscountType::NONE_DISCOUNT);
    
    // then
    EXPECT_DOUBLE_EQ(100, cash);
}

// TEST(PriceCalculator, return_81_when_given_90)
// {
//     PriceCalculator priceCalculator;
//     priceCalculator.AcceptPrice(90, DiscountType::PERCENT_DISCOUNT);
//     EXPECT_DOUBLE_EQ(81, test());
// }


