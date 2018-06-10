#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
using namespace std;

int main()
{
	int n,s,begin;

	map<string, bool>exist;
	cin >> n>>s>>begin;
	vector<string>ans, val(n+1);
	if (begin > n)
	{
		cout << "Keep going...";
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> val[i];
	while(begin<=n)
	{
		ans.push_back(val[begin]);
		exist[val[begin]] = 1;
		begin += s;
		while (begin<=n&&exist[val[begin]]) begin++;
		
	}
	for (auto i : ans)
		cout << i << endl;

	system("pause");
	return 0;
}