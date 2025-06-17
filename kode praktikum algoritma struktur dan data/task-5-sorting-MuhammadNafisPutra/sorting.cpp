#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <conio.h>
#include <iomanip> 

using namespace std;

string NAMA, NIM;


void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << fixed << setprecision(10);
    cout << sortName << "\ntook " << duration.count() << " seconds\n";
}

void insertionSort() {
    string data = NAMA;
    for (size_t i = 1; i < data.length(); ++i) {
        char key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
    cout << "Hasil Insertion sort: " << data << endl;
}

void merge(string& s, int l, int m, int r) {
    string K(s.begin() + l, s.begin() + m + 1);
    string T(s.begin() + m + 1, s.begin() + r + 1);
    size_t i = 0, j = 0, k = l;
    while (i < K.size() && j < T.size()) s[k++] = (K[i] <= T[j] ? K[i++] : T[j++]);
    while (i < K.size()) s[k++] = K[i++];
    while (j < T.size()) s[k++] = T[j++];
}

void mergeSortHelper(string& s, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortHelper(s, l, m);
        mergeSortHelper(s, m + 1, r);
        merge(s, l, m, r);
    }
}

void mergeSort() {
    string data = NAMA;
    mergeSortHelper(data, 0, data.length() - 1);
    cout << "Hasil Merge sort: " << data << endl;
}

void shellSort() {
    string data = NAMA;
    int n = data.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
                data[j] = data[j - gap];
            data[j] = temp;
        }
    }
    cout << "Hasil Shell sort: " << data << endl;
}

void bubbleSort() {
    string data = NIM;
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i + 1 < data.length(); ++i) {
            if (data[i] > data[i + 1]) {
                swap(data[i], data[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    cout << "Hasil Bubble sort: " << data << endl;
}

int partition(string& s, int low, int high) {
    char pivot = s[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (s[j] <= pivot) {
            ++i;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void quickSortHelper(string& s, int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSortHelper(s, low, pi - 1);
        quickSortHelper(s, pi + 1, high);
    }
}

void quickSort() {
    string data = NIM;
    quickSortHelper(data, 0, data.length() - 1);
    cout << "Hasil Quick sort: " << data << endl;
}

void selectionSort() {
    string data = NIM;
    for (size_t i = 0; i < data.length() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < data.length(); ++j) {
            if (data[j] < data[min_idx])
                min_idx = j;
        }
        swap(data[i], data[min_idx]);
    }
    cout << "Hasil Selection sort: " << data << endl;
}

int main() {
    NAMA = "Muhammad Nafis Putra";
    NIM = "2410817210021";

    int pilihan;
    do {
        cout << "\n================================\n";
        cout << "|            SORTING           |\n";
        cout << "================================\n";
        cout << "| 1. Insertion Sort            |\n";
        cout << "| 2. Merge Sort                |\n";
        cout << "| 3. Shell Sort                |\n";
        cout << "| 4. Bubble Sort               |\n";
        cout << "| 5. Quick Sort                |\n";
        cout << "| 6. Selection Sort            |\n";
        cout << "| 7. Exit                      |\n";
        cout << "================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout<<"Sebelum Insertion sort : "<<NAMA <<endl;
                timeSort(insertionSort, "Insertion Sort");
                break;
            case 2:
                cout<<"Sebelum Merge sort : "<<NAMA <<endl;
                timeSort(mergeSort, "Merge Sort");
                break;
            case 3:
                cout<<"Sebelum Shell sort : "<<NAMA <<endl;
                timeSort(shellSort, "Shell Sort");
                break;
            case 4:
                cout<<"Sebelum Bubble sort : "<<NIM <<endl;
                timeSort(bubbleSort, "Bubble Sort");
                break;
            case 5:
                cout<<"Sebelum Quick sort : "<<NIM <<endl;
                timeSort(quickSort, "Quick Sort");
                break;
            case 6:
                cout<<"Sebelum Selection sort : "<<NIM <<endl;
                timeSort(selectionSort, "Selection Sort");
                break;
            case 7:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");

    } while (pilihan != 7);
    return 0;
}