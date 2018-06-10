#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int sum_volume = 0,t, n, m, l;
vector<vector<vector<bool>>>g;

struct Node
{
	int i, j, k;
	Node(int a, int b, int c) :i(a), j(b), k(c) {};
	Node() {};
	Node operator+(Node &a)
	{
		Node temp=*this;
		temp.i += a.i;
		temp.j += a.j;
		temp.k += a.k;
		return temp;
	}
};

Node way[6] = {
	{-1,0,0},
	{1,0,0},
	{0,-1,0},
	{0,1,0},
	{0,0,-1},
	{0,0,1}
};


int BFS(int i,int j,int k)
{
	queue<Node>val;
	val.push(Node(i, j, k));						//忘了处理第一个结点
	g[i][j][k] = 0;
	int sum = 1;
	while (!val.empty())
	{
		for (int i = 0; i < 6; i++)
		{
			Node temp = val.front();
			temp = temp + way[i];
			if (g[temp.i][temp.j][temp.k])
			{
				g[temp.i][temp.j][temp.k] = 0;
				val.push(temp);
				sum++;
			}
		}
		val.pop();
	}
	if (sum >= t)
		return sum;
	else
		return 0;
}

int main()
{
	cin >> m >> l >> n >> t;

	g.resize(n + 2, vector<vector<bool>>(m + 2, vector<bool>(l + 2, 0)));

	for (int i = 1; i <= n; i++)				//层
		for (int j = 1; j <= m; j++)			//行
			for (int k = 1; k <= l; k++)		//列
			{
				int t;
				cin >> t;
				g[i][j][k] = t;
			}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= l; k++)
			{
				if (g[i][j][k])
				{
					sum_volume += BFS(i, j, k);
				}
			}
		}
	}
	cout << sum_volume<<endl;

	system("pause");
	return 0;
}