// https://www.acmicpc.net/problem/13335
#include <iostream>
using namespace std;

int n, w, l;
int truck[1001], leg[100];
int idx, ans;

void move()
{
	for (int i = w - 1; i > 0; i--)
		leg[i] = leg[i - 1];
	leg[0] = 0;
}

int sum()
{
	int ret = 0;
	for (int i = 0; i < w; i++)
		ret += leg[i];
	return (ret);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
		cin >> truck[i];
	do
	{
		move();
		if (sum() + truck[idx] <= l && idx < n)
			leg[0] = truck[idx++];
		ans++;
	} while (sum());
	cout << ans;
}
