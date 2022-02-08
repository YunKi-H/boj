// https://www.acmicpc.net/problem/1181
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string tmp;
vector<string> vec;

bool cmp(string s1, string s2)
{
	if (s1.length() == s2.length())
		return (s1 < s2);
	return (s1.length() < s2.length());
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), cmp);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << '\n';
}
