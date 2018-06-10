#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int a, n, temp, ans[34] = {}, i = 0,p1,p2,l;
	bool flag = 1;
	string k[2] = {"No","Yes"};
	cin >> a >> n;
	while (a)
	{
		temp = a%n;
		a /= n;
		ans[i] = temp;
		i++;
	}
	p2 = i - 1;
	p1 = 0;
	l=i/2;
	for (int j = 0; j < l; j++)
	{
		if (ans[p1] != ans[p2])
		{
			flag = 0;
			break;
		}
	}
	cout << k[flag] << endl;
	cout << ans[i - 1];
	for (int j = i - 2; j >= 0; j--)
		cout <<' '<< ans[j];
	system("pause");
	return 0;
}

