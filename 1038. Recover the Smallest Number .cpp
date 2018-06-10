#include"stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool cmp(string a, string b)
{
	return a+b < b+a;
}
int main()
{
	int n,i=0,flag=0;
	cin >> n;
	vector<string>val(n);

	for (int i = 0; i < n; i++)
		cin >> val[i];

	sort(val.begin(), val.end(),cmp);


	for (i = 0; i < n; i++)
	{
		int j = 0;
		if (flag)
			cout << val[i];
		else
		{
			for (j = 0; j < val[i].length(); j++)
				if (val[i][j] != '0')
					break;
			for (; j < val[i].length(); j++)
			{
				flag = 1;
				cout << val[i][j];
			}
		}

	}
	if (!flag)
		cout << '0';
	system("pause");
	return 0;
}


