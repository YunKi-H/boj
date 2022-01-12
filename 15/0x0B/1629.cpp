// 문제
// 자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

// 출력
// 첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
#include <iostream>
using namespace std;

long long solve(long long a, long long b, long long c)
{
	if (b == 1)
		return (a % c);
	long long val = solve(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0)
		return (val);
	return (val * a % c);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c);
}
