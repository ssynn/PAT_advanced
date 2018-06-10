#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<list>
#include<iomanip>
using namespace std;

/*
虽然是一遍过但是做完的感觉像r了狗
*/

vector<bool>v(10000, 0);
int minS=100000, minL=1000000;

struct Node
{
	int data,line;
};

int CntLine(vector<Node>&temp)
{
	int t = temp[0].line,cnt=1;
	for (auto i : temp)
	{
		if (i.line != t)
		{
			t = i.line;
			cnt++;
		}
	}
	return cnt;
}

void DFS(int begin,int end,vector<vector<Node>>&g,vector<Node>&temp,vector<Node>&ans)
{
	if (begin == end)
	{
		if (temp.size() == minS)
		{
			int m = CntLine(temp);
			if ( m < minL)
			{
				ans = temp;
				minL = m;
			}
		}
		else if (temp.size() < minS)
		{
		
			ans = temp;
			minS = ans.size();
			minL = CntLine(temp);
		}
	}

	if (temp.size() >= minS)
		return;

	for (auto &i : g[begin])
	{
		if (v[i.data] == 0)
		{
			v[i.data] = 1;
			temp.push_back(i);
			DFS(i.data, end, g, temp, ans);
			v[i.data] = 0;
			temp.pop_back();
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<Node>>g(10000);
	for (int i = 0; i < n; i++)
	{
		int k,a,b;
		cin >> k;
		cin >> a;
		while (--k)
		{
			cin >> b;
			Node t = { b,i + 1 };
			g[a].push_back(t);
			t.data = a;
			g[b].push_back(t);
			a = b;
		}
	}

	int m,a,b;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		minS = 100000, minL = 1000000;
		cin >> a >> b;
		vector<Node>ans;
		vector<Node>temp;
		
		v[a] = 1;
		DFS(a, b, g, temp, ans);
		v[a] = 0;
		
		int k = 0;
		Node t = { a,ans[0].line };
		ans.insert(ans.begin(), t);
		cout << ans.size()-1 << endl;;
		t.line = -1;
		ans.push_back(t);
		while (minL--)
		{
			cout << "Take Line#" << ans[k+1].line<<" from ";
			cout <<setfill('0')<<setw(4)<< ans[k].data<<" to ";
			k++;
			while ((k) < minS&&ans[k].line == ans[k + 1].line)
				k++;
			cout << setfill('0') << setw(4) << ans[k].data << '.';
			cout << endl;
		}
	}
	system("pause");
	return 0;
}


/*



*/