#include "Stdafx.h"
using namespace std;
#define count_monitor 4
/*
Ñîçäàòü áèíàðíûé ôàéë ñ èíôîðìàöèåé î ïðåäëîæåííûõ ê ðåàëèçàöèè ìîíèòîðàõ:
	- íàçâàíèå ôèðìû;
	- ðàçìåð ïî äèàãîíàëè;
	- ñòîèìîñòü. 
Îïðåäåëèòü ñðåäíþþ öåíó ìîíèòîðîâ, ðàçìåðîì íå ìåíåå 19 äþéìîâ è ðàñïå÷àòàòü ñâåäåíèÿ î íèõ
*/
#ifndef _monitor
#define _monitor
struct Monitor
{
	string		   company_name;
	unsigned short diagonal_size;
	unsigned int   price;    
} monitor[count_monitor];
#endif // !_monitor
void ShowInfo(Monitor* mas_mon)
{
	cout << "\nÑâåäåíèÿ, î ìîíèòîðàõ, õðàíÿùèåñÿ â ôàéëå <<monitor.dat>>\n";
	for (size_t i = 0; i < count_monitor; i++)
	{
		cout <<"\t"<<i+1<<"."<< mas_mon[i].company_name << " " << mas_mon[i].diagonal_size << " " << mas_mon[i].price << endl;

	}
}
void WorkFunc(Monitor* mas_mon)
{
	cout << "\nÑâåäåíèÿ î ìîíèòîðàõ ó êîòîðûõ ðàçìåð ïî äèàãîíàë íå ìåíåå 19 äþéìîâ, "
		"è èõ ñðåäíÿÿ \nñòîèìîñòü\n";
	double sum=0;
	int count = 0;
	bool flag = false;
	for (size_t i = 0; i < count_monitor; i++)
	{
		if ( mas_mon[i].diagonal_size >= 19 )
		{
			flag = true;
			cout << "\t" << i + 1 << "." << mas_mon[i].company_name << " " 
				          << mas_mon[i].diagonal_size << " " << mas_mon[i].price << endl;
			sum += mas_mon[i].price; count++;
		}
		
	}
	flag ? cout << "\tCðåäíÿ ñòîèìîñòü " << (double)(sum / count) << endl : 
		             cout << "\tÒàêèõ ìîíèòîðîâ íåò !\n";
}
void Base()
{
	cout << "\nBase level\n";
	FILE* f_out, * f_in;
	char path[] = "monitor.dat";
	f_out = fopen(path, "wb");
	string mas_company_name[] = {"LG", "Sumsung", "Asus", "Acer"} ;
	cout << "Äàííûå õðàíÿùèåñÿ â ôàéëå <<monitor.dat>>: \n";
	for (size_t i = 0; i < count_monitor; i++)
	{
		cout<< ( monitor[i].company_name = mas_company_name[i]) << "\t";
		cout<< ( monitor[i].diagonal_size = 10 + rand() % 20 ) <<"\t";
		cout<< ( monitor[i].price = 1000 + rand() % 20000 ) <<endl;
	}

	Monitor* buffer = new Monitor[count_monitor];
	//size_t size_mon = sizeof(Monitor);
	fwrite(monitor, sizeof(Monitor), count_monitor, f_out);
	fclose(f_out);
	f_in = fopen(path, "rb");
	fread(buffer, sizeof(Monitor), count_monitor, f_in);
	ShowInfo(buffer);
//	system("cls");
	WorkFunc(buffer);
	fclose(f_in);

}
