#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

struct Node
{
	string name;
	int online, gm, gf,gs;
	Node(string b,int a) :online(a),name(b) { gm = gf = -1; };
	Node()
	{
		name = "";
		online = gm = gs = gf = -1;
	}
	bool operator<(Node &a)
	{
		if (gs != a.gs)
			return gs > a.gs;
		else
			return name < a.name;
	}
};

int main()
{
	int a, b, c,s;
	cin >> a >> b >> c;
	map<string, Node>val;
	vector<Node>ans;
	string name;
	
	while (a--)
	{
		cin >> name >> s;
		if (s >= 200)
			val[name] = Node(name,s);
	}
	
	while (b--)
	{
		cin >> name >> s;
		auto temp = val.find(name);
		if (temp != val.end())
			temp->second.gm = s;
	}

	while (c--)
	{
		cin >> name >> s;
		
		auto temp = val.find(name);
		if (temp != val.end())
		{
			Node tt = temp->second;
			tt.gf = s;
			if (s < tt.gm)
				tt.gs = s*0.6 + tt.gm*0.4 + 0.5;
			else if(s>=60)
				tt.gs = s;
			if (tt.gs >= 60)
				ans.push_back(tt);
		}
	}

	sort(ans.begin(), ans.end());

	for (auto &i : ans)
	{
		cout << i.name << ' '
			<< i.online << ' '
			<< i.gm << ' '
			<< i.gf << ' '
			<< i.gs << endl;
	}
	system("pause");
	return 0;
}
