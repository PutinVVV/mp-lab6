#include "PPolynom.h"
#include <gtest.h>

TEST(PPolynom, is_digit_true)//+
{
	char a = '5';
	ASSERT_EQ(true,isDigit(a));
}

TEST(PPolynom, is_digit_false)//+
{
	char a = '+';
	ASSERT_EQ(false, isDigit(a));
}

TEST(PPolynom, stroka_no_trhows)//+
{
	char a[] = "3+2*5/(1+8)";
	char b[] = "325*19+/+";
	ASSERT_NO_THROW(Stroka(a));
}

TEST(PPolynom, stroka_eq)//+
{
	char a[] = "8/2-2*(1+1)";
	char b[] = "82/211+*-";
	ASSERT_EQ("82/211+*-", Stroka(a));
}

TEST(PPolynom, calculator)//+
{
	char b[] = "82/211+*-";//= "8/2-2*(1+1)";
	ASSERT_EQ(0, calcul(b));
}
