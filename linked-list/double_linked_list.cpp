#include "double_linked_list.h"
#include <iostream>
#include <stdexcept>

void DoubleLinkedList::init() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

bool DoubleLinkedList::is_empty() {
    return this->size == 0;
}

void DoubleLinkedList::add_front(char karakter) {
    if (is_empty()) {
        Node* ptr_new = new Node{karakter, nullptr, nullptr};
        this->head = this->tail = ptr_new;
        this->head->next = this->head;
        this->head->prev = this->head;
    } else {
        Node* ptr_new = new Node{karakter, this->head, this->tail};
        this->head->prev = ptr_new;
        this->tail->next = ptr_new; 
        this->head = ptr_new;
    }
    this->size++;
}

void DoubleLinkedList::add_back(char karakter) {
    if (is_empty()) {
        add_front(karakter);
        return;
    }
    Node* ptr_new = new Node{karakter, this->head, this->tail};
    this->tail->next = ptr_new;
    this->head->prev = ptr_new; 
    this->tail = ptr_new;
    this->size++;
}

void DoubleLinkedList::add_idx(char karakter, int idx_target) {
    if (idx_target < 0 || idx_target > this->size) 
        throw std::out_of_range("Index melebihi batas");

    if (idx_target == 0) {
        add_front(karakter);
        return;
    }
    if (idx_target == this->size) {
        add_back(karakter);
        return;
    }

    Node* ptr_bantu = this->head;
    for (int i = 0; i < idx_target; i++) ptr_bantu = ptr_bantu->next;
    
    Node* ptr_baru = new Node{karakter, ptr_bantu, ptr_bantu->prev};
    ptr_bantu->prev->next = ptr_baru;
    ptr_bantu->prev = ptr_baru;
    this->size++;
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) throw std::runtime_error("List kosong");

    Node* ptr_delete = this->head;
    if (this->size == 1) {
        this->head = this->tail = nullptr;
    } else {
        this->head = this->head->next;
        this->head->prev = this->tail; 
        this->tail->next = this->head; 
    }
    delete ptr_delete;
    this->size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) throw std::runtime_error("List kosong");
    if (this->size == 1) {
        delete_front();
        return;
    }

    Node* ptr_delete = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = this->head; 
    this->head->prev = this->tail; 
    
    delete ptr_delete;
    this->size--;
}

void DoubleLinkedList::delete_idx(int idx_target) {
    if (idx_target < 0 || idx_target >= this->size) 
        throw std::out_of_range("Indeks melebihi batas");

    if (idx_target == 0) {
        delete_front();
        return;
    }
    if (idx_target == this->size - 1) {
        delete_back();
        return;
    }

    Node* ptr_delete = this->head;
    for (int i = 0; i < idx_target; i++) ptr_delete = ptr_delete->next;

    ptr_delete->prev->next = ptr_delete->next;
    ptr_delete->next->prev = ptr_delete->prev;
    delete ptr_delete;
    this->size--;
}

void DoubleLinkedList::display() {
    if (is_empty()) return;
    Node* ptr_now = this->head;
    for (int i = 0; i < this->size; i++) {
        std::cout << ptr_now->data;
        ptr_now = ptr_now = ptr_now->next;
    }
    std::cout << std::endl;
}

char DoubleLinkedList::get(int idx_target) {
    if (idx_target < 0 || idx_target >= this->size) 
        throw std::out_of_range("Index melebihi batas");
    
    Node* ptr_now = this->head;
    for (int i = 0; i < idx_target; i++) ptr_now = ptr_now->next;
    return ptr_now->data;
}

void DoubleLinkedList::set(char karakter, int idx_target) {
    if (idx_target < 0 || idx_target >= this->size) 
        throw std::out_of_range("Index melebihi batas");
    
    Node* ptr_now = this->head;
    for (int i = 0; i < idx_target; i++) ptr_now = ptr_now->next;
    ptr_now->data = karakter;
}

void DoubleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}