/* 
Program   : QueueSystem.h 
Author    : - Maolana Firmansyah
            - Muhammad Dyfan Ramadhan
            - Yayang Setia Budi
Kelas     : 1A Kelompok A7

Deskripsi : Header file dari prototype Queue linked list Antrian Aplikasi DocOyen 

Tanggal   : 18-05-2022
Versi     : 1.0
*/ 

#ifndef _QUEUESYSTEM_H 
#define _QUEUESYSTEM_H 
#include "boolean.h"
#include "list.h"  
#include <stdio.h> 
#include <conio.h> 
#define nil NULL 
#define koper(P) (P)->jmlKoper
#define come(P) (P)->waktuDatang
#define nama(P) (P)->nama
#define next(P) (P)->next 
#define finish(P) (P)->waktuFinish
#define HEAD(Q) (Q).HEAD 
#define TAIL(Q) (Q).TAIL 


typedef char String[100];
typedef struct tElmQueue *address;
typedef struct InfoKucing *prosesPerawatan; 

typedef struct  {
	String namaKucing;
	String namaPemilik;
	List Penyakit;
	String kategori;
	int prioritas;
	int waktuDatang;
}InfoKucing;

typedef struct tElmQueue{ 
	InfoKucing info;
	address next; 
}ElmQueue; 

typedef struct{ 
	address HEAD; 
	address TAIL; 
}Queue; 

typedef struct{ 
	address FIRST; 
	address NEXT; 
}ListQueue; 

/**************** Constructor ****************************/ 

void CreateQueue(Queue *Q); 
/* I.S : Q terdefinisi tidak diketahui isinya 
   F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil 
*/ 

address AlokasiQueue(InfoKucing informasi);
/* mengirim sebuah address jika alokasi type Queue berhasil */

void AddQue(Queue *Q, InfoKucing informasi); 
/* I.S : Q terdefinisi sembarang mungkin kosong 
   F.S : Q bertambah sebuah element/antrian dibelakang yang berisi informasi tentang kucing dan hal lainnya
*/  

void AddsortingQueue(Queue *Q, InfoKucing informasi);

/**************** Descructor ****************************/ 
void DeAlokasi(address P); 
/* P direlease dari memori */

void DelQue(Queue *Q); 
/* I.S : Q terdefinisi sembarang tidak kosong 
   F.S : Q berkurang satu elemen didepan 
*/ 

/**************** Mutator *****************************/ 

/**************** Accessor ****************************/ 
char* getKategoriPenyakit(List penyakit);


/**************** Operasi penunjang ****************************/ 
void CetakQueue(Queue Q); 
/* I.S : Q terdefinisi sembarang 
   F.S : elemen Queue dicetak dilayar, akan menampilkan "Antrian Kosong" di layar jika Q kosong
*/ 

//Operasi boolean dan relasi terhadap Queue 
boolean IsQueueEmpty(Queue Q); 
/* Mengirim true jika Queue kosong  dan false sebaliknya  */ 
char* kategoriPenyakit(int Penyakit);
char* Token(String inputanPenyakit, String Hasil);
char* namaPenyakit(int nomorPenyaki);
addressList buildList(String daftarPenyakit);
void toStringPenyakit(char sakit,String *penyakit);
void insertAntrian(Queue *Q, InfoKucing informasi);
int HitungNilaiPrioritas(int Ringan, int Sedang, int Berat);
int HitungWaktuEstimasi(int Ringan, int Sedang, int Berat);
void Registrasi(Queue *Antrian);
#endif


