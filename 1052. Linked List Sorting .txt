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
}ss[100000];
bool cmp(node a, node b)
{
	return a.data<b.data;
}
int main()
{
	int add, n, k, i = 0,num=0;
	cin >>n>> add;
	k = add;
	vector<node>val(n);
	bool ex[100000] = {0};
	if (add < 0)
	{
		printf("%d %d\n", 0, -1);
		return 0;
	}


	for (i = 0; i<n; i++)//存储节点信息
	{
		node a;
		scanf_s("%d%d%d", &a.address, &a.data, &a.next);
		ss[a.address] = a;
		ex[a.address] = 1;
	}

	//节点排序


	if (ex[add])
	{
		int i = 0;
		node p = ss[add];
		while (p.next != -1)//顺序插入节点
		{
			val[num] = p;
			num++;
			add = p.next;
			p = ss[add];
		}

		val[num] = p;
		num++;
		sort(val.begin(), val.begin()+num, cmp);
		cout << num << ' ' << setfill('0') << setw(5) << val[0].address << endl;
		for (i = 0; i < num-1; i++)
		{
			printf("%05d %d %05d\n", val[i].address, val[i].data, val[i + 1].address);
		}
		printf("%05d %d %d\n", val[i].address, val[i].data, -1);
		return 0;
	}
	
	printf("%d %05d\n",0,k);



	system("pause");
	return 0;
}
