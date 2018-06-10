
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	double sum = 0,t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		sum = sum + t*(n - i)*(i + 1);
	}
	cout << fixed << setprecision(2) << sum;
	system("pause");
	return 0;
}

