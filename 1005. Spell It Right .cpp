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
	string n;
	vector<int>ans;
	string map[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	long long sum=0,temp=0;
	cin >> n;
	for (int i = 0; i < n.length(); i++)
		sum += (n[i] - '0');
	temp = sum;
	while (sum)
	{
		ans.push_back(sum%10);
		sum /= 10;
	}
	reverse(ans.begin(), ans.end());
	if (!temp)
		cout << map[0];
	else
	{
		cout << map[ans[0]];
		for (int i = 1; i < ans.size(); i++)
			cout << ' ' << map[ans[i]];
	}
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