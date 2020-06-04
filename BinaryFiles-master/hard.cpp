#include "Stdafx.h"
using namespace std;
/*
Создать бинарный файл с информацией о работниках телестудии: 
    - фамилия;
    - должность;
    - образование;
    - дата приема на работу;
    - пол. 
Вывести сведения о работниках телестудии, которые работают на должности инженеров, но не имеющие 
высшего образования
*/
template <typename T>
string toString(T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

void low()
{
    system("cls");
    printf("\nLow task level:\n");
    int count_workers = 10;
    WorkerTV* workers = new WorkerTV[count_workers];
    for (size_t i = 0; i < count_workers; i++)
    {
        workers[i].surname   = "Worker" + toString(i + 1);
        workers[i].position  = ((rand() % 2) == 1) ? "enginer" : "anyworker";
        workers[i].education =  rand() % 2;
       // workers[i].employment_date  = ;
        workers[i].gender    = ((rand() % 2) == 1) ? "man" : "woman";
    }

    string filename = "WorkerTVInfo";
    ofstream f_out; f_out.open(filename, ios::binary);
    int buffersize = sizeof(WorkerTV) * count_workers;
    f_out.write((char*)workers, buffersize); f_out.close();

    WorkerTV* buf = new WorkerTV[count_workers];
    ifstream f_in; f_in.open(filename, ios::binary);
    f_in.read((char*)buf, buffersize); f_in.close();

    cout << "\nИнформация прочитанная с файла <<WorkerTVInfo.bin>>: \n\t";
    for (size_t i = 0; i < count_workers; i++)
    {
        cout << workers[i].surname<< " ";
        cout << workers[i].position << " ";
        cout << workers[i].education << " ";
        cout << workers[i].gender <<"\n\t";
    }

    cout << "\nCведения о работниках телестудии, которые работают на должности инженеров, но не имеющие\n" 
        "высшего образования прочитанные с файла <<WorkerTVInfo.bin>>: \n\t";
    for (size_t i = 0; i < count_workers; i++)
    {
        if (workers[i].position== static_cast<string>("enginer") && workers[i].education) {
            cout << workers[i].surname << " ";
            cout << workers[i].position << " ";
            cout << workers[i].education << " ";
            cout << workers[i].gender << "\n\t";
        }
    }
    cout << "\nНажми Enter для завершения...\n";
    while (getchar() != '\n') { continue; }
}


