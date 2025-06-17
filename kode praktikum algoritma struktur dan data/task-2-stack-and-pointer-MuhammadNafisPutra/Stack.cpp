#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;


struct stack{
    int atas =-1;
    int data[MAX];
};
stack Tumpuk;

int penuh()
{
    if(Tumpuk.atas == MAX-1)
        return 1;
    else
        return 0;
}

int kosong()
{
    if(Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

void input(int data)
{
    if(kosong()==1)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    }
    else if(penuh()==0)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    }
    else
        cout << "Tumpukan Penuh\n";
}

void hapus()
{
    if(kosong()==0)
    {
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    }
    else
        cout << "Data Kosong\n";
}

void tampil()
{
    if(kosong()==0)
    {
        for(int i = Tumpuk.atas; i >= 0; i--)
        {
            cout << "Tumpukan Ke - " << i << " = "
                 << Tumpuk.data[i] << endl;
        }
    }
    else
        cout << "Tumpukan Kosong\n";
}

void bersih()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !\n";


}

int main() {
    int pil, data;

    do {
        cout << "\nALGORITMA STRUKTUR DATA" << endl;
        cout << "====================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Show Stack" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Quit" << endl;
        cout << "Pilih Menu: ";
        cin >> pil;

        switch (pil) {
            case 1:
                cout << "Masukkan Data: ";
                cin >> data;
                input(data);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
        }
        getch(); 
        system("cls"); 
    } while (pil != 5);

    return 0;
}