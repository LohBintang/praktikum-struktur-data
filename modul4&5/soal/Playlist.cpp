#include "Playlist.h"

Playlist::Playlist() {
    head = nullptr;
}

Playlist::~Playlist() {
    Lagu* current = head;
    while (current != nullptr) {
        Lagu* temp = current;
        current = current->next;
        delete temp;
    }
}

void Playlist::tambahAwal(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, head};
    head = baru;
    cout << "Lagu \"" << judul << "\" berhasil ditambahkan di awal playlist.\n";
}

void Playlist::tambahAkhir(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Lagu* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = baru;
    }
    cout << "Lagu \"" << judul << "\" berhasil ditambahkan di akhir playlist.\n";
}

void Playlist::tambahSetelahKe3(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, nullptr};
    Lagu* current = head;
    int posisi = 1;

    while (current != nullptr && posisi < 3) {
        current = current->next;
        posisi++;
    }

    if (current == nullptr) {
        cout << "Playlist kurang dari 3 lagu. Lagu ditambahkan di akhir.\n";
        tambahAkhir(judul, penyanyi, durasi);
    } else {
        baru->next = current->next;
        current->next = baru;
        cout << "Lagu \"" << judul << "\" berhasil ditambahkan setelah lagu ke-3.\n";
    }
}

void Playlist::hapusBerdasarkanJudul(string judul) {
    if (head == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    Lagu* current = head;
    Lagu* prev = nullptr;

    while (current != nullptr && current->judul != judul) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Lagu dengan judul \"" << judul << "\" tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
}

void Playlist::tampilkan() {
    if (head == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    cout << "\n=== Daftar Lagu dalam Playlist ===\n";
    Lagu* current = head;
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". Judul  : " << current->judul << endl;
        cout << "   Penyanyi : " << current->penyanyi << endl;
        cout << "   Durasi   : " << current->durasi << " menit\n";
        current = current->next;
    }
    cout << "==================================\n";
}
