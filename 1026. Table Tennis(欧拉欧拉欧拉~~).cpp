#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<list>
#include<iomanip>
using namespace std;

struct Node
{
	int arrive_time,start_t,last;
	bool vip;
	Node(int a, int b, int c, int d, int e)
	{
		arrive_time = a*3600+b*60+c;
		last = d*60;
		vip = e;
	}
	bool operator<(const Node &a) const
	{
		return arrive_time < a.arrive_time;
	}
};

list<Node>vip, people;
vector<bool>v;
vector<int>table, cnt;
vector<Node>ans;
int m;

void Out(Node a,int now)
{
	int flag = people.front().vip;

	int i, find = 1;
	if (flag == 1)															//当前最小值是vip则先寻找vip桌
	{
		for (i = 1; i <= m; i++)
		{
			if (table[i] <= now&&v[i] == 1)									//vip找到可用的vip桌
			{
				find = 0;
				break;
			}
		}
	}
	if (find)
	{
		for (i = 1; i <= m; i++)											//找到第一个空出来的桌子
		{
			if (table[i] <= now)
				break;
		}
	}
	cnt[i]++;															//这个桌子开始接客
	if (a.last <= 7200)
		table[i] = now + a.last;
	else
		table[i] = now + 7200;
	ans.push_back(a);
	ans.back().start_t = now;											//此桌开始时间一定是now

	for (int i = 1; i <= m; i++)										//更新小于等于now的桌的时间
		if (table[i] < now)
			table[i] = now;

}



void Disp(int a)
{
	int h = a / 3600;
	int m = a - 3600*h;
	m /= 60;
	int s = a % 60;
	printf("%02d:%02d:%02d ", h, m, s);
}

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		int a, b, c, d, e;
		char t;
		//scanf_s("%d %s %d %s %d %d %d", &a, &t, &b, &t, &c, &d, &e);
		cin >> a >> t >> b >> t >> c >> d >> e;
		people.push_back(Node(a, b, c, d, e));
		if (people.back().arrive_time >= 75600)
			people.pop_back();
	}
	people.sort();

	cin >> m>>n;
	v.resize(m+1,0);
	table.resize(m + 1, 0);
	cnt.resize(m + 1,0);
	while (n--)
	{
		int t;
		cin >> t;
		v[t] = 1;
	}
	int max_time, min_time,now;												//min_time代表最早空出来的桌子 now表示当前时间
	now = max_time = min_time = 28800;
	//Fill(max_time, min_time, now);										//填满桌子

	while (now<75600 && !people.empty())
	{
		int min_p = people.front().arrive_time;
		if (min_p > min_time)												//一定没有人在等待，直接上桌
		{
			now = min_p;
			auto it = people.begin();
			Out(*it, now);
			people.erase(it);
		}
		else																//当前有人在等待
		{
			int flag = 1;
			auto i = people.begin();
			auto it = i;
																			//存在等待的vip
			
			for (int i = 1; i <= m; i++)
			{
				if (table[i] <= now&&v[i] == 1)								//vip找到可用的vip桌
				{
					flag = 0;
					break;
				}
			}
			
			if(flag==0)
			for (; i != people.end();i++)									//寻找队列中在等待的vip
			{
				if (i->arrive_time > now)
					break;
				if (i->vip)
				{
					it = i;
					break;
				}
			}
			
			Out(*it, now);
			people.erase(it);
		}
		
		
		min_time = *min_element(table.begin()+1, table.end());
		max_time = *max_element(table.begin(), table.end());
		now = min_time;
	}

	for (auto i : ans)
	{
		Disp(i.arrive_time);
		Disp(i.start_t);
		cout << int((i.start_t - i.arrive_time)*1.0/60+0.5)<< endl;
	}

	for (int i = 1; i < m; i++)
		cout << cnt[i] << ' ';
	cout << cnt[m];
	system("pause");
	return 0;
}
