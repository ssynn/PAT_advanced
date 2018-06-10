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

struct Node
{
	vector<int>child;
};
int main()
{
	int n, m,k;
	cin >> n >> m;
	vector<Node>val(n+1);
	vector<int>in_degree(n + 1,0);
	vector<int>ans;
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		val[a].child.push_back(b);
		in_degree[b]++;
	}
	cin >> k;
	for(int j=0;j<k;j++)
	{
		int t;
		auto temp = in_degree;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &t);
			//入度为0，合法
			if (!temp[t])
				for (auto x : val[t].child) temp[x]--;
			//入度不为0，非法
			else
			{
				string grab;
				getline(cin, grab);
				ans.push_back(j);
				break;
			}
		}
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)cout << ' ' << ans[i];
	return 0;
}