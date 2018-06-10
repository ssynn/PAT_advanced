
#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include"stdio.h"
using namespace std;
int main()
{
	int a = 0,b=0,num[7],i=6,k=1;
	cin >> a;
	cin >> b;
	a = a + b;
	if (a < 0)
		k = -1;
	a = a*k;
	if (a == 0)
		cout << 0;
	while (a != 0)
	{
		num[i] = a % 10;
		a = a / 10;
		i--;
	}
	i++;
	if (k < 0)
		cout << '-';
	for (i; i < 7; i++)
	{
		cout << num[i];
		if (i == 0 || i == 3)
			cout << ',';
	}
	
	system("pause");
	return 0;
}