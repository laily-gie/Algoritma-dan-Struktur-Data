#include "double_linked_list.h"
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, R;
    if (!(std::cin >> N >> R)) return 0;

    DoubleLinkedList list_dimensi;
    list_dimensi.init();

    for (int i = 0; i < N; i++) {
        char c;
        std::cin >> c;
        list_dimensi.add_back(c);
    }

    if (list_dimensi.is_empty()) {
        std::cout << "EMPTY" << std::endl;
        return 0;
    }

    Node* pAlpha = list_dimensi.head;
    Node* pBeta = list_dimensi.tail;

    for (int ronde = 0; ronde < R; ronde++) {
        long long X, Y;
        if (!(std::cin >> X >> Y)) break;
        if (list_dimensi.size == 0) break;

        long long stepA = X % list_dimensi.size;
        for (long long j = 0; j < stepA; j++) {
            pAlpha = pAlpha->next;
        }

        long long stepB = Y % list_dimensi.size;
        for (long long j = 0; j < stepB; j++) {
            pBeta = pBeta->prev;
        }

        if (pAlpha == pBeta) {
            Node* hancur = pAlpha;
            Node* nxtA = hancur->next;
            Node* prvB = hancur->prev;

            if (list_dimensi.size == 1) {
                list_dimensi.delete_idx(0);
                pAlpha = pBeta = nullptr;
                break;
            } else {
                int target_idx = 0;
                Node* temp = list_dimensi.head;
                while (temp != hancur) {
                    temp = temp->next;
                    target_idx++;
                }

                list_dimensi.delete_idx(target_idx);
                pAlpha = nxtA;
                pBeta = prvB;
            }
        } 
        else if (pAlpha->next == pBeta) {
            char temp_val = pAlpha->data;
            pAlpha->data = pBeta->data;
            pBeta->data = temp_val;
        }
        else if (pAlpha->prev == pBeta) {
            char temp_val = pAlpha->data;
            pAlpha->data = pBeta->data;
            pBeta->data = temp_val;
        }
    }

    if (list_dimensi.size == 0) {
        std::cout << "EMPTY" << std::endl;
    } else {
        list_dimensi.display();
    }

    list_dimensi.clear();
    return 0;
}