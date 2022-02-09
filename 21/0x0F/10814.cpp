// https://www.acmicpc.net/problem/10814
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, string> > arr;

bool cmp(const pair<int, string> &p1, const pair<int, string> &p2)
{
	return (p1.first < p2.first);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		string b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	stable_sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';
}
