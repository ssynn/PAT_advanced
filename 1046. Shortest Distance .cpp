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

//这道题类似于求时钟的时差
int main()
{
	
	int n,m, begin,end,sum=0;
	cin >> n;
	vector<int>val(n+2,0);
	for (int i = 2; i <= n+1; i++)
	{
		scanf_s("%d", &val[i]);
		sum += val[i];
		val[i] = sum;
	}
	cin >> m;
	vector<int>ans(m);
	for (int i = 0; i < m; i++)
	{
		int len1 =0, len2 = 0;
		scanf_s("%d%d", &begin, &end);
		if (begin > end)
		{
			int t;
			t = begin;
			begin = end;
			end = t;
		}
		len1 = val[end] - val[begin];
		
		len2 = sum - val[end] + val[begin];
		//cout << len1 << ' ' << len2 << endl;


		if (len2 < len1)
			len1 = len2;
		ans[i] = len1;
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	system("pause");
	return 0;
}


