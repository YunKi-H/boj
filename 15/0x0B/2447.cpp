// 문제
// 재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.

// 크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.

// ***
// * *
// ***
// N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.

// 입력
// 첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.

// 출력
// 첫째 줄부터 N번째 줄까지 별을 출력한다.
#include <iostream>
using namespace std;

void solve(int n, int x, int y)
{
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
		cout << ' ';
	else if (n / 3 == 0)
		cout << '*';
	else
		solve(n / 3, x, y);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			solve(n, i, j);
		cout << '\n';
	}
}
