#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<list>
using namespace std;


int main()
{
	string a, b;
	bool mm[130] = {};
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < b.length(); i++)
		mm[b[i]] = 1;
	
	for (int i = 0; i < a.length(); i++)
		if (!mm[a[i]])
			cout << a[i];
	
	system("pause");
	return 0;
}


