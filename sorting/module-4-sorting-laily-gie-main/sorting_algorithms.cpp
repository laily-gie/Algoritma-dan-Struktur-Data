#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>



using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i= 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            m.comparisons++;

            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break; 
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

   for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            m.comparisons++;

            if (data[j] < data[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(data[i], data[min_index]);
            m.swaps++;
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

   for (int i = 1; i < n; i++) {
        int temp = data[i];
        int j = i - 1;
        
        while (j >= 0) {
            m.comparisons++;
            if (data[j] > temp) {
                data[j + 1] = data[j];
                m.shifts++;
                j--;
            } else {
                break;
            }
        }
        data[j + 1] = temp;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void merge_helper(std::vector<int>& data, int kiri, int tengah, int kanan, Metrics& m) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = data[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = data[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        m.comparisons++;
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_recursive(std::vector<int>& data, int kiri, int kanan, Metrics& m) {
    m.recursive_calls++;
    if (kiri >= kanan) return;

    int tengah = kiri + (kanan - kiri) / 2;
    merge_sort_recursive(data, kiri, tengah, m);
    merge_sort_recursive(data, tengah + 1, kanan, m);
    merge_helper(data, kiri, tengah, kanan, m);
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (!data.empty()) {
        merge_sort_recursive(data, 0, data.size() - 1, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



int partition_helper(std::vector<int>& data, int bawah, int atas, Metrics& m) {
    int tengah = bawah + (atas - bawah) / 2;
    
    if (tengah != atas) {
        std::swap(data[tengah], data[atas]);
        m.swaps++; 
    }

    int pivot = data[atas];
    int i = bawah - 1;
 
    for (int j = bawah; j < atas; j++) {
        m.comparisons++;
        if (data[j] < pivot) {
            i++;
            if (i != j) {
                std::swap(data[i], data[j]);
                m.swaps++;
            }
        }
    }
    
    if (i + 1 != atas) {
        std::swap(data[i + 1], data[atas]);
        m.swaps++;
    }
    
    return i + 1;
}

void quick_sort_recursive(std::vector<int>& data, int bawah, int atas, Metrics& m) {
    m.recursive_calls++;
    if (bawah < atas) {
        int pi = partition_helper(data, bawah, atas, m);
        quick_sort_recursive(data, bawah, pi - 1, m);
        quick_sort_recursive(data, pi + 1, atas, m);
    }
}

void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (!data.empty()) {
        quick_sort_recursive(data, 0, data.size() - 1, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void counting_sort_for_radix(std::vector<int>& data, int exp, Metrics& m) {
    int n = data.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (data[i] / exp) % 10;
        count[digit]++;
        m.array_accesses++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        m.array_accesses++; 
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (data[i] / exp) % 10;
        output[count[digit] - 1] = data[i];
        count[digit]--;
        m.array_accesses += 2; 
    }

    for (int i = 0; i < n; i++) {
        data[i] = output[i];
    }
}

void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

   int max_val = data[0];
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_for_radix(data, exp, m);
    }
    
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}