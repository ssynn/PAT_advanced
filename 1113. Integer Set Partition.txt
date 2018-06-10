#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int Sum(vector<int>&a,int begin,int end)
{
	int s = a[end];
	while (begin!=end)
	{
		s += a[begin];
		begin++;
	}
	return s;
}
int main()
{
	int n,sum1,sum2;
	cin >> n;
	vector<int>val(n);
	for (auto &i : val)
		cin >> i;
	sort(val.begin(), val.end());
	sum1 = Sum(val, 0, n / 2-1);
	sum2 = Sum(val, n / 2, n - 1);
	cout << n % 2;
	cout<< ' ' << sum2 - sum1;


	system("pause");
	return 0;
}
