#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string nama[5];
    float nilai[5][3];
    float rata[5];
    int terbaik = 0;

    cout << "=== Input Data Nilai Mahasiswa ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nNama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];
        float total = 0;
        for (int j = 0; j < 3; j++) {
            cout << "Nilai mata kuliah ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }
        rata[i] = total / 3;
    }

    for (int i = 1; i < 5; i++) {
        if (rata[i] > rata[terbaik]) {
            terbaik = i;
        }
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===" << endl;
    cout << left << setw(12) << "Nama" 
         << setw(10) << "MK1"
         << setw(10) << "MK2"
         << setw(10) << "MK3"
         << setw(10) << "Rata-rata"
         << "Keterangan" << endl;

    for (int i = 0; i < 5; i++) {
        cout << left << setw(12) << nama[i];
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << nilai[i][j];
        }
        cout << setw(10) << rata[i];
        if (i == terbaik) cout << " <- Terbaik";
        cout << endl;
    }

    return 0;
}
