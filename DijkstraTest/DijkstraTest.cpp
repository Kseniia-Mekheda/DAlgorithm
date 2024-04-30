#include "pch.h"
#include "CppUnitTest.h"
#include "../DAlgorithm/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DijkstraTest
{
	TEST_CLASS(DijkstraTest)
	{
	public:
		TEST_METHOD(AlgorithmTest)
		{
            Graph A(5);
            A.addEdge(0, 1, 10);
            A.addEdge(0, 2, 3);
            A.addEdge(1, 2, 1);
            A.addEdge(1, 3, 2);
            A.addEdge(2, 1, 4);
            A.addEdge(2, 3, 8);
            A.addEdge(2, 4, 2);
            A.addEdge(3, 4, 7);
            A.addEdge(4, 3, 9);

            int expected = A.dijkstra(0);

            Assert::AreEqual(9, expected);
		}

        TEST_METHOD(InvalidEdgeTest)
        {
            Graph A(3);
            stringstream ss;
            streambuf* old_buf = cout.rdbuf();
            cout.rdbuf(ss.rdbuf());

            A.addEdge(0, 0, 2);

            cout.rdbuf(old_buf);
            string output = ss.str();
            string expected_output = "Edge can`t have two similar vertexes!\n";
            Assert::AreEqual(expected_output, output);
        }

        TEST_METHOD(InvaldWeightTest)
        {
            Graph A(3);
            stringstream ss;
            streambuf* old_buf = cout.rdbuf();
            cout.rdbuf(ss.rdbuf());

            A.addEdge(0, 1, -2);

            cout.rdbuf(old_buf);
            string output = ss.str();
            string expected_output = "Invalid weight\n";
            Assert::AreEqual(expected_output, output);
        }

        TEST_METHOD(Algorithm2Test)
        {
            Graph g(6);
            g.addEdge(0, 1, 4);
            g.addEdge(0, 2, 2);
            g.addEdge(1, 2, 5);
            g.addEdge(1, 3, 10);
            g.addEdge(2, 4, 3);
            g.addEdge(3, 4, 4);
            g.addEdge(3, 5, 2);
            g.addEdge(4, 5, 1);

            int expected = g.dijkstra(0);
            Assert::AreEqual(8, expected);
        }

        TEST_METHOD(GetWeightTest)
        {
            Graph g(6);
            g.addEdge(0, 1, 4);
            g.addEdge(0, 2, 2);
            g.addEdge(1, 2, 5);
            g.addEdge(1, 3, 10);
            g.addEdge(2, 4, 3);
            g.addEdge(3, 4, 4);
            g.addEdge(3, 5, 2);
            g.addEdge(4, 5, 1);

            Assert::AreEqual(4, g.getEdgeWeight(0, 1));
            Assert::AreEqual(10, g.getEdgeWeight(1, 3));
            Assert::AreEqual(1, g.getEdgeWeight(4, 5));
        }
	};
}
