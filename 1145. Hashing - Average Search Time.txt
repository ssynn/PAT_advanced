#include <iostream>
#include<vector>
#include <math.h>
#include<stdio.h>
#include<map>
#include<string>
#include<math.h>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<regex>
using namespace std;
int n;
bool IfPrime(int a)
{
	if (a == 1)
		return 0;
	if (a < 4)
		return 1;
	if (a % 2 == 0)
		return 0;
	int t = sqrt(a);
	for (int i = 3; i < t; i += 2)
		if (a%i == 0)
			return 0;
	return 1;
}
int main()
{
	int k, m, cnt=0;
	cin >> k >> n >> m;
	while (!IfPrime(k))k++;
	vector<int>val(k, 0);
	map<int, bool>e;
	for (int i = 0; i < n; i++)
	{
		int t, flag = 0,j=0;
		cin >> t;
		while (val[(t+j*j)%k])
		{
			j++;
			if (j == k)
			{
				cout <<t<< " cannot be inserted.\n";
				break;
			}
		}
		if (j < k)val[(t + j*j) % k] = t;
	}
	for(int j=0;j<m;j++)
	{
		int t;
		cin >> t;
		for (int i = 0; i <= k; i++)
		{
			cnt++;
			if (val[(t + i*i) % k] == t || val[(t + i*i) % k]==0)
				break;
		}
	}
	
	printf("%0.1lf", 1.0*cnt / m);
	return 0;
}