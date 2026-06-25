#include "single_linked_list.h"
#include <iostream>
#include <stdexcept> 

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return size == 0;
}

void SingleLinkedList::add_front(int val) {
    Node* new_node = new Node{val, head};
    if (is_empty()) {
        head = tail = new_node;
        new_node->next = head; 
    } else {
        head = new_node;
        tail->next = head; 
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    if (is_empty()) {
        add_front(val);
        return;
    }
    Node* new_node = new Node{val, head}; 
    tail->next = new_node;
    tail = new_node;
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) throw std::out_of_range("Indeks melebihi batas"); 
    
    if (idx == 0) return add_front(val);
    if (idx == size) return add_back(val);

    Node* ptr_now = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_now = ptr_now->next;
    }
    Node* new_node = new Node{val, ptr_now->next};
    ptr_now->next = new_node;
    size++;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) throw std::runtime_error("List kosong");
    
    Node* ptr_delete = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        tail->next = head; 
    }
    delete ptr_delete;
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) throw std::runtime_error("List kosong");
    if (size == 1) return delete_front();

    Node* ptr_now = head;
    while (ptr_now->next != tail) {
        ptr_now = ptr_now->next;
    }
    delete tail;
    tail = ptr_now;
    tail->next = head; 
    size--;
}

void SingleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Indeks melebihi batas");
    if (idx == 0) return delete_front();
    if (idx == size - 1) return delete_back();

    Node* ptr_prev = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_prev = ptr_prev->next;
    }
    Node* ptr_delete = ptr_prev->next;
    ptr_prev->next = ptr_delete->next;
    delete ptr_delete;
    size--;
}

int SingleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size) throw std::out_of_range("Indeks melebihi batas");
    
    Node* ptr_now = head;
    for (int i = 0; i < idx; i++) {
        ptr_now = ptr_now->next;
    }
    return ptr_now->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (is_empty() || idx < 0 || idx >= size) throw std::out_of_range("Index out of range");
    
    Node* ptr_now = head;
    for (int i = 0; i < idx; i++) {
        ptr_now = ptr_now->next;
    }
    ptr_now->data = val;
}

void SingleLinkedList::display() {
    if (is_empty()) return;
    Node* ptr_now = head;
    for (int i = 0; i < size; i++) {
        std::cout << ptr_now->data << " ";
        ptr_now = ptr_now->next;
    }
    std::cout << std::endl;
}

void SingleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}