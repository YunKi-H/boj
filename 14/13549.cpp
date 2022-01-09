// 문제
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

// 출력
// 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

int check[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 200001; i++)
		check[i] = -1;
	check[n] = 0;
	deque<int> dq;
	dq.push_back(n);
	while (check[k] == -1)
	{
		int now = dq.front();
		dq.pop_front();
		if (now * 2 <= 200000 && check[now * 2] == -1)
		{
			check[now * 2] = check[now];
			dq.push_front(now * 2);
		}
		if (now - 1 >= 0 && check[now - 1] == -1)
		{
			check[now - 1] = check[now] + 1;
			dq.push_back(now - 1);
		}
		if (now + 1 <= 200000 && check[now + 1] == -1)
		{
			check[now + 1] = check[now] + 1;
			dq.push_back(now + 1);
		}
	}
	cout << check[k];
}
