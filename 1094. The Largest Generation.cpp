#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	int cntLevel[101] = { 0 }, maxGenerationNum[101] = { 0 };
	int n, m,id,k,kid,p,max=0,cnt;
	cin >> n >> m;
	vector<list<int>>tree(n+1);
	queue<int>levelVisit;
	for (int i = 0; i < m; i++)
	{
		cin >> id >> k;
		while (k--)
		{
			cin >> kid;
			tree[id].push_back(kid);
		}
	}

	levelVisit.push(1);
	cntLevel[1] = 1;
	while (!levelVisit.empty())
	{
		p = levelVisit.front();
		for (auto &i : tree[p])
		{
			cntLevel[i] = cntLevel[p] + 1;
			levelVisit.push(i);
		}
		levelVisit.pop();
	}

	for (int i = 1; i <= n; i++)
		maxGenerationNum[cntLevel[i]]++;

	for (int i = 1; i <= 100;i++)
	{
		if (max < maxGenerationNum[i])
		{
			max = maxGenerationNum[i];
			cnt = i;
		}
	}
	
	cout << max << ' ' << cnt;
	system("pause");
	return 0;
}