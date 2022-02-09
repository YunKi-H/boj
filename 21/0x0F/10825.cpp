// https://www.acmicpc.net/problem/10825
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<pair<string, int>, pair<int, int> > > arr;

bool cmp(const pair<pair<string, int>, pair<int, int> > &p1, const pair<pair<string, int>, pair<int, int> > &p2)
{
	if (p1.first.second == p2.first.second)
	{
		if (p1.second.first == p2.second.first)
		{
			if (p1.second.second == p2.second.second)
				return (p1.first.first < p2.first.first);
			return (p1.second.second > p2.second.second);
		}
		return (p1.second.first < p2.second.first);
	}
	return (p1.first.second > p2.first.second);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		int k, e, m;
		cin >> name >> k >> e >> m;
		arr.push_back(make_pair(make_pair(name, k), make_pair(e, m)));
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].first.first << '\n';
}
