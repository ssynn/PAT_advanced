#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int n,m;
	map<int, bool>e;
	cin >> m >> n;
	vector<int>pre(n);
	for (auto &i : pre)
	{
		scanf("%d", &i);
		e[i] = true;
	}

	while (m--)
	{
		int a, b,s;
		scanf("%d %d", &a, &b);
		for (auto i : pre)
		{
			int x=a, y=b;
			if (x > y)swap(x, y);
			if ((i > x&&i < y) || i == x || i == y)
			{
				s = i;
				break;
			}
		}
		bool a_in = e[a];
		bool b_in = e[b];
		if (!a_in && !b_in)
			printf("ERROR: %d and %d are not found.\n", a, b);
		else if (!a_in)
			printf("ERROR: %d is not found.\n", a);
		else if (!b_in)
			printf("ERROR: %d is not found.\n", b);
		else if (s == a)
			printf("%d is an ancestor of %d.\n", a, b);
		else if (s == b)
			printf("%d is an ancestor of %d.\n", b, a);
		else
			printf("LCA of %d and %d is %d.\n", a, b, s);
	}
	return 0;
}
