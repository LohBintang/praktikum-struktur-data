#include "circularlist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        P->next = P; 
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        P->next = L.First;
        last->next = P;
        L.First = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        insertFirst(L, P);
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        last->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
        return;
    }

    P = L.First;

    if (L.First->next == L.First) { 
        L.First = Nil;
    } else {
        address last = L.First;
        while (last->next != L.First) last = last->next;

        L.First = P->next;
        last->next = L.First;
    }

    P->next = Nil;
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == L.First) {
        P = Nil;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
        return;
    }

    if (L.First->next == L.First) {
        P = L.First;
        L.First = Nil;
    } else {
        address last = L.First;
        address before = Nil;
        while (last->next != L.First) {
            before = last;
            last = last->next;
        }
        P = last;
        before->next = L.First;
    }
    P->next = Nil;
}

address findElm(List L, infotype x) {
    if (L.First == Nil) return Nil;

    address P = L.First;
    do {
        if (P->info.nim == x.nim) return P;
        P = P->next;
    } while (P != L.First);

    return Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong" << endl;
        return;
    }

    int n = 0;
    address P = L.First;
    do {
        n++;
        P = P->next;
    } while (P != L.First);

    infotype *arr = new infotype[n];
    int i = 0;
    P = L.First;
    do {
        arr[i++] = P->info;
        P = P->next;
    } while (P != L.First);

    for (int a = 0; a < n - 1; a++) {
        for (int b = a + 1; b < n; b++) {
            if (arr[a].nim > arr[b].nim) {
                swap(arr[a], arr[b]);
            }
        }
    }

    for (int k = 0; k < n; k++) {
        cout << "Nama : " << arr[k].nama << endl;
        cout << "NIM  : " << arr[k].nim << endl;
        cout << "L/P  : " << arr[k].jenis_kelamin << endl;
        cout << "IPK  : " << arr[k].ipk << endl;
        cout << endl;
    }

    delete[] arr;
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}
