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

TEST(ErrorTest, Error_example_1) 
{
  try
  {
    string filename = "../../src/examples/Error_example_18.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: Could not open file: ../../src/examples/Error_example_18.txt", string(e.what()));
  }
}

TEST(ErrorTest, Error_example_2) 
{
  try
  {
    string filename = "../../src/examples/Error/Error_example_1.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: File is empty: ../../src/examples/Error/Error_example_1.txt", string(e.what()));
  }
}

TEST(ErrorTest, Error_example_3) 
{
  try
  {
    string filename = "../../src/examples/Error/Error_example_2.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: Invalid format for vertices and edges count in the first line of ../../src/examples/Error/Error_example_2.txt", string(e.what()));
  }
}

TEST(ErrorTest, Error_example_4) 
{
  try
  {
    string filename = "../../src/examples/Error/Error_example_3.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: Number of vertices must be (1000>=V>=2), and edges must be (10000>=E>=1) in ../../src/examples/Error/Error_example_3.txt", string(e.what()));
  }
}

TEST(ErrorTest, Error_example_5) 
{
  try
  {
    string filename = "../../src/examples/Error/Error_example_4.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: Invalid format for edge data at line 2 of ../../src/examples/Error/Error_example_4.txt", string(e.what()));
  }
}

TEST(ErrorTest, Error_example_6) 
{
  try
  {
    string filename = "../../src/examples/Error/Error_example_5.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: The index of a vertex or other value is beyond the acceptable range. At line 2 of ../../src/examples/Error/Error_example_5.txt", string(e.what()));
  }
}

TEST(ErrorTest, Error_example_7) 
{
  try
  {
    string filename = "../../src/examples/Error/Error_example_6.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: Invalid format for start and end point after edges", string(e.what()));
  }
}

TEST(ErrorTest, Error_example_8) 
{
  try
  {
    string filename = "../../src/examples/Error/Error_example_7.txt"; 
    auto myGraph = readGraphFromFile(filename);
    FAIL() << "Expected an exception to be thrown, but it wasn't";
  }
  catch (const runtime_error& e)
  {
    EXPECT_EQ("Error: Invalid start or end point", string(e.what()));
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
