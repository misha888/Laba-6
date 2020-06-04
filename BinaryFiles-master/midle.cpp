#include "Stdafx.h"
using namespace std;
/*
Ввести в Memo или в StringGrid некоторое количество целых чисел в диапазоне 33 - 255  и записать их в 
бинарный файл. Переписать бинарный файл так, чтобы каждое значение, записанное в файле, было 
преобразовано в данные типа char, тоесть в символьный тип данных. Распечатать содержимое файла до и 
после изменения данных в файле.
*/
template <typename T>
string toString(T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

void midle()
{
    system("cls");
    printf("\nMidle task level: \n");
    string filen = "DigitFile.bin";
    ofstream f_out;  f_out.open(filen, ios::binary );
    int count_digit = 10 + rand() % 10;
    int* mas_digit = new int[count_digit];
    for (size_t i = 0; i < count_digit; i++) { mas_digit[i] = 33 + rand() % 223; }
    int buffer_size = sizeof(int) * count_digit;
    f_out.write((char*)mas_digit, sizeof(int)*count_digit);
    f_out.close();
    ifstream f_in;
    f_in.open(filen, ios::binary);
    int* buffer = new int[count_digit];
    f_in.read((char*)buffer, sizeof(int)*count_digit); 
    f_in.close();
    printf_s("\nÑîäåðæèìîå ñ÷èòàíîå ñ ôàéëà <<%s>>: \t",filen.c_str());
    string strbuf;
    for (size_t i = 0; i < count_digit; i++)
    {
        if (i % 25 == 0)
            cout << endl << "\t";
        cout << buffer[i]<<" ";
        strbuf += toString(buffer[i]);
    }
    int str_length = strbuf.length()+1;
    const char* char_buf ;
    char_buf = strbuf.c_str();
    f_out.open(filen, ios::binary | ios::trunc);
    f_out.write((char*)char_buf, sizeof(char)*str_length);
    f_out.close();
    char* char_buffer = new char[str_length];
    char_buffer[str_length] = '\0';
    f_in.open(filen, ios::binary); f_in.read((char*)char_buffer, sizeof(char) * str_length); f_in.close();
    cout << "\nÑîäåðæèìîå ôàéëà ïîñëå âíåñåííûõ èçìèåíèé: \n\t";
    for (size_t i = 0; char_buffer[i] != 0; i++)
    {
        cout << char_buffer[i] << " ";
    }
    delete[] buffer;    buffer    = nullptr;
    delete[] mas_digit; mas_digit = nullptr;
}
