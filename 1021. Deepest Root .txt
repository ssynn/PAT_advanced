
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
using namespace std;

void DFS(const vector<vector<bool>> &map, int i, vector<bool> &exist, int n)
{
	exist[i] = 1;
	for (int j = 1; j <= n; j++)
	{
		if (exist[j] == 0 && map[i][j] == 1)
			DFS(map, j, exist, n);
	}

}

int DFSFindRoot(const vector<vector<bool>> &map, int i, vector<bool> &exist, int n,vector<int> &cnt)
{
	int max = 0,temp;
	exist[i] = 1;
	if (cnt[i] == 1&&exist[i]==0)
		return 1;
	for (int j = 1; j <= n; j++)
	{
		if (exist[j] == 0 && map[i][j] == 1)
		{
			temp = DFSFindRoot(map,j,exist,n,cnt)+1;
			if (max < temp)
				max = temp;
		}
	}
	return max;

}
int main()
{
	int n, a, b, k = 0;
	cin >> n;

	vector<vector<bool>>map(n + 1, vector<bool>(n + 1, 0));
	vector<int>cnt(n + 1, 0);
	vector<bool>exist(n + 1, 0);
	vector<int>root(n+1,0);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		cnt[a]++;
		cnt[b]++;
		map[a][b] = 1;
		map[b][a] = 1;

	}
	for (int i = 1; i <= n; i++)
	{
		if (exist[i] == 0)
		{
			DFS(map, i, exist, n);
			k++;
		}
	}
	if (k > 1)
	{

		cout << "Error: " << k << " components";
	}
	else if (n > 1000)											//Í¶»úÈ¡ÇÉ
	{
		for (int i = 1; i <= n; i++)
			if (cnt[i] == 1)
				cout << i<<endl;
	}
	else
	{
		int max = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cnt[i] == 1)
			{
				vector<bool>exist2(n+1,0);
				root[i] = DFSFindRoot(map, i, exist2,n,cnt);
				if (root[i] > max)
					max = root[i];
			}
		}
		for (int i = 1; i <= n; i++)
			if(root[i]==max)
				cout << i<<endl;
	}
	system("pause");
	return 0;
}