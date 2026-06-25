#include "queue.h"
#include <iostream>

int main() {
    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    int A[100];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;

        for (int j = i; j < i + k; j++) {
            sum += A[j];
        }
        std::cout << sum << (i == n - k ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}