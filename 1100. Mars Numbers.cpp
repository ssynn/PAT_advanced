
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
using namespace std;

string a[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string b[13] = { "","tam","hel","maa","huh","tou","kes","hei","elo", "syy", "lok", "mer", "jou" };
map<string, int>toInt;

void ToMars(string &temp)
{
	int num = stoi(temp);
	int x = num / 13, y = num % 13;
	if(x)
		cout << b[x];
	if (x&&y)
		cout << ' ';
	if(y)
		cout<< a[y];
	if (!x && !y)
		cout << a[0];
	cout << endl;

}

void ToEarth(string &temp)
{
	int i = 0,sum=0;
	string ans1;
	while (i < temp.size())
	{
		if (temp[i] == ' ')
		{
			sum += toInt[ans1];
			ans1 = "";
			i++;
			continue;
		}
		ans1.push_back(temp[i]);
		i++;
	}
	
	sum += toInt[ans1];
	cout << sum << endl;
}

int main()
{

	for (int i = 0; i <= 12; i++)
		toInt[a[i]] = i;
	for (int i = 1; i < 13; i++)
		toInt[b[i]] = i*13;

	int n;
	string temp;
	cin >> n;
	getline(cin, temp);
	while (n--)
	{
		getline(cin, temp);
		if (temp[0] <= '9'&&temp[0] >= '0')
			ToMars(temp);
		else
			ToEarth(temp);
	}
	system("pause");
	return 0;
}
/*



*/
/*
169
tret
jan
feb
mar
apr
may
jun
jly
aug
sep
oct
nov
dec
tam tret
tam jan
tam feb
tam mar
tam apr
tam may
tam jun
tam jly
tam aug
tam sep
tam oct
tam nov
tam dec
hel tret
hel jan
hel feb
hel mar
hel apr
hel may
hel jun
hel jly
hel aug
hel sep
hel oct
hel nov
hel dec
maa tret
maa jan
maa feb
maa mar
maa apr
maa may
maa jun
maa jly
maa aug
maa sep
maa oct
maa nov
maa dec
huh tret
huh jan
huh feb
huh mar
huh apr
huh may
huh jun
huh jly
huh aug
huh sep
huh oct
huh nov
huh dec
tou tret
tou jan
tou feb
tou mar
tou apr
tou may
tou jun
tou jly
tou aug
tou sep
tou oct
tou nov
tou dec
kes tret
kes jan
kes feb
kes mar
kes apr
kes may
kes jun
kes jly
kes aug
kes sep
kes oct
kes nov
kes dec
hei tret
hei jan
hei feb
hei mar
hei apr
hei may
hei jun
hei jly
hei aug
hei sep
hei oct
hei nov
hei dec
elo tret
elo jan
elo feb
elo mar
elo apr
elo may
elo jun
elo jly
elo aug
elo sep
elo oct
elo nov
elo dec
syy tret
syy jan
syy feb
syy mar
syy apr
syy may
syy jun
syy jly
syy aug
syy sep
syy oct
syy nov
syy dec
lok tret
lok jan
lok feb
lok mar
lok apr
lok may
lok jun
lok jly
lok aug
lok sep
lok oct
lok nov
lok dec
mer tret
mer jan
mer feb
mer mar
mer apr
mer may
mer jun
mer jly
mer aug
mer sep
mer oct
mer nov
mer dec
jou tret
jou jan
jou feb
jou mar
jou apr
jou may
jou jun
jou jly
jou aug
jou sep
jou oct
jou nov
jou dec


168
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
*/