#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
using namespace std;



int main()
{
	int n, m,k,q,a,b;
	cin >> n >> m;
	vector<vector<int>>val(n);
	vector<bool>edge;

	for (int i=0;i<m;i++)
	{
		cin >> a >> b;
		val[a].push_back(i);
		val[b].push_back(i);
	}

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int t;
		edge.clear();
		edge.resize(m, 0);
		cin >> k;
		while (k--)
		{
			cin >> t;
			for (auto s : val[t])
				edge[s] = 1;
		}
		if (count(edge.begin(), edge.end(), 0))
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	system("pause");
	return 0;
}
