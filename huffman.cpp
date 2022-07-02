#include "huffman.h"

/* mengurutkan teks yang dimasukkan berdasarkan karakter */
void sort(string* text, int length) {
    char temp;
    int i, j;

    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if ((*text)[i] > (*text)[j]) {
                temp = (*text)[i];
                (*text)[i] = (*text)[j];
                (*text)[j] = temp;
            }
        }
    }
}

/* menghitung frekuensi karakter dari teks yang dimasukkan */
void countFrequency(string text, int length, queue *q) {
    int count, i, j;
    char temp;

    for (i = 0; i < length; i++) {
        temp = text[i];
        
        // jika temp sama dengan karakter sebelumnya, maka lewati
        if (i > 0 && temp == text[i - 1]) {
            continue;
        }

        count = 0;
        for (j = 0; j < length; j++) {
            if (temp == text[j]) {
                count++;
            }
        }
        
        // buat menjadi node queue
        enqueue(q, text[i], count);
    }
}

/* mengurutkan node queue berdasarkan frekuensi, kemudian berdasarkan karakter */
void sortFrequency(queue *q) {
    queue_address current, index;

    // urutkan berdasarkan frekuensi dahulu
    current = (*q).first;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->frequency > index->frequency) {
                swapNode(&current, &index);
            }
            index = index->next;
        }
        current = current->next;
    }

    // lalu berdasarkan karakter
    current = (*q).first;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if ((current->frequency == index->frequency) && (current->character > index->character)) {
                swapNode(&current, &index);
            }

            if ((current->frequency == index->frequency) && (current->character == '\0')) {
                swapNode(&current, &index);
            }
            index = index->next;
        }
        current = current->next;
    }
}

/* menukar nilai node */
void swapNode(queue_address *node1, queue_address *node2) {
    int freq_temp;
    char char_temp;
    tree_address left, left2, right, right2;

    left = left2 = right = right2 = NULL;
    
    // jika node queue mempunyai anak (tree node kiri dan kanan), tampung dahulu
    if ((*node1)->tree_left) {
        left = (*node1)->tree_left;
        (*node1)->tree_left = NULL;
    }

    if ((*node1)->tree_right) {
        right = (*node1)->tree_right;
        (*node1)->tree_right == NULL;
    }

    if ((*node2)->tree_left) {
        left2 = (*node2)->tree_left;
        (*node2)->tree_left = NULL;
    }

    if ((*node2)->tree_right) {
        right2 = (*node2)->tree_right;
        (*node2)->tree_right == NULL;
    }

	// tukar nilai kedua node
    freq_temp = (*node1)->frequency;
    char_temp = (*node1)->character;
    (*node1)->frequency = (*node2)->frequency;
    (*node1)->character = (*node2)->character;
    (*node2)->frequency = freq_temp;
    (*node2)->character = char_temp;
    (*node2)->tree_left = left;
    (*node2)->tree_right = right;
    (*node1)->tree_left = left2;
    (*node1)->tree_right = right2;
}

/* menggabungkan 2 node pertama queue dan mengubahnya menjadi node tree */
void combineNodes(queue *q) {
    queue_address first, second, parent;
    tree_address tree_node1, tree_node2;

    first = (*q).first;
    second = first->next;

	// membuat tree node dari node queue pertama
    tree_node1 = allocateTree(first->character, first->frequency);
    if (first->character == '\0' && first->tree_left && first->tree_right) {
        tree_node1->left = first->tree_left;
        tree_node1->right = first->tree_right;
    }

	// membuat tree node dari node queue kedua
    tree_node2 = allocateTree(second->character, second->frequency);
    if (second->character == '\0' && second->tree_left && second->tree_right) {
        tree_node2->left = second->tree_left;
        tree_node2->right = second->tree_right;
    }

	// membuat node queue untuk menghubungkan 2 tree node yang sudah dibuat
    parent = allocateQueue('\0', first->frequency + second->frequency);
    if (parent != NULL) {
        parent->tree_left = tree_node1;
        parent->tree_right = tree_node2;
        parent->next = second->next;
    }
    (*q).first = parent;

    first->next = NULL;
    second->previous = NULL;
    second->next = NULL;

    free(first);
    free(second);
}

/* mengubah node queue terakhir menjadi tree node */
bool convertQueueToTree(queue *q, binary_tree *tree) {
    tree_address root;
    queue_address first;

    first = (*q).first;

	// jika node queue belum tersisa 1
    if (first->previous || first->next) {
        return false;
    }

    root = allocateTree(first->character, first->frequency);
    root->left = first->tree_left;
    root->right = first->tree_right;

    first->tree_left = NULL;
    first->tree_right = NULL;

    (*q).first = NULL;
    (*q).last = NULL;
    free(first);

    (*tree).root = root;

    return true;
}
