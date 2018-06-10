#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Mes
{
	string name;
	int height;
	bool operator < (Mes &a)
	{
		if (height != a.height)
			return height > a.height;
		else
			return name < a.name;
	}
};
int main()
{
	int n,k,rowNum,j=0;
	cin >> n>>k;
	rowNum = n / k;
	vector<Mes>val(n);
	vector<vector<string>>ans(k,vector<string>(rowNum,"2"));
	ans[0].resize(rowNum + n%k,"2");

	for (int i = 0; i < n; i++)
		cin >> val[i].name >> val[i].height;
	sort(val.begin(), val.end());

	for (int i = 0; i < k; i++)
	{
		int p = ans[i].size() / 2, sign = 1;
		for (int t = 0; t < ans[i].size(); t++)
		{
			p = p + t*sign;
			ans[i][p] = val[j].name;
			j++;
			sign *= -1;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << ans[i][0];
		for (int j = 1; j < ans[i].size(); j++)
			cout <<' '<< ans[i][j];
		cout << endl;
	}

	system("pause");
	return 0;
}