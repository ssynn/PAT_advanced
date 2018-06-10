#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<stdio.h>
using namespace std;
int main()
{
	int numMap[10001] = {0}, flag = 0;
	int n,num;
	cin >> n;
	vector<int>numList(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numList[i];
		numMap[numList[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (numMap[numList[i]] == 1)
			{
				cout << numList[i];
				flag = 1;
				break;
			}
	}
	if (flag==0)
		cout << "None";
	system("pause");
	return 0;
}


