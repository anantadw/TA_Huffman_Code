#ifndef huff_H
#define huff_H

#include "tree.h"
#include "queue.h"

/* mengurutkan teks yang dimasukkan berdasarkan karakter */
void sort(string *, int);

/* menghitung frekuensi karakter dari teks yang dimasukkan */
void countFrequency(string, int, queue *);

/* mengurutkan node queue berdasarkan frekuensi, kemudian berdasarkan karakter */
void sortFrequency(queue *);

/* menukar nilai node */
void swapNode(queue_address *, queue_address *);

/* menggabungkan 2 node pertama queue dan mengubahnya menjadi node tree */
void combineNodes(queue *);

/* mengubah node queue terakhir menjadi tree node */
bool convertQueueToTree(queue *, binary_tree *);

#endif
