#include <iostream>
#include <vector>
#include <queue>

struct point { 
    int baris, kolom, jarak; 
};

int main() {
    int jumlahBaris, jumlahKolom; 
    std::cin >> jumlahBaris >> jumlahKolom;

    std::vector<std::vector<int>> grid(jumlahBaris, std::vector<int>(jumlahKolom));
    for(int i = 0; i < jumlahBaris; ++i) {
        for(int j = 0; j < jumlahKolom; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int startBaris, startKolom, finishBaris, finishKolom; 
    std::cin >> startBaris >> startKolom >> finishBaris >> finishKolom;

    std::queue<point> antrian; 
    antrian.push({startBaris, startKolom, 0});
    grid[startBaris][startKolom] = 1;

    int arahBaris[] = {-1, 1, 0, 0};
    int arahKolom[] = {0, 0, -1, 1};
    
    bool ditemukan = false;
    while(!antrian.empty()) {
        point saatIni = antrian.front(); 
        antrian.pop();

        if(saatIni.baris == finishBaris && saatIni.kolom == finishKolom) { 
            std::cout << saatIni.jarak; 
            ditemukan = true;
            break; 
        }

        for(int i = 0; i < 4; ++i) {
            int barisBaru = saatIni.baris + arahBaris[i]; 
            int kolomBaru = saatIni.kolom + arahKolom[i];

            if(barisBaru >= 0 && barisBaru < jumlahBaris && kolomBaru >= 0 && kolomBaru < jumlahKolom && grid[barisBaru][kolomBaru] == 0) {
                grid[barisBaru][kolomBaru] = 1; 
                antrian.push({barisBaru, kolomBaru, saatIni.jarak + 1});
            }
        }
    }

    if(!ditemukan) {
        std::cout << -1;
    }

    return 0;
}