#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    infotype x;

    for (int i = 0; i < 4; i++) {  
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.tahun;

        address P = searchByNopol(L, x.nopol);
        if (P != NULL) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertFirst(L, alokasi(x)); 
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
