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
    //mhs.nama = "bintang";
    //mhs.NIM = "103133333324";
    cout << "Nama : ";
    getline(cin, mhs.nama);
    cout << "NIM : ";
    cin >> mhs.NIM;
    
    cout << "Nama: " << mhs.nama << endl
         << "NIM : " << mhs.NIM;
}
