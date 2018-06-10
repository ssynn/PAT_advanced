#include <iostream>
#include<vector>
#include <math.h>
#include<stdio.h>
#include<map>
#include<string>
#include<math.h>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<regex>
using namespace std;


int main()
{
	int n, k;
	//freopen("d://aa.txt", "r", stdin);
	cin >> n >> k;
	string last, now;
	last += to_string(n);
	while (--k)
	{

		char t = last[0];
		int i = 0, cnt = 0;
		while (i < last.size())
		{
			if (t == last[i])
			{
				cnt++;
			}
			else
			{
				now += t;
				now += to_string(cnt);
				cnt = 1;
				t = last[i];
			}
			i++;
		}

		now += t;
		now += to_string(cnt);
		last = now;
		now = "";
	}
	cout << last << endl;
	return 0;
}

