/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, count_leading_characters_single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_long_repeating_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAA1ijoiasdf23");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, count_leading_characters_uppercase_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAA1ijoiasAAdf23Aa");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, count_leading_characters_lowercase_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("bAA1ijoiaasAAdf23Aab");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, only_uppercase_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ABCDEF");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_lowercase_characters)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aaaaajijijodjodsaocda");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, single_uppercase_among_lowercas)
{
	Password my_password;
	int actual = my_password.has_mixed_case("joajiodIokjoajfoo");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_lower_then_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_upper_then_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_single_lowercase_letter)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("a");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_single_uppercase_letter)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, count_leading_characters_empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, count_leading_characters_case_sensitive)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zzz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_non_letter_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("   x");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, mixed_case_lowercase_with_digits)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abc123");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_uppercase_with_symbols)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ABC!?");
	ASSERT_EQ(false, actual);
}