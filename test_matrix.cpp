#include <gtest/gtest.h>
#include <iostream>

class Matrix_Test : public ::testing::Test{
protected:
    AdjacencyMatrix matrix;
    const std::string TestFile = "";

    virtual void SetUp(){
        if(TestFile!="")matrix.loadFromFile(TestFile);
	}
    virtual void TearDown(){
        matrix.clear();
	}
	//------
	Matrix_Test(){}
	~Matrix_Test(){}
	//-------
};

TEST(Matrix_Test,generate){
    int vertexAmount=10;
    int maxValue=100;
    int minValue=-100;
    if(matrix.GetV()!=0)GetMatrix().clear();
    GetMatrix().generate(vertexAmount,minValue,maxValue);
    EXPECT_TRUE(matrix.GetV()==vertexAmount);
    EXPECT_TRUE(matrix.GetE()==vertexAmount(vertexAmount-1));
    for(auto i : vertexAmount){
        for(auto j : vertexAmount){
            if(i!=j){EXPECT_TRUE(matrix.getValue(i,j)>=minValue&&matrix.getValue(i,j)<=maxValue);}
        }
    }
}
TEST(Matrix_Test,clear){

}

TEST(Matrix_Test,loadFromFile){

}


TEST(Matrix_Test,addVertex){

}

TEST(Matrix_Test,addEdge){

}

TEST(Matrix_Test,getEdgeValue){

}



int main(int argc,char * argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
