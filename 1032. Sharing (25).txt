// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<stdio.h>
using namespace std;
struct node
{
	int address;
	char data;
	int next;
	bool flag;
};

int main()
{
	int add, add2, n, i = 0, cnt = 0;
	cin >> add >> add2 >> n;
	vector<node>val, val2;
	node last;
	node ss[100000];

	for (i = 0; i<n; i++)//存储节点信息
	{
		node a;
		a.flag = 0;
		scanf("%d", &a.address);
		cin >> a.data;
		scanf("%d", &a.next);
		if (a.next == -1)
		{
			last = a;
			cnt++;
		}

		ss[a.address] = a;
	}
	//节点排序
	//node p = ss[add], p2 = ss[add2];
	//add2 = ss[add2].next;
	while (add != -1)//顺序插入节点
	{
		//cout << p.data;
		ss[add].flag = 1;
		add = ss[add].next;
	}

	while (add2 != -1)
	{
		//cout << p2.data;
		if (ss[add2].flag == 1)
		{
			break;
		}
		add2 = ss[add2].next;

	}

	//cout << add;
	if (add2 != -1 || n == 1)
		cout << setfill('0') << setw(5) << ss[add2].address;

	else
		cout << -1;
	system("pause");
	return 0;
}