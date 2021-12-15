#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n;
	string s;

	cin >> n;
	while (n--)
	{
		list<char> c;
		list<char>::iterator node = c.begin();
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '-')
			{
				if (node == c.begin())
					continue ;
				else
					node = c.erase(--node);
			}
			else if (s[i] == '<')
			{
				if (node == c.begin())
					continue ;
				else
					node--;
			}
			else if (s[i] == '>')
			{
				if (node == c.end())
					continue ;
				else
					node++;
			}
			else
				c.insert(node, s[i]);
		}
		for (node = c.begin(); node != c.end(); node++)
			cout << *node;
	}
}