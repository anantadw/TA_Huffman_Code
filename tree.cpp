#include "tree.h"

/* fungsi untuk melakukan alokasi tree */
tree_address allocateTree(char character, int frequency) {
    tree_address node;

    node = (tree_address) malloc(sizeof(tree_element));
    if (node != NULL) {
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

/* mencek apakah tree kosong */
bool isTreeEmpty(binary_tree t) {
	return t.root == NULL;
}

/* prosedur untuk membuat struktur dari binary tree */
void printBinaryTree(tree_address node, int space) {
    if (node == NULL)
        return;
 
    // tambah jarak antara level
    space += CNT;
 
    // proses node kanan terlebih dahulu
    printBinaryTree(node->right, space);
 
    // print current node setelah space
    // count
    cout << "\n";

    for (int i = CNT; i < space; i++) {
		cout << " ";
	}
	
	if (node->character == '\0') {
		cout << node->frequency << endl;	
	} else {
		cout << node->character << endl;
	}
    
    // proses node kiri
    printBinaryTree(node->left, space);
}

/* fungsi untuk mengubah dari struktur binary menjadi sebuah bit (encode) */
tree_address binaryToBit(tree_address root, string str, char text, string *encoded_text) {
    if (root == NULL) {
    	return NULL;
	}

    if (root->character == text) {
        cout << " " << root->character << " " << (char)175 << " " << str << endl;
        (*encoded_text).append(str);
        
        return root;
    }

    tree_address check = binaryToBit(root->left, str + "0", text, encoded_text);
    if (check != NULL) {
        return check;
    }

    return binaryToBit(root->right, str + "1", text, encoded_text);
}

/* prosedur untuk mengubah dari bit menjadi sebuah karakter yang bisa dibaca (decode) dan menampilkannya */
void bitToCharacter(tree_address root, string encoded_text) {
    int i;
    tree_address node;
    string decoded_text, c;

    node = root;
    for (i = 0; i < encoded_text.length(); i++) {
        if (encoded_text[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->character != '\0') {
            c = node->character;
            decoded_text.append(c);
            node = root;
        }
    }

    cout << decoded_text << endl;
}
