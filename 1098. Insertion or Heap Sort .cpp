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
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			return i;
	return n - 1;
}
void HeapAdjust(vector<int> &a, int begin, int end)
{
	if (end <= 0)
		return;
	int rc = a[begin];										//临时存储第一个父节点的值
	int i = begin;											//i表示父节点
	for (int j = 2 * i + 1; j <= end; j *= 2)				//j为i的左孩子
	{
		if (j < end&&a[j] < a[j + 1])j++;					//从较大的孩子往下调整
		if (rc > a[j])break;
		a[i] = a[j];										//将较大的值付给根节点
		i = j;												//跟新父节点
	}
	a[i] = rc;
}

int main()
{
	int n, k, len = 2;
	bool flag = 0;
	cin >> n;
	vector<int>a1(n), a2(n);
	for (int i = 0; i < n; i++)
		cin >> a1[i];
	for (int i = 0; i < n; i++)
		cin >> a2[i];

	k = IfIncrease(a2, n) + 1;
	for (int i = k; i<n; i++)
		if (a2[i] != a1[i])
		{
			flag = 1;
			break;
		}
	if (!flag)
	{
		cout << "Insertion Sort\n";
		sort(a2.begin(), a2.begin() + k + 1);
		
	}
	else
	{
		int temp;
		temp = n - 1;
		while (a2[temp] > a2[0])temp--;
		temp++;
		pop_heap(a2.begin(), a2.begin() + temp);

		cout << "Heap Sort\n";
	}
	
	cout << a2[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << a2[i];
	system("pause");
	return 0;
}

