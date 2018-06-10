#include"stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<stdio.h>
using namespace std;

/*
这道题时间卡的很死
*/
int ToInt(const string &s)
{
	return (s[0] - 'A') * 26 * 26 * 10 + (s[1] - 'A') * 26 * 10 + (s[2] - 'A') * 10 + s[3] - '0';
}
int ToInt(char *s)
{
	return (s[0] - 'A') * 26 * 26 * 10 + (s[1] - 'A') * 26 * 10 + (s[2] - 'A') * 10 + s[3] - '0';
}
int main()
{
	vector<list<int>>course(180000);
	int k, n,num,stuNum;
	cin >> k >> n;
	char name[5];
	vector<string>nameList(k);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &num, &stuNum);
		for (int j = 0; j < stuNum; j++)
		{
			scanf_s("%s", name,5);
			//cout << ToInt(name)<<endl;
			course[ToInt(name)].push_back(num);
		}

	}
	for (int i = 0; i < k; i++)
	{
		scanf_s("%s", name,5);
		nameList[i] = name;
	}
	list<int>::iterator it;
	for (int i = 0; i < k; i++)
	{
		course[ToInt(nameList[i])].sort();
		cout << nameList[i] << ' ';
		n = course[ToInt(nameList[i])].size();
		printf("%d",n);
		for (it = course[ToInt(nameList[i])].begin(); it != course[ToInt(nameList[i])].end(); it++)
			printf(" %d",*it);
		cout << endl;
	}
	system("pause");
	return 0;
}


