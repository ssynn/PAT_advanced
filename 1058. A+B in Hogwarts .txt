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
using namespace std;

int main()
{

	int a1, b1, c1, a2, b2, c2;
	char t;
	cin >> a1 >> t >> b1 >> t >> c1;
	cin >> a2 >> t >> b2 >> t >> c2;
	a1 += a2;
	b1 += b2;
	c1 += c2;
	if (c1 > 28)
	{
		b1++;
		c1 %= 29;
	}
	if (b1 > 16)
	{
		a1++;
		b1 %= 17;
	}

	cout << a1 << '.' << b1 << '.' << c1;
	system("pause");
	return 0;
}
