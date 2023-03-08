#include "gtest/gtest.h"

int add(int a, int b) {
	return a + b;
}

TEST(testadd, test1) {
	EXPECT_EQ(4, add(2, 2));
	EXPECT_EQ(0, add(-1, 1));
}
TEST(testadd, test2) {
	EXPECT_EQ(9, add(7, 2));
	EXPECT_EQ(1, add(0, 1));
}