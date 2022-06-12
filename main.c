<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "QueueSystem.h"


void menu();

int main(int argc, char *argv[]) {
	InfoKucing info;
    UnderTreatment Onproses;
	Queue antrian;
	CreateQueue(&antrian);
	createEmptyOnproses(&Onproses);
	
	int pilihan;
	
	do {
		system("cls");
		menu();
		printf("\n\t\t\t\t\t                    Masukan Pilihan Anda: "); scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1:
				system("cls");
				Registrasi(&antrian,&Onproses);
				cekonproses(&antrian, &Onproses);
				break;
			case 2:
				system("cls");
				PrintAntrian(antrian,Onproses);
				system("pause");
				break;
			case 3:
				system("cls");
				ProsesAntrian(&antrian,&Onproses);
				system("pause");
				break;
			case 4:
				system("cls");
				MenuRiwayat();
				break;
			case 5:
				system("cls");
				printf("\n\t\t\t\t\tSampai Berjumpa Lagi ....\n");
				break;
			default:
				system("cls");
				printf("\n\t\t\t\t\tPilihan tidak ada, Silakan masukan pilihan yang sesuai\n");
				system("pause");
			break;
		}
	}while(pilihan != 5);
	
   
	return 0;
	
}

void menu(){
		printf("\t\t\t\t\t _____________________________________________________________\n");
		printf("\t\t\t\t\t\xb3                                                             \xb3\n");
		printf("\t\t\t\t\t\xb3  _________________________________________________________  \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3");
		printf("  \t  ____                ___                           \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t |  _ \\  ___   ___   / _ \\ _   _  ___ _ __          \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t | | | |/ _ \\ / __| | | | | | | |/ _ \\ '_ \\         \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t | |_| | (_) | (__  | |_| | |_| |  __/ | | |        \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t |____/ \\___/ \\___|  \\___/ \\__, |\\___|_| |_|        \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t                           |___/                    \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3_________________________________________________________\xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3  _________________________________________________________  \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                   _ _  __  __                           \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                  | | ||__||  ||  |                      \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                  |   ||__ |  ||__|                      \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                                                         \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    1. Registrasi                                        \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    2. Tampilkan Antrian                                 \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    3. Proses Antrian                                    \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    4. Riwayat Pelayanan                                 \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    5. Exit                                              \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                                                         \xb3 \xb3\n"); 
		printf("\t\t\t\t\t\xb3 \xb3_________________________________________________________\xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3_____________________________________________________________\xb3\n");
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "QueueSystem.h"


void menu();

int main(int argc, char *argv[]) {
	InfoKucing info;
	Onprocess UnderTreatment;
	Queue antrian;
	CreateQueue(&antrian);
	createEmptyOnproses(&UnderTreatment);
	
	int pilihan;
	
	do {
		system("cls");
		menu();
		printf("\n\t\t\t\t\t                    Masukan Pilihan Anda: "); scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1:
				system("cls");
				Registrasi(&antrian,&UnderTreatment);
				cekonproses(&antrian, &UnderTreatment);
				break;
			case 2:
				system("cls");
				PrintAntrian(antrian,UnderTreatment);
				system("pause");
				break;
			case 3:
				system("cls");
				ProsesAntrian(&antrian,&UnderTreatment);
				system("pause");
				break;
			case 4:
				system("cls");
				MenuRiwayat();
				break;
			case 5:
				system("cls");
				printf("\n\t\t\t\t\tSampai Berjumpa Lagi ....\n");
				break;
			default:
				system("cls");
				printf("\n\t\t\t\t\tPilihan tidak ada, Silakan masukan pilihan yang sesuai\n");
				system("pause");
			break;
		}
	}while(pilihan != 5);
	
   
	return 0;
	
}

void menu(){
		printf("\t\t\t\t\t _____________________________________________________________\n");
		printf("\t\t\t\t\t\xb3                                                             \xb3\n");
		printf("\t\t\t\t\t\xb3  _________________________________________________________  \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3");
		printf("  \t  ____                ___                           \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t |  _ \\  ___   ___   / _ \\ _   _  ___ _ __          \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t | | | |/ _ \\ / __| | | | | | | |/ _ \\ '_ \\         \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t | |_| | (_) | (__  | |_| | |_| |  __/ | | |        \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t |____/ \\___/ \\___|  \\___/ \\__, |\\___|_| |_|        \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3  \t                           |___/                    \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3_________________________________________________________\xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3  _________________________________________________________  \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                   _ _  __  __                           \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                  | | ||__||  ||  |                      \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                  |   ||__ |  ||__|                      \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                                                         \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    1. Registrasi                                        \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    2. Tampilkan Antrian                                 \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    3. Proses Antrian                                    \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    4. Riwayat Pelayanan                                 \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3    5. Exit                                              \xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3 \xb3                                                         \xb3 \xb3\n"); 
		printf("\t\t\t\t\t\xb3 \xb3_________________________________________________________\xb3 \xb3\n");
		printf("\t\t\t\t\t\xb3_____________________________________________________________\xb3\n");
}

>>>>>>> 6e76413a45021063041b272bc0f2b8afaa7e8a2a
