#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<list>
#include<iomanip>
using namespace std;

struct Node
{
	string data;
	int left, right;

};


bool If(Node &a)
{
	if (a.right == -1)
		return 1;
	else
		return 0;
}

void InOrder(vector<Node>&t, int root)
{
	if (t[root].left != -1)
	{
		if (!If(t[t[root].left]))
		{
			cout << '(';
			InOrder(t, t[root].left);
			cout << ')';
		}
		else
			InOrder(t, t[root].left);
	}

	cout << t[root].data;

	if (t[root].right != -1)
	{
		if (!If(t[t[root].right]))
		{
			cout << '(';
			InOrder(t, t[root].right);
			cout << ')';
		}
		else
			InOrder(t, t[root].right);

	}
}

int main()
{
	int n,root;
	cin >> n;
	vector<Node>val(n + 1);
	vector<bool>ex(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i].data >> val[i].left >> val[i].right;
		if(val[i].left!=-1)
			ex[val[i].left] = 1;
		if(val[i].right!=-1)
			ex[val[i].right] = 1;
	}
	for(int i=1;i<=n;i++)
		if (!ex[i])
		{
			root = i;
			break;
		}

	InOrder(val, root);

	system("pause");
	return 0;
}