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

//ÕâµÀÌâÂÔÎ¢¿¨iostream
struct Chain
{
	int begin, end,val;
};
int main()
{
	int n, k, value, min, p = 0,q=0;
	cin >> n >> k;
	min = INT_MAX;
	vector<int>val(n);
	vector<Chain>ans;
	for (int i = 0; i < n; i++)
		scanf_s("%d", &val[i]);
	value = val[0];
	if (value > k)
	{
		min = value;
		Chain temp = { p,q,value };
		ans.push_back(temp);	
	}

	while (q < n-1)
	{
		if (value <= k)
		{
				q++;
				value += val[q];
		}
		else
		{
				value -= val[p];
				p++;
		}

		//cout << p+1 << ' ' << q+1 <<' '<<value <<endl;
		if (value >= k&&value <= min)
		{
			min = value;
			Chain temp = { p,q,value};
			ans.push_back(temp);
		}
	}
	while (p<n&&value > k)
	{
		value -= val[p];
		p++;
		//cout << p + 1 << ' ' << q + 1 << ' ' << value << endl;
		if (value >= k&&value <= min)
		{
			min = value;
			Chain temp = { p,q,value };
			ans.push_back(temp);
		}
	}

	for (int i = 0; i < ans.size(); i++)
		if (ans[i].val == min)
			printf("%d-%d\n", ans[i].begin + 1 , ans[i].end + 1);


	system("pause");
	return 0;
}


