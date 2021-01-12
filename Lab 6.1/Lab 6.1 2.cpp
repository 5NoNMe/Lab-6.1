#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

void task(int* a, const int size, int count, int suma, int i)
{
	if ((a[i] > 0) && (a[i] % 3 == 0))
	{
		count++;
		suma += a[i];
		a[i] = 0;
	}

	if (i < size)
		task(a, size, count, suma, i + 1);
	else
	{
		cout << "Count: " << count << endl;
		cout << "Suma: " << suma << endl;
	}
}

int main()
{
	srand(time(0));

	const int n = 22;
	int a[n];

	int Low = -10;
	int High = 35;

	Create(a, n, Low, High, 0);
	Print(a, n, 0);

	task(a, n, 0, 0, 0);
	Print(a, n, 0);

	return 0;
}