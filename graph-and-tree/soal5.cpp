#include <iostream>
#include <string>
#include "RedBlackTree.h"

using namespace std;

void preOrder(const RedBlackTree::Node* simpul, const RedBlackTree::Node* nil) {
    if (simpul == nil) return;

    cout << simpul->key << " ";
    preOrder(simpul->left, nil);
    preOrder(simpul->right, nil);
}

void inOrder(const RedBlackTree::Node* simpul, const RedBlackTree::Node* nil) {
    if (simpul == nil) return;

    inOrder(simpul->left, nil);
    cout << simpul->key << " ";
    inOrder(simpul->right, nil);
}

void postOrder(const RedBlackTree::Node* simpul, const RedBlackTree::Node* nil) {
    if (simpul == nil) return;

    postOrder(simpul->left, nil);
    postOrder(simpul->right, nil);
    cout << simpul->key << " ";
}

int main() {
    int banyakData;
    cin >> banyakData;

    RedBlackTree tree;

    for (int i = 0; i < banyakData; i++) {
        int angka;
        cin >> angka;

        if (!tree.contains(angka)) {
            tree.insert(angka);
        }
    }

    if (tree.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan.";
        return 0;
    }

    int banyakQuery;
    cin >> banyakQuery;

    string daftarQuery[20];

    for (int i = 0; i < banyakQuery; i++) {
        cin >> daftarQuery[i];
    }

    for (int i = 0; i < banyakQuery; i++) {
        if (daftarQuery[i] == "PREORDER") {
            cout << "[Preorder]: ";
            preOrder(tree.root(), tree.nil());
            cout << endl;
        } 
        else if (daftarQuery[i] == "INORDER") {
            cout << "[Inorder]: ";
            inOrder(tree.root(), tree.nil());
            cout << endl;
        } 
        else if (daftarQuery[i] == "POSTORDER") {
            cout << "[Postorder]: ";
            postOrder(tree.root(), tree.nil());
            cout << endl;
        } 
        else if (daftarQuery[i] == "ALL") {
            cout << "[Preorder]: ";
            preOrder(tree.root(), tree.nil());
            cout << endl;

            cout << "[Inorder]: ";
            inOrder(tree.root(), tree.nil());
            cout << endl;

            cout << "[Postorder]: ";
            postOrder(tree.root(), tree.nil());
            cout << endl;
        }
    }

    return 0;
}