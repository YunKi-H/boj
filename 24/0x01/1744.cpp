// https://www.acmicpc.net/problem/1744
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n, tmp, ans;
deque<int> pos;
deque<int> neg;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == 1)
			ans++;
		else if (tmp > 0)
			pos.push_back(tmp);
		else
			neg.push_back(tmp);
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	while (pos.size() > 1)
	{
		ans += *(pos.end() - 1) * *(pos.end() - 2);
		pos.pop_back();
		pos.pop_back();
	}
	if (pos.size())
		ans += pos[0];
	while (neg.size() > 1)
	{
		ans += neg[0] * neg[1];
		neg.pop_front();
		neg.pop_front();
	}
	if (neg.size())
		ans += neg[0];
	cout << ans;
}
