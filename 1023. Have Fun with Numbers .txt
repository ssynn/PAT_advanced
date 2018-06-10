#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
#include<map>
#include<list>
using namespace std;

int main()
{
	string a;
	int mm[10] = {0}, flag = 1;
	cin >> a;
	reverse(a.begin(), a.end());
	vector<int>b(a.length() + 1,0),c(a.length() + 1, 0),d(a.length() + 1, 0);

	for(int i = 0; i < a.length(); i++)
	{
		mm[ a[i] - '0']++;
		b[i] += 2 * (a[i]-'0');
		if (b[i] > 9)
		{
			b[i] %= 10;
			b[i + 1]++;
		}
		mm[b[i]]--;
	}

	for (int i = 0; i < 10; i++)
		if (mm[i] != 0)
			flag = 0;

	if (b[a.length()])
		flag = 0;

	if (flag==0)
		cout << "No"<<endl;
	else
		cout << "Yes"<<endl;

	reverse(b.begin(), b.end());

	if (b[0])
		cout << b[0];
	for (int i = 1; i < b.size(); i++)
		cout << b[i];

	system("pause");
	return 0;
}