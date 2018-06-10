#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include<stdio.h>
using namespace std;
vector<int>set(10001, 0);
int FindF(int a)
{
	int p = a;
	while (set[p])
		p = set[p];
	if (p != a)
		set[a] = p;
	return p;
}

void Union(int a, int b)
{
	if (a != b)
		set[b] = a;
}
int main()
{
	//string map[2] = { "No","Yes" };
	char mm[2][4] = { "No","Yes" };
	int n, m,max=0,temp,head,cnt=0;
	cin >> n;
	while (n--)
	{
		cin >> m;
		scanf("%d", &temp);
		max = temp > max ? temp:max;
		head = FindF(temp);
		while (--m)
		{
			scanf("%d", &temp);
			if (temp > max)
				max = temp;
			Union(head, FindF(temp));
		}
	}

	for (int i = 1; i <= max; i++)
		if (!set[i])
			cnt++;
	cout << cnt << ' ' << max << endl;

	cin >> m;
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a = FindF(a);
		b = FindF(b);
		printf("%s\n", mm[a == b]);
	}
	system("pause");
    return 0;
}

