#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[10];
string dataBaru;

void initCH();
void initCHT();
int isEmptyCH();
int isEmptyCHT();

void tambahDepanCH();
void tambahDepanCHT();
void tambahBelakangCH();
void tambahBelakangCHT();
void hapusDepanCH();
void hapusDepanCHT();
void hapusBelakangCH();
void hapusBelakangCHT();
void tampilkanCH();
void tampilkanCHT();
void clearCH();
void clearCHT();

int main() {
menu:
    cout << "Double Linked List Circular (DLLC)" << endl;
    cout << "Silahkan pilih program DLLC yang ingin dijalankan!" << endl;
    cout << "1. DLLC dengan Head" << endl;
    cout << "2. DLLC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if(menu == 1) {
        initCH();
        do {
            cout << "Double Linked List Circular (DLLC) (Head)" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pil;
            pil = atoi(pilihan);

            switch(pil) {
                case 1: tambahDepanCH(); break;
                case 2: tambahBelakangCH(); break;
                case 3: tampilkanCH(); break;
                case 4: hapusDepanCH(); break;
                case 5: hapusBelakangCH(); break;
                case 6: clearCH(); break;
                default: system("cls"); goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");

        } while(pil < 7);

    } else if(menu == 2) {
        initCHT();
        do {
            cout << "Double Linked List Circular (DLLC) (Head dan Tail)" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pil;

            switch(pil) {
                case 1: tambahDepanCHT(); break;
                case 2: tambahBelakangCHT(); break;
                case 3: tampilkanCHT(); break;
                case 4: hapusDepanCHT(); break;
                case 5: hapusBelakangCHT(); break;
                case 6: clearCHT(); break;
                default: system("cls"); goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");

        } while(pil < 7);

    } else {
        cout << "\nTERIMA KASIH" << endl;
    }
}

void initCH() { head = NULL; }
int isEmptyCH() { return head == NULL; }

void tambahDepanCH() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode{dataBaru, NULL, NULL};
    if (isEmptyCH()) {
        head = baru;
        head->next = head;
        head->prev = head;
    } else {
        TNode *last = head->prev;
        baru->next = head;
        baru->prev = last;
        head->prev = baru;
        last->next = baru;
        head = baru;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakangCH() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode{dataBaru, NULL, NULL};
    if (isEmptyCH()) {
        head = baru;
        head->next = head;
        head->prev = head;
    } else {
        TNode *last = head->prev;
        baru->next = head;
        baru->prev = last;
        last->next = baru;
        head->prev = baru;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void tampilkanCH() {
    if (isEmptyCH()) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    TNode *bantu = head;
    do {
        cout << bantu->data << " ";
        bantu = bantu->next;
    } while (bantu != head);
    cout << endl;
}

void hapusDepanCH() {
    if (isEmptyCH()) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    string data = head->data;
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        TNode *last = head->prev;
        TNode *hapus = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        delete hapus;
    }
    cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
}

void hapusBelakangCH() {
    if (isEmptyCH()) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    TNode *hapus = head->prev;
    string data = hapus->data;
    if (hapus == head) {
        delete head;
        head = NULL;
    } else {
        TNode *sebelum = hapus->prev;
        sebelum->next = head;
        head->prev = sebelum;
        delete hapus;
    }
    cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus." << endl;
}

void clearCH() {
    while (!isEmptyCH()) {
        hapusDepanCH();
    }
    cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
}

void initCHT() { head = tail = NULL; }
int isEmptyCHT() { return head == NULL && tail == NULL; }

void tambahDepanCHT() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode{dataBaru, NULL, NULL};
    if (isEmptyCHT()) {
        head = tail = baru;
        head->next = head->prev = head;
    } else {
        baru->next = head;
        baru->prev = tail;
        head->prev = baru;
        tail->next = baru;
        head = baru;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakangCHT() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode{dataBaru, NULL, NULL};
    if (isEmptyCHT()) {
        head = tail = baru;
        tail->next = tail->prev = tail;
    } else {
        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        head->prev = baru;
        tail = baru;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void tampilkanCHT() {
    if (isEmptyCHT()) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    TNode *bantu = head;
    do {
        cout << bantu->data << " ";
        bantu = bantu->next;
    } while (bantu != head);
    cout << endl;
}

void hapusDepanCHT() {
    if (isEmptyCHT()) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    string data = head->data;
    if (head == tail) {
        delete head;
        head = tail = NULL;
    } else {
        TNode *hapus = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete hapus;
    }
    cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
}

void hapusBelakangCHT() {
    if (isEmptyCHT()) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    string data = tail->data;
    if (head == tail) {
        delete tail;
        head = tail = NULL;
    } else {
        TNode *hapus = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete hapus;
    }
    cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus." << endl;
}

void clearCHT() {
    while (!isEmptyCHT()) {
        hapusDepanCHT();
    }
    cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
}
