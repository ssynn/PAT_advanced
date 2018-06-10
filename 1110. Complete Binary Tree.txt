#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
	int left, right;
};
int Change(string &a,vector<bool> &e)
{
	if (a == "-")
		return -1;
	int t = stoi(a);
	e[t] = 1;
	return t;
}

int main()
{
	int n,flag=1,left,right,root;
	string l, r;								//²»ÄÜÓÃchar
	cin >> n;
	vector<bool>exist(n, 0);
	vector<Node>val(n);
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		val[i].left = Change(l,exist);
		val[i].right = Change(r,exist);
	}

	for(int i=0;i<n;i++)
		if (exist[i] == 0)
		{
			root = i;
			break;
		}

	queue<int>level;
	vector<int>ans;
	level.push(root);
	ans.push_back(root);
	while (!level.empty())
	{
		int top = level.front();
		if (val[top].left != -1)
		{
			level.push(val[top].left);
			ans.push_back(val[top].left);
		}
		else
			break;
		if (val[top].right != -1)
		{
			level.push(val[top].right);
			ans.push_back(val[top].right);
		}
		else
			break;
		level.pop();
	}

	if (ans.size() != n)
		flag = 0;
	
	if (!flag)
		cout << "NO " << root;
	else
		cout << "YES " << ans[n - 1];

	system("pause");
	return 0;
}
