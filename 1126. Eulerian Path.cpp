#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
using namespace std;

//首先要保证是连通图

int FindF(int a, vector<int>&f)
{
	int p = a;
	while (f[p])
		p = f[p];
	return p;
}

void Union(int a, int b, vector<int> &f)
{
	int fa = FindF(a, f);
	int fb = FindF(b, f);
	if (fa != fb)
		f[fb] = fa;
}

int main()
{
	int n,m,a,b,cnt=0,root=0;
	cin >> n>>m;
	vector<int>val(n + 1,0),f(n+1,0);
	while (m--)
	{
		cin >> a >> b;
		val[a]++;
		val[b]++;
		Union(a, b, f);
	}
	cout << val[1];
	if (val[1] % 2 == 1)
		cnt++;
	for (int i = 2; i <= n; i++)
	{
		cout << ' ' << val[i];
		if (val[i] % 2 == 1)
			cnt++;
	}
	for (auto i : f)
		if (!i)
			root++;
	if (root > 2)
		cnt = 4;
	//cout << root << ' ' << cnt;
	cout << endl;
	if (cnt == 0)
		cout << "Eulerian\n";
	else if (cnt == 2)
		cout << "Semi-Eulerian\n";
	else
		cout << "Non-Eulerian\n";


	system("pause");
	return 0;
}
/*



*/