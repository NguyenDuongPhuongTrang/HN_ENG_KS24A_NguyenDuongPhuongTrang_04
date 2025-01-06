#include "function.h"
#include "datatype.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int size = 0;
	int *numberUser = &size;
	loadToFile(numberUser);
	int choice;
	char emailAdmin[50], passAdmin[50];
	char enterName[50], enterPass[50];
	printf("***Bank Management System Using C***\n\n");
	do{
		printf("\n\n");
		printf("\tCHOOSE YOUR ROLE");
		printf("\n================================\n");
		printf("\n[1]. Admin.\n");
		printf("\n[2]. User.\n");
		printf("\n[0]. Exit the program.\n");
		printf("\n================================\n");
		printf("Enter the choice: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				printf("\n\t     LOGIN");
				printf("\n================================\n");
				printf("Email: ");
				fgets(emailAdmin,sizeof(emailAdmin),stdin);
				emailAdmin[strcspn(emailAdmin, "\n")] = '\0';
				printf("Pass: ");
				char star;
				int index = 0;
				while((star = getch()) != '\r'){
					if(star == '\b'){
						if(index > 0){
							index--;
							printf("\b \b");
						}
					}
					else{
						printf("*");
						passAdmin[index++] = star;
					}
				}
				passAdmin[index] = '\0';
				printf("\n================================\n");
				if(strcmp(emailAdmin,"1") == 0 && strcmp(passAdmin,"1") == 0){
							menuAdmin(numberUser);
				}else{
					printf("\nTai khoan hoac mat khau khong hop le.\nVui long kiem tra lai.\n");
				}
				break;
			case 2:
				fflush(stdin);
				printf("\n\t     LOGIN");
				printf("\n================================\n");
				printf("Username: ");
				fgets(enterName,sizeof(enterName),stdin);
				enterName[strcspn(enterName, "\n")] = '\0';
				printf("Pass: ");
				int found = 0;
				char starU;
				int indexU = 0;
				while((starU = getch()) != '\r'){
					if(starU == '\b'){
						if(indexU > 0){
							indexU--;
							printf("\b \b");
						}
					}
					else{
						printf("*");
						enterPass[indexU++] = starU;
					}
				}
				enterPass[indexU] = '\0';
				printf("\n================================\n");
				for(int i=0; i<*numberUser; i++){
					if(strcmp(enterName,user[i].username) == 0 && strcmp(enterPass,user[i].acc.pass) == 0){
						found = 1;
						if(user[i].acc.status == 0){
							menuUser(numberUser,i);
							break;
						}
						else{
							printf("\nTai khoan dang bi khoa!Vui long kiem tra lai.\n");
						}
					}
				}
				if(found == 0){
					printf("\nTai khoan hoac mat khau khong hop le.\nVui long kiem tra lai.\n");
				}
				break;
			case 0:
				printf("\n===========THANHK YOU===========\n");
				printf("\n==========SEE YOU SOON==========\n");
				break;
			default:
				printf("\nERROR\n");
				break;
		}
	}while(choice!=0);
	return 0;
}

