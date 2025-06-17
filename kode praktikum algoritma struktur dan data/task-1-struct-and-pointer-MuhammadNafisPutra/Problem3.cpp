#include<iostream>

using namespace std;

 string huruf;
 int angka;
 char kata [10];

int main(){

    cout << "Masukkan Sebuah Huruf = "; cin >> huruf;
    cout << "Masukkan Sebuah Kata  = "; cin >> kata;
    cout << "Masukkan Angka        = "; cin >> angka;

    cout << "\nHuruf yang Anda Masukkan adalah = " << huruf;
    cout << "\nKata yang Anda Masukkan adalah  = " << kata;
    cout << "\nAngka yang Anda Masukkan adalah = " << angka;

    return 0;
}