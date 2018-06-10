#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>
#include<map>
#include<limits.h>
using namespace std;

int IfIncrease(vector<int> &a, int n)
{
	for (int i = 0; i < n-1; i++)
		if (a[i] > a[i + 1])
			return i;
	return n-1;
}

void MergeSort(vector<int> &a, int n,int len)
{
	int k = n / len;
	for (int i = 0; i < k; i++)
		sort(a.begin() + i*len, a.begin() + (i + 1)*len);
	sort(a.begin() + k*len, a.end());
	
}

int main()
{
	int n,k,len=2;
	bool flag = 0;
	cin >> n;
	vector<int>a1(n), a2(n);
	for (int i = 0; i < n; i++)
		cin >> a1[i];
	for (int i = 0; i < n; i++)
		cin >> a2[i];

	k = IfIncrease(a2, n)+1;
	for(int i=k;i<n;i++)
		if (a2[i] != a1[i])
		{
			//cout << i;
			flag = 1;
			break;
		}
	if (!flag)
	{
		cout << "Insertion Sort\n";
		sort(a2.begin(), a2.begin() + k+1);
		cout << a2[0];
		for (int i = 1; i < n; i++)
			cout << ' ' << a2[i];
		return 0;
	}

	cout << "Merge Sort\n";
	
	while (a2 != a1)
	{
		MergeSort(a1, n, len);
		len *= 2;
	}
	MergeSort(a1, n, len);
	cout << a1[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << a1[i];
	system("pause");
	return 0;
}

