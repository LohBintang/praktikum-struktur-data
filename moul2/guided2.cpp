#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai[MAX]; // array 1 dimensi
    static int nilai_tahun[MAX][MAX] = {//array
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };
    //input data array 1 dimensi
    cout << "=== Input nilai Siswa ===\n";
    for ( i = 0; i < MAX; i++){
        cout << "masukkan nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }
    
    // manampilkan isi array 1 dimensi
    cout << "\n=== Data Nilai Siswa ===\n";
    for (i = 0; i < MAX; i++){
        cout << "Nilai ke-" << i + 1 << " = "
        << nilai[i]
        << endl;
    }
    
    // manampilkan isi array 2 dimensi
    cout << "\n=== Data   Tahunan  ===\n";
    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            cout << nilai_tahun[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}