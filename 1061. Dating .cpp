#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<string.h>
#include<list>
#include<stack>
#include<set>
using namespace std;

int main()
{
	string a1, a2, b1, b2;
	int p1 =0, p2 = 0,flag=0,hour,minute,day;
	cin >> a1 >> a2 >> b1 >> b2;
	string a[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	while (p1 < a1.size() && p2 < a2.size())
	{
		switch (flag)
		{
		case 0:
			if (a1[p1] == a2[p2] && a1[p1] >= 'A'&&a1[p1] <= 'G')
			{
				flag = 1;
				day = a1[p1] - 'A';
			}
			break;
		case 1:
			if (a1[p1] == a2[p2] && ((a1[p1] >= 'A'&&a1[p1] <= 'N') || (a1[p1] >= '0'&&a1[p1] <= '9')))
			{
				if (a1[p1] >= 'A'&&a1[p1] <= 'N')
					hour = a1[p1] - 'A' + 10;
				else
					hour = a1[p1] - '0';
				flag = 2;
			}
			break;
		}
		if (flag == 2)
			break;
		p1++;
		p2++;
	}
	p1 = p2 = 0;
	while (p1 < b1.size() && p2 < b2.size())
	{
		if (b1[p1] == b2[p2]&&isalpha(b1[p1]))
		{
			minute = p1;
			break;
		}
		p1++;
		p2++;
	}

	cout << a[day] << ' ';
	cout << setfill('0') << setw(2) << hour << ':';
	cout << setfill('0') << setw(2) << minute;

	system("pause");
	return 0;
}
