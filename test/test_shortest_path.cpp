#include <gtest/gtest.h>
#include "../includes/file_reader.h"
#include "../includes/HeapDijkstra.h"

using namespace std;

TEST(DefaulteTests, Test_1) {
  string filename = "../../src/examples/basic_example_1.txt"; 
  auto myGraph = readGraphFromFile(filename);

  int result = shortestPath(myGraph);
  
  EXPECT_EQ(475, result);
}

TEST(DefaulteTests, Test_2)
{
  string filename = "../../src/examples/basic_example_2.txt"; 
  auto myGraph = readGraphFromFile(filename);

  int result = shortestPath(myGraph);
  
  EXPECT_EQ(173, result);
}

TEST(MyTests, Test_1)
{
  string filename = "../../src/examples/my_example_1.txt"; 
  auto myGraph = readGraphFromFile(filename);

  int result = shortestPath(myGraph);
  
  EXPECT_EQ(16, result);
}

TEST(MyTests, Test_2)
{
  string filename = "../../src/examples/my_example_2.txt"; 
  auto myGraph = readGraphFromFile(filename);

  int result = shortestPath(myGraph);
  
  EXPECT_EQ(18, result);
}

TEST(MyTests, Test_3)
{
  string filename = "../../src/examples/my_example_3.txt"; 
  auto myGraph = readGraphFromFile(filename);

  int result = shortestPath(myGraph);
  
  EXPECT_EQ(7, result);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
