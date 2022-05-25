#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueSystem.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	List fs;
	InfoKucing info,info2;
	Queue antrian;
	String penyakit = "1234";
	String penyakit1 = "12345";
	CreateList(&fs);
	CreateQueue(&antrian);

//	strcpy(info.namaKucing,"meow");
//	strcpy(info.namaPemilik,"budi");
//	info.prioritas = 170;
//	info.Penyakit = NULL;
//	info.waktuDatang = 10;
//	insertAntrian(&antrian,info,penyakit);
//	
//	strcpy(info2.namaKucing,"oyen");
//	strcpy(info2.namaPemilik,"setia");
//	info2.prioritas = 10;
//	info2.Penyakit = NULL;
//	info2.waktuDatang = 50;
//	insertAntrian(&antrian,info2,penyakit1);
//
//	strcpy(info.namaKucing,"Mao");
//	strcpy(info.namaPemilik,"nnn");
//	info.prioritas = 15;
//	info.Penyakit = NULL;
//	info.waktuDatang = 10;
//	insertAntrian(&antrian,info,penyakit);
//	
//	strcpy(info2.namaKucing,"dggd");
//	strcpy(info2.namaPemilik,"setia");
//	info2.prioritas = 1;
//	info2.Penyakit = NULL;
//	info2.waktuDatang = 50;
//	insertAntrian(&antrian,info2,penyakit1);
//	
//	printf("%s ",antrian.HEAD->info.namaKucing);
//	printf("%s ",antrian.HEAD->next->info.namaKucing);
//	printf("%s ",antrian.HEAD->next->next->info.namaKucing);
//	printf("%s ",antrian.TAIL->info.namaKucing);

	Registrasi(&antrian);
	printf("%s ",antrian.HEAD->info.namaKucing);
	return 0;
}
