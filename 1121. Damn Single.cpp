#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	vector<int>couple(100000, -1),ans;
	int n,a,b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		couple[a] = b;
		couple[b] = a;
	}
	cin >> n;
	while (n--)
	{
		cin >> a;
		if (couple[a]!=-1&&couple[couple[a]] == -2)
			couple[couple[a]]=-1;
		else
			couple[a] = -2;
	}
	for (int i = 0; i < 100000; i++)
		if (couple[i] == -2)
			ans.push_back(i);
	
	cout << ans.size() << endl;
	if (ans.size())
	{
		cout << setfill('0') << setw(5) << ans[0];
		for (int i = 1; i < ans.size(); i++)
			cout <<' ' << setfill('0') << setw(5) << ans[i];
	}

	system("pause");
	return 0;
}

