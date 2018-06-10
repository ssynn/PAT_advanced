#include <iostream>
#include<vector>
#include <math.h>
#include<stdio.h>
#include<map>
#include<string>
#include<math.h>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<regex>
using namespace std;
int n;
struct Node
{
	int data;
	int left, right;
	Node()
	{
		data = 0;
		left = right = 0;
	}
};

bool CheckMax(vector<Node>&val,int p)
{
	if (p==0||p > n/2)
		return 1;
	if (CheckMax(val, val[p].left) && CheckMax(val,val[p].right))
	{
		bool flag = val[p].data >= val[val[p].left].data; 
		if(flag&&val[p].right)
			val[p].data >= val[val[p].right].data;
		return flag;
	}
	return 0;

}

bool CheckMin(vector<Node>&val, int p)
{
	if (p==0||p > n / 2)
		return 1;
	if (CheckMin(val, val[p].left) && CheckMin(val, val[p].right))
	{
		bool flag = val[p].data <= val[val[p].left].data;
		if (flag&&val[p].right)
			val[p].data <= val[val[p].right].data;
		return flag;
	}
	return 0;
}

void PostOrder(vector<Node>&val, int p)
{
	if (p == 0)
		return;
	PostOrder(val, val[p].left);
	PostOrder(val, val[p].right);
	cout << val[p].data << ' ';
}
void Disp(vector<Node>&val)
{
	PostOrder(val, val[1].left);
	PostOrder(val, val[1].right);
	cout << val[1].data << endl;;
}
int main()
{
	int k;
	cin >> k >> n;
	while (k--)
	{
		int t;
		vector<Node>val(n + 1,Node());
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &t);
			val[i].data = t;
			int ch = i * 2;
			if(ch<=n)
				val[i].left = ch;
			++ch;
			if(ch<=n)
				val[i].right = ch;
		}
		if (val[1].data <= val[2].data&&val[1].data <= val[3].data)
		{
			if (CheckMin(val, 1))
				cout << "Min Heap\n";
			else
				cout << "Not Heap\n";
		}
		else
		{
			if (CheckMax(val, 1))
				cout << "Max Heap\n";
			else
				cout << "Not Heap\n";
		}
		Disp(val);
	}
	return 0;
}