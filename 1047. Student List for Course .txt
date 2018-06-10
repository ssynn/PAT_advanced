#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<list>
using namespace std;
struct Name
{
	char n[5];
};

bool cmp(const Name &a,const Name &b)
{
	int k = strcmp(a.n, b.n);
	if (k <= 0)
		return 1;
	else
		return 0;
}
int main()
{
	
	int n, k,c,course;
	char name[5];
	cin >> n >> k;
	vector<vector<Name>>val(k+1,vector<Name>());
	Name temp;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", name, 5);
		temp.n[0] = name[0];
		temp.n[1] = name[1];
		temp.n[2] = name[2];
		temp.n[3] = name[3];
		temp.n[4] = name[4]='\0';
		scanf_s("%d", &c);
		for (int j = 0; j < c; j++)
		{
			cin >> course;
			val[course].push_back(temp);

		}
	}
	vector<Name>::iterator it;
	for (int i = 1; i <= k; i++)
	{
		printf("%d %d\n", i ,val[i].size());
		sort(val[i].begin(),val[i].end(),cmp);
		it = val[i].begin();
		for (; it != val[i].end(); it++)
			printf("%s\n", it->n);
	}
	system("pause");
	return 0;
}


