// Project3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool IfPrime(int a)
{
	if (a == 1)
		return 0;
	if (a < 4)
		return 1;
	if ((a & 1)==0)
		return 0;
	int n = sqrt(a);
	for (int i = 3; i <= n; i += 2)
		if (a%i == 0)
			return 0;
	return 1;
}

int BigPrime(int a)
{
	if (a == 1)
		return 2;
	if ((a & 1) == 0)
		a++;
	while (!IfPrime(a))
		a += 2;
	return a;
}
int main()
{
	int n, m,num,cnt,p,k=0;
	cin >> n >> m;

	n = BigPrime(n);
	vector<int>hash(n,0),ans(m,-1);
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cnt = n;
		k = 0;
		while (cnt)
		{
			p = (num + k*k) % n;
			if (hash[p] == 0)
			{
				hash[p] = num;
				ans[i] = p;
				break;
			}
			k++;
			cnt--;
			//cout << cnt;
		}
	}
	
	if (ans[0] != -1)
		printf("%d", ans[0]);
	else
		printf("-");

	for (int i = 1; i < m; i++)
		if (ans[i] != -1)
			printf(" %d", ans[i]);
		else
			printf(" -");
	
    return 0;
}

