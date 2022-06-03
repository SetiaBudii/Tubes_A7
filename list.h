/* File        : list1.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#ifndef list_H
#define list_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef char String[100];
typedef struct tElmtList *addressList;
typedef struct tElmtList {
    String info;
    String kategoriPenyakit;
    addressList  next;
} ElmtList;    

typedef struct {
     addressList First;	
} List;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
addressList AlokasiList (String Penyakit);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlokasiList (addressList P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressList P ke system */


/**** PRIMITIF BERDASARKAN NILAI ****/

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, addressList * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void DelAll (List * L);
/* Delete semua elemen list dan alamat elemen di dealokasi */

void DelVFirst (List * L);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */


/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, addressList P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-addressList P sebagai elemen pertama */

void InsertAfter (List * L, addressList P, addressList Prec);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List * L, addressList P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void InsVFirst (List * L, String X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List * L, String Penyakit);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */



/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintDaftarPenyakit (addressList L);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

int NbElmt (List L);

/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/

//void DelAll (List * L);
/* Delete semua elemen list dan alamat elemen di dealokasi */

/**** Pencarian sebuah elemen List ****/
//addressList Search (List L, String X);
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan addressList elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

//boolean FSearch (List L, addressList P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

//addressList SearchPrec (List L, String X);
/* Mengirimkan addressList elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan addressList Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

//void DelVLast (List * L, String * X);
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

//void DelP (List * L, String X);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

//void DelLast (List * L, addressList * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

//void DelAfter (List * L, addressList * Pdel, addressList Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */

#endif

