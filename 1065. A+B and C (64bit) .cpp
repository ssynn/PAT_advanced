#include"stdafx.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include <algorithm>
#include<list>
#include<map>
#include<string>
#include<iomanip>
#include<set>
using namespace std;
//考验数据溢出的题
int main()
{
	int n;
	long long a=0, b=0, c=0;
	cin >> n;
	bool ans[10] = { 0 };
	string flag[2] = { "false","true" };
	for (int i = 0; i < n; i++)
	{
		//scanf_s("%lld %lld %lld", &a, &b, &c);
		cin >> a >> b >> c;
		cout << a << ' ' << b << ' ' << c << 555<<endl;

		long long temp = a + b;
		if (a > 0 && b > 0 && temp < 0) ans[i] = 1;
		else if (a < 0 && b < 0 && temp>0) ans[i] = 0;
		else ans[i] = temp >c;
	}

	for (int i = 0; i < n; i++)
		cout <<"Case #"<<i+1<<": "<< flag[ans[i]] << endl;

	system("pause");
	return 0;
}
