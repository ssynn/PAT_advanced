#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<string.h>
#include<list>
#include<stack>
#include<set>
using namespace std;
/*

这道题数据花样很多
有0.00001、000111.45、200000、000000000000、00.000、45.0000....
*/
struct Node
{
	int num,cnt;
};
int FindPoint(const string &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] =='.')
		{
			return i;
		}
	}
	return a.size();
}

int FindFirstNum(const string &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > '0'&&a[i] <= '9')
		{
			return i;
		}
	}
	return -1;
}

void GetValue(string &a,int n,string v,int s)
{
	int cnt = 0,i=s;
	while (cnt < n&&i < v.length())
	{
		if (v[i] != '.')
		{
			a.push_back(v[i]);
			cnt++;
		}
		i++;
	}
	while (cnt < n)
	{
		a.push_back('0');
		cnt++;
	}
}
int main()
{
	string a, b;
	int n,a1,ap,b1,bp,k1,k2;
	string ans1,ans2;
	cin >> n >> a >> b;
	a1 = FindFirstNum(a);
	ap = FindPoint(a);
	b1 = FindFirstNum(b);
	bp = FindPoint(b);
	k1 = ap - a1;
	k2 = bp - b1;
	if (k1 < 0)
		k1++;
	if (k2 < 0)
		k2++;
	//cout << a1 <<' '<< b1<<endl;
	//cout << ap << ' ' << bp << endl;
	if (a1 >= 0)
		GetValue(ans1, n, a,a1);
	else
	{
		for (int i = 0; i < n; i++)
			ans1.push_back('0');
	}

	if (b1 >= 0)
		GetValue(ans2, n, b,b1);
	else
	{
		for (int i = 0; i < n; i++)
			ans2.push_back('0');
	}
	if (ans1 == ans2)
	{
		cout << "YES 0." << ans1 << "*10^";
		if (ans1[0] != '0')
			cout << k1;
		else
			cout << '0';
	}
	else
	{
		cout << "NO 0." << ans1 << "*10^";
		if (ans1[0] != '0')
			cout << k1;
		else
			cout << '0';
		cout << " 0." << ans2 << "*10^";
		if (ans2[0] != '0')
			cout << k2;
		else
			cout << '0';
	}
	
	system("pause");
	return 0;
}
/*
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (*(a.end() - 1) == '0')
	{
		a.pop_back();
	}
	while (*(b.end() - 1) == '0')
	{
		b.pop_back();
	}


*/