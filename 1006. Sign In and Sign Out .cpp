// 555.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n,frist=INT_MAX,last=0,t1,t2,t3,time,gg;
	char a;
	string unlock, lock,temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp>>t1>>a>>t2>>a>>t3;
		time = t1 * 3600 + t2 * 60 + t3;
		gg = time;
		if (time < frist)
		{
			frist = time;
			unlock = temp;
		}
		cin >> t1 >> a >> t2 >> a >> t3;
		time = t1 * 3600 + t2 * 60 + t3;
		if (gg > time)
			time += (24 * 3600);
		if (time > last)
		{
			last = time;
			lock = temp;
		}
		
	}
	cout << unlock << ' ' << lock;
	system("pause");
	return 0;
}

/*
//输出邻接表
for(int i=0;i<n;i++)
{
cout<<i;
p=AdjList[i].next;
while(p)
{
cout<<p->adjvex<<' ';
p=p->next;
}
cout<<endl;
}

*/