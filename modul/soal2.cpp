#include <iostream>
using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan",
                   "sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas",
                   "enam belas","tujuh belas","delapan belas","sembilan belas"};

string puluhan[] = {"","","dua puluh","tiga puluh","empat puluh","lima puluh",
                    "enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 20) cout << satuan[n];
    else if (n < 100) {
        cout << puluhan[n/10];
        if (n % 10 != 0) cout << " " << satuan[n%10];
    }
    else if (n == 100) cout << "seratus";
    else cout << "di luar jangkauan";

    return 0;
}
