#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
using namespace std;


int main()
{
	char map[14] = "0123456789ABC",k[3][3];
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	for (int i = 0; i < 3; i++)
	{
		k[i][0] = map[a[i] / 13];
		k[i][1] = map[a[i] % 13];
	}
	cout << "#";
	for (int i = 0; i < 3; i++)
		cout << k[i][0] << k[i][1];
	system("pause");
	return 0;
}