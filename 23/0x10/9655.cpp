// https://www.acmicpc.net/problem/9655
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n % 2 == 0)
		cout << "CY";
	else
		cout << "SK";
}
