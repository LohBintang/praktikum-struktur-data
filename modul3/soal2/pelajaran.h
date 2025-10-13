#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string namaMapel;
    string kodeMapel;
} pelajaran;

pelajaran create_pelajaran(string namaMapel, string kodeMapel);

void tampil_pelajaran(pelajaran pel);

#endif
