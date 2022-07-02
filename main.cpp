/*
    Program Huffman Code - Tugas Akhir MK Struktur Data dan Algoritma Praktikum
    Dibuat oleh:
     - Ananta Destawardhana	211511004
     - M. Fatur Maulidan A.	211511020
    Kelas D3 / 1A - Teknik Informatika
    Tahun 2022
*/

#include "menu.h"

int main() {
    /* kamus data */
    string text, text_temp;
    int length, choice = 0, i;
    queue list_queue;
    binary_tree b_tree;
    
    /* program */
    while (true) {
    	system("cls");
		choice = menu();
	    switch (choice) {
	    	case 1:
	    		text = inputText(&length, &text_temp);
	    		break;
	    	case 2:
				processHuffman(&text, text_temp, length, &list_queue, &b_tree);
	    		break;
	    	case 3:
	    		aboutProgram();
	    		break;
	    	case 4:
	    		exit(1);
	    		break;
		}
	}

    return 0;
}
