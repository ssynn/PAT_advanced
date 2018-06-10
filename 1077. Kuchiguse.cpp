// Project3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//找尾部共同字符串
int main()
{
	int n,minSize=1000;
	cin >> n;
	
	vector<string>val(n);
	string ans;
	getline(cin, val[0]);
	for (int i = 0; i < n; i++)
	{
		getline(cin, val[i]);
		if (val[i].size() < minSize)
			minSize = val[i].size();
	}
	
	while (minSize)
	{
		char endChar=val[0][val[0].size()-1];

		val[0].pop_back();
		for (int i = 1; i < n; i++)
		{
			if (endChar != val[i][val[i].size() - 1])
			{
				if (!ans.size())
				{
					cout << "nai";
					return 0;
				}
				else
				{
					reverse(ans.begin(), ans.end());
					cout << ans;
					return 0;
				}
			}
			val[i].pop_back();
		}
		ans.push_back(endChar);
		minSize--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
    return 0;
}

