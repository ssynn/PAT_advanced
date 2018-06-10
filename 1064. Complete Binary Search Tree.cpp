#include"stdafx.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include <algorithm>
#include<list>
#include<map>
#include<iomanip>
#include<set>

//利用了完全二叉树下标的规律，而且完全二叉搜索树中序遍历就是从小到大的顺序
using namespace std;
int n,m=1;

void inOrder(int index,vector<int> &val,vector<int> &ans)
{
	if (index * 2 <= n) inOrder(2 * index,val,ans);
	ans[index] = val[m++];
	if (index * 2 + 1 <= n) inOrder(2 * index + 1, val, ans);
}

int main()
{
	cin >> n;
	vector<int>val(n+1),ans(n+1);
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	sort(val.begin(), val.end());

	inOrder(1, val, ans);
	for (int i = 1; i < n; i++)
		cout << ans[i]<<' ';
	cout << ans[n];
	system("pause");
	return 0;
}
