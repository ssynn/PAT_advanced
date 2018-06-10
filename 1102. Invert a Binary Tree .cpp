#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;
vector<int>ans;
struct Node
{
	int left, right;

};

void InOrder(vector<Node> &a, int r)
{
	if (a[r].left != -1)
		InOrder(a, a[r].left);
	ans.push_back(r);
	if (a[r].right != -1)
		InOrder(a, a[r].right);
}

int main()
{
	int n,root,p;
	char t;
	Node empt = { -1,-1 };
	cin >> n;
	vector<Node>tree(n,empt);
	vector<bool>exist(n, 0);
	queue<int>levelVisit;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (t >= '0'&&t <= '9')
		{
			tree[i].right = t - '0';
			exist[tree[i].right] = 1;
		}
		cin >> t;
		if (t >= '0'&&t <= '9')
		{
			tree[i].left = t - '0';
			exist[tree[i].left] = 1;
		}


	}
	for(int i=0;i<n;i++)
		if (exist[i] == 0)
		{
			root = i;
			break;
		}

	levelVisit.push(root);
	while (!levelVisit.empty()) 
	{
		p = levelVisit.front();
		if (p != root)
			cout << ' ';
		cout << p;
		if (tree[p].left != -1)
			levelVisit.push(tree[p].left);
		if (tree[p].right != -1)
			levelVisit.push(tree[p].right);
		levelVisit.pop();
	}
	InOrder(tree, root);
	cout <<endl<< ans[0];
	for (int i = 1; i < n; i++)
		cout <<' '<< ans[i];

	system("pause");
	return 0;
}

/*
for (int i = 0; i < n; i++)
cout << lMaxVal[i] << ' ';
cout << endl;
for (int i = 0; i < n; i++)
cout << rMaxVal[i] << ' ';
*/