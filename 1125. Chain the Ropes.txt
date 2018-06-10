#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,sum;
	cin >> n;
	vector<int>val(n);
	for (auto &i : val)cin >> i;
	sort(val.begin(), val.end());
	sum = val[0];
	for (int i = 1; i < n; i++)
	{
		sum += val[i];
		sum /= 2;
	}
	cout << sum;

	system("pause");
	return 0;
}