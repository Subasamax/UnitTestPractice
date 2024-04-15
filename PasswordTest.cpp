/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password){
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, Check_different_char){
	Password my_password;
	int actual = my_password.count_leading_characters("ZA");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, Check_different_char_multiple){
	Password my_password;
	int actual = my_password.count_leading_characters("ZAAA");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, check_different_case){
	Password my_password;
	int actual = my_password.count_leading_characters("ZZz");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, Check_special_pass){
	Password my_password;
	int actual = my_password.count_leading_characters("@@Z");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, no_password){
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, two_leading_blank_space){
	Password my_password;
	int actual = my_password.count_leading_characters("  ");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, leading_blank_space){
	Password my_password;
	int actual = my_password.count_leading_characters(" ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, five_leading){
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAA");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, no_mixed_case){
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case){
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAa");
	ASSERT_EQ(true, actual);
}


TEST(PasswordTest, no_password_mixed_case){
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}


TEST(PasswordTest, random_mixed_case){
	Password my_password;
	bool actual = my_password.has_mixed_case("aAvXE");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_space){
	Password my_password;
	bool actual = my_password.has_mixed_case("AAA XE");
	ASSERT_EQ(false, actual);
}


TEST(PasswordTest, lowercase_special){
	Password my_password;
	bool actual = my_password.has_mixed_case("AAA@XE");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_special){
	Password my_password;
	bool actual = my_password.has_mixed_case("AAA@zXE");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_one_char){
	Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_all_lowercase){
	Password my_password;
	bool actual = my_password.has_mixed_case("aasdfsds");
	ASSERT_EQ(false, actual);
}


