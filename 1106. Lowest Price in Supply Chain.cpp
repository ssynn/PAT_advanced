#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<list>
#include<queue>
using namespace std;

int main()
{
	int n,k,kid,cnt=1;
	double price, increase,min=100000000;
	cin >> n >> price >> increase;
	vector<list<int>>tree(n);
	vector<int>retailers;
	vector<double>levelPrice(n);
	queue<int>level;
	increase = 1 + increase*0.01;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		if (k == 0)
		{
			retailers.push_back(i);
			continue;
		}
		for (int j = 0; j < k; j++)
		{
			cin >> kid;
			tree[i].push_back(kid);
		}
	}

	levelPrice[0] = price;
	level.push(0);
	while (!level.empty())
	{
		int p = level.front();
		for (auto &i : tree[p])
		{
			level.push(i);
			levelPrice[i] = levelPrice[p] * increase;
		}
		level.pop();
	}
	//for (int i = 0; i < n; i++)
		//cout << levelPrice[i] << ' ';
	for (int i = 0; i < retailers.size(); i++)
	{
		if (levelPrice[retailers[i]] < min)
		{
			cnt = 1;
			min = levelPrice[retailers[i]];
		}
		else if(min== levelPrice[retailers[i]])
			cnt++;
	}
	cout <<fixed<<setprecision(4)<< min << ' ' << cnt;
	system("pause");
	return 0;
}

