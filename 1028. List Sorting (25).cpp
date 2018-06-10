#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
#include<map>
#include<list>
using namespace std;

/*
又是一道卡iostream的题
*/
struct Data
{
	int num;
	string name;
	char nn[12];
	int score;
};
bool cmp1(Data a,Data b)
{
	return a.num < b.num;
}

bool cmp2(Data a,Data b)
{
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.num < b.num;
}
bool cmp3(Data a, Data b)
{
	if (a.score != b.score)
		return a.score < b.score;
	else
		return a.num < b.num;
}
int main()
{
	int n, k;

	cin >> n >> k;
	vector<Data>student(n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d",&(student[i].num));
		scanf_s("%s",student[i].nn,12);
		scanf_s("%d",&student[i].score);
		student[i].name =student[i].nn;
	}
	switch (k)
	{
	case 1:
		sort(student.begin(), student.end(), cmp1);
		break;
	case 2:
		sort(student.begin(), student.end(), cmp2);
		break;
	case 3:
		sort(student.begin(), student.end(), cmp3);
		break;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%06d %s %d\n", student[i].num, student[i].nn, student[i].score);
	}
	system("pause");
	return 0;
}