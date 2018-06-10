#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<limits.h>
#include<list>
#include<stack>
using namespace std;

int main()
{
	int n, m, k,flag=1,kk;
	string ss[2] = { "NO","YES" };
	cin >> n >> m >> k;
	vector<bool>ans(k,1);
	for (int i = 0; i < k; i++)
	{
		int s=1,num;
		stack<int>temp;
		for (int j = 0; j < m; j++)
		{

			scanf_s("%d", &num);
			while (temp.size() == 0 || temp.top() != num)
			{
				temp.push(s);
				if (temp.size() > n)
				{
					
					flag = 0;
					ans[i] = 0;
					break;
				}
				//kk = temp.top();
				s++;
			}
			//cout << temp.top() << ' ' << num << endl;
			if (temp.size()>=1 && temp.top() == num)
				temp.pop();
			//kk = temp.top();
			//cout << temp.size();
		}
	}

	for (int i = 0; i < k; i++)
		cout << ss[ans[i]] << endl;
	system("pause");
	return 0;
}


