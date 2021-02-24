#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int strLen(char str[]);

void to_upper(char str[]); // переводит строку в верхний регистр
void to_lower(char str[]); // в нижний
void capitalize(char str[]); // первую букву каджого слова в предложении делает заглавной и удаляет лишние пробелы

int main()
{
	setlocale(LC_ALL, "Rus");
	system("Color 0A");
	system("CHCP 1251");
	system("CLS");

	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	const int n = 30;
	char str[n];
	cout << "Введите строку: "; SetConsoleCP(1251); cin.getline(str, n); //SetConsoleCP(866);
	//cout << str << endl;
	cout << "Размер массива: " << sizeof(str) << endl;
	cout << "Размер строки: " << strLen(str) << endl;
	cout << "Верхний регистр: "; to_upper(str); cout << endl;
	cout << "Нижний регистр: "; to_lower(str); cout << endl;
	cout << "Заглавная буква в каждом слове(англ) и удаление лишних пробелов: "; capitalize(str); cout << endl;
}

int strLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
		cout << str[i];
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
		cout << str[i];
	}
}

void capitalize(char str[])
{
	char *sup;
	sup = strtok(str, " ");
	do 
	{
		if (*sup == tolower(*sup))
			*sup = toupper(*sup);

		cout << sup << ' ';
		sup = strtok(NULL, " ");
	} while (sup);
}