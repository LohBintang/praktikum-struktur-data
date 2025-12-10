#include <iostream>
using namespace std;
#include "multilist.h"

boolean ListEmpty(listinduk L){
    return (L.first == Nil);
}

boolean ListEmptyAnak(listanak L){
    return (L.first == Nil);
}

void CreateList(listinduk &L){
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L){
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotypeinduk X){
    address P = new elemen_list_induk;
    if(P != Nil){
        P->info = X;
        CreateListAnak(P->lanak);
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

address_anak alokasiAnak(infotypeanak X){
    address_anak P = new elemen_list_anak;
    if(P != Nil){
        P->info = X;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address P){
    delete P;
}

void dealokasiAnak(address_anak P){
    delete P;
}

address findElm(listinduk L, infotypeinduk X){
    address P = L.first;
    while(P != Nil){
        if(P->info == X) return P;
        P = P->next;
    }
    return Nil;
}

address_anak findElm(listanak L, infotypeanak X){
    address_anak P = L.first;
    while(P != Nil){
        if(P->info == X) return P;
        P = P->next;
    }
    return Nil;
}

boolean fFindElm(listinduk L, address P){
    address Q = L.first;
    while(Q != Nil){
        if(Q == P) return true;
        Q = Q->next;
    }
    return false;
}

boolean fFindElmanak(listanak L, address_anak P){
    address_anak Q = L.first;
    while(Q != Nil){
        if(Q == P) return true;
        Q = Q->next;
    }
    return false;
}

address findBefore(listinduk L, address P){
    if(P == L.first) return Nil;
    return P->prev;
}

address_anak findBeforeAnak(listanak L, infotypeinduk X, address_anak P){
    if(P == L.first) return Nil;
    return P->prev;
}

void insertFirst(listinduk &L, address P){
    if(ListEmpty(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec){
    if(Prec != Nil){
        P->next = Prec->next;
        P->prev = Prec;
        if(Prec->next != Nil) Prec->next->prev = P;
        Prec->next = P;
        if(P->next == Nil) L.last = P;
    }
}

void insertLast(listinduk &L, address P){
    if(ListEmpty(L)){
        insertFirst(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertFirstAnak(listanak &L, address_anak P){
    if(ListEmptyAnak(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec){
    if(Prec != Nil){
        P->next = Prec->next;
        P->prev = Prec;
        if(Prec->next != Nil) Prec->next->prev = P;
        Prec->next = P;
        if(P->next == Nil) L.last = P;
    }
}

void insertLastAnak(listanak &L, address_anak P){
    if(ListEmptyAnak(L)){
        insertFirstAnak(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void delFirst(listinduk &L, address &P){
    if(!ListEmpty(L)){
        P = L.first;
        if(L.first == L.last){
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
        }
        P->next = Nil;
    }
}

void delLast(listinduk &L, address &P){
    if(!ListEmpty(L)){
        P = L.last;
        if(L.first == L.last){
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
        }
        P->prev = Nil;
    }
}

void delAfter(listinduk &L, address &P, address Prec){
    if(Prec != Nil){
        P = Prec->next;
        if(P != Nil){
            Prec->next = P->next;
            if(P->next != Nil) P->next->prev = Prec;
            else L.last = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
    }
}

void delP(listinduk &L, infotypeinduk X){
    address P = findElm(L, X);
    if(P != Nil){
        if(P == L.first){
            delFirst(L, P);
        } else if(P == L.last){
            delLast(L, P);
        } else {
            address temp;
            delAfter(L, temp, P->prev);
        }
        dealokasi(P);
    }
}

void delFirstAnak(listanak &L, address_anak &P){
    if(!ListEmptyAnak(L)){
        P = L.first;
        if(L.first == L.last){
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
        }
        P->next = Nil;
    }
}

void delLastAnak(listanak &L, address_anak &P){
    if(!ListEmptyAnak(L)){
        P = L.last;
        if(L.first == L.last){
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
        }
        P->prev = Nil;
    }
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec){
    if(Prec != Nil){
        P = Prec->next;
        if(P != Nil){
            Prec->next = P->next;
            if(P->next != Nil) P->next->prev = Prec;
            else L.last = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
    }
}

void delPAnak(listanak &L, infotypeanak X){
    address_anak P = findElm(L, X);
    if(P != Nil){
        if(P == L.first){
            delFirstAnak(L, P);
        } else if(P == L.last){
            delLastAnak(L, P);
        } else {
            address_anak temp;
            delAfterAnak(L, temp, P->prev);
        }
        dealokasiAnak(P);
    }
}

void printInfo(listinduk L){
    address P = L.first;
    while(P != Nil){
        cout << "Induk: " << P->info << " -> Anak: ";
        printInfoAnak(P->lanak);
        P = P->next;
    }
}

int nbList(listinduk L){
    int count = 0;
    address P = L.first;
    while(P != Nil){
        count++;
        P = P->next;
    }
    return count;
}

void printInfoAnak(listanak L){
    address_anak P = L.first;
    while(P != Nil){
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int nbListAnak(listanak L){
    int count = 0;
    address_anak P = L.first;
    while(P != Nil){
        count++;
        P = P->next;
    }
    return count;
}

void delAll(listinduk &L){
    address P;
    while(!ListEmpty(L)){
        delFirst(L, P);
        dealokasi(P);
    }
}
