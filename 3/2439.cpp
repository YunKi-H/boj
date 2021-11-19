#include <iostream>
using namespace std;

int	main(void)
{
	int	c;

	cin >> c;
	for (int i = 1; i <= c; i++)
	{
		for (int j = c - i; j > 0; j--)
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << "\n";
	}
}
