#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<list>
using namespace std;
int main()
{
	int n, sum_value;
	bool exist[105] = { 0 };
	
	cin >> n >> sum_value;
	vector<vector<int>>map(sum_value+1,vector<int>(101,0)),ans(sum_value+1);
	vector<int>cnt(101, 0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		map[0][temp]++;
	}
	exist[0] = 1;
	for (int i = 1; i <= sum_value; i++)
	{
		vector<int>temp;
		for (int j = 1; j <= i; j++)
		{
			if (exist[i - j] && map[i - j][j])
			{
				temp = ans[i - j];
				temp.push_back(j);
				sort(temp.begin(), temp.end());
				if (ans[i].size() == 0 || temp < ans[i])
				{
					ans[i] = temp;
					exist[i] = 1;
					map[i] = map[i - j];
					map[i][j]--;
				}
			}
		}
	}
	if (exist[sum_value])
	{
		cout << ans[sum_value][0];
		for (int i = 1; i < ans[sum_value].size(); i++)
			cout << ' ' << ans[sum_value][i];
	}
	else
		cout << "No Solution";
	system("pause");
	return 0;
}
