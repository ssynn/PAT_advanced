#include <iostream>
#include<vector>
#include <math.h>
#include<stdio.h>
#include<map>
#include<string>
#include<math.h>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<regex>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<bool>>g(n + 1, vector<bool>(n + 1, false));
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = true;
	}
	int k;
	cin >> k;
	while (k--)
	{
		int num,flag=0;
		cin >> num;
		vector<int>temp(num,0);
		vector<bool>exist(n + 1, false);
		for (auto &i : temp)
		{
			cin >> i;
			exist[i] = true;
		}
		for (int i = 0; i < num && !flag; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (i!=j && !g[temp[i]][temp[j]])
				{
					flag = 1; 
					break;
				}
			}
		}
		if (flag)
		{
			cout << "Not a Clique\n";
		}
		else
		{
			int s = 0;
			for (int i = 1; i <= n; i++)
			{
				int kk = 0;
				if (!exist[i])
				{
					for (auto &j : temp)
						if (g[i][j])++kk;
				}
				if (kk == num)
				{
					s = 1;
					break;
				}
			}
			if (s)
				cout << "Not Maximal\n";
			else
				cout << "Yes\n";
		}
	}

	return 0;
}