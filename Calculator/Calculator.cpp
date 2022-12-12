#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#pragma warning(disable : 4996)

void menu()
{
	system("cls");
	printf("   1. Сложение(+)\n");
	printf("   2. Вычитание(-)\n");
	printf("   3. Умножение(*)\n");
	printf("   4. Деление(/)\n");
	printf("   5. Остаток от деления\n");
	printf("   6. Извлечение корня\n");
	printf("   7. Воведение в степень\n");
	printf("   8. Выход\n");
	printf("   9. Изменить числовые значения\n");
}
void fuck(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
int main()
{
	system("color 3F");
	system("cls");
	setlocale(LC_ALL, "Russian");
	using std::cout;
	using std::cin;

	const int nmi = 9;
	int n = 0;
	int amix = 0;
	int ch = 0;
	bool exit = false;
	long long x, y, a = 0;
Mazafaka:
	printf("\nВведите 1 число\n");
	while (!(cin >> x) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		printf("Введены неккоректные данные\n");
	}
	printf("\nВведите 2 число\n");
	while (!(cin >> y) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		printf("Введены неккоректные данные\n");
	}
	while (!exit)
	{
		char qq = 16;
		menu();
		fuck(0, amix); cout << qq;
		ch = getch();
		if (ch == 224)
			ch = getch();
		switch (ch)
		{
		case 27: exit = true; break;
		case 72: amix--; break;
		case 80: amix++; break;
		case 13:
			if (amix == 0)
			{
				a = x + y;
				if ((a > 100000000000000000) || (a < -100000000000000000))
				{
					printf("Выход за границы числового значения\n");
				}
				else
				{
					printf("\n\n\n\n\n\n\n\n\nОтвет %lld\n", a);
				}
				n = getch();
			}
			else if (amix == 1)
			{
				a = x - y;
				if ((a > 100000000000000000) || (a < -100000000000000000))
				{
					printf("\n\n\n\n\n\n\n\nВыход за границы числового значения\n");
				}
				else
				{
					printf("\n\n\n\n\n\n\n\nОтвет %lld\n", a);
				}

				n = getch();
			}
			else if (amix == 2)
			{
				a = x * y;
				if ((a > 100000000000000000) || (a < -1000000000000000000))
				{
					printf("\n\n\n\n\n\n\nВыход за границы числового значения\n");
				}
				else
				{
					printf("\n\n\n\n\n\n\nОтвет %lld\n", a);
				}
				n = getch();
			}
			else if (amix == 3)
			{
				if (y == 0)
					printf("\n\n\n\n\n\n\nДелитель не должен быть равен 0\n");
				else if (!(y == 0))
				{
					a = x / y;
					if ((a > 100000000000000000) || (a < -100000000000000000))
					{
						printf("\n\n\n\n\n\n\nВыход за границы числового значения\n");
					}
					else
					{
						printf("\n\n\n\n\n\n\nОтвет %lld\n", a);
					}
				}
				else
				{
					printf("\n\n\n\n\n\n\n Один из символов неверный или меньше 0\n");
				}
				n = getch();
			}
			else if (amix == 4)
			{
				if (y > 0)
				{
					printf("\n\n\n\n\n\nОтвет %lld\n", x % y);
				}
				else
				{
					printf(" \n\n\n\n\n\nОдин из символов неверный или меньше 0\n");
				}
				n = getch();
			}
			else if (amix == 5)
			{
				if (x > 0)
				{
					float z = 0.0;
					z = sqrt(x);
					printf("\n\n\n\n\nОтвет %.0f\n", z);
				}
				else
				{
					printf("\n\n\n\n\n Символ неверный или меньше 0\n");
				}
				n = getch();
			}
			else if (amix == 6)
			{
				a = pow(x, y);
				if ((a > 100000000000000000) || (a < -100000000000000000))
				{
					printf("\n\n\n\n\nВыход за границы числового значения\n");
				}
				else
				{
					printf("\n\n\n\n\nОтвет %lld\n", a);
				}
				n = getch();
			}
			else if (amix == 7)
			{
				_Exit(1);
			}
			else if (amix == 8)
			{
				goto Mazafaka;
			}

			break;
		}

		if (amix < 0) amix = 8;
		if (amix > nmi - 1) amix = 0;
		if (ch == 49) amix = 0;
		if (ch == 50) amix = 1;
		if (ch == 51) amix = 2;
		if (ch == 52) amix = 3;
		if (ch == 53) amix = 4;
		if (ch == 54) amix = 5;
		if (ch == 55) amix = 6;
		if (ch == 56) amix = 7;
		if (ch == 57) amix = 8;

	}
	return 3;
}