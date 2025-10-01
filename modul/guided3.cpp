#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;

};

int main()
{
    Mahasiswa mhs;
    mhs.nama = "bintang";
    mhs.NIM = "103133333324";
    
    cout << "Nama: " << mhs.nama << endl
         << "NIM : " << mhs.NIM;
}
