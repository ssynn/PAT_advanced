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
	int add, n, k, i = 0;
	cin >> add >> n >> k;
	vector<node>val;
	map<int, node>ss;

	for (i = 0; i<n; i++)//�洢�ڵ���Ϣ
	{
		node a;
		cin >> a.address >> a.data >> a.next;
		if (a.data<0)
			a.flag = -1;
		else if (a.data >= 0 && a.data <= k)
			a.flag = 0;
		else
			a.flag = 1;
		ss[a.address] = a;
	}

	//�ڵ�����

	node p = ss[add];

	while (p.next != -1)//˳�����ڵ�
	{
		val.push_back(p);
		add = p.next;
		p = ss[add];
	}
	val.push_back(p);
	stable_sort(val.begin(), val.end(), cmp);
	for (i = 0; i<val.size()-1; i++)
	{
		cout << setfill('0') << setw(5) << val[i].address << ' ';
		cout << val[i].data<<' ';
		cout << setfill('0') << setw(5) << val[i+1].address<<endl;
	}
	cout << setfill('0') << setw(5) << val[i].address << ' ';
	cout << val[i].data<<' '<<-1;
	system("pause");
	return 0;
}

