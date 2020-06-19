#include <iostream>
#include "gtest/gtest.h"

#include "Bond.hpp"

TEST(BondTest, ConstructorDefault) 
{
	Bond bond;
	
	EXPECT_EQ(0, bond.getValue());
}

TEST(BondTest, ConstructorDefaultNeq) 
{
	Bond bond;
	
	EXPECT_NE(2, bond.getValue());
}

TEST(BondTest, ConstructorParam) 
{
	auto upBond = std::make_unique<Bond>(250);

	EXPECT_EQ(250, upBond->getValue());
}