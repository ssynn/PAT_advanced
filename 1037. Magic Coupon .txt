#include"stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool cmp(long long a, long long b)
{
	return a > b;
}
int main()
{
	int n,k=0,j=0;
	long long sum = 0;
	cin >> n;
	vector<long long>copon(n);
	for (int i = 0; i < n; i++)
		cin >> copon[i];
	cin >> n;
	vector<long long>copon2(n);
	for (int i = 0; i < n; i++)
		cin >> copon2[i];
	sort(copon.begin(), copon.end(),cmp);
	sort(copon2.begin(), copon2.end(),cmp);
	while (k < copon.size() && k < copon2.size()&&copon[k] >0 && copon2[k] > 0 )
	{
		sum += copon2[k] * copon[k];
		k++;
	}
	j = copon.size() - 1;
	k = copon2.size() - 1;
	while (j >= 0 && k >= 0&&copon[j] < 0 && copon2[k] < 0 )
	{
		sum += copon2[k] * copon[j];
		j--;
		k--;
	}
	cout << sum;

	system("pause");
	return 0;
}


