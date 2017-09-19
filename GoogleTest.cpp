#include <iostream>
#include <gtest/gtest.h>
using namespace std;


TEST(SquareRootTest, Negative) {
  int i=1;
	int j=2;
	ASSERT_EQ(3,i+j);
}
/*
 *How to compile
 * g++ name.cpp -o name -lgtest
 */

int main(int argc,char * argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
