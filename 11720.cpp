#include <iostream>
using namespace std;

int	main(void)
{
	int		n;
	int		result;
	char	c;

	cin >> n;
	result = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		result += c - '0';
	}
	cout << result;
	return (0);
}
