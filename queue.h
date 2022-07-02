#ifndef queue_H
#define queue_H

#include "tree.h"

/* struktur queue */
typedef struct queue_element *queue_address;
typedef struct queue_element {
    char character;
    int frequency;
    queue_address previous, next;
    tree_address tree_left, tree_right;
} queue_node;

typedef struct list {
    queue_address first, last;
} queue;

/* mencek apakah queue kosong */
bool isQueueEmpty(queue);

/* membuat queue baru */
void createQueue(queue *);

/* mengalokasikan node baru untuk queue */
queue_address allocateQueue(char, int);

/* menambahkan node baru ke awal queue */
void enqueue(queue *, char, int);

/* menampilkan isi queue */
void printQueue(queue);

/* menghitung jumlah node queue */
int countQueue(queue);

#endif
