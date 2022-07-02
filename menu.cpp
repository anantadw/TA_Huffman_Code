#include "menu.h"

using namespace std;

/* menampilkan menu */
int menu() {
	int i, counter = 1;
	int colors[] = {11, 7, 7, 7};
	char key;
	bool loop = true;
	
	while (loop) {
		// set cursor ke awal screen
		gotoXY(0, 0);
		
		// garis atas
		cout << (char)201;
		for (i = 0; i < 42; i++) {
			cout << (char)205;
		}
		cout << (char)187 << endl;
		
		// judul
		cout << (char)186 << "                                          " << (char)186 << endl;
		cout << (char)186 << "          PROGRAM HUFFMAN CODE            " << (char)186 << endl;
		cout << (char)186 << "                                          " << (char)186 << endl;
	    
	    // garis bawah
	    cout << (char)204;
		for (i = 0; i < 42; i++) {
			cout << (char)205;
		}
		cout << (char)185 << endl;
		
		// menu
		cout << (char)186 << "                                          " << (char)186 << endl;
		cout << (char)186 << "  Pilih menu:                             " << (char)186 << endl;
		cout << (char)186 << "                                          " << (char)186 << endl;
		cout << (char)186 << "  "; setColor(colors[0]); cout << "1. Masukkan teks"; setColor(7); cout << "                        " << (char)186 << endl;
		cout << (char)186 << "  "; setColor(colors[1]); cout << "2. Cetak Kode Huffman"; setColor(7); cout << "                   " << (char)186 << endl;
		cout << (char)186 << "  "; setColor(colors[2]); cout << "3. Tentang program"; setColor(7); cout << "                      " << (char)186 << endl;
		cout << (char)186 << "  "; setColor(colors[3]); cout << "4. Keluar program"; setColor(7); cout << "                       " << (char)186 << endl;
		cout << (char)186 << "                                          " << (char)186 << endl;
		cout << (char)186 << "  ^ : menggeser pilihan ke atas           " << (char)186 << endl;
		cout << (char)186 << "  v : menggeser pilihan ke bawah          " << (char)186 << endl;
		cout << (char)186 << "  Enter : memilih menu                    " << (char)186 << endl;
		cout << (char)186 << "                                          " << (char)186 << endl;
		cout << (char)200;
		for (i = 0; i < 42; i++) {
			cout << (char)205;
		}
		cout << (char)188 << endl;

		// ambil input keyboard
		key = getch();
		
		if (key == 72 && counter > 1) { // jika input adalah panah atas
			counter--;
		} else if (key == 80 && counter < 4) { // jika input adalah panah bawah
			counter++;
		} else if (key == 13) { // jika input adalah enter
			loop = false;
		}
		
		// set warna
		colors[0] = colors[1] = colors[2] = colors[3] = 7;
		colors[counter - 1] = 11;
	}
	
	return counter;
}

/* mengubah warna tampilan teks */
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/* menampilkan teks yang berwarna */
void printColoredText(string text, int color) {
	setColor(color);
	cout << endl << text;
	setColor(7);
}

/* mengatur posisi cursor */
void gotoXY(int x, int y) {
	COORD c;
	
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/* menginput teks yang akan dikompres */
string inputText(int *length, string *text_temp) {
	string text;
	int i;
	
	do {
		system("cls");
		
		// garis atas
		cout << (char)201;
		for (i = 0; i < 42; i++) {
			cout << (char)205;
		}
		cout << (char)187 << endl;
		
		// judul
		cout << (char)186 << "                                          " << (char)186 << endl;
		cout << (char)186 << "               MASUKKAN TEKS              " << (char)186 << endl;
		cout << (char)186 << "                                          " << (char)186 << endl;
	    
	    // garis bawah
	    cout << (char)200;
		for (i = 0; i < 42; i++) {
			cout << (char)205;
		}
		cout << (char)188 << endl;
		
		// ambil input text
		getline(cin>>ws, text);
		
		(*length) = text.length();
		(*text_temp) = text;
		
		// jika teks berisi kurang dari 2 karakter, ulangi input
		if (*length < 2) {
			printColoredText("Teks minimal 2 karakter", 12);
			getch();
		}
	} while (*length < 2);
	
	printColoredText("Teks berhasil dimasukkan", 10);
	getch();
	
	return text;
}

/* memproses teks menjadi huffman code */
void processHuffman(string *text, string text_temp, int length, queue *q, binary_tree *t) {
	bool success = false;
	string encoded_text;
	int i = 0;
	
	system("cls");
	
	// garis atas
	cout << (char)201;
	for (i = 0; i < 42; i++) {
		cout << (char)205;
	}
	cout << (char)187 << endl;
	
	// judul
	cout << (char)186 << "                                          " << (char)186 << endl;
	cout << (char)186 << "             CETAK KODE HUFFMAN           " << (char)186 << endl;
	cout << (char)186 << "                                          " << (char)186 << endl;
    
    // garis bawah
    cout << (char)200;
	for (i = 0; i < 42; i++) {
		cout << (char)205;
	}
	cout << (char)188;
	
	// jika teks kosong
	if ((*text).empty()) {
		printColoredText("Teks masih kosong", 12);
		getch();
		
		return;
	}
	
	// proses konversi
	sort(text, length);
	createQueue(q);
	countFrequency(*text, length, q);
	sortFrequency(q);
	while (countQueue(*q) != 1) {
		combineNodes(q);
		sortFrequency(q);
	}
	success = convertQueueToTree(q, t);
	
	// jika konversi berhasil
	if (success) {
		// tampilkan binary tree
		cout << endl << "Bentuk Binary Tree" << endl;
		printBinaryTree((*t).root, 0);
		
		// tampilkan hasil konversi bit per karakter
		cout << endl << "Kode Huffman per karakter" << endl;
		for (int i = 0; i < length; i++) {
	        binaryToBit((*t).root, "", text_temp[i], &encoded_text);
	    }
	    
	    // tampilkan hasil konversi teks keseluruhan
	    cout << endl << "Konversi Kode Huffman dari teks (encode)" << endl;
	    cout << encoded_text << endl;
	    
	    // tampilkan dari bit menjadi karakter kembali
	    cout << endl << "Konversi Kode Huffman menjadi teks (decode)" << endl;
	    bitToCharacter((*t).root, encoded_text);
	    
	    // tampilkan ukuran teks asal
	    cout << endl << "Ukuran teks asal" << endl;
	    cout << "8 * " << length << " = " << 8 * length << " bit" << endl;
	    
	    // tampilkan ukuran teks setelah dikompres
	    cout << endl << "Ukuran teks setelah dikompres" << endl;
	    cout << encoded_text.length() << " bit" << endl;
	} else {
		printColoredText("Konversi gagal", 12);
	}
	
	getch();
}

void aboutProgram() {
	int i;
	
	system("cls");
	
	// garis atas
	cout << (char)201;
	for (i = 0; i < 42; i++) {
		cout << (char)205;
	}
	cout << (char)187 << endl;
	
	// judul
	cout << (char)186 << "                                          " << (char)186 << endl;
	cout << (char)186 << "            TENTANG  PROGRAM              " << (char)186 << endl;
	cout << (char)186 << "                                          " << (char)186 << endl;
    
    // garis bawah
    cout << (char)204;
	for (i = 0; i < 42; i++) {
		cout << (char)205;
	}
	cout << (char)185 << endl;
	
	// isi
	cout << (char)186 << " Huffman Code adalah algoritma kompresi   " << (char)186 << endl;
	cout << (char)186 << " dengan metode Lossless, yang mengubah    " << (char)186 << endl;
	cout << (char)186 << " karakter menjadi bit 0 dan 1 menggunakan " << (char)186 << endl;
	cout << (char)186 << " binary tree, untuk memperkecil ukuran    " << (char)186 << endl;
	cout << (char)186 << " data dari yang sebenarnya.               " << (char)186 << endl;
	cout << (char)186 << "                                          " << (char)186 << endl;
	cout << (char)186 << " Program ini dibuat oleh:                 " << (char)186 << endl;
	cout << (char)186 << " - Ananta Destawardhana 211511004         " << (char)186 << endl;
	cout << (char)186 << " - M. Fatur Maulidan Azzahra 211511020    " << (char)186 << endl;
	cout << (char)186 << " Mahasiswa Progam Studi D3 Teknik         " << (char)186 << endl;
	cout << (char)186 << " Informatika, Politeknik Negeri Bandung   " << (char)186 << endl;
	cout << (char)186 << " Tahun 2022                               " << (char)186 << endl;
	
	cout << (char)200;
	for (i = 0; i < 42; i++) {
		cout << (char)205;
	}
	cout << (char)188 << endl;
	
	getch();
}
