// 555.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	int n1, n2,k,max1=0,max2=0,cnt=0;
	cin >> n1;
	double s1[1001] = { 0 }, s2[1001] = {0};
	for (int i = 0; i < n1; i++)
	{
		cin >> k;
		cin>>s1[k];
		if (k > max1)
			max1 = k;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> k;
		cin >> s2[k];
		if (k > max2)
			max2 = k;
	}
	vector<double>ans(max1+max2+2,0);
	int j = 0,temp=0;
	for (int i = 0; i <= max1; i++)
		if (s1[i])
			for (j = 0; j <= max2; j++)
				if (s2[j])
				{
					temp = i + j;
					ans[temp] += (s1[i] * s2[j]);
				}
	for (j = max1 + max2 + 1; j >= 0; j--)
		if (ans[j])
			cnt++;
	cout << cnt;
	for (j = max1 + max2 + 1; j >= 0; j--)
		if (ans[j])
			cout <<' '<< j << ' ' <<fixed<<setprecision(1)<< ans[j];

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