//trien khai cac ham
#include"datatype.h"

void loadToFile(int *numberUser){
	FILE *file = fopen("bank.bin", "rb");
	if(file == NULL){
		printf("\nKhong the mo file!\n");
		return;
	}
	*numberUser = fread(&user, sizeof(struct Users), 100, file);
	fclose(file);
}

void saveFile(int *numberUser){
	FILE *file = fopen("bank.bin", "wb");
	if(file == NULL){
		return;
	}
	fwrite(&user, sizeof(struct Users), *numberUser, file);
	fclose(file);
}

int checkAny(char *check, int *numberUser, int flag){
	switch(flag){
		case 1:
			for(int i=0; i<*numberUser; i++){
				if(strcmp(user[*numberUser].id,user[i].id) == 0){
					return 0;
				}
			}
			return 1;
		case 2:
			for(int i=0; i<*numberUser; i++){
				if(strcmp(user[*numberUser].acc.email,user[i].acc.email) == 0){
					return 0;
				}
			}
			return 1;
		case 3:
			for(int i=0; i<*numberUser; i++){
				if(strcmp(user[*numberUser].phone,user[i].phone) == 0){
					return 0;
				}
			}
			return 1;
		case 4:
			for(int i=0; i<*numberUser; i++){
				if(strcmp(user[*numberUser].username,user[i].username) == 0){
					return 0;
				}
			}
			return 1;
		}
	}

void addUser(int *numberUser){
	getchar();
	do{
		printf("\nEnter the ID: ");
		fgets(user[*numberUser].id,20,stdin);
		user[*numberUser].id[strcspn(user[*numberUser].id, "\n")] = '\0';
		int found = 0;
		if(strlen(user[*numberUser].id) != 10){
			found = 1;
			printf("\nID khong hop le!Vui long nhap lai!\n");
		}
		for(int i = 0; i < 10; i++){
			if(!isdigit(user[*numberUser].id[i]) || user[*numberUser].id[i] == ' '){
				printf("\nID khong hop le!Vui long thu lai!\n");
				found = 1;
				break;
			}
		}
		if(checkAny(user[*numberUser].id, numberUser, 1) == 0){
			found = 1;
			printf("\nID da ton tai!\n");
		}
		if(found == 0){
			break;
		}
	}while(1);
		
	do{
		int found = 0;
		printf("\nEnter the name: ");
		fgets(user[*numberUser].name,50,stdin);
		user[*numberUser].name[strcspn(user[*numberUser].name, "\n")] = '\0';
		if(strlen(user[*numberUser].name) == 0){
			printf("\nTen khong hop le!Vui long thu lai!\n");
			found = 1;
		}
		if(user[*numberUser].name[0] == ' '){
			printf("\nTen khong hop le!Vui long thu lai!\n");
			found = 1;
		}
		int length = strlen(user[*numberUser].name);
		for(int i = 0; i < length; i++){
			if(!isalpha(user[*numberUser].name[i]) && user[*numberUser].name[i] != ' '){
				found = 1;
				printf("\nTen khong hop le!Vui long thu lai!\n");
				break;
			}
		}
		if(found == 0){
			break;
		}
	}while(1);
	
	do{
		char checkEmail[] = "@gmail.com";
		int checkEmailLength = strlen(checkEmail);
		int found = 0;
		printf("\nEnter the email: ");
		fgets(user[*numberUser].acc.email,20,stdin);
		user[*numberUser].acc.email[strcspn(user[*numberUser].acc.email, "\n")] = '\0';
		int emailLength = strlen(user[*numberUser].acc.email);
		if(isalnum(user[*numberUser].acc.email[0])){
        		if (emailLength >= checkEmailLength && strcmp(user[*numberUser].acc.email + emailLength - checkEmailLength, checkEmail) == 0){
		        }else{
		        	printf("\nEmail khong hop le! Vui long thu lai.\n");
		        	found = 1;
				}
        }else{
		    printf("\nEmail khong hop le! Vui long thu lai.\n");
		    found = 1;
		}
		if(checkAny(user[*numberUser].acc.email, numberUser, 2) == 0){
			printf("\nEmail da ton tai!\n");
			found = 1;
		}
		if(found == 0){
			break;
		}
	}while(1);
	
	do{
		int found = 0;
		printf("\nEnter the phone: ");
		fgets(user[*numberUser].phone,20,stdin);
		user[*numberUser].phone[strcspn(user[*numberUser].phone, "\n")] = '\0';
		if(strlen(user[*numberUser].phone) != 10){
			printf("\nSo dien thoai khong hop le!\n");
			found = 1;
		}
		if(checkAny(user[*numberUser].phone, numberUser, 3) == 0){
			printf("\nSo dien thoai da ton tai! Vui long nhap lai!\n");
			found = 1;
		}
		for(int i = 0; i < 10; i++){
			if(!isdigit(user[*numberUser].phone[i]) || user[*numberUser].phone[i] == ' '){
				printf("\nSo dien thoai khong hop le!Vui long thu lai!\n");
				found = 1;
				break;
			}
		}
		if(found == 0){
			break;
		}
	}while(1);
		
	fflush(stdin);
	
	do{
		printf("\nEnter the gender (0.Nu ; 1.Nam) ");
		scanf("%d", &user[*numberUser].gender);
		if(user[*numberUser].gender != 0 && user[*numberUser].gender != 1){
			printf("\nKhong hop le! Vui long thu lai!\n");
		}
	}while(user[*numberUser].gender != 0 && user[*numberUser].gender != 1);
	
	
	printf("\nEnter the date of birth:\n");
	do {
        printf("\n\tEnter the year: ");
        scanf("%d", &user[*numberUser].birth.year);
        if (user[*numberUser].birth.year <= 0 || user[*numberUser].birth.year > 2025) {
            printf("\nNam khong hop le.Vui long thu lai!\n");
        }
    } while (user[*numberUser].birth.year <= 0 || user[*numberUser].birth.year > 2025);
    do {
        printf("\n\tEnter the month: ");
        scanf("%d", &user[*numberUser].birth.month);
        if (user[*numberUser].birth.month <= 0 || user[*numberUser].birth.month > 12) {
            printf("\nThang khong hop le.Vui long thu lai!\n");
        }
    } while (user[*numberUser].birth.month <= 0 || user[*numberUser].birth.month > 12);
    do {
        switch (user[*numberUser].birth.month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                do {
                    printf("\n\tEnter the day: ");
                    scanf("%d", &user[*numberUser].birth.day);
                    if (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 31) {
                        printf("\nNgay khong hop le.Vui long thu lai!\n");
                    }
                } while (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 31);
                break;

            case 4: case 6: case 9: case 11:
                do {
                    printf("\n\tEnter the day: ");
                    scanf("%d", &user[*numberUser].birth.day);
                    if (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 30) {
                        printf("\nNgay khong hop le.Vui long thu lai!\n");
                    }
                } while (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 30);
                break;

            case 2:
                do {
                    printf("\n\tEnter the day: ");
                    scanf("%d", &user[*numberUser].birth.day);
                    if ((user[*numberUser].birth.year % 4 == 0 && user[*numberUser].birth.year % 100 != 0) || (user[*numberUser].birth.year % 400 == 0)) {
                        if (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 29) {
                            printf("\nNgay khong hop le.Vui long thu lai!\n");
                        }
                    } else {
                        if (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 28) {
                            printf("\nNgay khong hop le.Vui long thu lai!\n");
                        }
                    }
                } while ((user[*numberUser].birth.year % 4 == 0 && user[*numberUser].birth.year % 100 != 0) || (user[*numberUser].birth.year % 400 == 0) ? (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 29) : (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 28));
                break;

            default:
                printf("\nThang khong hop le.Vui long thu lai!\n");
                return ;
        }
        if (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 31) {
            printf("\nNgay khong hop le.Vui long thu lai!\n");
        }

    } while (user[*numberUser].birth.day <= 0 || user[*numberUser].birth.day > 31);
	getchar();
	
	do{
		int found = 0;
		printf("\nEnter the username: ");
		fgets(user[*numberUser].username,50,stdin);
		user[*numberUser].username[strcspn(user[*numberUser].username, "\n")] = '\0';
		if(strlen(user[*numberUser].username) == 0){
			printf("\nTen khong hop le!Vui long thu lai!\n");
			found = 1;
		}
		if(checkAny(user[*numberUser].username, numberUser, 4) == 0){
			printf("\nTen nguoi dung da ton tai! Vui long thu lai!\n");
			found = 1;
		}
		int lenght = strlen(user[*numberUser].username);
		for(int i = 0; i < lenght; i++){
			if(!isalnum(user[*numberUser].username[i]) || user[*numberUser].username[i] == ' '){
				printf("\nTen nguoi dung khong hop le!Vui long thu lai!\n");
				found = 1;
				break;
			}
		}
		if(found == 0){
			break;
		}
	}while(1);
	
	strcpy(user[*numberUser].acc.pass,user[*numberUser].phone);
	user[*numberUser].acc.status = 0;
	user[*numberUser].balance = 0;
	(*numberUser)++;
	saveFile(numberUser);
	printf("\nThem thanh cong!\n");
}

void showUser(int *numberUser) {
    if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung nao de hien thi.\n");
        return;
    }
    printf("\n+-----+------------------+----------------------+----------------------+------------------+\n");
    printf("| %-3s | %-16s | %-20s | %-20s | %-16s |\n", "STT", "ID", "Name", "Username", "Status");
    printf("+-----+------------------+----------------------+----------------------+------------------+\n");
    for (int i = 0; i < *numberUser; i++) {
        printf("| %-3d | %-16s | %-20s | %-20s | %-16s |\n", 
            i + 1,                    
            user[i].id,              
            user[i].name,            
            user[i].username,         
            user[i].acc.status == 0 ? "Unlock" : "Lock");         
    }
    printf("+-----+------------------+----------------------+----------------------+------------------+\n");
}

void showDetailUser(int *numberUser) {
    if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung nao de hien thi.\n");
        return;
    }
    printf("\n+-----+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
    printf("| %-3s | %-16s | %-20s | %-20s | %-12s | %-9s | %-10s | %-20s | %-20s | %-11s | %-14s |\n", 
        "STT", "ID", "Name", "Email", "Phone", "Gender", "Birthdate", "Username", "Password", "Balance", "Status");
    printf("+-----+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
    for (int i = 0; i < *numberUser; i++) {
        printf("| %-3d | %-16s | %-20s | %-20s | %-12s | %-9s | %02d/%02d/%4d | %-20s | %-20s | %-11.3f | %-14s |\n", 
            i + 1,                               
            user[i].id,                         
            user[i].name,                       
            user[i].acc.email,                  
            user[i].phone,                      
            user[i].gender == 0 ? "Nu" : "Nam",                    
            user[i].birth.day,                  
            user[i].birth.month,                
            user[i].birth.year,                 
            user[i].username,                   
            user[i].acc.pass,               
            user[i].balance,                    
            user[i].acc.status == 0 ? "Unlock" : "Lock"
        );
    }
    printf("+-----+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
}

void statusAcc(int *numberUser) {
	if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung de tim kiem.\n");
        return;
    }
    char checkID[20];
    fflush(stdin);
    int found = 0;
	printf("\nNhap ID can sua: ");
	fgets(checkID,20,stdin);
	checkID[strcspn(checkID, "\n")] = '\0';
	for (int i=0 ; i<*numberUser; i++){
    	if(strcmp(checkID, user[i].id) == 0){
    		printf("\nTrang thai tai khoan: %s\n", user[i].acc.status == 0 ? "Unlock" : "Lock");
    		int status;
    		do{
    			int choiceS;
    			printf("\nSua trang thai tai khoan (0.Unlock ; 1.Lock) ");
    			scanf("%d",&status);
    			switch(status){
    				case 0:
    					printf("\nBan co chac chan muon mo khoa tai khoan khong?(0.Yes / 1.No) ");
    					scanf("%d",&choiceS);
    					switch(choiceS){
							case 1:
								printf("\nMo khoa that bai!\n");
								break;
							case 0:
								user[i].acc.status = status;
								printf("\nMo khoa thanh cong!\n");
								break;
							default:
								printf("\nERROR\n");
		    					break;
		    				}
		    			break;
    				case 1:
    					printf("\nBan co chac chan muon khoa tai khoan khong?(0.Yes / 1.No) ");
    					scanf("%d",&choiceS);
    					switch(choiceS){
							case 1:
								printf("\nKhoa that bai!\n");
								break;
							case 0:
								user[i].acc.status = status;
								printf("\nKhoa thanh cong!\n");
								break;
							default:
								printf("\nERROR\n");
		    					break;
		    				}
		    			break;
    				default:
    					printf("\nERROR\n");
    					break;
				}
			}while(status!=0 && status!=1);
			printf("\nSua thanh cong!\n");
			saveFile(numberUser);
			return;
		}
	}
	printf("\nID khong ton tai\n");
}

void searchByID(int *numberUser) {
    if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung de tim kiem.\n");
        return;
    }
    fflush(stdin);
    char searchID[20];
    do{
	    printf("\nNhap ID tim kiem: ");
	    fgets(searchID, 20, stdin);
	    searchID[strcspn(searchID, "\n")] = '\0'; 
		if(strlen(searchID) != 10){
			printf("\nID khong hop le!Vui long nhap lai!\n");
		}
	}while(strlen(searchID) != 10);
    for (int i = 0; i < *numberUser; i++) {
        if (strcmp(searchID, user[i].id) == 0) {
            printf("\n+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            printf("| %-16s | %-20s | %-20s | %-12s | %-9s | %-10s | %-20s | %-20s | %-11s | %-14s |\n", 
                "ID", "Name", "Email", "Phone", "Gender", "Birthdate", "Username", "Password", "Balance", "Status");
            printf("+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            printf("| %-16s | %-20s | %-20s | %-12s | %-9s | %02d/%02d/%4d | %-20s | %-20s | %-11.3f | %-14s |\n", 
                user[i].id,                        
                user[i].name,                      
                user[i].acc.email,                
                user[i].phone,                     
                user[i].gender == 0 ? "Nu" : "Nam",                      
                user[i].birth.day,                 
                user[i].birth.month,               
                user[i].birth.year,                
                user[i].username,                  
                user[i].acc.pass,              
                user[i].balance,                   
                user[i].acc.status == 0 ? "Unlock" : "Lock"                    
            );
            printf("+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            return;
        }
    }
    printf("\nID nguoi dung khong ton tai!\n");
}

void sortUserByName(int *numberUser){
	if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung nao de sap xep.\n");
        return;
    }
	int choiceSort;
	printf("Moi ban chon:\n");
	printf("[1]. Tang dan\n");
	printf("[2]. Giam dan\n");
	scanf("%d",&choiceSort);
	fflush(stdin);
	switch(choiceSort){
		case 1:
			for(int i=0; i<*numberUser; i++){
    			for(int j=0; j < *numberUser - 1 - i; j++){
    				if(strcmp(user[j].name,user[j+1].name) > 0){
    					struct Users temp = user[j];
    					user[j] = user[j+1];
    					user[j+1] = temp;
					}
				}
			}
			printf("\nDanh sach nguoi dung da duoc sap xep theo ten.\n");
			break;
		case 2:
			for(int i=0; i<*numberUser; i++){
    			for(int j=0; j < *numberUser - 1 - i; j++){
    				if(strcmp(user[j].name,user[j+1].name) < 0){
    					struct Users temp = user[j];
    					user[j] = user[j+1];
    					user[j+1] = temp;
					}
				}
			}
			printf("\nDanh sach nguoi dung da duoc sap xep theo ten.\n");
			break;
	}
}

void searchByName(int *numberUser) {
    if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung de tim kiem.\n");
        return;
    }
    char keyword[50];
    char fullName[100];
    fflush(stdin);
	do{
		int found = 0;
		printf("\nNhap ten de tim kiem: ");
    	fgets(keyword, 50, stdin);
    	keyword[strcspn(keyword, "\n")] = '\0';
		if(strlen(keyword) == 0){
			printf("\nTen khong hop le!Vui long thu lai!\n");
			found = 1;
		}
		if(found == 0){
			break;
		}
	}while(1);
    int find = 0; 
    strlwr(keyword);  
    printf("\nKet qua tim kiem:\n");
    printf("+----+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
    printf("| STT| ID               | Name                 | Email                | Phone        | Gender    | Birthdate  | Username             | Password             | Balance     | Status         |\n");
    printf("+----+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
    for (int i = 0; i < *numberUser; i++) {
        strcpy(fullName, user[i].name);
        strlwr(fullName);  
        if (strstr(fullName, keyword) != NULL) {
            printf("| %-2d | %-16s | %-20s | %-20s | %-12s | %-9s | %02d/%02d/%4d | %-20s | %-20s | %-11.3f | %-14s |\n",
                   i + 1,                              
                   user[i].id,                       
                   user[i].name,                       
                   user[i].acc.email,                 
                   user[i].phone,                     
                   user[i].gender == 0 ? "Nu" : "Nam",                       
                   user[i].birth.day,                  
                   user[i].birth.month,                
                   user[i].birth.year,                 
                   user[i].username,                   
                   user[i].acc.pass,              
                   user[i].balance,                   
                   user[i].acc.status == 0 ? "Unlock" : "Lock"  
            );
            find = 1;
        }
    }
    printf("+----+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
    if (find != 1) {
        printf("\nKhong tim thay nguoi dung nao phu hop voi tu khoa '%s'.\n", keyword);
    }
}

void deleteByID(int *numberUser){
	if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung de xoa.\n");
        return;
    }
    char delID[20];
    fflush(stdin);
    int found = 0;
    printf("\nNhap ID de xoa: ");
    fgets(delID,20,stdin);
    delID[strcspn(delID, "\n")] = '\0';
    for(int i = 0; i<*numberUser; i++){
    	if(strcmp(delID,user[i].id) == 0){
    		for(int j = i; j<*numberUser; j++){
    			user[j] = user[j+1];
			}
			(*numberUser)--;
			found = 1;
		}
	}
	if(found == 0){
		printf("\nID khong ton tai!\n");
	}else{
		printf("\nXoa thanh cong!\n");
	}
}

void editUser(int *numberUser){
	if (numberUser == NULL || *numberUser <= 0) {
        printf("\nKhong co nguoi dung de sua.\n");
        return;
    }
    char editID[20];
    fflush(stdin);
    int found = 0;
    printf("\nNhap ID de sua: ");
    fgets(editID,20,stdin);
    editID[strcspn(editID, "\n")] = '\0';
    for(int i=0; i<*numberUser; i++){
    	if(strcmp(editID,user[i].id) == 0){
    		printf("\n+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            printf("| %-16s | %-20s | %-20s | %-12s | %-9s | %-10s | %-20s | %-20s | %-11s | %-14s |\n", 
                "ID", "Name", "Email", "Phone", "Gender", "Birthdate", "Username", "Password", "Balance", "Status");
            printf("+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            printf("| %-16s | %-20s | %-20s | %-12s | %-9s | %02d/%02d/%4d | %-20s | %-20s | %-11.3f | %-14s |\n", 
                user[i].id,                        
                user[i].name,                      
                user[i].acc.email,                
                user[i].phone,                     
                user[i].gender == 0 ? "Nu" : "Nam",                      
                user[i].birth.day,                 
                user[i].birth.month,               
                user[i].birth.year,                
                user[i].username,                  
                user[i].acc.pass,              
                user[i].balance,                   
                user[i].acc.status == 0 ? "Unlock" : "Lock"                    
            );
            printf("+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            
			int choiceName;
			printf("\nBan co muon sua ho va ten khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceName);
            fflush(stdin);
            switch(choiceName){
            	case 0:
            		do{
						int found = 0;
						printf("\nHo va ten moi: ");
						fgets(user[i].name,50,stdin);
						user[i].name[strcspn(user[i].name, "\n")] = '\0';
						if(strlen(user[i].name) == 0){
							printf("\nTen khong hop le!Vui long thu lai!\n");
							found = 1;
						}
						if(user[i].name[0] == ' '){
							printf("\nTen khong hop le!Vui long thu lai!\n");
							found = 1;
						}
						int length = strlen(user[i].name);
						for(int j = 0; j < length; j++){
							if(!isalpha(user[i].name[j]) && user[i].name[j] != ' '){
								found = 1;
								printf("\nTen khong hop le!Vui long thu lai!\n");
								break;
							}
						}
						if(found == 0){
							break;
						}
					}while(1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceEmail;
			printf("\nBan co muon sua email khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceEmail);
            fflush(stdin);
            switch(choiceEmail){
            	case 0:
            		do{
						char checkEmail[] = "@gmail.com";
						int checkEmailLength = strlen(checkEmail);
						int found = 0;
						printf("\nEmail moi: ");
						fgets(user[i].acc.email,20,stdin);
						user[i].acc.email[strcspn(user[i].acc.email, "\n")] = '\0';
						int emailLength = strlen(user[i].acc.email);
						if(isalnum(user[i].acc.email[0])){
				        		if (emailLength >= checkEmailLength && strcmp(user[i].acc.email + emailLength - checkEmailLength, checkEmail) == 0){
						        }else{
						        	printf("\nEmail khong hop le! Vui long thu lai.\n");
						        	found = 1;
								}
				        }else{
						    printf("\nEmail khong hop le! Vui long thu lai.\n");
						    found = 1;
						}
						if(checkAny(user[i].acc.email, numberUser, 2) == 0){
							printf("\nEmail da ton tai!\n");
							found = 1;
						}
						if(found == 0){
							break;
						}
					}while(1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choicePhone;
			printf("\nBan co muon sua so dien thoai khong? (0.Yes / 1.No) ");
            scanf("%d",&choicePhone);
            fflush(stdin);
            switch(choicePhone){
            	case 0:
            		do{
						int found = 0;
						printf("\nSo dien thoai moi: ");
						fgets(user[i].phone,20,stdin);
						user[i].phone[strcspn(user[i].phone, "\n")] = '\0';
						if(strlen(user[i].phone) != 10){
							printf("\nSo dien thoai khong hop le!\n");
							found = 1;
						}
						if(checkAny(user[i].phone, numberUser, 3) == 0){
							printf("\nSo dien thoai da ton tai! Vui long nhap lai!\n");
							found = 1;
						}
						for(int j = 0; j < 10; j++){
							if(!isdigit(user[i].phone[j]) || user[i].phone[j] == ' '){
								printf("\nSo dien thoai khong hop le!Vui long thu lai!\n");
								found = 1;
								break;
							}
						}
						if(found == 0){
							break;
						}
					}while(1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceGender;
			printf("\nBan co muon sua gioi tinh khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceGender);
            fflush(stdin);
            switch(choiceGender){
            	case 0:
            		do{
						printf("\nNhap gioi tinh (0.Nu ; 1.Nam) ");
						scanf("%d", &user[i].gender);
						if(user[i].gender != 0 && user[i].gender != 1){
							printf("\nKhong hop le! Vui long thu lai!\n");
						}
					}while(user[i].gender != 0 && user[i].gender != 1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceBirth;
			printf("\nBan co muon sua ngay thang nam sinh khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceBirth);
            fflush(stdin);
            switch(choiceBirth){
            	case 0:
            		printf("\nNgay thang nam sinh moi:\n");
					do {
				        printf("\n\tNam: ");
				        scanf("%d", &user[i].birth.year);
				        if (user[i].birth.year <= 0 || user[i].birth.year > 2025) {
				            printf("\nNam khong hop le.Vui long thu lai!\n");
				        }
				    } while (user[i].birth.year <= 0 || user[i].birth.year > 2025);
				    do {
				        printf("\n\tThang: ");
				        scanf("%d", &user[i].birth.month);
				        if (user[i].birth.month <= 0 || user[i].birth.month > 12) {
				            printf("\nThang khong hop le.Vui long thu lai!\n");
				        }
				    } while (user[i].birth.month <= 0 || user[i].birth.month > 12);
				    do {
				        switch (user[i].birth.month) {
				            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				                do {
				                    printf("\n\tNgay: ");
				                    scanf("%d", &user[i].birth.day);
				                    if (user[i].birth.day <= 0 || user[i].birth.day > 31) {
				                        printf("\nNgay khong hop le.Vui long thu lai!\n");
				                    }
				                } while (user[i].birth.day <= 0 || user[i].birth.day > 31);
				                break;
				
				            case 4: case 6: case 9: case 11:
				                do {
				                    printf("\n\tNgay: ");
				                    scanf("%d", &user[i].birth.day);
				                    if (user[i].birth.day <= 0 || user[i].birth.day > 30) {
				                        printf("\nNgay khong hop le.Vui long thu lai!\n");
				                    }
				                } while (user[i].birth.day <= 0 || user[i].birth.day > 30);
				                break;
				
				            case 2:
				                do {
				                    printf("\n\tNgay: ");
				                    scanf("%d", &user[i].birth.day);
				                    if ((user[i].birth.year % 4 == 0 && user[i].birth.year % 100 != 0) || (user[i].birth.year % 400 == 0)) {
				                        if (user[i].birth.day <= 0 || user[i].birth.day > 29) {
				                            printf("\nNgay khong hop le.Vui long thu lai!\n");
				                        }
				                    } else {
				                        if (user[i].birth.day <= 0 || user[i].birth.day > 28) {
				                            printf("\nNgay khong hop le.Vui long thu lai!\n");
				                        }
				                    }
				                } while ((user[i].birth.year % 4 == 0 && user[i].birth.year % 100 != 0) || (user[i].birth.year % 400 == 0) ? (user[i].birth.day <= 0 || user[i].birth.day > 29) : (user[i].birth.day <= 0 || user[i].birth.day > 28));
				                break;
				
				            default:
				                printf("\nThang khong hop le.Vui long thu lai!\n");
				                return ;
				        }
				        if (user[i].birth.day <= 0 || user[i].birth.day > 31) {
				            printf("\nNgay khong hop le.Vui long thu lai!\n");
				        }
				
				    } while (user[i].birth.day <= 0 || user[i].birth.day > 31);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceUsername;
			char newUsername[50];
			printf("\nBan co muon sua ten dang nhap khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceUsername);
            fflush(stdin);
            switch(choiceUsername){
            	case 0:
            		do{
						int found = 0;
						printf("\nTen dang nhap moi: ");
						fgets(newUsername,50,stdin);
						newUsername[strcspn(newUsername, "\n")] = '\0';
						if(strlen(newUsername) == 0){
							printf("\nTen khong hop le!Vui long thu lai!\n");
							found = 1;
						}
						int lenght = strlen(newUsername);
						for(int j = 0; j < lenght; j++){
							if(!isalnum(newUsername[j]) || newUsername[j] == ' '){
								printf("\nTen nguoi dung khong hop le!Vui long thu lai!\n");
								found = 1;
								break;
							}
						}
						if(checkAny(newUsername, numberUser, 4) == 0){
							printf("\nTen nguoi dung da ton tai! Vui long thu lai!\n");
							found = 1;
						}
						if(found == 0){
							break;
						}
					}while(1);
					strcpy(user[i].username, newUsername);
					printf("\nSua thanh cong!\n");
	            	break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
		}
	}
}

void showBalance(int *numberUser,int i, struct Users *user){
	printf("So du tai khoan la: %.3f\n",user[i].balance);
}

void depositMoney(int *numberUser,int i, struct Users *user){
	float money;
	do{
		printf("\nSo tien muon nap vao tai khoan: ");
		scanf("%f",&money);
		if(money <= 0){
			printf("\nSo tien nap vao khong hop le!Vui long thu lai!\n");
		}
	}while(money <= 0);
	user[i].balance += money;
	printf("\nNap thanh cong!\n");
}

void withDrawMoney(int *numberUser,int i, struct Users *user){
	float money;
	do{
		printf("\nSo tien muon rut: ");
		scanf("%f",&money);
		if(money <= 0){
			printf("\nSo tien muon rut khong hop le!Vui long thu lai!\n");
		}
		if(money > user[i].balance){
			printf("\nSo du trong tai khoan khong du! Vui long thu lai!\n");
		}
	}while(money <= 0 || money > user[i].balance);
	user[i].balance -= money;
	printf("\nRut thanh cong!\n");
}

void transaction(int *numberUser,int i, struct Users *user){
	char transID[20];
	float trans;
	do{
		fflush(stdin);
		printf("\nNhap ID muon chuyen tien: ");
		fgets(transID, 20, stdin);
		transID[strcspn(transID, "\n")] = '\0';
		if(strlen(transID) != 10){
				printf("\nID khong hop le!Vui long nhap lai!\n");
				break;
			}
		int found = 0;
		for (int j = 0; j < *numberUser; j++) {
	        if (strcmp(transID, user[j].id) == 0){
	        	if(strcmp(user[i].id, user[j].id) == 0){
	        		printf("\nKhong the tu chuyen tien cho chinh minh!\n");
                    found = 1;
                    break;
	        	}
	        	printf("\nNhap so tien muon chuyen: ");
				scanf("%f",&trans);
				if (user[i].balance < trans) {
		            printf("\nSo du khong du de thuc hien giao dich!\n");
		            found = 1;
		            break;
		        }
		        if(trans <= 0){
					printf("\nSo tien khong hop le!Vui long thu lai!\n");
					found = 1;
					break;
				}
				user[j].balance += trans;
				user[i].balance -= trans;
				printf("\nChuyen tien thanh cong\n");
				return;
			}
	    }
		if(found == 0){
			printf("ID khong ton tai!Vui long thu lai!");
		}
	}while(1);
}

void changeInfor(int *numberUser, int i, struct Users *user){
    		printf("\n+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            printf("| %-16s | %-20s | %-20s | %-12s | %-9s | %-10s | %-20s | %-20s | %-11s | %-14s |\n", 
                "ID", "Name", "Email", "Phone", "Gender", "Birthdate", "Username", "Password", "Balance", "Status");
            printf("+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            printf("| %-16s | %-20s | %-20s | %-12s | %-9s | %02d/%02d/%4d | %-20s | %-20s | %-11.3f | %-14s |\n", 
                user[i].id,                        
                user[i].name,                      
                user[i].acc.email,                
                user[i].phone,                     
                user[i].gender == 0 ? "Nu" : "Nam",                      
                user[i].birth.day,                 
                user[i].birth.month,               
                user[i].birth.year,                
                user[i].username,                  
                user[i].acc.pass,              
                user[i].balance,                   
                user[i].acc.status == 0 ? "Unlock" : "Lock"                    
            );
            printf("+------------------+----------------------+----------------------+--------------+-----------+------------+----------------------+----------------------+-------------+----------------+\n");
            
            int choiceUserName;
			printf("\nBan co muon sua ho va ten khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceUserName);
            fflush(stdin);
            switch(choiceUserName){
            	case 0:
            		do{
						int found = 0;
						printf("\nHo va ten moi: ");
						fgets(user[i].name,50,stdin);
						user[i].name[strcspn(user[i].name, "\n")] = '\0';
						if(strlen(user[i].name) == 0){
							printf("\nTen khong hop le!Vui long thu lai!\n");
							found = 1;
						}
						if(user[i].name[0] == ' '){
							printf("\nTen khong hop le!Vui long thu lai!\n");
							found = 1;
						}
						int length = strlen(user[i].name);
						for(int j = 0; j < length; j++){
							if(!isalpha(user[i].name[j]) && user[i].name[j] != ' '){
								found = 1;
								printf("\nTen khong hop le!Vui long thu lai!\n");
								break;
							}
						}
						if(found == 0){
							break;
						}
					}while(1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceUserEmail;
			printf("\nBan co muon sua email khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceUserEmail);
            fflush(stdin);
            switch(choiceUserEmail){
            	case 0:
            		do{
						char checkEmail[] = "@gmail.com";
						int checkEmailLength = strlen(checkEmail);
						int found = 0;
						printf("\nEmail moi: ");
						fgets(user[i].acc.email,20,stdin);
						user[i].acc.email[strcspn(user[i].acc.email, "\n")] = '\0';
						int emailLength = strlen(user[i].acc.email);
						if(isalnum(user[i].acc.email[0])){
				        		if (emailLength >= checkEmailLength && strcmp(user[i].acc.email + emailLength - checkEmailLength, checkEmail) == 0){
						        }else{
						        	printf("\nEmail khong hop le! Vui long thu lai.\n");
						        	found = 1;
								}
				        }else{
						    printf("\nEmail khong hop le! Vui long thu lai.\n");
						    found = 1;
						}
						if(checkAny(user[i].acc.email, numberUser, 2) == 0){
							printf("\nEmail da ton tai!\n");
							found = 1;
						}
						if(found == 0){
							break;
						}
					}while(1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceUserPhone;
			printf("\nBan co muon sua so dien thoai khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceUserPhone);
            fflush(stdin);
            switch(choiceUserPhone){
            	case 0:
            		do{
						int found = 0;
						printf("\nSo dien thoai moi: ");
						fgets(user[i].phone,20,stdin);
						user[i].phone[strcspn(user[i].phone, "\n")] = '\0';
						if(strlen(user[i].phone) != 10){
							printf("\nSo dien thoai khong hop le!\n");
							found = 1;
						}
						if(checkAny(user[i].phone, numberUser, 3) == 0){
							printf("\nSo dien thoai da ton tai! Vui long nhap lai!\n");
							found = 1;
						}
						for(int j = 0; j < 10; j++){
							if(!isdigit(user[i].phone[j]) || user[i].phone[j] == ' '){
								printf("\nSo dien thoai khong hop le!Vui long thu lai!\n");
								found = 1;
								break;
							}
						}
						if(found == 0){
							break;
						}
					}while(1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
		}
			
			int choiceUserGender;
			printf("\nBan co muon sua gioi tinh khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceUserGender);
            fflush(stdin);
            switch(choiceUserGender){
            	case 0:
            		do{
						printf("\nNhap gioi tinh (0.Nu ; 1.Nam) ");
						scanf("%d", &user[i].gender);
						if(user[i].gender != 0 && user[i].gender != 1){
							printf("\nKhong hop le! Vui long thu lai!\n");
						}
					}while(user[i].gender != 0 && user[i].gender != 1);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceUserBirth;
			printf("\nBan co muon sua ngay thang nam sinh khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceUserBirth);
            fflush(stdin);
            switch(choiceUserBirth){
            	case 0:
            		printf("\nNgay thang nam sinh moi:\n");
					do {
				        printf("\n\tNam: ");
				        scanf("%d", &user[i].birth.year);
				        if (user[i].birth.year <= 0 || user[i].birth.year > 2025) {
				            printf("\nNam khong hop le.Vui long thu lai!\n");
				        }
				    } while (user[i].birth.year <= 0 || user[i].birth.year > 2025);
				    do {
				        printf("\n\tThang: ");
				        scanf("%d", &user[i].birth.month);
				        if (user[i].birth.month <= 0 || user[i].birth.month > 12) {
				            printf("\nThang khong hop le.Vui long thu lai!\n");
				        }
				    } while (user[i].birth.month <= 0 || user[i].birth.month > 12);
				    do {
				        switch (user[i].birth.month) {
				            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				                do {
				                    printf("\n\tNgay: ");
				                    scanf("%d", &user[i].birth.day);
				                    if (user[i].birth.day <= 0 || user[i].birth.day > 31) {
				                        printf("\nNgay khong hop le.Vui long thu lai!\n");
				                    }
				                } while (user[i].birth.day <= 0 || user[i].birth.day > 31);
				                break;
				
				            case 4: case 6: case 9: case 11:
				                do {
				                    printf("\n\tNgay: ");
				                    scanf("%d", &user[i].birth.day);
				                    if (user[i].birth.day <= 0 || user[i].birth.day > 30) {
				                        printf("\nNgay khong hop le.Vui long thu lai!\n");
				                    }
				                } while (user[i].birth.day <= 0 || user[i].birth.day > 30);
				                break;
				
				            case 2:
				                do {
				                    printf("\n\tNgay: ");
				                    scanf("%d", &user[i].birth.day);
				                    if ((user[i].birth.year % 4 == 0 && user[i].birth.year % 100 != 0) || (user[i].birth.year % 400 == 0)) {
				                        if (user[i].birth.day <= 0 || user[i].birth.day > 29) {
				                            printf("\nNgay khong hop le.Vui long thu lai!\n");
				                        }
				                    } else {
				                        if (user[i].birth.day <= 0 || user[i].birth.day > 28) {
				                            printf("\nNgay khong hop le.Vui long thu lai!\n");
				                        }
				                    }
				                } while ((user[i].birth.year % 4 == 0 && user[i].birth.year % 100 != 0) || (user[i].birth.year % 400 == 0) ? (user[i].birth.day <= 0 || user[i].birth.day > 29) : (user[i].birth.day <= 0 || user[i].birth.day > 28));
				                break;
				
				            default:
				                printf("\nThang khong hop le.Vui long thu lai!\n");
				                return ;
				        }
				        if (user[i].birth.day <= 0 || user[i].birth.day > 31) {
				            printf("\nNgay khong hop le.Vui long thu lai!\n");
				        }
				
				    } while (user[i].birth.day <= 0 || user[i].birth.day > 31);
					printf("\nSua thanh cong!\n");
            		break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
			
			int choiceNewUsername;
			printf("\nBan co muon sua ten dang nhap khong? (0.Yes / 1.No) ");
            scanf("%d",&choiceNewUsername);
            fflush(stdin);
            switch(choiceNewUsername){
            	case 0:
            		do{
						int found = 0;
						printf("\nTen dang nhap moi: ");
						fgets(user[i].username,50,stdin);
						user[i].username[strcspn(user[i].username, "\n")] = '\0';
						if(strlen(user[i].username) == 0){
							printf("\nTen khong hop le!Vui long thu lai!\n");
							found = 1;
						}
						if(checkAny(user[i].username, numberUser, 4) == 0){
							printf("\nTen nguoi dung da ton tai! Vui long thu lai!\n");
							found = 1;
						}
						int lenght = strlen(user[i].username);
						for(int j = 0; j < lenght; j++){
							if(!isalnum(user[i].username[j]) || user[i].username[j] == ' '){
								printf("\nTen nguoi dung khong hop le!Vui long thu lai!\n");
								found = 1;
								break;
							}
						}
						if(found == 0){
							break;
						}
					}while(1);
					printf("\nSua thanh cong!\n");
	            	break;
            	case 1:
            		printf("\nGiu nguyen.\n");
            		break;
            	default:
            		printf("\nERROR\n");
            		break;
			}
}

void changePass(int *numberUser, int i, struct Users *user){
	fflush(stdin);
	char oldPass[20];
	char newPass[50];
	char checkNewPass[50];
	int found = 0;
	while(1){
		printf("\nNhap mat khau hien tai: ");
		fgets(oldPass,20,stdin);
		oldPass[strcspn(oldPass, "\n")] = '\0';
		if(strcmp(oldPass,user[i].acc.pass) == 0){
			while(1){
				printf("\nNhap mat khau moi: ");
				fgets(newPass,50,stdin);
				newPass[strcspn(newPass, "\n")] = '\0';
				int length = strlen(newPass);
				if(length <= 8){
					printf("\nMat khau qua ngan! Vui long thu lai!\n");
				}else{
					while(1){
						printf("\nNhap lai mat khau moi: ");
						fgets(checkNewPass,50,stdin);
						checkNewPass[strcspn(checkNewPass, "\n")] = '\0';
						if(strcmp(checkNewPass,newPass) == 0){
							strcpy(user[i].acc.pass, checkNewPass);
							found = 1;
							printf("\nDoi mat khau hoan tat!\n");
							break;
						}else{
							printf("\nSai mat khau!\n");
						}
					}
				}
				if(found == 1){
					break;
				}
			}
		}else{
			printf("\nMat khau sai!\n");
		}
		if(found == 1){
			break;
		}
	}
}

void backOrExit(int *numberUser){
	fflush(stdin);
	char choiceBE;
	do{
		printf("\nGo Back(b) or Exit(0)?  ");
		scanf("%c",&choiceBE);
		getchar();
		switch(choiceBE){
			case 'b':
				break;
			case '0':
				printf("\nTHOAT THANH CONG\n");
				exit(0);
			default:
				printf("\nERROR\n");
				break;
		}
	}while(choiceBE!='b');
}

void menuAdmin(int *numberUser){
	int choiceAdmin;
	do{
		printf("\n\t      MENU");
		printf("\n================================\n");
		printf("\n[1]. Add a new user.");
		printf("\n[2]. Show all user.");
		printf("\n[3]. Show detail an user.");
		printf("\n[4]. Lock (Unlock) an user.");
		printf("\n[5]. Search for users by ID.");
		printf("\n[6]. Sort users by name (ascending/descending).");	
		printf("\n[7]. Search for users by name.");
		printf("\n[8]. Delete users by ID");
		printf("\n[9]. Edit users by ID");
		printf("\n[0]. Thoat.");
		printf("\n================================\n");
		printf("Enter the choice: ");
		scanf("%d",&choiceAdmin);
		system("cls");
		switch(choiceAdmin){
			case 1:
				addUser(numberUser);
				backOrExit(numberUser);
				break;
			case 2:
				showUser(numberUser);
				backOrExit(numberUser);
				break;
			case 3:
				showDetailUser(numberUser);
				backOrExit(numberUser);
				break;
			case 4:
				statusAcc(numberUser);
				backOrExit(numberUser);
				break;
			case 5:
				searchByID(numberUser);
				backOrExit(numberUser);
				break;
			case 6:
				sortUserByName(numberUser);
				backOrExit(numberUser);
				break;
			case 7:
				searchByName(numberUser);
				backOrExit(numberUser);
				break;
			case 8:
				deleteByID(numberUser);
				saveFile(numberUser);
				backOrExit(numberUser);
				break;
			case 9:
				editUser(numberUser);
				saveFile(numberUser);
				backOrExit(numberUser);
				break;
			case 0:
				printf("\nTHOAT THANH CONG\n");
				return;
			default:
				printf("\nERROR\n");
				break;
		}
	}while(choiceAdmin != 0);
	return;
}

void menuUser(int *numberUser, int i){
	int choiceUser;
	do{
		printf("\n\t      MENU");
		printf("\n================================\n");
		printf("\n[1]. Show Balance.");
		printf("\n[2]. Deposit Money.");
		printf("\n[3]. Withdraw Money.");
		printf("\n[4]. Transfer Money.");
		printf("\n[5]. Change Password.");
		printf("\n[6]. User Guideline.");
		printf("\n[7]. About Us");
		printf("\n[0]. Thoat.");
		printf("\n================================\n");
		printf("Enter the choice: ");
		scanf("%d",&choiceUser);
		system("cls");
		switch(choiceUser){
			case 1:
				showBalance(numberUser,i,user);
				backOrExit(numberUser);
				break;
			case 2:
				depositMoney(numberUser,i,user);
				saveFile(numberUser);
				backOrExit(numberUser);
				break;
			case 3:
				withDrawMoney(numberUser, i, user);
				saveFile(numberUser);
				backOrExit(numberUser);
				break;
			case 4:
				transaction(numberUser,i,user);
				saveFile(numberUser);
				backOrExit(numberUser);
				break;
			case 5:
				changePass(numberUser,i,user);
				saveFile(numberUser);
				backOrExit(numberUser);
				break;
			case 6:
				break;
			case 7:
				break;
			case 0:
				printf("\nTHOAT THANH CONG\n");
				break;
			default:
				printf("\nERROR\n");
				break;
		}
	}while(choiceUser!=0);
	return;
}







