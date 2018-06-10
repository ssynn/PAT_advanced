#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
int dire[4][2] = { 0,1,1,0,0,-1,-1,0 };
void Fill(vector<vector<int>> &m, vector<int>&val, int n)
{
	int x = 1, y = 1,k=0;
	for (int i = 0; i < n; i++)
	{
		m[x][y] = val[i];
		if (m[x + dire[k][0]][y + dire[k][1]] >0)
		{
			k++;
			k %= 4;
		}
		x += dire[k][0];
		y += dire[k][1];
	}
}
int main()
{
	int n = 4, a, b, i = 0, x = 0, y = 0, k = 1;
	cin >> n;

	vector<int>c(n);
	for (i = 0; i < n; i++)
		cin >> c[i];
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	a = sqrt(n);
	while (a <= n)
	{
		if (n%a == 0)
			break;
		a++;
	}
	a = a > (n / a) ? a : (n / a);
	b = n / a;
	
	vector<vector<int>>ans(a+2, vector<int>(b+2, 0));
	for (int i = 0; i <= b + 1; i++)
		ans[0][i] = ans[a + 1][i] = 1;
	for (int i = 0; i <= a + 1; i++)
		ans[i][0] =ans[i][b+1]= 1;

	Fill(ans, c, n);
	
	for (i = 1; i <= a; i++)
	{
		cout << ans[i][1];
		for (int j = 2; j <= b; j++)
			cout << " " << ans[i][j];
		cout << endl;
	}

	system("pause");
	return 0;
}
