#include"stdafx.h"
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int IfSorted(vector<int> &a, int n,int be)
{
	for (int i = be; i<n; i++)
		if (a[i] != i)
			return i;
	return 0;
}
int main() {
	int n, zero, cnt = 0, flag = 1,t;
	cin >> n;
	vector<int> map(n);			//map用于存放每个数字的位置
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &t);
		map[t] = i;
	}
	while (flag)//flag为每次找到的最小的有序数
	{
		while(map[0])
		{
			t = map[0];
			map[0] = map[t];
			map[t] = t;
			cnt++;
		}
		flag = IfSorted(map, n,flag);
		if (flag)
		{
			map[0] = map[flag];
			map[flag] = 0;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}