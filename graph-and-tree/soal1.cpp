#include <iostream>
#include <vector>
#include <map>

int main() {
    int jumlahVertex, jumlahEdge;
    std::cin >> jumlahVertex;

    std::vector<char> daftarVertex(jumlahVertex);
    std::map<char, int> petaIndeks;

    for (int i = 0; i < jumlahVertex; ++i) {
        std::cin >> daftarVertex[i];
        petaIndeks[daftarVertex[i]] = i;
    }

    std::vector<std::vector<int>> matriksBobot(jumlahVertex, std::vector<int>(jumlahVertex, 0));
    std::cin >> jumlahEdge;

    for (int i = 0; i < jumlahEdge; ++i) {
        char vertexU, vertexV; 
        int bobot;
        std::cin >> vertexU >> vertexV >> bobot;
        matriksBobot[petaIndeks[vertexU]][petaIndeks[vertexV]] = bobot;
    }

    std::cout << "Adjacency Matrix:" << std::endl;
    std::cout << " ";
    for (int i = 0; i < jumlahVertex; ++i) {
        std::cout << " " << daftarVertex[i];
    }
    
    std::cout << std::endl;
    for (int i = 0; i < jumlahVertex; ++i) {
        std::cout << daftarVertex[i];
        for (int j = 0; j < jumlahVertex; ++j) {
            std::cout << " " << matriksBobot[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}