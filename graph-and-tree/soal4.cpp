#include <iostream>

using namespace std;

int baris, kolom;
int grid[7][7];
bool cek[7][7];
int tBaris, tKolom;
int jalur = 0;

int keBaris[] = {-1, 1, 0, 0};
int keKolom[] = {0, 0, -1, 1};

void cari(int b, int k) {
    if (b == tBaris && k == tKolom) {
        jalur++;
        return;
    }

    cek[b][k] = true;

    for (int i = 0; i < 4; i++) {
        int bBaru = b + keBaris[i];
        int kBaru = k + keKolom[i];

        if (bBaru >= 0 && bBaru < baris &&
            kBaru >= 0 && kBaru < kolom &&
            grid[bBaru][kBaru] == 0 &&
            !cek[bBaru][kBaru]) {
            cari(bBaru, kBaru);
        }
    }

    cek[b][k] = false;
}

int main() {
    if (!(cin >> baris >> kolom)) return 0;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cin >> grid[i][j];
            cek[i][j] = false;
        }
    }

    int bAwal, kAwal;
    cin >> bAwal >> kAwal >> tBaris >> tKolom;

    cari(bAwal, kAwal);

    cout << jalur;

    return 0;
}