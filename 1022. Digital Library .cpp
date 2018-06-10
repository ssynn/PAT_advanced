
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
#include<map>
#include<list>
using namespace std;
struct Reader
{
	int k;
	string query;
	list<int>bookNum;
};
void KeywordsCut(map<string,list<int>> &find,string &keywords,int num)
{
	string keyword;
	int i = 0;
	while (i<keywords.length())
	{
		if (keywords[i] != ' ')
		{
			keyword += keywords[i];
		}
		else
		{
			find[keyword].push_back(num);
			//cout << keyword<<endl;
			keyword.clear();
		}
		i++;
	}
	find[keyword].push_back(num);
	//cout << keyword;
	
}

int main()
{
	list<int>a;
	map<string,list<int>>findBookTitle;
	map<string, list<int>>findAuthor;
	map<string, list<int>>findKeyword;
	map<string, list<int>>findPublisher;
	map<string, list<int>>findYear;

	map<string, list<int>> *p[5] = {&findBookTitle,&findAuthor,&findKeyword,&findPublisher,&findYear };
	
	
	string author, bookTitle, publisher,keywords,query, publishedYear;
	
	int n=0, m,num,k;
	char colon;
	/*
	author = "test code sort keywords";
	KeywordsCut(find,author,1);
	*/
	cin >> n;
	
	for (int i = 0;i < n; i++)
	{
		cin >> num;
		getline(cin, author);
		getline(cin, bookTitle);
		getline(cin, author);
		getline(cin, keywords);
		getline(cin,publisher);
		getline(cin, publishedYear);
		findAuthor[author].push_back(num);
		findBookTitle[bookTitle].push_back(num);
		findPublisher[publisher].push_back(num);
		findYear[publishedYear].push_back(num);
		KeywordsCut(findKeyword, keywords, num);
		
	}
	
	cin >> m;
	vector<Reader>ans(m);
	//vector<string>kk(m);
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		cin >> colon;
		getline(cin, query);
		query.erase(query.begin());
		ans[i].query = query;
		ans[i].k = k;
		switch (k)
		{
		case 1:
			ans[i].bookNum= findBookTitle[query];

			break;
		case 2:
			
			ans[i].bookNum = findAuthor[query];
			break;
		case 3:
	
			ans[i].bookNum = findKeyword[query];
			break;
		case 4:
	
			ans[i].bookNum = findPublisher[query];
			break;
		case 5:
		
			ans[i].bookNum = findYear[query];
			break;
		}
		ans[i].bookNum.sort();
	
	}
	list<int>::iterator it;
	for (int i = 0; i < m; i++)
	{
		cout << ans[i].k<<": "<<ans[i].query<<endl;
		it = ans[i].bookNum.begin();
		for (; it != ans[i].bookNum.end(); it++)
			cout << setfill('0') << setw(7) << *(it) << endl;//这里要保证输出长度为7
		if (ans[i].bookNum.size() == 0)
			cout << "Not Found"<<endl;

	}
	system("pause");
	return 0;
}