#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;

#define defSize 300
#define defMaxWeight 150
#define defMinWeight 5
#define defPath "filename2.txt"

int main()
{
	srand(time(NULL));
	vector<int> thisLine;
	vector<vector<int>> graph;
	for (int i = 0; i < defSize; i++)
	{
		for (int j = 0; j < defSize; j++)
		{
			if (i == j)
				thisLine.push_back(0);
			else
			{
				thisLine.push_back(rand() % (defMaxWeight - defMinWeight + 1) + defMinWeight - 1);
			}
		}
		graph.push_back(thisLine);
		thisLine.clear();
	}
	for (int i = 0; i < defSize; i++)
	{
		for (int j = i + 1; j < defSize; j++)
		{
			if (graph[i][j] == graph[j][i])
			{
				cout << "[" << i << "," << j << "]" << " is equal to " << "[" << j << "," << i << "]" << endl;
				if (graph[i][j] > defMaxWeight / 2)
				{
					--graph[i][j];
				}
				else
				{
					++graph[i][j];
				}
				cout << "\tnow" << "[" << i << "," << j << "]" << " is " << graph[i][j] << endl;
				cout << "\tnow" << "[" << j << "," << i << "]" << " is " << graph[j][i] << endl;
			}
		}
	}
	ofstream output;
	output.open(defPath);
	output << graph.size();
	for (int i = 0; i < defSize; i++)
	{
		for (int j = 0; j < defSize; j++)
		{
			output << " " << graph[i][j];
		}
	}
	graph.clear();
	output.close();
}