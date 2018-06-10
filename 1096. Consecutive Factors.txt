#include<iostream>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const vector<int>&a, const vector<int>&b)
{
	if ((a[1] - a[0]) != (b[1] - b[0]))
		return (a[1] - a[0]) < (b[1] - b[0]);
	else
		return a[0] > b[0];
}

int main() 
{
	int n;
	vector<vector<int>>ans;
	cin >> n;

	int m = sqrt(n);
	for (int i = 2; i <= m; i++)
	{
		if (n%i == 0)
		{
			vector<int>temp(2);
			temp[0] = i;
			int t = n,j=i;
			while (t%j == 0)
			{
				t /= j;
				j++;
			}
			temp[1] = j-1 ;
			ans.push_back(temp);
		}
	}

	if (ans.size() == 0)
	{
		cout << 1 << endl
			<< n;
		return 0;
	}

	sort(ans.begin(), ans.end(), cmp);
	int a = ans.back()[0];
	int b = ans.back()[1];
	cout << b - a + 1<<endl;
	cout << a;
	for (int i = a + 1; i <= b; i++)
		cout << '*' << i;

	system("pause");
	return 0;
}
