
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
using namespace std;


int main()
{
	string a;
	cin >> a;
	int n = a.length(),temp;
	int height = (n-1) / 3;
	temp = n - 2 * height;
	vector<char>n1(height),n2(temp),n3(height);
	for (int i = 0; i < height; i++)
	{
		n1[i] = a[i];
		n3[i] = a[n - 1 - i];
	}
	for (int i = 0; i < temp ; i++)
	{
		n2[i] = a[height + i];
	}
	for (int i = 0; i < height; i++)
	{
		cout << n1[i];
		for (int j = 0; j < temp - 2; j++)
			cout << ' ';
		cout << n3[i]<<endl;
	}
	for (int i = 0; i < temp; i++)
		cout << n2[i];
	system("pause");
	return 0;
}