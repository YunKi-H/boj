#include <iostream>
using namespace std;

int	main(void)
{
	char	c;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 && cin >> c; j++)
			cout << c;
		cout << "\n";
	}
	return (0);
}
