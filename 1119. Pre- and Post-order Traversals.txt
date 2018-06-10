#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
using namespace std;
vector<int>pre, post,ans;
bool flag = 1;

struct Node
{
	int data;
	Node *left, *right;
};

int FindP(int begin, int end, int n)
{
	for (int i = begin; i <= end; i++)
		if (post[i] == n)
			return i;
	return -1;
}

Node* CreatTree(int preBegin,int preEnd,int postBegin,int postEnd)
{
	Node *root = new Node;
	root->data = pre[preBegin];
	root->left = NULL;
	root->right = NULL;
	if (preBegin == preEnd)
		return root;

	int lEnd = FindP(postBegin, postEnd, pre[preBegin+1]);
	int lLen = lEnd - postBegin+1;
	root->left = CreatTree(preBegin + 1, preBegin + lLen, postBegin, lEnd);

	int rEnd = postEnd - 1;
	if (rEnd == lEnd)
	{
		flag = 0;
		return root;

	}
	root->right = CreatTree(preBegin + lLen + 1, preEnd, lEnd + 1, rEnd);

	return root;
}

void InOrder(Node* p)
{
	if (p == NULL) return;
	InOrder(p->left);
	ans.push_back(p->data);
	InOrder(p->right);
}

int main()
{
	int n;
	cin >> n;
	pre.resize(n);
	post.resize(n);
	for (auto &i : pre) cin >> i;
	for (auto &i : post) cin >> i;

	Node *root = CreatTree(0, n - 1, 0, n - 1);
	InOrder(root);
	if (flag) cout << "Yes\n";
	else cout << "No\n";
	cout << ans[0];
	for (int i = 1; i < n; i++) cout << ' ' << ans[i];
	cout << endl;
	system("pause");
	return 0;
}
/*



*/