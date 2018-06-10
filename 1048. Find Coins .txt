#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<list>
using namespace std;

int BinerySserach(vector<int> &val, int k, int n)
{
	int center = n / 2, p, q;
	p = 0, q = n - 1;
	while (val[center] != k&&p != center&&q != center)
	{
		if (val[center]>k)
		{
			q = center;
			center = (p + center) / 2;

		}
		else if (val[center]<k)
		{
			p = center;
			center = (center + q) / 2;

		}
	}
	if (val[center] != k)
		return q;
	return center;
}
int main()
{
	
	int n,k,p=0,sum;
	cin >> n>>k;
	vector<int>val(n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &val[i]);

	sort(val.begin(), val.end());
	int q = BinerySserach(val, k - val[0], n);
	sum = val[p] + val[q];
	//cout << p << ' ' << q<<endl;
	while (p < q)
	{
		//cout << p << ' ' << q << endl;
		if (sum == k)
		{
			cout << val[p] << ' ' << val[q];
			break;
		}

		if (sum > k)
			q--;
		else if (sum < k)
			p++;
		if (p == q)
		{
			sum = -1;
			break;
		}
		sum = val[p] + val[q];
	}
	//cout << sum << ' ' << k;
	if (sum != k)
		cout << "No Solution";
	system("pause");
	return 0;
}


