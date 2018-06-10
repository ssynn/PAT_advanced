#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>
using namespace std;

struct StuMes
{
	string name, id;
	int score;
	bool operator<(const StuMes &a)
	{
		return score > a.score;
	}
};
int main()
{
	int n,minScore,maxScore,cnt=0;
	cin >> n;
	vector<StuMes>val(n);
	for (int i = 0; i < n; i++)
		cin >> val[i].name >> val[i].id >> val[i].score;
	cin >> minScore >> maxScore;
	sort(val.begin(), val.end());
	for (int i = 0; i < n; i++)
	{
		if (val[i].score >= minScore&&val[i].score <= maxScore)
		{
			cout << val[i].name << ' ' << val[i].id << endl;
			cnt++;
		}
	}
	if (!cnt)
		cout << "NONE";
    return 0;
}

