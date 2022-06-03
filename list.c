#include "list.h"
#include "QueueSystem.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L){
/* Mengirim true jika List Kosong */
	if(First(L)==Nil){
		return true;
	}
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L){
	/* IS : L sembarang */
    /* FS : Terbentuk List Kosong */
	First(*L)=Nil;
}

/**** Manajemen Memory ****/
addressList AlokasiList (String Penyakit){
/*Mengirimkan addressList hasil alokasi sebuah elemen 
  Jika alokasi berhasil, maka addressList != Nil, 	   
  dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil 
  Jika alokasi gagal, mengirimkan Nil */
   addressList P;
   P=(addressList)malloc(sizeof(ElmtList));  //Memesan memori
   if(P!=Nil) { 
     strcpy(P->info,Penyakit);
	 Next(P)=Nil;
	 //jika pemesanan memori sukses maka P->info = X dan P->Next = NULL
   }
   return P;	   
}

void DeAlokasiList (addressList P){
	/* IS : P terdefinisi */
	/* FS : P dikembalikan ke sistem */
	/* Melakukan dealokasi / pengembalian addressList P ke system */
	Next(P)=Nil; //Jika dealloc, maka P->Next tidak boleh menunjuk kemanapun (NULL)	
    free(P);     //Dealloc P
}

void InsVFirst (List * L, String X){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil 
   Jika alokasi gagal maka element pertama tidak ditambahkan*/
   addressList P = AlokasiList(X);
   if(P!=Nil) { 
      InsertFirst(&(*L),P);
    }
}

void InsVLast (List * L, String Penyakit){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
	addressList P = AlokasiList(Penyakit);
	if(P!=Nil){
		InsertLast(&(*L),P);
	}
}



///**** Penghapusan Elemen ****/
void DelAll (List * L){
	/* Delete semua elemen list dan alamat elemen di dealokasi */
	
	while(First(*L)!=Nil){
		DelVFirst (&(*L));
	}
}

void DelVFirst (List * L){
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi 
    Nilai dari info akan ditampung ke X , lalu dealokasi dari memori*/

  addressList Pertama;
  
  DelFirst(&(*L),&Pertama); 		
  DeAlokasiList(Pertama);
	
}

void DelFirst (List * L, addressList * P){
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama 
   jika element pertama sudah berganti maka yang menunjuk ke next nya diisi NULL*/

	*P = First(*L);
	First(*L) = First(*L)->next;
	Next(*P)=Nil;		
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, addressList P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-addressList P sebagai elemen pertama */
	Next(P)=Nil;
    First(*L)=P;
}

void InsertAfter (List * L, addressList P, addressList Prec){
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P)=Next(Prec);
	Next(Prec)=P;	
}

void InsertLast (List * L, addressList P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
/* Pertama, cek dulu apakah list kosong atau tidak, jika kosong
   maka yang dinnputkan akan menjadi element list pertama. Dan 
   jika sudah ada list sebelumnya maka cari sampai element list terakhir
   atau X->next = NULL. lalu tunjukan atau sambungkan X->next tersebut ke P (alokasi baru)*/
   	addressList X = First(*L);
	if(First(*L)==Nil){
		InsertFirst(&(*L),P);
	}else{	
		while(Next(X)!=Nil){
			X = Next(X);
		}
	  Next(X) = P;
	}
}


///**** PROSES SEMUA ELEMEN LIST  ****/
void PrintDaftarPenyakit (addressList L){
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
	
	if(L == Nil){
		printf("\nList Kosong");
	}else{
		while(L->next != Nil){
			printf("%s,",L->info);
			L=L->next;
		}printf("%s\n",L->info);
	}
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
	addressList P=First(L);
	int totalElmt=0;
	
	if(P==Nil){
		return totalElmt;
	}else{
		while(Next(P)!=Nil){
			totalElmt++;
			P=Next(P);
		}totalElmt++;
	}
	
	return totalElmt;
}

//infotype Max (List L){
//	/* Mengirimkan nilai Info(P) yang maksimum */
//	addressList P = First(L);
//	int max;
//	
//	if(P!=NULL){
//		max = Info(P);
//		while(Next(P)!=Nil){
//			if(max <= Info(P)){
//				max=Info(P);
//			}
//			P = Next(P);
//		 }
//		 	if(max <= Info(P)){
//				max=Info(P);
//			}
//	}else{
//		return 0;
//	}
//	
//	return max;
//}
//
//addressList AdrMax (List L){
///* Mengirimkan addressList P, dengan info(P) yang bernilai maksimum */
//	addressList TempMax;
//	addressList P = First(L);
//	
//	TempMax = P;
//	while(Next(P)!=Nil){
//		P = Next(P);
//		if(Info(P) == Max(L)){
//			TempMax=P;
//		}
//	}
//
//	return TempMax;
//}
//
//infotype Min (List L){
///* Mengirimkan nilai Info(P) yang minimum */
//	addressList P = First(L);
//	int min;
//	
//	if(P!=NULL){
//		min = Info(P);
//		while(Next(P)!=Nil){
//			if(min >= Info(P)){
//				min=Info(P);
//			}
//			P = Next(P);
//		 }
//		 if(min >= Info(P)){
//				min=Info(P);
//			}
//	}else{
//		return 0;
//	}
//	
//	return min;
//}
//
//addressList AdrMin (List L){
///* Mengirimkan addressList P, dengan info(P) yang bernilai minimum */
//	addressList TempMin;
//	addressList P = First(L);
//	
//	TempMin=P;
//	while(Next(P)!=Nil){
//		P = Next(P);
//		if(Info(P) == Min(L)){
//			TempMin=P;
//		}
//	}
//
//	return TempMin;
//}
//
//infotype Average (List L){
///* Mengirimkan nilai rata-rata Info(P) */
//	addressList P=First(L);
//	int totalElmt=NbElmt(L);
//	int totalSum=0;
//	int average = 0;
//	
//	if(P==Nil){
//		return average;
//	}else{
//		while(Next(P)!=Nil){
//			totalSum = totalSum + Info(P);
//			P=Next(P);
//		}
//		totalSum = totalSum + Info(P);
//	}
//	average = totalSum/totalElmt;
//	
//	return average;
//}
//
//
///***************************************/
///*******  PROSES TERHADAP LIST  ********/
///***************************************/
//
//void DelAll (List * L){
//	/* Delete semua elemen list dan alamat elemen di dealokasi */
//	
//	int lastInfo;
//	while(First(*L)!=Nil){
//		DelVFirst (&(*L),&lastInfo);
//	}
//}
//
//void InversList (List * L){
///* IS : L sembarang */
///* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
///*	Membalik elemen list, tanpa melakukan alokasi / dealokasi */
///*Prev dan Current adalah pointer tambahan
//Prev akan berisi element list pertama dan Current akan
//berisi elemetlist kedua */
//	addressList Prev,Current;
//	
//	if(First(*L)!= NULL){
//        Prev = First(*L);
//        Current = First(*L)->next;
//        First(*L) = First(*L)->next;
//
//        Prev->next = NULL;
//
//        while(First(*L)!= NULL){
//            First(*L) = First(*L)->next;
//            Current->next = Prev;
//
//            Prev = Current;
//            Current = First(*L);
//        }
//
//        First(*L) = Prev;
//	}
//}
//
//List FInversList (List L){
///* Mengirimkan list baru, hasil invers dari L */
//	InversList (&L);
//	return L;
//}
//
//void CopyList (List L1, List * L2){
///* IS : L1 sembarang */
///* FS : L2 = l1 */
///* L1 dan L2 "menunjuk" ke list yang sama, Tidak ada alokasi / dealokasi */
//	*L2=L1;
//}
//
//List FCopyList (List L){
///* Mengirimkan List yang merupakan salinan L */
//	List Baru;
//	CreateList(&Baru);
//	CopyList (L, &Baru);
//	
//	return Baru;
//}
//
//void CpAlokList (List Lin, List * Lout);
///* IS : Lin Sembarang */
///* FS : Jika semua alokasi berhasi, maka Lout berisi hasil copy Lin */
///* 	Jika ada alokasi yang gagal, maka Lout = Nil dan semua elemen yang */
///*	terlanjur di alokasi, maka didealokasikan */
///* 	Dengan melakukan alokasi elemen */
///*	Lout adalah  list kosong jika ada alokasi elemen yang gagal */
//
//void Konkat (List L1, List L2, List * L3){
///* IS : L1 dan L2 sembarang */
///* FS : L1 dan L2 tetap, L3 adalah hasil konkatenansi L1 dan L2 */
///*	Jika semua alokasi berhasil , maka L3 adalah hasil konkatenasi */
///*	Jika ada alokasi gagal, semua elemen yang sudah di alokasi harus */
///* 	di dealokasi dan L3 = Nil */
///* Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru" */
///* Elemen L3 adalah hasil alokasi elemen yang "baru". Jika ada alokasi yang */
///*	  GAGAL, maka L3 harus bernilai nil dan semua elemen yang pernah di */
///*	  alokasi didealokasi */
//	addressList p;
//	addressList satu = First(L1);
//	addressList dua = First(L2);
//	
//    while(Next(satu)!=Nil){
//    	p = AlokasiList(Info(satu));
//    	InsertLast (&(*L3), p);
//    	satu = Next(satu);
//	}
//	
//	p = AlokasiList(Info(satu));
//    InsertLast (&(*L3), p);
//	
//	while(Next(dua)!=Nil){
//    	p = AlokasiList(Info(dua));
//    	InsertLast (&(*L3) , p);
//    	dua = Next(dua);
//	}
//	
//	p = AlokasiList(Info(dua));
//    	InsertLast (&(*L3) , p);
//	
//}
//
//void Konkat1 (List * L1, List * L2, List * L3);
///* IS : L1 dan L2 sembarang */
///* FS : L1 dan L2 kosong, L3 adalah hasil konkatenansi L1 dan L2 */
///*	Konkatenasi dua buah List L1 dan L2; menghasilkan L3 yang baru */
///* 	(dengan elemen List L1 dan L2) */
///*	dan L1 serta L2 menjadi list kosong */
///* 	Tidak ada alokasi / dealokasi pada procedure ini */
//
//void PecahList (List * L1, List * L2, List L);
///* IS : L mungkin kosong */
///* FS : berdasarkan L, dibentuk dua buah list L1 dan L2 */
///* L tidak berubah : untuk membentuk L1 dan L2 harus alokasi */
///* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
///* Jika elemen L ganjil , maka separuh adalah NbElmt (L) div 2 */


///**** Pencarian sebuah elemen List ****/
//addressList Search (List L, infotype X){
///* Mencari apakah ada elemen list dengan Info(P) = X */
///* Jika ada, mengirimkan addressList elemen tsb. */
///* Jika tidak ada, mengirimkan Nil */
//
//	boolean ketemu = false;
//	
//	while((First(L)!=Nil) && (!ketemu)){
//		if(First(L)->info == X){
//			return First(L);
//		}else{
//			First(L) = First(L)->next;
//		}
//	}
//}

//boolean FSearch (List L, addressList P){
///* Mencari apakah ada elemen list yang beralamat P */
///* Mengirimkan true jika ada, false jika tidak ada */
///*Temp adalah penampung sementara dari L.First*/
//  addressList Temp = First(L);
//  boolean ketemu=false;
//  
///*Selama Temp bukan NULL dan Element list yang beralamat P belum ketemu maka bandingkan Temp dan P.
//  Jika P=Temp maka ketemu=true dan jika P!=Temp maka beralih ke yang ditunjuk Temp->next*/
//  while((Temp!=Nil)&&(!ketemu)){
//     if(Temp==P) {
//	 	ketemu=true;
//     }else{ 
//	 	Temp=Next(Temp);     
//     }  
//  } 
//  return ketemu;
//}
//
//addressList SearchPrec (List L, infotype X){
///* Mengirimkan addressList elemen sebelum elemen yang nilainya = X */
///* Mencari apakah ada elemen list dengan Info(P) = X */
///* Jika ada, mengirimkan addressList Prec, dengan Next(Prec) = P dan Info(P) = X */
///* Jika tidak ada, mengirimkan Nil */
///* Jika P adalah elemen pertama, maka Prec = Nil */
///* Search dengan spesifikasi seperti ini menghindari */
///* traversal ulang jika setelah Search akan dilakukan operasi lain */
//addressList Prec;
//addressList P = First(L);
//boolean ketemu=false;
//
//	if(P->next==Nil){
//		Prec = Nil;
//	}else{
//		while((Next(P)!=Nil)&&(Info(P)!=X)&&(!ketemu)){
//			if(P->next->info==X){
//				Prec = P;
//				ketemu=true;
//			}else{
//				P = Next(P);
//				Prec = Nil;
//			}
//		}
//	}
//			
//	return Prec;
//}
//
///**** PRIMITIF BERDASARKAN NILAI ****/
///**** Penambahan Elemen ****/


//void DelVLast (List * L, infotype * X){
///* IS : L TIDAK Kosong */
///* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
///* 	dan alamat elemen terakhir di dealokasi */
//	addressList Terakhir;
//	
//	DelLast (&(*L),&Terakhir);
//	*X = Info(Terakhir); 		
//    DeAlokasi(Terakhir);
//}

///**** Penghapusan sebuah elemen ****/
//void DelFirst (List * L, addressList * P){
///* IS : L TIDAK kosong */
///* FS : P adalah alamat elemen pertama list sebelum penghapusan */
///*	elemen list berkurang satu (mungkin menjadi kosong) */
///* First elemen yang baru adalah suksessor elemen pertama yang lama 
//   jika element pertama sudah berganti maka yang menunjuk ke next nya diisi NULL*/
//
//	*P = First(*L);
//	First(*L) = First(*L)->next;
//	Next(*P)=Nil;		
//}
//
//void DelP (List * L, infotype X){
///* IS : L sembarang */
///* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
///* 	Maka P dihapus dari list dan di dealokasi */
///* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
///* List mungkin menjadi kosong karena penghapusan */
//
//	addressList Temp = First(*L);
//	addressList beforeLast;
//	
//	while(Info(Temp)!=X){
//   		beforeLast = Temp;
//   		Temp = Next(Temp);
//	   }
//	Next(beforeLast)=beforeLast->next->next;
//	Temp->next=Nil;
//}
//
//void DelLast (List * L, addressList * P){
///* IS : L TIDAK kosong */
///* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
///*	Elemen list berkurang satu (mungkin menjadi kosong) */
///* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */	
//   addressList beforeLast=Nil;
//   *P = First(*L);
//   if(Next(*P) == Nil){
//	   	First(*L) = Nil;
//   }else{
//   	while(Next(*P)!=Nil){
//   		beforeLast = *P;
//   		*P = Next(*P);
//	   }
//	Next(beforeLast)=Nil;
//   }
//}
//
//void DelAfter (List * L, addressList * Pdel, addressList Prec){
///* IS : L TIDAK Kosong, Prec adalah anggota List */
///* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
//	*Pdel=Next(Prec);
//	Next(Prec)=Next(*Pdel);
//}
//
