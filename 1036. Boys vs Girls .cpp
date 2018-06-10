#include"stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Student
{
	string name, course;
	char gender;
	int score;
};

int main()
{
	int n;
	cin >> n;
	Student male = { "","",'M',200 }, female{"","",'F',-1},temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp.name >> temp.gender >> temp.course >> temp.score;
		if (temp.gender == 'M'&&male.score > temp.score)
			male = temp;
		else if (temp.gender == 'F'&&female.score < temp.score)
			female = temp;
	}

	if (female.score > 0)
		cout << female.name << ' ' << female.course << endl;
	else
		cout << "Absent" << endl;

	if (male.score != 200)
		cout << male.name << ' ' << male.course << endl;
	else
		cout << "Absent"<<endl;

	if (male.score != 200 && female.score > 0)
		cout << female.score - male.score;
	else
		cout << "NA";
	system("pause");
	return 0;
}


