#include <iostream>
using namespace std;
#include "multilist.h"

int main(){
    listinduk L;
    CreateList(L);

    insertLast(L, alokasi(10));
    insertLast(L, alokasi(20));
    insertLast(L, alokasi(30));

    address I = findElm(L, 20);
    if(I != Nil){
        insertLastAnak(I->lanak, alokasiAnak(101));
        insertLastAnak(I->lanak, alokasiAnak(102));
        insertLastAnak(I->lanak, alokasiAnak(103));
    }

    I = findElm(L, 10);
    if(I != Nil){
        insertLastAnak(I->lanak, alokasiAnak(111));
        insertLastAnak(I->lanak, alokasiAnak(112));
    }

    cout << "==== DATA MULTILIST ====" << endl;
    printInfo(L);

    cout << "\nJumlah induk: " << nbList(L) << endl;

    cout << "\nMenghapus induk 20..." << endl;
    delP(L, 20);

    printInfo(L);

    return 0;
}
