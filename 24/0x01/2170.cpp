// https://www.acmicpc.net/problem/2170
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, ans, sp, ep;
vector<pair<int, int> > line;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sp >> ep;
		line.push_back(make_pair(sp, ep));
	}
	sort(line.begin(), line.end());
	int s = line[0].first;
	int e = line[0].second;
	for (int i = 1; i < n; i++)
	{
		int ns = line[i].first;
		int ne = line[i].second;
		if (ns <= e && ne >= e)
			e = ne;
		if (ns > e)
		{
			ans += e - s;
			s = ns;
			e = ne;
		}
	}
	ans += e - s;
	cout << ans;
}
