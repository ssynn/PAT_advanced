#include "stdafx.h"
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<sstream>
#include<queue>
using namespace std;
int n, l;
struct Node
{
	int num;
	Node *next;
	Node() { next = NULL; }
};

void LevelVisite(int query,int nowLevel,vector<Node> &val,int &cnt,vector<bool> &visited)
{
	if (nowLevel == l)
		return;
	queue<Node>queryList;
	Node *p;
	p = val[query].next;
	while (p)
	{

		if (visited[p->num] == 0)
		{
			cnt++;
			//cout << p->num << ' ';
			visited[p->num] = 1;
			queryList.push(*p);
			
		}
		p = p->next;
	}

	while (queryList.size())
	{
		LevelVisite(queryList.front().num, nowLevel + 1, val, cnt, visited);
		queryList.pop();
	}
}
int main()
{
	int follow,followNum,query,qNum,cnt;
	cin >> n >> l;
	queue<Node>queryList;
	vector<Node>val(n + 1);
	Node *p;
	for (int i = 1; i <= n; i++)
	{
		cin >> followNum;
		val[i].num = i;
		for (int j = 0; j < followNum; j++)
		{
			cin >> follow;
			p = new Node;
			p->num = i;
			p->next=val[follow].next;
			val[follow].next = p;
		}
	}
	cin >> qNum;
	vector<int>ans(qNum);
	for (int i = 0; i < qNum; i++)
	{
		vector<bool>visited( n+1, 0);
		cin>>query;
		visited[query] = 1;
		cnt = 0;
		LevelVisite(query, 0, val, cnt, visited);
		ans[i] = cnt;
	}

	for (int i = 0; i < qNum; i++)
		cout << ans[i] << endl;
	system("pause");
	return 0;
}

