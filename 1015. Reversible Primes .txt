#include "stdafx.h"
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
int charge(int a)
{
	int i = 0;
	if (a == 0 || a == 1)//0和1不是质数
		return 0;
	int n = sqrt(a);
	for (i = 2; i <= n; i++)
	{
		if (a%i==0)
			return 0;
	}
	if (i == n + 1)
		return 1;
	
}
int main() {
	int n, m;
	bool flag;
	vector<bool>result;
	string map[2] = {"No","Yes"};
	while (1)
	{
		flag = 1;
		int k,temp=0;
		vector<int>ans;
		cin >> n;
		if (n < 0)
			break;
		cin >> m;
		if (!charge(n))
		{
			result.push_back(0);
			continue;
		}
		while (n)
		{
			k = n%m;
			n /= m;
			temp = temp*m + k;
		}
		if (!charge(temp))
			flag = 0;
		result.push_back(flag);
	}
	for (int i = 0; i < result.size(); i++)
		cout << map[result[i]] << endl;

	return 0;
}


