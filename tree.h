#ifndef tree_H
#define tree_H

#include <iostream>

#define CNT 10

using namespace std;

/* struktur tree */
typedef struct tree_element *tree_address;
typedef struct tree_element {
    char character;
    int frequency;
    tree_address left, right;
} tree_node;

typedef struct tree {
    tree_address root;
} binary_tree;

/* fungsi untuk melakukan alokasi tree */
tree_address allocateTree(char, int);

/* mencek apakah tree kosong */
bool isTreeEmpty(binary_tree);

/* prosedur untuk membuat struktur dari binary tree */
void printBinaryTree(tree_address, int);

/* fungsi untuk mengubah dari struktur Binary menjadi sebuah bit (encode) */
tree_address binaryToBit(tree_address, string, char, string *);

/* prosedur untuk mengubah dari bit menjadi sebuah karakter yang bisa dibaca (decode) dan menampilkannya */
void bitToCharacter(tree_address, string);

#endif
