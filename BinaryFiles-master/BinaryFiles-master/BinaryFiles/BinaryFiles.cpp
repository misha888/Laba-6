// BinaryFiles.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
using namespace std;

struct Book
{
	string fio;
	string book_name;
	int    cost;
	int    count;
};
void CheckDigit(int& anydigit);

Book* FillStruct(Book* mas_book, int count)  //Всего лишь заполняет масив структур
{
	if (mas_book == nullptr)
		mas_book = new Book[count];
	for (size_t i = 0; i < count; i++)
	{
		mas_book[i].fio       = "FIO" + to_string(i+1);
		mas_book[i].book_name = "BooksName" + to_string(i + 1);
		mas_book[i].cost       =  100 + rand() % 1000;
		mas_book[i].count      =  1 + rand() % 100;
	}
	return mas_book;
} 
void ShowBooks(Book* mas_books, int count)
{
	cout << "\nИнформация о всех книах: \n";
	for (size_t i = 0; i < count; i++)
	{
		printf("\nИнформация о %d книге: \n\t", i + 1);
		cout << mas_books[i].fio << " " ;
		cout << mas_books[i].book_name << " ";
		cout << mas_books[i].cost << " " ;
		cout << mas_books[i].count << "\n";
	}
}
Book* LoadFile( int count)  //Прочитать данные с файла
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in);
	Book* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Book));
	f_in.close();
	return buffer;
}
void SaveFile(Book* mas_book, int count)
{
	ofstream f_out; f_out.open("database.bin", ios::binary | ios::out);
	int BufferSize = count * sizeof(Book);
	f_out.write((char*)mas_book, BufferSize);
	f_out.close();
}
int IsSetDiscount(int count) //Установление скидки если соблюдается условие 
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in );
	Book* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Book));
	f_in.close();
	for (size_t i = 0; i < count; i++)
	{
		if (buffer[i].count > 20)
		{
			buffer[i].cost -= buffer[i].cost * 0.05;
		}
	}
	SaveFile(buffer, count);
	return 0;
}
void hard_task()
{
	cout << "\nHard task level: \n";
	int count = 10;
	Book* mas_book = new Book[count];
	mas_book = FillStruct(mas_book, count);
	SaveFile(mas_book, count);
	mas_book = LoadFile( count);
	cout << "\nСодержимое файла до внесенных изминений: \n";
	cout << "\nВ файле хранится масив структур содержащих следущие поля: \n";
	cout << "\t-ФИО автора\n\t-название книги\n\t-цена за ед.\n\t-количетсво экзэмпляров";
	ShowBooks(mas_book, count);
	cout << "\nСодержимое файла после внесенных изминений: ";
	 IsSetDiscount(count);
	Book* buffer = new Book[count];
	buffer = LoadFile(count);
	SaveFile(buffer, count);
	ShowBooks(buffer, count);
	cout << "\nНажмите <Enter> для завершения...";
	while (getchar() != '\n')
		continue;
}
void CheckDigit(int& anydigit)
{
	while (true)
	{
		cin >> anydigit;
		if (!cin.good() || cin.fail())
		{
			cin.clear();
			cin.ignore(32567, '\n');
			cout << "\nВведите коректное числовое значение...\n";
			cout << "\nПовторите ввод: ";
		}
		break;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	srand(time(0));
	hard_task();
}

