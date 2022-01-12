// 문제
// 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

// 입력
// 첫째 줄에 N이 주어진다. N은 항상 3×2k 수이다. (3, 6, 12, 24, 48, ...) (0 ≤ k ≤ 10, k는 정수)

// 출력
// 첫째 줄부터 N번째 줄까지 별을 출력한다.
#include <iostream>
using namespace std;

char arr[3072][6144];

void solve (int n, int x, int y)
{
	if (n == 3)
	{
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		for (int i = y - 2; i <= y + 2; i++)
			arr[x + 2][i] = '*';
		return ;
	}
	n /= 2;
	solve(n, x, y);
	solve(n, x + n, y - n);
	solve(n, x + n, y + n);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n - 1; j++)
			arr[i][j] = ' ';
	solve(n, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}
