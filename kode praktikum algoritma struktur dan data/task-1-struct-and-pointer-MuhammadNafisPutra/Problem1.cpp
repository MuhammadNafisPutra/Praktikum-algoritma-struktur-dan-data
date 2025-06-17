#include <iostream>

using namespace std;

struct mhs {
    char nama[20], nim[10], jurusan[2];
    int sks, program;
};

struct mhs bayar[2];

int main() {
    int bts, var, tetap;
    
    for(int i = 0; i < 2; i++) {

        cout << "\n----------------------------------------\n";
        cout << "Nama Mhs        = "; cin >> bayar[i].nama;
        cout << "NIM             = "; cin >> bayar[i].nim;
        cout << "Jurusan [TI, PTK] = "; cin >> bayar[i].jurusan;

        input:
        cout << "Program [1=D3, 2=S2] = "; cin >> bayar[i].program;

        if (bayar[i].program < 1 || bayar[i].program > 2) {
            cout << "Program tidak sesuai!\n";
            goto input;
        }

        cout << "Jumlah SKS      = "; cin >> bayar[i].sks;

        if (bayar[i].program == 1) {
            tetap = 500000;
            var = bayar[i].sks * 25000;
        } 
        else if (bayar[i].program == 2) {
            tetap = 7500000;
            var = bayar[i].sks * 50000;
        }

        cout << endl;
    }


    cout << "\n----------------------------------------\n";
    for(int i = 0; i < 2; i++) {
        cout << "\nNama Mhs         : " << bayar[i].nama;
        cout << "\nNIM              : " << bayar[i].nim;
        cout << "\nJurusan          : " << bayar[i].jurusan;
        cout << "\nJumlah SKS       : " << bayar[i].sks;
        cout << "\nBiaya Tetap      : " << tetap;
        cout << "\nBiaya Variabel   : " << var;
        cout << endl << endl;
    }

    return 0;
}