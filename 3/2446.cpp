#include <iostream>
using namespace std;

int	main(void)
{
	int	c;

	cin >> c;
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = 0; j < 2 * (c - i) - 1; j++)
			cout << "*";
		cout << "\n";
	}
	for (int i = c - 1; i > 0; i--)
	{
		for (int j = i - 1; j > 0; j--)
			cout << " ";
		for (int j = 2 * (c - i) + 1; j > 0; j--)
			cout << "*";
		cout << "\n";
	}
	return (0);
}
