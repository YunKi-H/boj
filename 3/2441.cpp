#include <iostream>
using namespace std;

int	main(void)
{
	int	c;

	cin >> c;
	for (int i = c; i > 0; i--)
	{
		for (int j = 0; j < c - i; j++)
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << "\n";
	}
}
