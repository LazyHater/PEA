#include <gtest/gtest.h>
#include <iostream>

class Matrix_Test : public ::testing::Test{
  const std::string TestFile = "READMY.txt";

  virtual void SetUp(){
	}
	virtual void TearDown(){

	}
	//------
	Matrix_Test(){}
	~Matrix_Test(){}
	//-------
};


TEST(Matrix,Matrix){

}

TEST(Matrix,addVertex){

}

TEST(Matrix,addEdge){

}

TEST(Matrix,getEdgeValue){

}



int main(int argc,char * argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
