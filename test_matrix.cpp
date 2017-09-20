#include <gtest/gtest.h>
#include <iostream>
#include "AdjacencyMatrix.h"
class Matrix_Test : public ::testing::Test{
protected:

    virtual void SetUp(){
       if(TestFile!="")matrix.loadFromFile(TestFile);
       std::cout<<matrix.getV();
	}
    virtual void TearDown(){
        matrix.clear();
	}
  AdjacencyMatrix matrix;
  const std::string TestFile = "";
};

TEST_F(Matrix_Test,generate){
    int vertexAmount = 10;
    int maxValue = 100;
    int minValue = -100;
    int value=matrix.getV();

    if(matrix.getV()!=0)matrix.clear();
    matrix.generate(vertexAmount,minValue,maxValue);
    EXPECT_TRUE(matrix.getV()==vertexAmount);
    EXPECT_TRUE(matrix.getE()==vertexAmount*(vertexAmount-1));

    for(int i=0;i<vertexAmount;i++){
      for(int j=0;j<vertexAmount;j++){
            if(i!=j){EXPECT_TRUE(matrix.getValue(i,j)>=minValue&&matrix.getValue(i,j)<=maxValue);}
        }
    }
}


TEST_F(Matrix_Test,clear){
  int vertexAmount = 10;
  int maxValue = 100;
  int minValue = -100;
  matrix.generate(vertexAmount,minValue,maxValue);
  matrix.clear();
  EXPECT_TRUE(matrix.getV()==0);
  EXPECT_TRUE(matrix.getE()==0);
}

TEST_F(Matrix_Test,loadFromFile){
    matrix.clear();
    matrix.loadFromFile("tsp4.txt");
    EXPECT_TRUE(matrix.getV()==4)<<matrix.getV();
    EXPECT_TRUE(matrix.getE()==12)<<matrix.getE();
    EXPECT_TRUE(matrix.getValue(0,0)==0);
    EXPECT_TRUE(matrix.getValue(1,1)==0);
    EXPECT_TRUE(matrix.getValue(2,2)==0);
    EXPECT_TRUE(matrix.getValue(3,3)==0);

    EXPECT_TRUE(matrix.getValue(0,1)==92);
    EXPECT_TRUE(matrix.getValue(0,2)==89);
    EXPECT_TRUE(matrix.getValue(0,3)==17);

    EXPECT_TRUE(matrix.getValue(1,0)==92);
    EXPECT_TRUE(matrix.getValue(1,2)==24);
    EXPECT_TRUE(matrix.getValue(1,3)==95);

    EXPECT_TRUE(matrix.getValue(2,0)==89);
    EXPECT_TRUE(matrix.getValue(2,1)==24);
    EXPECT_TRUE(matrix.getValue(2,3)==67);

    EXPECT_TRUE(matrix.getValue(3,0)==17);
    EXPECT_TRUE(matrix.getValue(3,1)==95);
    EXPECT_TRUE(matrix.getValue(3,2)==67);

}


TEST_F(Matrix_Test,addVertex){

}

TEST_F(Matrix_Test,addEdge){

}

TEST_F(Matrix_Test,getEdgeValue){

}



int main(int argc,char * argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
