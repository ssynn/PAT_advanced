#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>
using namespace std;

void Add(long long &a, long long &b, long long a1, long long b1)
{
	
	a = a*b1 + a1*b;
	b *= b1;
	long long c = 1, t1 = abs(a), t2 = abs(b);
	//找最大公因数
	if (t1 < t2)
	{
		c = t1;
		t1 = t2;
		t2 = c;
	}
	while (c)
	{
		c = t1%t2;
		t1 = t2;
		t2 = c;
	}
	a = a / t1;
	b = b / t1;
	if (a*b < 0)
		a = abs(a)*-1;
	b = abs(b);
}

int main()
{
	int n;
	long long a1 = 0, b1 = 1, a2, b2,t;
	char temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a2 >>temp>> b2;
		Add(a1, b1, a2, b2);
	}
	t = a1 / b1;
	if (t)
	{
		a1 %= t;
		cout << t;
		if(a1)
			cout<< ' ' << a1 << '/' << b1;
	}
	else
	{
		if (a1)
			cout << a1 << '/' << b1;
		else
			cout << 0;
	}

    return 0;
}

