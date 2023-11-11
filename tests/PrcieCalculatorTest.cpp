#include <gtest/gtest.h>

#include "hello.h"
#include "PriceCalculator.h"
using namespace PriceCal;


TEST(PriceCalculator, return_100_when_given_100)
{
    PriceCalculator priceCalculator;
    priceCalculator.AcceptPrice(100, DiscountType::NONE_DISCOUNT);
    EXPECT_DOUBLE_EQ(100, test());
}

