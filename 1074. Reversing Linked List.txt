#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
using namespace std;
struct node
{
	int address;
	int data;
	int next;
	int flag;
};

bool cmp(node a, node b)
{
	return a.flag<b.flag;
}
int main()
{
	int add, n, k, i = 0,cnt=1;
	cin >> add >> n >> k;

	vector<node>val;
	map<int, node>ss;
	node a;
	for (i = 0; i<n; i++)//存储节点信息
	{
		cin >> a.address >> a.data >> a.next;
		ss[a.address] = a;
	}

	//节点排序

	node p = ss[add];

	while (p.next != -1)//顺序插入节点,同时统计有效结点数目！！！！
	{
		val.push_back(p);
		add = p.next;
		p = ss[add];
		cnt++;
	}
	cnt /= k;

	val.push_back(p);
	int p1 = 0, q = k;
	
	for (i = 0; i < cnt; i++)
	{
		reverse(val.begin() + p1, val.begin() + q);
		p1 = q;
		q += k;
	}

	/*输出结果*/
	for (i = 0; i<val.size() - 1; i++)
	{
		cout << setfill('0') << setw(5) << val[i].address << ' ';
		cout << val[i].data << ' ';
		cout << setfill('0') << setw(5) << val[i + 1].address << endl;
	}
	cout << setfill('0') << setw(5) << val[i].address << ' ';
	cout << val[i].data << ' ' << -1;
	system("pause");
	return 0;
}

