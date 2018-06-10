#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, m, start, dest;								
const int INF = 10000000;
int min_time = 10000000;
int min_len = 10000000;

vector<int>ans, ans1,temp;
vector<bool>v;												//记录已经找到最短路径的结点
vector<vector<int>>len, t;

int Dijkstria(vector<vector<int>>&a)
{
	vector<int>cost(n, INF);
	vector<bool>in(n, 0);
	in[start] = 1;									//已经找到最小的路径

	for (int i = 0; i < n; i++)						//更新路径长度
		cost[i] = a[start][i];

	for (int i = 1; i < n; i++)
	{
		int min_cost = INF;								//记录最短路径长度
		int j;											//记录最小的结点
		for (int k = 0; k < n; k++)
		{
			if (in[k] == 0 && cost[k] < min_cost)
			{
				j = k;
				min_cost = cost[j];
			}
		}
		in[j] = 1;
		for (int k = 0; k < n; k++)								//更新父节点
		{
			if (in[k] == 0 && ((cost[j] + a[j][k]) < cost[k]))
				cost[k] = cost[j] + a[j][k];
		}
	}
	return cost[dest];
}

void DFS1(int p, int lenth, int time)
{
	if (p == dest)
	{
		if (lenth == min_len && time < min_time)
		{
			ans = temp;
			min_time = time;
		}
	}
	if (lenth > min_len) return;

	for(int i=0;i<n;i++)
		if (v[i] == 0 && len[p][i] < INF)
		{
			v[i] = 1;
			temp.push_back(i);
			DFS1(i, lenth + len[p][i], time + t[p][i]);
			temp.pop_back();
			v[i] = 0;
		}
}

void DFS2(int p,int time)
{
	if (p == dest)
	{
		if (ans1.size() == 0 || time == min_time&&temp.size() < ans1.size())
			ans1 = temp;
	}
	if (time >  min_time)
		return;
	for(int i=0;i<n;i++)
		if (v[i] == 0 && t[p][i] < INF)
		{
			v[i] = 1;
			temp.push_back(i);
			DFS2(i, time + t[p][i]);
			temp.pop_back();
			v[i] = 0;
		}
}

int main()
{
	cin >> n >> m;
	len.resize(n, vector<int>(n,INF));
	t.resize(n, vector<int>(n,INF));
	while (m--)
	{
		int a, b, c, d, w;
		scanf_s("%d %d %d %d %d", &a, &b, &w, &c, &d);
		len[a][b] = c;
		t[a][b] = d;
		if (!w)
		{
			t[b][a] = t[a][b];
			len[b][a] = len[a][b];
		}
	}

	cin >> start >> dest;
	v.resize(n);
	v[start] = 1;
	min_len = Dijkstria(len);
	DFS1(start, 0, 0);

	min_time = Dijkstria(t);
	DFS2(start, 0);
	if (ans == ans1)
	{
		cout << "Distance = " << min_len << "; "
			<< "Time = " << min_time << ": "
			<< start;
		for (auto i : ans)
			cout << " -> " << i;
	}
	else
	{
		cout << "Distance = " << min_len << ": " << start;
		for (auto i : ans)
			cout << " -> " << i;

		cout << "\nTime = " << min_time << ": " << start;
		for (auto i : ans1)
			cout << " -> " << i;
	}
	system("pause");
	return 0;
}