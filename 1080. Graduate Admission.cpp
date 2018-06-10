#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>

using namespace std;

struct StuAdmission
{
	int ge, gi,gf, preferSchool[5],num;
	bool operator<(const StuAdmission &a)
	{
		if (gf != a.gf)
			return gf > a.gf;
		else
			return ge > a.ge;
	}
};

struct AcceptLine
{
	int gf, ge;
};
int main()
{
	int n, schoolNum, choiceNum;
	cin >> n >> schoolNum >> choiceNum;

	int quota[105];									//记录每个学校的录取名额
	vector<StuAdmission>admission(n);					//记录学生信息
	vector<list<int>>result(schoolNum);				//记录每个学校的录取结果
	AcceptLine scoreLine[105];						//记录当前录取分数线

	for (int i = 0; i < schoolNum; i++)
		scanf("%d", &quota[i]);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &admission[i].ge,&admission[i].gi);
		for (int j = 0; j < choiceNum; j++)
			scanf("%d", &admission[i].preferSchool[j]);
		admission[i].gf = admission[i].ge + admission[i].gi;
		admission[i].num = i;
	}
	
	sort(admission.begin(), admission.end());

	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < choiceNum; j++)
		{
			int temp= admission[i].preferSchool[j];
			if (quota[temp]>0)																								//录取成功
			{
				quota[temp]--;
				result[temp].push_back(admission[i].num);
				scoreLine[temp].ge = admission[i].ge;
				scoreLine[temp].gf = admission[i].gf;
				break;
			}
			else if((scoreLine[temp].ge==admission[i].ge)&&scoreLine[temp].gf == admission[i].gf)									//超额录取
			{
				result[temp].push_back(admission[i].num);
				break;
			}
		}
	}
	for (int i = 0; i < schoolNum; i++)
	{
		result[i].sort();
		if (result[i].size())
		{
			list<int>::iterator it = result[i].begin();
			printf("%d", *it);
			it++;
			for (;it!=result[i].end();it++)
				printf(" %d", *it);
		}
		printf("\n");
	}

    return 0;
}

/*
for (auto &i : admission)
cout << i.num << ' ' << i.ge << ' ' << i.gf << ' ' << i.preferSchool[0] << ' ' << i.preferSchool[1] << ' ' << i.preferSchool[2] << endl;

*/