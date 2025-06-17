#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

void INSERT(char data);
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();

int PIL, F, R;
char PILIHAN[n], HURUF;
char Q[n];

int IsFull()
{
    if(R == 10-1)
{
    return 1;
}
    else
{
    return 0;
}
};

int IsEmpty()
{
    if (R == -1)
{
 return 1;
}
    else
{
 return 0;
}
};

void INSERT (char data)
{
     if(IsEmpty()==1)
 { R++;
    F = R = 0;
    Q [R] = data;
 }
    else if(IsFull()==0)
     R++;
     Q[R] = data;
     cout <<"data " << Q[R] <<" masuk ke queue\n";
};

void DELETE()
{
 int i;
 int e = Q[F];
    for(i=F; i<=R-1; i++)
 {
    Q[i] = Q[i+1];
    
}
 R--; cout << "data sudah terambil" << endl;
};

void CETAKLAYAR()
{
    if(IsEmpty()==0)
    {
        for(int i = R; i >= 0; i--)
        {
            cout << "Tumpukan Ke - " << i << " = "
                 << Q[i] << endl;
        }
    }
    else
        cout << "Tumpukan Kosong\n";
}

void Inisialisasi()
{
F =R = -1;
}

int main() {
    Inisialisasi();
    do {
        cout << "QUEUE" << endl;
        cout << "=================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : ";
        cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
            cout<<"Masukkan huruf : "; cin >> HURUF;
                INSERT(HURUF);
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }

        cout << "Press any key to continue" << endl;
        getch();
        system("cls");

    } while (PIL < 4);
}