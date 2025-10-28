#include "Doublylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
    while (P != nullptr) {
        cout << "Nomor : " << P->info.nomor << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.tahun << endl;
        cout << endl;
        P = P->next;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }

    P = L.first;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }

    P = L.last;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = P->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr) {
        P->next->prev = Prec;
    } else {
        L.last = Prec;
    }
    P->next = nullptr;
    P->prev = nullptr;
}
