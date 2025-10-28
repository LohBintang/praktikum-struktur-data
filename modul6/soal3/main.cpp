#include "Doublylist.h"
#include <iostream>
using namespace std;

address searchByNomor(List L, string nomor) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info.nomor == nomor) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

int main() {
    List L;
    createList(L);
    infotype x;

    for (int i = 0; i < 3; i++) {
        cout << "Masukkan nomor: ";
        cin >> x.nomor;
        cout << "Masukkan warna: ";
        cin >> x.warna;
        cout << "Masukkan tahun: ";
        cin >> x.tahun;

        insertLast(L, alokasi(x));
        cout << endl;
    }

    cout << "\nData awal:\n";
    printInfo(L);

    string hapusNomor;
    cout << "\nMasukkan nomor kendaraan yang ingin dihapus: ";
    cin >> hapusNomor;

    address target = searchByNomor(L, hapusNomor);
    address P = nullptr;

    if (target == nullptr) {
        cout << "\nData dengan nomor '" << hapusNomor << "' tidak ditemukan.\n";
    } else {
        if (target == L.first) {
            deleteFirst(L, P);
        }
        else if (target == L.last) {
            deleteLast(L, P);
        }
        else {
            address prec = target->prev;
            deleteAfter(L, prec, P);
        }

        cout << "\nData dengan nomor '" << hapusNomor << "' telah dihapus.\n";
        delete P;
    }

    cout << "\nData setelah penghapusan:\n";
    printInfo(L);

    return 0;
}
