// 555.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int main() {
	int max[3] = { 0 }; ;
	double ans[3][3], sum = 1;
	char map[4] = "WTL";
	for (int i = 0; i < 3; i++)
		{
			cin >> ans[i][0]>>ans[i][1]>>ans[i][2];
			for (int j = 0; j < 3; j++)
			{
				if (ans[i][j] > ans[i][max[i]])
					max[i] = j;
			}
			sum *= ans[i][max[i]];
		}
	sum *= 0.65;
	sum=sum-1;
	sum *= 2;
	cout << map[max[0]] << ' ' << map[max[1]] << ' ' << map[max[2]] << ' ';
	cout <<fixed<<setprecision(2)<< sum;
	system("pause");
	return 0;
}

