// 54.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int i = 1, n = 0, exp = 0, ten = 1, charge = 0, zero = 0;
	char a[10010], mark2;;
	cin >> a;
	n = strlen(a);
	while (i <= n)//确定指数大小
	{
		exp = exp + (a[n - i] - '0')*ten;
		ten *= 10;
		i++;
		if (a[n - i] == '-' || a[n - i] == '+')
		{
			mark2 = a[n - i];
			break;
		}
	}
	i = 1;
	if (a[0] == '-')
		cout << '-';


	if (mark2 == '-')//往前加0
	{
		cout << 0 << '.';
		for (int j = 0; j<exp - 1; j++)
			cout << 0;
		cout << a[1];
		i = 3;
		while (a[i] != 'E')
		{
			cout << a[i];
			i++;
		}
	}
	else//往后加0
	{
		cout << a[1];
		i = 3;
		while (a[i] != 'E')
		{
			cout << a[i];

			if ((i - 2) == exp&&a[i+1]!='E')//输出小数点
				cout << '.';

			i++;
		}
		for (int j = 0; j<exp - i + 3; j++)
			cout << 0;
	}

	system("pause");
	return 0;
}

/*
末位不可以有小数点！！！！！！！！！！！！！！！！！！！！！！！！！

*/
