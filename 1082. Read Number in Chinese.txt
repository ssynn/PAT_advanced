#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>
using namespace std;


int main()
{
	
		int n, flag = 0, unit;
		string chineseUnit[6] = { "Fu","Shi","Bai","Qian","Wan","Yi" },
			chineseNum[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" },
			num;
		vector<string>ans;
		cin >> num;
		reverse(num.begin(), num.end());
		n = num.size();
		if (num[0] == '0'&&n==1)
		{
			cout << "ling";
			return 0;
		}

		for (int i = 0; i<n; i++)
		{
			if (i == 4)
				ans.push_back(chineseUnit[4]);
			else if (i == 8)
				ans.push_back(chineseUnit[5]);

			if (num[i] == '0'&&flag == 1)
			{
				ans.push_back(chineseNum[0]);
				flag = 0;
			}
			else if (num[i] > '0'&&num[i] <= '9')
			{
				flag = 1;
				unit = i % 4;
				if (unit > 0)
					ans.push_back(chineseUnit[unit]);

				ans.push_back(chineseNum[num[i] - '0']);
			}
			else if (num[i] == '-')
				ans.push_back(chineseUnit[0]);

		}

		for (int i = ans.size() - 1; i>0; i--)
			cout << ans[i] << ' ';

		cout << ans[0] << endl;
	
	

    return 0;
}

