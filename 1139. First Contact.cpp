#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;

map<int, vector<int>>val;

bool cmp(const vector<int>&a, const vector<int>&b)
{
	if (a[0] != b[0])
		return a[0] < b[0];
	else
		return a[1] < b[1];
}
int main()
{
	int n, m;
	cin >> n >> m;


	while (m--)
	{
		int a, b;
		cin >> a >> b;
		val[a].push_back(b);
		val[b].push_back(a);
	}

	cin >> m;
	while (m--)			//手动深度优先
	{
		int a, b;
		cin >> a >> b;
		vector<vector<int>>ans;
		for (auto &i : val[a])
		{
			vector<int>temp;
			if (i!=b&&a*i >= 0)
			{
				temp.push_back(abs(i));
				for (auto &j : val[i])
				{
					if (j!=b&&j!=a&&b*j >= 0)
					{
						temp.push_back(abs(j));
						for(auto &x:val[j])
							if (x == b)
								ans.push_back(temp);
						temp.pop_back();
					}
				}
				temp.pop_back();
			}
		}

		sort(ans.begin(), ans.end(), cmp);

		cout << ans.size() << endl;
		for (auto i : ans)
			cout <<setfill('0')<<setw(4)<< i[0] << ' ' 
			<< setfill('0') << setw(4) << i[1] << endl;
	}

	system("pause");
	return 0;
}
