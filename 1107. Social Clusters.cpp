#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
//想的太简单。。。。。。。。
int FindF(int *a, int p)
{
	int i = p;
	while (a[i]) i = a[i];
	return i;
}

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int hobby[1005] = { 0 }, father[1005] = { 0 };
	int n, k, hi;
	char t;
	cin >> n;
	vector<int>ans(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> k >> t;
		while (k--)
		{
			cin >> hi;
			if (!hobby[hi])								//设置集合首领
			{
				hobby[hi] = i;
			}
			else										//并入集合
			{
				father[FindF(father,i)] = FindF(father, hobby[hi]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		k = FindF(father, i);
		ans[k]++;
		//cout << i << ':' << k<<' ';
	}

	sort(ans.begin(), ans.end(), cmp);

	k = 0;
	for (int i = 0; i <= n; i++)
	{
		if (ans[i] == 0)
			break;
		k++;
	}

	cout << k << endl << ans[0];
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 0)
			break;
		cout << ' ' << ans[i];
	}
	system("pause");
	return 0;
}

/*


for (int i = 0; i <= n; i++)
cout << i << ':' << ans[i] << ' ';
cout << endl;



*/