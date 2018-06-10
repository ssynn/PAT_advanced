#include "stdafx.h"
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;

int n=0,visitedNum=0;
bool visit[1001];
bool s[1001][1001];
void dfs(int p,int n)
{
	int i = 1;
	//cout << p << endl;
	for (i=1; i <= n; i++)
	{
		//cout << visit[i] << ' ' << s[p][i] << endl;
		if (visit[i] == 0 && s[p][i]==1)
		{
			visitedNum++;
			//cout << p << ' ' << i << endl;
			visit[i] = 1;
			dfs(i,n);
		}
	}
	
}
int main() {
	int temp, m, k, p, q,cnt;
	cin >> n >> m >> k;
	vector<int>ans(k+1);
	for (int i = 1; i <= m; i++)//建立邻接矩阵
	{
		cin >> p >> q;
		s[p][q] = s[q][p] = 1;
	}

	for (int i = 0; i < k; i++)
	{
		int num=0;
		cin >> temp;

		for (int j = 1; j <=n; j++)//去掉被占领的城市
			visit[j] = 0;
		visit[temp] = 1;

		cnt = 1;
		visitedNum = 1;
		while (cnt)//遍历整个图找到城市孤岛的个数，
		{
			num++;
			int l = 1;
			while (visit[l]&&l<n)
				l++;
			visit[l] = 1;
			visitedNum++;
			dfs(l,n);
			//cout << visitedNum << endl;
			cnt = n - visitedNum;
		}
		
		ans[i] = num-1;
	}
	for (int i = 0; i < k; i++)
		cout << ans[i]<<endl;
	system("pause");
	return 0;
}


