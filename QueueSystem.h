<<<<<<< HEAD
/* 
Program   : QueueSystem.h 
Author    : - Maolana Firmansyah
            - Muhammad Dyfan Ramadhan
            - Yayang Setia Budi
Kelas     : 1A Kelompok A7

Deskripsi : Header file dari prototype Queue linked list Antrian Aplikasi DocOyen 

Tanggal   : 08-06-2022
Versi     : 4.0 - Fix Bugs
*/ 

#ifndef _QUEUESYSTEM_H 
#define _QUEUESYSTEM_H 
#include "boolean.h"
#include "Adtjam.h"
#include "list.h"  
#include <stdio.h> 
#include <conio.h> 
#define nil NULL 
#define next(P) (P)->next 
#define HEAD(Q) (Q).HEAD 
#define TAIL(Q) (Q).TAIL 
#define prioritas(P) (P)->info.prioritas
#define info(P) (P)->info
#define NamaKucing(P) (P)->info.namaKucing
#define NamaPemilik(P) (P)->info.namaPemilik


typedef char String[100];
typedef struct tElmQueue *address;

/** Menyimpan informasi kucing **/
typedef struct  {
	String namaKucing;
	String namaPemilik;
	List Penyakit;
	int prioritas;
    //Waktu dalam satuan detik
	int waktuDatang;
	int waktuSelesai;
	int estimasiWaktu;
}InfoKucing;

/** Queue **/
typedef struct tElmQueue{ 
	InfoKucing info;
	address next; 
}ElmQueue; 

/** Menyimpan head dan tail dari queue **/
typedef struct{ 
	address HEAD; 
	address TAIL; 
}Queue; 

/** Menyimpan jumlah total penyakit per kategori yang dimiliki oleh pasien/antrian **/
typedef struct  {
	int Ringan;
	int Sedang;
	int Berat;
}JmlKategoriPenyakit;

/** Menyimpan informasi kucing yang sedang dirawat **/
typedef struct  {
	InfoKucing info;
	int waktuSelesai;
	boolean OnGoing;
}UnderTreatment;

/** Menyimpan informasi kucing yang sudah dirawat **/
typedef struct  {
	String NamaKucing;
	String NamaPemilik;
	String DaftarPenyakit;
	String Date;
	Jam waktuSelesai;
	Jam waktuDatang;
}Riwayat;

/**************** Constructor && Insert Antrian ****************************/ 
void CreateQueue(Queue *Q); 
void EnQue(Queue *Q, InfoKucing informasi);  
void AddsortingQueue(Queue *Q, InfoKucing informasi);
void insertAntrian(Queue *Q, InfoKucing informasi);
void createEmptyJmlKategori(JmlKategoriPenyakit *jumlahPerKategori);
List buildList(String daftarPenyakit);
void createEmptyOnproses(UnderTreatment *Onproses);
                        
/**************** Manajement Memory **********************/
address AlokasiQueue(InfoKucing informasi);
void DeAlokasi(address P); 

/**************** Descructor ****************************/ 
void DelQue(Queue *Antrian, UnderTreatment *onproses); 

/**************** Mutator *****************************/ 
void setJmlPerKategori(JmlKategoriPenyakit *jumlahPerKategori, String daftarPenyakit);

/**************** Accessor ****************************/ 
int getTimeRightNow(UnderTreatment Onproses);
Jam getJamKedatangan(InfoKucing info);

/**************** Validator ****************************/ 
boolean IsQueueEmpty(Queue Q); 
boolean IsValidComeTime(int waktuKedatangan, Queue Antrian,UnderTreatment onproses);
boolean isValidDiseases(String daftarPenyakit);

/**************** Menu ****************************/ 
void Registrasi(Queue *Antrian,UnderTreatment *Onproses);
void ProsesAntrian(Queue *Antrian,UnderTreatment *Onproses);



/**************** Operasi Penujang lainnya *************/ 
void PrintAntrian(Queue Q,UnderTreatment onproses); 
char* kategoriPenyakit(char Penyakit);
char* Token(String inputanPenyakit, String Hasil);
char* namaPenyakit(char nomorPenyakit);
int HitungNilaiPrioritas(JmlKategoriPenyakit jumlahPerKategori);
int HitungWaktuEstimasi(JmlKategoriPenyakit jumlahPerKategori);
void UpdateWaktuSelesai(Queue *Antrian, UnderTreatment otw);
void cekonproses(Queue *Antrian, UnderTreatment *onproses);
int findMaxWaktuKedatangan(Queue Antrian);
void ListDaftarPenyakit();
void AddRiwayat(InfoKucing info);
void TampilRiwayat();
char *riwayatPenyakit(addressList L,String Temp);
char *DateNow(String Temp);
void cariRiwayat();
void MenuRiwayat();
void DelAfter(Queue *Antrian,UnderTreatment onproses);
void loading();

#endif


=======
/* 
Program   : QueueSystem.h 
Author    : - Maolana Firmansyah
            - Muhammad Dyfan Ramadhan
            - Yayang Setia Budi
Kelas     : 1A Kelompok A7

Deskripsi : Header file dari prototype Queue linked list Antrian Aplikasi DocOyen 

Tanggal   : 18-05-2022
Versi     : 1.1
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

/** ADT untuk menyimpan informasi kucing **/
typedef struct  {
	String namaKucing;
	String namaPemilik;
	List Penyakit;
	int prioritas;
	int waktuDatang;
	int waktuSelesai;
	int estimasiWaktu;
}InfoKucing;

/** ADT Queue **/
typedef struct tElmQueue{ 
	InfoKucing info;
	address next; 
}ElmQueue; 

/** ADT untuk menyimpan head dan tail dari queue **/
typedef struct{ 
	address HEAD; 
	address TAIL; 
}Queue; 

/** ADT untuk menyimpan jumlah total penyakit per kategori **/
typedef struct  {
	int Ringan;
	int Sedang;
	int Berat;
}JmlKategoriPenyakit;

/** ADT untuk menyimpan informasi kucing yang sedang dirawat **/
typedef struct  {
	InfoKucing info;
	int waktuSelesai;
	boolean OnGoing;
}Onprocess;

typedef struct  {
	String NamaKucing;
	String NamaPemilik;
	String DaftarPenyakit;
	String Date;
}Riwayat;

/**************** Constructor && Insert Antrian ****************************/ 
void CreateQueue(Queue *Q); 
void EnQue(Queue *Q, InfoKucing informasi);  
void AddsortingQueue(Queue *Q, InfoKucing informasi);
void insertAntrian(Queue *Q, InfoKucing informasi);
void createEmptyJmlKategori(JmlKategoriPenyakit *jumlahPerKategori);
List buildList(String daftarPenyakit);
void createEmptyOnproses(Onprocess *Onproses);
                        
/**************** Manajement Memory **********************/
address AlokasiQueue(InfoKucing informasi);
void DeAlokasi(address P); 

/**************** Descructor ****************************/ 
void DelQue(Queue *Antrian, Onprocess *onproses); 

/**************** Mutator *****************************/ 
void setWaktuSelesai(Queue Antrian,int Estimasi,int *waktuSelesai);
void setJmlPerKategori(JmlKategoriPenyakit *jumlahPerKategori, String daftarPenyakit);

/**************** Accessor ****************************/ 
int getTimeRightNow(Onprocess Onproses);

/**************** Validator ****************************/ 
boolean IsQueueEmpty(Queue Q); 
boolean IsValidComeTime(int waktuKedatangan, Queue Antrian,Onprocess onproses);
boolean isValidDiseases(String daftarPenyakit);

/**************** Menu ****************************/ 
void Registrasi(Queue *Antrian,Onprocess *Onproses);
void ProsesAntrian(Queue *Antrian,Onprocess *Onproses);



/**************** Operasi Penujang lainnya *************/ 
void PrintAntrian(Queue Q,Onprocess onproses); 
char* kategoriPenyakit(char Penyakit);
char* Token(String inputanPenyakit, String Hasil);
char* namaPenyakit(char nomorPenyakit);
int HitungNilaiPrioritas(JmlKategoriPenyakit jumlahPerKategori);
int HitungWaktuEstimasi(JmlKategoriPenyakit jumlahPerKategori);
void UpdateWaktuSelesai(Queue *Antrian, int LastTime);
void cekonproses(Queue *Antrian, Onprocess *onproses);
int findMaxWaktuKedatangan(Queue Antrian);
void ListDaftarPenyakit();
void AddRiwayat(InfoKucing info);
void TampilRiwayat();
char *riwayatPenyakit(addressList L,String Temp);
char *DateNow(String Temp);
void cariRiwayat();
void MenuRiwayat();
void DelAfter(Queue *Antrian,Onprocess onproses);
void loading();

#endif


>>>>>>> 6e76413a45021063041b272bc0f2b8afaa7e8a2a
