// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;
bool Prime(int a)
{
	if (a == 1)
		return 0;
	if (a < 4)
		return 1;
	if (a % 2 == 0)
		return 0;
	int n = sqrt(a);
	for (int i = 3; i <= n; i += 2)
	{
		if (a%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	vector<int>map(10000, 0);
	string a[5] = { "Are you kidding?","Mystery Award","Minion","Chocolate","Checked" };
	int n,m,name;
	cin >> n;
	cin >> name;
	map[name] = 1;
	for (int i = 2; i <= n; i++)
	{
		cin >> name;
		if (Prime(i))
			map[name] = 2;
		else
			map[name] = 3;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		cout << setfill('0')<<setw(5) << name << ": " << a[map[name]] << endl;
		if (map[name])
			map[name] = 4;
	}
	system("pause");
    return 0;
}

