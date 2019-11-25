#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
int show(), light(), count(); void menu(); 
int main()
{
	setlocale(LC_ALL, "Russian");
	menu();
	return 0;
}
void menu(){
	    system("cls");
        int a;
		cout << "Выберите, что хотите сделать" << endl;
		cout << "1.Вывести текст на экран дисплея" << endl;
		cout << "2.Выделить слова, у которых первый и последний символ совпадают" << endl;
		cout << "3.Количество слов, у которых первый и последний символы совпадают" << endl;
		cin >> a;
		while (a < 1 || a>3) { cin >> a; }
		a = a - 1;
		switch (a) {
		case 0: show(); break;
		case 1: light(); break;
		case 2: count(); break;
		}
}
int show(){
	system("cls");
	char s[70];
	ifstream f("text.txt");
	while (!f.eof()) 
	{
		f.getline(s, 70);
		cout << s<<endl;
	}
	f.close();
	cout << "Нажмите пробел, что б вернутся в меню";
	int code;
	code = _getch();
	if (code == 32) { menu(); }
	else return 0;
}
int light() {
	system("cls");

	return 0;
}
int count() {
	system("cls");

	return 0;
}