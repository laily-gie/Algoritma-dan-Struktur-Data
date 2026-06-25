#include "single_linked_list.h"
#include <iostream>

int main() {
    int jumlah_batu;
    long long jarak, jarak_awal;
    if (!(std::cin >> jumlah_batu >> jarak)) return 0;
    jarak_awal = jarak;

    SingleLinkedList list;
    list.init();
    for (int i = 0; i < jumlah_batu; i++) {
        int nilai;
        std::cin >> nilai;
        list.add_back(nilai);
    }

    int indeks_sekarang = 0; 

    while (list.size > 1) {    
        int indeks_target = (indeks_sekarang + jarak - 1) % list.size;
        
        int nilai_hancur = list.get(indeks_target);
        list.delete_idx(indeks_target);

        if (nilai_hancur % 2 == 0) jarak++;
        else jarak--;

        if (jarak <= 0) jarak = jarak_awal;

        indeks_sekarang = indeks_target;
        if (list.size > 0) indeks_sekarang %= list.size;
    }

    std::cout << list.get(0) << std::endl;
    list.clear();
    return 0;
}