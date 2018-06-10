#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<list>
using namespace std;

int main()
{
	map<int,int>colorNum;
	int m, n,max=0,maxN=0,temp;
	cin >> m >> n;
	m *= n;
	for (int i = 0; i < m; i++)
	{
		scanf("%d",&n);
		temp=++colorNum[n];
		if (temp > maxN)
		{
			maxN = temp;
			max = n;
		}
	}
	cout << n;
	system("pause");
	return 0;
}
