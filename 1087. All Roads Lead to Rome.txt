#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>
#include<map>
#include<limits.h>
using namespace std;

int  happySum = INT_MAX, aveHappy = INT_MAX, diffetentPath = 1, minCost = INT_MAX, n;

bool visited[201] = { 1 };
int cityHappy[201] = { 0 };
list<int>ans, temp;
void ToAns(int cost, int happy, int num)
{
	happySum = happy;
	minCost = cost;
	aveHappy = happy / num;
	ans = temp;
}
void DFS(vector<vector<int>> &g, int now, int rome, int cost, int happy, int num)
{
	if (now == rome)
	{
		int ave = happy / num;
		if (cost < minCost)
		{
			diffetentPath = 1;
			ToAns(cost, happy, num);
		}
		else if (cost == minCost)
		{
			diffetentPath++;
			if (happy > happySum)
				ToAns(cost, happy, num);
			else if (happy == happySum&&ave>aveHappy)
				ToAns(cost, happy, num);
		}
	}

	if (cost >= minCost)
		return;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0 && g[now][i])
		{
			visited[i] = 1;
			temp.push_back(i);
			DFS(g, i, rome, cost + g[now][i], happy + cityHappy[i], num + 1);
			visited[i] = 0;
			temp.pop_back();
		}
	}
}

int main()
{
	int m, rome, p1, p2, distance;
	cin >> n >> m;

	string city;
	map<string, int>cityIndex;
	vector<string>cityName(n);
	vector<vector<int>>graph(n, vector<int>(n, 0));
	cin>>cityName[0];
	cityIndex[cityName[0]] = 0;
	
	for (int i = 1; i < n ; i++)
	{
		cin >> cityName[i] >> cityHappy[i];
		cityIndex[cityName[i]] = i;
		
		if (cityName[i] == "ROM")
			rome = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> city;
		p1 = cityIndex[city];
		cin >> city;
		p2 = cityIndex[city];
		cin >> distance;
		graph[p1][p2] = graph[p2][p1] = distance;
	}
	
	DFS(graph, 0, rome, 0, 0, 0);

	cout << diffetentPath << ' '
		<< minCost << ' '
		<< happySum << ' '
		<< aveHappy << endl;
	cout << cityName[0];
	list<int>::iterator it = ans.begin();
	
	for (; it != ans.end(); it++)
		cout << "->" << cityName[*it];
	system("pause");
	return 0;
}

/*
for (int i = 0; i < n; i++)
cout << cityIndex[cityName[i]] << ' ';



for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
cout << graph[i][j] << '\t';
cout << endl;
}

*/