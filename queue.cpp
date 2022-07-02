#include "queue.h"

/* mencek apakah queue kosong */
bool isQueueEmpty(queue q) {
    return (q.first == NULL && q.last == NULL);
}

/* membuat queue baru */
void createQueue(queue *q) {
    (*q).first = NULL;
    (*q).last = NULL;
}

/* mengalokasikan node baru untuk queue */
queue_address allocateQueue(char character, int frequency) {
    queue_address node;

    node = (queue_address)malloc(sizeof(queue_element));
    if (node != NULL) {
        node->character = character;
        node->frequency = frequency;
        node->previous = NULL;
        node->next = NULL;
    }

    return node;
}

/* menambahkan node baru ke awal queue */
void enqueue(queue *q, char character, int frequency) {
    queue_address last, new_node;
    
    new_node = allocateQueue(character, frequency);
    if (isQueueEmpty(*q)) {
        (*q).first = (*q).last = new_node;
    } else {
        (*q).last->next = new_node;
        new_node->previous = (*q).last;
        (*q).last = new_node;
    }
}

/* menampilkan isi queue */
void printQueue(queue q) {
    queue_address node;

    if (isQueueEmpty(q)) {
        cout << "Queue kosong";
    } else {
        node = q.first;
        while (node != NULL) {
            if (node->character == '\0') {
                cout << "|null-" << node->frequency << "|";
                if (node->tree_left && node->tree_right) {
                    cout << "(kiri: " << node->tree_left->character << " kanan: " << node->tree_right->character << ")";
                }
                cout << " ";
            } else {
                cout << "|" << node->character << "-" << node->frequency << "|";
                cout << " ";
            }

            node = node->next;
        }
    }

    cout << endl;
}

/* menghitung jumlah node queue */
int countQueue(queue q) {
    queue_address node;
    int count = 0;

    node = q.first;
    while (node != NULL) {
        count++;
        node = node->next;
    }

    return count;
}
