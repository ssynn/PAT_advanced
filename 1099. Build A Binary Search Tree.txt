#include"stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
struct Child
{
	int left, right,data;
};

void InOrder(vector<Child> &tree, vector<int> &val, int now,int &i)
{
	if (tree[now].left != -1)
		InOrder(tree, val, tree[now].left, i);
	
	tree[now].data = val[i];
	i++;

	if (tree[now].right != -1)
		InOrder(tree, val, tree[now].right, i);
}
int main()
{
	int n,k=0,p;
	cin >> n;
	vector<Child>tree(n);
	vector<int>val(n);
	queue<int>levelVisit;
	for (int i = 0; i < n; i++)
		cin >> tree[i].left >> tree[i].right;
	for (int i = 0; i < n; i++) cin >> val[i];
	
	sort(val.begin(), val.end());

	InOrder(tree, val, 0, k);

	levelVisit.push(0);
	while (!levelVisit.empty())
	{
		p = levelVisit.front();
		if (p != 0)
			cout << ' ';
		cout << tree[p].data;
		if (tree[p].left != -1)
			levelVisit.push(tree[p].left);
		if (tree[p].right != -1)
			levelVisit.push(tree[p].right);
		levelVisit.pop();
	}

	system("pause");
	return 0;
}