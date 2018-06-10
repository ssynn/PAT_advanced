#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
//没理解题意~~~~~
struct Node
{
	int send, back;
	vector < int>path;
	bool operator<(Node &a)
	{
		if (send != a.send)
			return send < a.send;
		else
			return back < a.back;
	}
};

vector<vector<int>>g;
vector<int> val, temp;
vector<Node>ans;
vector<bool>v;
int minLen = 10000000, num, cap;

void DFS(int p, int end, int len)
{
	//cout << p << '\n';
	if (p == end)
	{
		Node t;
		t.path = temp;
		if (len < minLen)
		{
			minLen = len;
			ans.clear();
			ans.push_back(t);
		}
		else if (len == minLen)
			ans.push_back(t);
	}
	if (len >= minLen)
		return;

	for (int i = 1; i <= num; i++)
		if (!v[i] && g[p][i])
		{
			temp.push_back(i);
			v[i] = 1;
			DFS(i, end, len + g[p][i]);
			v[i] = 0;
			temp.pop_back();
		}
}

int main()
{
	int  end, edge;
	cin >> cap >> num >> end >> edge;
	cap /= 2;
	val.resize(num + 1, 0);
	g.resize(num + 1, vector<int>(num + 1, 0));
	v.resize(num + 1, 0);
	v[0] = 1;

	for (auto i = val.begin() + 1; i != val.end(); i++) cin >> *i;

	while (edge--)
	{
		int a, b, len;
		cin >> a >> b >> len;
		g[a][b] = len;
		g[b][a] = len;
	}

	DFS(0, end, 0);

	for (auto &i : ans)
	{
		i.back = 0;
		i.send = 0;
		for (auto j : i.path)
		{
			i.back += (val[j] - cap);
			if (i.back < 0)
			{
				i.send -= i.back;
				i.back = 0;
			}
		}
	}


	
	auto m = min_element(ans.begin(), ans.end());
	cout << m->send << ' '<<0;
	for (auto i : m->path)
		cout << "->" << i;
	cout <<' '<< m->back;

	system("pause");
	return 0;
}