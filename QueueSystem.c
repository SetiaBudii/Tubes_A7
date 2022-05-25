#include "QueueSystem.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreateQueue(Queue *Q){
	HEAD(*Q)=nil;
	TAIL(*Q)=nil;
}

address AlokasiQueue(InfoKucing informasi){
   address P;
   addressList L;
   
   P=(address)malloc(sizeof(ElmQueue));  
   if(P!=nil) {
   	P->info= informasi;
	P->next = nil;
   }
   return P;
}

 void DeAlokasi(address P){
    free(P);   
 } 

void AddQue(Queue *Q, InfoKucing informasi){
	address P = AlokasiQueue(informasi);
	address Temp = HEAD(*Q);
	
	if(IsQueueEmpty(*Q)){
		next(P)=nil;
    	HEAD(*Q)=P;
    	TAIL(*Q)=P;
	}else{ 
      while(next(Temp)!=nil){
			Temp = next(Temp);
	  }
	  next(Temp) = P;
	  TAIL(*Q) = P;
    }
	
}

void DelQue(Queue *Q){
  address First = HEAD(*Q);
  
  HEAD(*Q) = next(HEAD(*Q));
  next(First)=nil;
  //*y = info(First); 		
  DeAlokasi(First);
}

boolean IsQueueEmpty(Queue Q){
	if(HEAD(Q)==nil){
		return true;
	}else{
		return false;
	}
}

char* Token(String inputanPenyakit, String Hasil){
    char *token;
   
   /* get the first token */
   token = strtok(inputanPenyakit,",");
   
   /* walk through other tokens */
   while( token != NULL ) {
      strcat(Hasil,token);
      token = strtok(NULL,",");
   }

	return Hasil;
}

void toStringPenyakit(char sakit,String *penyakit){
	if(sakit == '1'){
		strcpy(*penyakit,"Penyakit kulit");
	}else if (sakit == '2'){
		strcpy(*penyakit,"Luka ringan");
	}else if (sakit == '3'){
		strcpy(*penyakit,"Bersin");
	}else if (sakit == '4'){
		strcpy(*penyakit,"Cacingan");
	}else if (sakit == '5'){
		strcpy(*penyakit,"Diare");
	}else if (sakit == '6'){
		strcpy(*penyakit,"Luka dalam");
	}else if (sakit == '7'){
		strcpy(*penyakit,"Gangguan kerongkongan");
	}else if (sakit == '8'){
		strcpy(*penyakit,"Kuning");
	}else if (sakit == '9'){
		strcpy(*penyakit,"Terkena virus");
	}
}

addressList buildList(String daftarPenyakit){
	int i;
	String penyakitTemp;
	addressList temp;
	List list;
	CreateList (&list);
	 
	for(i=0;i<strlen(daftarPenyakit);i++){
		//toStringPenyakit(daftarPenyakit[i],&penyakitTemp);
		InsVLast (&list, namaPenyakit(daftarPenyakit[i]));
	}
	
	return list.First;
}

void AddsortingQueue(Queue *Q, InfoKucing informasi){
	address Temp = (*Q).HEAD;
	address P = AlokasiQueue(informasi);
	boolean lanjut = true;
	
	while(Temp->next != NULL && lanjut ){
		if(Temp->next->info.prioritas < P->info.prioritas){
			P->next = Temp->next;
			Temp->next = P;
			lanjut=false;
		}
		
		Temp = Temp->next;
	}
}

void insertAntrian(Queue *Q, InfoKucing informasi){

	if(IsQueueEmpty((*Q)) || (informasi.prioritas <= (*Q).TAIL->info.prioritas)){
		AddQue(&(*Q),informasi);
	}else if(informasi.prioritas > (*Q).HEAD->info.prioritas){
		address Temp = (*Q).HEAD;
		address P = AlokasiQueue(informasi);
		P->next = Temp;
		(*Q).HEAD = P;
	}else{
		AddsortingQueue(&(*Q),informasi);
	}
}

char* namaPenyakit(int nomorPenyakit){
	nomorPenyakit++;
	
	switch(nomorPenyakit){
		case 1: 
			return "Penyakit kulit";
			break;
		case 2: 
			return "Luka ringan";
			break;
		case 3: 
			return "Bersin";
			break;
		case 4: 
			return "Cacingan";
			break;
		case 5: 
			return "Diare";
			break;
		case 6: 
			return "Luka dalam";
			break;
		case 7: 
			return "Gangguan kerongkongan";
			break;
		case 8: 
			return "Kuning";
			break;
		case 9: 
			return "Terkena virus";
			break;
		default: 
			return "Penyakit tidak ada dalam list";
			break;
	}
}

/* Proses : Melakukan pengecekan kategori penyakit hewan berdasarkan nilai prioritas antrian */
char *kategoriPenyakit(int Penyakit){
	if (Penyakit<4){
		return "Ringan";
	} else if (Penyakit<7){
		return "Sedang";
	} else if (Penyakit<10){
		return "Berat";
	}	
}

/* Menentukan nilai prioritas dari suatu antrian berdasarkan jumlah penyakit yang diderita */
int HitungNilaiPrioritas(int Ringan, int Sedang, int Berat){
	
	int nilai = 0;
	nilai = nilai + (Berat*5);
	
	if (Sedang >= 2){
		nilai = nilai + (Sedang*4);
	}else{
		nilai = nilai + (Sedang*3);
	}
	
	if (Ringan >= 3){
		nilai = nilai + (Ringan*2);
	}else{
		nilai = nilai + Ringan;
	}
	
	return nilai;
}

/* Mengembalikan waktu estimasi pelayanan berdasarkan nilai prioritas antrian */
int PeriksaWaktuEstimasi(int Penyakit){
	if (Penyakit<4){
		return 15;
	} else if (Penyakit<7){
		return 30;
	} else if (Penyakit<10){
		return 45;
	}
}

/* Menghitung waktu estimasi pelayanan */
int HitungWaktuEstimasi(int Ringan, int Sedang, int Berat){
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}

void Registrasi(Queue *Antrian){
	InfoKucing Info;
	String daftarPenyakit;
	int jumlahPenyakit;
	
	CreateList(&Info.Penyakit);
	
	do{
		fflush(stdin);
		scanf("%[^\]s",&Info.namaKucing);
		
		fflush(stdin);
		scanf("%[^\]s",&Info.namaPemilik);
		
		fflush(stdin);
		scanf("%d",&Info.waktuDatang);
		
//		fflush(stdin);
//		scanf("%d",&jumlahPenyakit);
		
		fflush(stdin);
		scanf("%[^\]s",&daftarPenyakit);
		
		/// error
	
		Info.Penyakit = buildList(daftarPenyakit);
		
	} while(Info.Penyakit == NULL);
	
     insertAntrian(&(*Antrian),Info);
}
