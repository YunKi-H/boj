// 문제
// N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

// 출력
// 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
#include <iostream>
using namespace std;

int vis1[40];
int vis2[40];
int vis3[40];
int cnt, n;

void solve(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (vis1[i] || vis2[cur + i] || vis3[cur - i + n - 1])
			continue;
		vis1[i] = 1;
		vis2[cur + i] = 1;
		vis3[cur - i + n - 1] = 1;
		solve(cur + 1);
		vis1[i] = 0;
		vis2[cur + i] = 0;
		vis3[cur - i + n - 1] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	solve(0);
	cout << cnt;
}
