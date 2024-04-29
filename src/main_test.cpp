#include "main_test.h"
TEST(TestGoogleTest, Test0)
{
	EXPECT_EQ(0, 0);
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}