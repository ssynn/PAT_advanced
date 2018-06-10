//µÂ²ÅÂÛ
#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct stuMes
{
	int num;
	int de;
	int cai;
	int sum;
};
void display(vector<stuMes> a, int n);
int comp(stuMes a, stuMes b);
int main()
{
	int n, min, good, i, count = 0;
	cin >> n >> min >> good;
	vector<stuMes>first, second, third, last;
	for (i = 0; i < n; i++)
	{
		stuMes temp;

		scanf("%d%d%d", &temp.num, &temp.de, &temp.cai);
		temp.sum = temp.de + temp.cai;
		if (temp.de >= good&&temp.cai >= good)
			first.push_back(temp);
		else if (temp.de >= good&&temp.cai < good&&temp.cai >= min)
			second.push_back(temp);
		else if (temp.de >= temp.cai&&temp.de < good&&temp.cai < good&&temp.de >= min&&temp.cai >= min)
			third.push_back(temp);
		else if (temp.de >= min&&temp.cai >= min)
			last.push_back(temp);
		else
			count++;
	}
	cout << n - count << endl;
	sort(first.begin(), first.end(), comp);
	sort(second.begin(), second.end(), comp);
	sort(third.begin(), third.end(), comp);
	sort(last.begin(), last.end(), comp);
	display(first, first.size());
	display(second, second.size());
	display(third, third.size());
	display(last, last.size());

	system("pause");
	return 0;
}
int comp(stuMes a, stuMes b)
{
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.de != b.de)
		return a.de > b.de;
	else
		return a.num < b.num;
}
void display(vector<stuMes> a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", a[i].num, a[i].de, a[i].cai);
}
