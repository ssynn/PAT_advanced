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

void ToLower(string &a)
{
	for (auto &i : a)
	{
		if (i >= 'A'&&i<='Z')
			i = tolower(i);
	}
}
struct Node
{
	string name;
	double score;
	int cnt;
	Node() {};
	Node(string a, double s)
	{
		name = a;
		score = s;
		cnt = 1;
	}
	bool operator<(Node&a)
	{
		if (score != a.score)  return score > a.score;
		else if (cnt != a.cnt)  return cnt < a.cnt;
		else return name < a.name;
	}
};

int main()
{
	map<string, Node>val;
	int n, k;
	cin >> n;
	while (n--)
	{
		string num, school;
		double score;
		cin >> num >> score >> school;
		ToLower(school);
		if (num[0] == 'B')
			score /= 1.5;
		else if (num[0] == 'T')
			score *= 1.5;
		auto it = val.find(school);
		if (it != val.end())
		{
			it->second.cnt++;
			it->second.score += score;
		}
		else
		{
			val[school] = Node(school, score);
		}
	}
	vector<Node>ans;

	for (auto i : val)
	{
		i.second.score = int(i.second.score);
		ans.push_back(i.second);
	}
	sort(ans.begin(), ans.end());
	vector<int>rank(ans.size());
	rank[0] = 1;
	for (int i = 1; i < ans.size(); i++)
	{
		rank[i] = i+1;
		if (ans[i].score == ans[i - 1].score)
			rank[i] = rank[i - 1];
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d %s %.0lf %d\n", rank[i], ans[i].name.c_str(), ans[i].score, ans[i].cnt);
	}
	return 0;
}