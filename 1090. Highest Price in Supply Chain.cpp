#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>
#include<queue>
#include<math.h>
using namespace std;
double price, increase;
int main()
{
	int n, ki,root,cnt=1;
	double max = 0;
	cin >> n >> price >> increase;
	increase = increase / 100 + 1;

	vector<list<int>>supplyTree(n);
	vector<double>nodePrice(n,0);
	queue<int>visit;

	for (int i = 0; i < n; i++)
	{
		cin >> ki;
		if (ki >= 0)					//少写一个等号
			supplyTree[ki].push_back(i);
		else
			root = i;
	}

	nodePrice[root] = price;
	visit.push(root);

	while (!visit.empty())
	{
		int p = visit.front();
		for (auto &i : supplyTree[p])
		{
			nodePrice[i] = nodePrice[p]*increase;
			visit.push(i);
		}
		visit.pop();
	}
	for (int i = 0; i < n; i++)
	{
		if (nodePrice[i] > max)
		{
			max = nodePrice[i];
			cnt = 1;
		}
		else if (max == nodePrice[i])
			cnt++;
		
	}
	cout << fixed << setprecision(2) << max << ' ' << cnt;
	return 0;
}

