#include "Bill.h"
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Bill bill;
	cin >> bill;
	cout << bill;
}