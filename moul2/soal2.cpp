#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah elemen array: ";
    cin >> N;

    int *arr = new int[N];
    int *ptr = arr;

    cout << "Masukkan " << N << " bilangan:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    int jumlah = 0, maks = *ptr, min = *ptr;

    for (int i = 0; i < N; i++) {
        int val = *(ptr + i);
        jumlah += val;
        if (val > maks) maks = val;
        if (val < min) min = val;
    }

    cout << "\nHasil Perhitungan:" << endl;
    cout << "Jumlah = " << jumlah << endl;
    cout << "Nilai Maksimum = " << maks << endl;
    cout << "Nilai Minimum = " << min << endl;

    delete[] arr; // hapus alokasi memori
    return 0;
}
