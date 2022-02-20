// https://www.acmicpc.net/problem/2457
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, fm, fd, tm, td, ans;
vector<pair<int, int> > flower;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> fm >> fd >> tm >> td;
		flower.push_back(make_pair(fm * 100 + fd, tm * 100 + td));
	}
	int now = 301;
	while (now <= 1130)
	{
		int tmp = now;
		for (int i = 0; i < n; i++)
		{
			if (now >= flower[i].first && tmp < flower[i].second)
				tmp = flower[i].second;
		}
		if (tmp == now)
		{
			ans = 0;
			break;
		}
		ans++;
		now = tmp;
	}
	cout << ans;
}
