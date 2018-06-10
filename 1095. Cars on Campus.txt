#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;
//烦的要死的一道题，还卡iostream
struct Node
{
	int cnt,time;
	Node() :cnt(0),time(0) {};
	Node(int a, int b)
	{
		time = a;
		if (b == 0)
			cnt = 1;
		else
			cnt = -1;
	}
	bool operator<(Node&a)
	{
		return time < a.time;
	}
};

struct Car
{
	string num;
	int time;
	bool flag;
	Car() {};
	Car(string n, int a, int b, int c, char x)
	{
		num = n;
		time = a * 3600 + b * 60 + c;
		if (x == 'i')
			flag = 0;
		else
			flag = 1;
	}

	bool operator<(Car &a)
	{
		return time < a.time;
	}
};
void Disp(int a)
{
	int h = a / 3600;
	int m = a - 3600 * h;
	m /= 60;
	int s = a % 60;
	printf("%02d:%02d:%02d", h, m, s);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Car>val;
	vector<int>query;
	map<string, Car>un_get;
	vector<Node>record;
	vector<string>max_time;
	map<string, int>time_cnt;

	while (n--)
	{
		string num,flag;
		int a, b, c;
		char t;
		cin >> num >> a >> t >> b >> t >> c >> flag;
		val.push_back(Car(num, a, b, c, flag[0]));
	}

	while (m--)
	{
		int a, b, c;
		char t;
		scanf_s("%d%1s%d%1s%d", &a, &t, &b,&t, &c);
		query.push_back(a * 3600 + 60 * b + c);
	}

	int m_time = 0;
	sort(val.begin(), val.end());
	for (auto i : val)
	{
		auto it = un_get.find(i.num);
		if (i.flag == 0)
			un_get[i.num] = i;
		else if (it != un_get.end())	//找到这辆车
		{
			record.push_back(Node(it->second.time, it->second.flag));
			record.push_back(Node(i.time,i.flag));
			int time = i.time - it->second.time;
			time_cnt[i.num] += time;
			un_get.erase(it);
		}
	}

	sort(record.begin(), record.end());
	int sum = 0;
	for (auto &i:record)
	{
		sum += i.cnt;
		i.cnt = sum;
	}

	int j = 0;
	for (int i = 0; i < query.size(); i++)
	{
		while (j+1<record.size()&&!(record[j].time <= query[i]&&query[i]<record[j+1].time))
			j++;
		printf("%d\n", record[j].cnt);
	}

	for (auto i : time_cnt)
	{
		if (i.second > m_time)
		{
			max_time.clear();
			max_time.push_back(i.first);
			m_time = i.second;
		}
		else if (m_time == i.second)
			max_time.push_back(i.first);
	}
	sort(max_time.begin(), max_time.end());
	for (auto i : max_time) cout << i << ' ';
	Disp(m_time);

	system("pause");
	return 0;
}

/*

*/