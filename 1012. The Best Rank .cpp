#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int flag = 0;

struct Node
{
	string num;
	int score[4], rank[4],best;
};

struct KK
{
	int n,rank;
};

bool cmp(Node &a, Node &b)
{
	return a.score[flag] > b.score[flag];
}

int main()
{
	int n, m;
	cin >> n >> m;
	map<string, Node>val;
	vector<Node>temp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i].num >> temp[i].score[1] >> temp[i].score[2] >> temp[i].score[3];
		temp[i].score[0] = (temp[i].score[1] + temp[i].score[2] + temp[i].score[3]) / 3.0 + 0.5;
	}

	for (flag = 0; flag <= 3; flag++)
	{
		sort(temp.begin(), temp.end(), cmp);
		int lastScore = temp[0].score[flag],rank=1;
		temp[0].rank[flag] = 1;
		for (int i = 1; i < n; i++)
		{
			if (temp[i].score[flag] != lastScore)
			{
				lastScore = temp[i].score[flag];
				rank = i+1;
			}
			temp[i].rank[flag] = rank;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int minR = 1000;
		for (int j = 0; j < 4; j++)
			if (temp[i].rank[j] < minR)
				minR = temp[i].rank[j];
		for(int j=0;j<4;j++)
			if (minR == temp[i].rank[j])
			{
				temp[i].best = j;
				break;
			}
		val[temp[i].num]=temp[i];
	}

	char mm[5] = "ACME";
	for (int i = 0; i < m; i++)
	{
		string num;
		cin >> num;
		auto tt = val.find(num);
		if (tt != val.end())
		{
			cout << tt->second.rank[tt->second.best] << ' '
				<< mm[tt->second.best] << endl;
		}
		else
			cout << "N/A\n";
	}
	system("pause");
	return 0;
}
