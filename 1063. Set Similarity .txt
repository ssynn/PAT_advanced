
#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include <algorithm>
#include<list>
#include<map>
#include<iomanip>
#include<set>
using namespace std;
//set³õÌåÑé
int main()
{
	int n,m,temp,k,p,q,sum1,sum2,distinct;
	cin >> n;
	vector<set<int>>val(n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &temp);
			if (val[i].count(temp)==0)
				val[i].insert(temp);
		}
	}
	cin >> k;
	vector<double>ans(k);
	set<int>::iterator it;
	for (int i = 0; i < k; i++)
	{
		distinct=sum1 = sum2 = 0;
		scanf_s("%d%d", &p, &q);
		p--;
		q--;
		sum1 = val[p].size();
		for (it = val[q].begin(); it != val[q].end(); it++)
		{
			if (val[p].count(*it))
				distinct++;
			else
				sum1++;
		}
		ans[i] = distinct*1.0 / sum1;
		ans[i] *= 100;
	}
	for (int i = 0; i < k; i++)
		printf("%.1lf%%\n", ans[i]);
	system("pause");
	return 0;
}
