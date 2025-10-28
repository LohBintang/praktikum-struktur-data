#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    infotype x;

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.tahun;

        address P = searchByNopol(L, x.nopol);
        if (P != NULL) {
            cout << "Nomor polisi sudah terdaftar!" << endl;
        } else {
            insertFirst(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    cout << "\nMasukkan Nomor Polisi yang ingin dicari: ";
    string cari;
    cin >> cari;
    findElm(L, cari);

    return 0;
}
