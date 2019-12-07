#include <iostream>
#include <conio.h>
#include <fstream>
#include <cctype> 
using namespace std;
int show(), light(), count(); void menu(); 
int back()
{   
	cout << "Нажмите пробел, что б вернутся в меню";
	int code;
	code = _getch();
	if (code == 32) { menu(); }
	else return 0;
}
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
	f.seekg(0, ios::beg);
	while (!f.eof()) 
	{
		f.getline(s, 70);
		cout <<s<<endl;
	}
	f.close();
	
	back();
	return 0;
}
int light(){ 
	int codee;
	system("cls");
	char text[1000] = {'\0'};
	ifstream f("text.txt");
	f.read(text, 1000);
	for (int i = 0; i < 1000; i++)
	{
		if (isalpha(text[i]))
		{ 
			text [i]=tolower(text[i]); 
		}
	}
	
	for (int i = 0; i < 1000; i++)
	{
		for (int j = i + 1; j < 1000; j++)
		{
			if ((isalpha(text[i]) && isalpha(text[j])) && (text[i] == text[j]) && ((text[j + 1] == ' ' || text[j + 1] == ',' || text[j + 1] == '\0' || text[j + 1] == '.' || text[j + 1] == '!' || text[j + 1] == '?' || text[j + 1] == '\n') && (text[i] >= 66 || text[i] <= 90 || text[i - 1] == '\n' || text[i - 1] == ' ' || !isalpha(i-1))))
			{
				cout << "Нажмите любую клавишу, если хотите выделить следующее слово. Нажмите SPACE, если хотите обратно"<<endl;
				codee = _getch();
				if (codee != 32)
				{
					system("cls");
					text[i] = toupper(text[i]);
					text[j] = toupper(text[j]);
					for (int a = 0; a < 1000; a++)
					{
						cout << text[a];
					}
					i =+j;
					text[i] = tolower(text[i]);
					text[j] = tolower(text[j]);
					break;
				}
				else menu();
			}
			else if (text[j + 1] == ' ' || text[j + 1] == ',' || text[j + 1] == '.' || text[j + 1] == '!' || text[j + 1] == '?' || text[j + 1] == '\n') { break; }
		}
	}
	back();
	return 0;
}
int count() {
	system("cls");
	int count=0;
	char text[1000] = { '\0' };
	ifstream f("text.txt");
	f.read(text, 1000);
	for (int i = 0; i < 1000; i++)
	{
		if (isalpha(text[i]))
		{
			text[i] = tolower(text[i]);
		}
	}

	for (int i = 0; i < 1000; i++)
	{
		for (int j = i + 1; j < 1000; j++)
		{
			if ((isalpha(text[i]) && isalpha(text[j])) && (text[i] == text[j]) && ((text[j + 1] == ' ' || text[j + 1] == ',' || text[j + 1] == '\0' || text[j + 1] == '.' || text[j + 1] == '!' || text[j + 1] == '?' || text[j + 1] == '\n') && (text[i] >= 66 || text[i] <= 90 || text[i - 1] == '\n' || text[i - 1] == ' ' || !isalpha(i - 1))))
			{
				i =+ j;
				count =count+ 1;
					break;
			}
			
			else if (text[j + 1] == ' ' || text[j + 1] == ',' || text[j + 1] == '.' || text[j + 1] == '!' || text[j + 1] == '?' || text[j + 1] == '\n') { break; }
		}
	}
	cout << count << " ---- вот столько слов, которые начинаются и заканчиваются на одну и туже букву" << endl;
	back();
	return 0;
}