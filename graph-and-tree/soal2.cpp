#include <iostream>
#include <vector>

int main() {
    int jumlahVertex;
    if (!(std::cin >> jumlahVertex)) return 0;

    std::vector<char> daftarVertex(jumlahVertex);
    for (int i = 0; i < jumlahVertex; i++) {
        std::cin >> daftarVertex[i];
    }

    std::vector<std::vector<int>> matriksBobot(jumlahVertex, std::vector<int>(jumlahVertex));
    for (int i = 0; i < jumlahVertex; i++) {
        for (int j = 0; j < jumlahVertex; j++) {
            std::cin >> matriksBobot[i][j];
        }
    }

    std::cout << "Adjacency List:" << std::endl;

    for (int i = 0; i < jumlahVertex; i++) {
        std::cout << daftarVertex[i] << " -> ";

        bool terdapatEdge = false;

        for (int j = 0; j < jumlahVertex; j++) {
            if (matriksBobot[i][j] > 0) {
                if (terdapatEdge) std::cout << ", ";
                std::cout << "(" << daftarVertex[j] << "," << matriksBobot[i][j] << ")";
                terdapatEdge = true;
            }
        }

        if (!terdapatEdge) {
            std::cout << "-";
        }

        std::cout << std::endl;
    }

    return 0;
}