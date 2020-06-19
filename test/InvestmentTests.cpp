#include <iostream>
#include "gtest/gtest.h"

#include "Investment.hpp"

TEST(InvestmentTest, ConstructorDefault) 
{
	Investment bond;
	
	EXPECT_EQ(0, bond.getValue());
}

TEST(InvestmentTest, ConstructorDefaultNeq) 
{
	Investment bond;
	
	EXPECT_NE(2, bond.getValue());
}