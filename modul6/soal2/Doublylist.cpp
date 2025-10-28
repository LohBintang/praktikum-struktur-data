#include "Doublylist.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.tahun << endl;
        P = P->next;
    }
}

address searchByNopol(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            cout << "Nomor Polisi  : " << P->info.nopol << endl;
            cout << "Warna         : " << P->info.warna << endl;
            cout << "Tahun         : " << P->info.tahun << endl;
            return P;
        }
        P = P->next;
    }
    cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan." << endl;
    return NULL;
}
