#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void printWithIndex(const vector<int> &n){
    for (int a = 0; a < n.size(); ++a)
    {
        cout << "" << setw(3) << n[a] << " : {"<< setw(3) << a << "}   ";
        if ((a + 1) % 5 == 0)
            cout << '\n';
    }
    cout << "\n";
}

void sequentialSearch(const vector<int> &nums, int target){
    vector<int> cari_indeks;
    for (int a = 0; a < nums.size(); ++a){
        if (nums[a] == target){
            cari_indeks.push_back((int)a);
        }
    }

    if (cari_indeks.empty()){ 
        cout << "Angka " << target << " tidak ditemukan.\n";
    }
    else{
        cout << "Angka " << target << " ditemukan " << cari_indeks.size() << " kali pada indeks: ";
        for (int a = 0; a < cari_indeks.size(); ++a){
            cout << cari_indeks[a];
            if (a != cari_indeks.size() - 1)
                cout << ", ";
        }
        cout << ".\n";
    }
}

void binarySearch(const vector<int> &nums, int target){
    vector<int> sortnms = nums;
    sort(sortnms.begin(), sortnms.end());
    system("cls");
    
    cout << "\nSetelah diurutkan untuk Binary Search\n";
    printWithIndex(sortnms);

    int kiri = 0, kanan = (int)sortnms.size() - 1;
    while (kiri <= kanan){
        int tengah = kiri + (kanan - kiri) / 2;
        if (sortnms[tengah] == target){
            cout << "Angka " << target << " ditemukan di indeks ke " << tengah << ".\n";
            return;
        }
        else if (target < sortnms[tengah]){
            kanan = tengah - 1;
        }
        else{
            kiri = tengah + 1;
        }
    }

    cout << "Angka " << target << " TIDAK ditemukan.\n";
}

void clearScreen(){
    system("cls");
}

void explain(){
    cout << "\nHow Sequential Search Work :\n";
    cout << "    Cara kerjanya sangat sederhana, yaitu memeriksa satu per satu setiap elemen dari awal hingga menemukan data yang dicari atau sampai akhir data.\n    Metode ini bisa digunakan pada data yang belum diurutkan.\n\n";
    cout << "How Binary Search Work  :\n";
    cout << "    Binary search menggunakan data yang sudah terurut. Ini dilakukan dengan membagi data menjadi dua bagian dan mencari nilai yang dicari berdasarkan nilai tengah.\n    Jika nilai belum ditemukan, pembagian dan pencarian diulangi pada bagian data yang relevan hingga nilai atau seluruh kemungkinan ditemukan.\n\n";
    cout << "Big-O Time and Space Complexity Sequential Search : \n";
    cout << "    Sequential Search bekerja dengan memeriksa elemen satu per satu secara berurutan hingga menemukan data yang dicari atau mencapai akhir data. \n    Dalam skenario terbaik, pencarian hanya membutuhkan satu langkah jika elemen yang dicari berada di posisi pertama, sehingga kompleksitas waktunya adalah O(1).\n    Namun, dalam skenario terburuk, pencarian harus memeriksa semua elemen, sehingga kompleksitas waktunya menjadi O(n).\n    Dari segi ruang, metode ini tidak memerlukan memori tambahan, sehingga kompleksitas ruangnya adalah O(1).\n\n";
    cout << "Big-O Time and Space Complexity Binary Search : \n";
    cout << "    Binary Search hanya dapat digunakan pada data yang sudah terurut. Dalam skenario terbaik, hanya diperlukan satu pemeriksaan dengan \n    kompleksitas waktu O(1) jika elemen yang dicari berada tepat di tengah data; dalam skenario terburuk, proses pencarian dilakukan \n    dengan terus membagi data menjadi dua bagian hingga elemen ditemukan atau hingga kompleksitas waktu menjadi O(log n).\n    Dalam hal penggunaan ruang, pendekatan iteratif menggunakan kompleksitas ruang O(1), sementara pendekatan rekursif menggunakan kompleksitas ruang O(n).\n\n";
    cout << "Best Usage Sequential Search :\n";
    cout << "    1.Tidak membutuhkan kondisi khusus pada data.\n    2.Bagus untuk struktur data yang sering berubah atau pencarian sekali saja.\n    3.sederhana, tapi kurang cepat jika data besar.\n\n";
    cout << "Best Usage Binary Search :\n";
    cout << "    1.Cocok untuk data besar yang sudah terurut.\n    2.Efektif untuk pencarian berulang pada data terurut.\n    3.Lebih cepat dan efisien, terutama pada data besar.\n";
}

int main(){
    int opt, target;
    do{
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt){
        case 1:{
            vector<int> nums(100);
            mt19937_64 rng(random_device{}());
            uniform_int_distribution<int> dist(1, 50);

            for (auto &val : nums){
                val = (dist(rng));
            }

            cout << "\nDaftar 100 angka acak : \n";
            cout << "angka : {index}\n\n";
            printWithIndex(nums);

            cout << "Masukkan angka yang ingin dicari: ";
            cin >> target;

            sequentialSearch(nums, target);
            break;
        }

        case 2:{
            int size;
            cout << "Masukkan ukuran vector: ";
            cin >> size;

            vector<int> nums(size);
            mt19937_64 rng(random_device{}());
            uniform_int_distribution<int> dist(1, 100);

            for (auto &val : nums){
                val = dist(rng);
            }

            cout << "\nDaftar angka acak : \n";
            cout << "angka : {index}\n\n";
            printWithIndex(nums);

            cout << "Masukkan angka yang ingin dicari: ";
            cin >> target;

            binarySearch(nums, target);
            break;
        }

        case 3:
            explain();
            break;

        case 4:
            cout << "\nTERIMA KASIH\n";
            cout << "Programme was made by Muhammad Nafis Putra (2410817210021)" << endl;
            break;

        default:
            cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
            break;
        }

        if (opt != 4){
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

   return 0;
} 