// 54.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	
	int n,max=1,tcnt;
	string val,temp;
	map<string, int>cnt;
	getline(cin, val);
	n = val.size();
	for (int i = 0; i < n; i++)
	{
		if (val[i] >= 'A'&&val[i] <= 'Z' || val[i] >= 'a'&&val[i] <= 'z' || val[i] >= '0'&&val[i] <= '9')
			temp.push_back(tolower(val[i]));
		else if (temp.size())
		{
			tcnt=++cnt[temp];
			if (tcnt > max)
				max = tcnt;
			//cout << temp << ' ';
			temp = "";
		}
	}
	for (auto &i : cnt)
	{
		if (i.second == max)
		{
			temp = i.first;
			break;
		}
	}

	cout << temp << ' ' << max;
	system("pause");
	return 0;
}

