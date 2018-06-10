#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<stdio.h>
#include<limits.h>
using namespace std;


int main()
{
	int n, num = 0,maxLength=0;
	cin >> n;
	vector<int>exist(n+1,0);
	vector<int>val;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		exist[num] = i+1;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (exist[num])
			val.push_back(exist[num]);
	}

	vector<int>res(val.size(), 0);
	for (int i = 0; i < val.size(); i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (val[i] >= val[j] && res[j] >= max)
				max = res[j];
		}
		res[i] = max+1;
		if (max + 1 > maxLength)
			maxLength = max + 1;
	}

	cout << maxLength;
	system("pause");
	return 0;
}


