#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Data {
  char nim[10], nama[100], kelas[10];
  int show;
};

struct Data User[100];
int length = 0, i;

void create(void) {
	char nim [10],nama[100], kelas[10];
	
	up:
	printf("==Create Data==\n");
	printf("Masukkan nim : "); scanf("%s[^\n]", &nim); fflush(stdin);
	printf("Masukkan nama : "); scanf("%s[^\n]", &nama); fflush(stdin);
	printf("Masukkan kelas : "); scanf("%s[^\n]", &kelas); fflush(stdin);

	FILE *out=fopen("data mahasiswa.txt","w");
	fprintf(out,"%s\n %s\n %s\n",nim, nama, kelas);
	
	//cek duplicate

    printf("=========================\n"); 	
	if (length == 0) {
		strcpy(User[length].nim, nim);
        strcpy(User[length].nama, nama);
        strcpy(User[length].kelas, kelas);
        

        User[length].show = 1;
        ++length;

        printf("Berhasil ditambahkan\n");
        sleep(2);
	} else {
		for (i = 0; i < length; i++) {
    		sleep(3);
    		bool isDuplicate = strcmp(User[i].nim, nim) == 0;
    		if (isDuplicate) {
            	sleep(2);
            	system("cls");
            	goto up;
			} else {
				strcpy(User[length].nim, nim);
        		strcpy(User[length].nama, nama);
        		strcpy(User[length].kelas, kelas);
        		

        		User[length].show = 1;
        		++length;

        		printf("Berhasil ditambahkan\n");
        		fclose(out);
				getchar();
        		sleep(2);
        		break;
			}
		}
	}
	
    
}
void show(){
		char nim [10],nama[100], kelas[10];
		FILE *in=fopen("data mahasiswa.txt","r");
		
		printf("==List Data==\n");
		
        	while(!feof(in)){
           		fscanf(in,"%s\n%s\n%s\n", &nim, &nama, &kelas);
		   		fflush(stdin);   
        		printf("\nNIM     : %s", nim);
				printf("\nNama    : %s", nama);
				printf("\nKelas   : %s", kelas);
           		printf("\n================");
        	}
		fclose(in);
		getchar();

}

void update(){
	char nim [10],nama[100], kelas[10];
	printf("==Update Data==\n");
	printf("Masukkan nim : "); scanf("%s[^\n]", &nim); fflush(stdin);
	printf("Masukkan nama : "); scanf("%s[^\n]", &nama); fflush(stdin);
	printf("Masukkan kelas : "); scanf("%s[^\n]", &kelas); fflush(stdin);

	FILE *out=fopen("data mahasiswa.txt","a");
	fprintf(out,"%s\n#%s\n%s\n",nim, nama, kelas);
	fclose(out);
	printf("Sukses menambah data.");
	getchar();
        
}
void delete (){
	char nim[10];
	FILE *out=fopen("data mahasiswa.txt","w+");
	printf("== Delete Data ==\n");
	printf("Masukkan NIM yang ingin dihapus: ");
	scanf("%s", nim);
	
	up:
		for (i = 0; i < length; i++) {
			if (strcmp(User[i].nim, nim) == 0 && User[i].show == 1){
				strcpy(User[i].nim, "");
				User[i].show = 0;
				break;
			} else {
				printf("User tidak di temukan\n");
				goto up;
			}
		}
	sleep(1);
	fclose(out);
}
int main(void) {

    int pilih;

    top:
    	system("cls");
    	printf("Sistem Pendataan Akun I-Lab Infotech");
    	printf("\n\n=== Pilihan Menu ===");
    	printf("\n\n1. Create Data.");
    	printf("\n2. Show Data.");
    	printf("\n3. Update Data");
    	printf("\n4. Delete Data");
    	printf("\n5. Exit");

    	printf("\n\n Masukkan Pilihan : ");
    	scanf("%d", & pilih);

    	system("cls");
    	switch (pilih) {
    	case 1:
      		create();
      		goto top;
      		break;
    	case 2:
      		show();
      		goto top;
      		break;
    	case 3:
      		update();
      		goto top;
      		break;
    	case 4:
      		delete();
      		goto top;
      		break;
      	case 5:close();
			return 0;
			
    	}
    goto top;
}

