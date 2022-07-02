#ifndef menu_H
#define menu_H

#include "tree.h"
#include "queue.h"
#include "huffman.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

/* menampilkan menu */
int menu();

/* mengubah warna tampilan teks */
void setColor(int color);

/* menampilkan teks yang berwarna */
void printColoredText(string, int);

/* mengatur posisi cursor */
void gotoXY(int x, int y);

/* menginput teks yang akan dikompres */
string inputText(int *, string *);

/* memproses teks menjadi huffman code */
void processHuffman(string *, string, int , queue *, binary_tree *);

/* menampilkan tentang program */
void aboutProgram();

#endif
