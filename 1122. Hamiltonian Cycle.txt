#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	int n, m, a, b, k;
	cin >> n >> m;
	vector<vector<bool>>graph(n + 1, vector<bool>(n + 1, 0));
	vector<bool>ans;
	string val[2] = { "NO","YES" };
	while (m--)
	{
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	cin >> m;
	while (m--)
	{
		vector<bool>visited(n + 1, 0);
		bool flag = 1;
		int head;
		cin >> k;
		cin >> a;
		head = a;
		visited[a] = 1;
		for(int i=1;i<k;i++)
		{
			cin >> b;
			if (!graph[a][b])
				flag = 0;
			visited[b] = 1;
			a = b;
		}
		for (int i = 1; i <= n; i++)
			if (!visited[i])
			{
				flag = 0;
				break;
			}
		if (head != b)
			flag = 0;
		if (k == (n + 1) && flag)
			ans.push_back(1);
		else
			ans.push_back(0);
		
	}
	for (auto i : ans)
	{
		cout << val[i] << endl;
	}
	system("pause");
	return 0;
}