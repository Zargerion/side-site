#include <iostream>
#include <iomanip>
using namespace std;

void render(int bl, int bl2)
{
	int i = 1;
	int hh = 10;

	while (true)
	{
		for (i = 1; i < hh+1; i++)
		{
			for (int j = 1; j < hh+1; j++)
			{
				if (i == bl and j == bl2)
				{
					cout << setw(5) << bl+bl2/2;
				}
				else
				{
					if (j == hh)
					{
						cout << setw(5) << "#" << endl;
					}
					else
					{
						cout << setw(5) << "#"; // setw sew wight
					}
				}
			}
		}

		int a = i;
		cout << endl
			 << a << endl;
	}
}

int main()
{
	int biglow;
	int biglow2;
	cin >> biglow;
	cin >> biglow2;

	render(biglow, biglow2);
}
