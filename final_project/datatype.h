// noi import thu vien, khai bao cac struct
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

struct Transaction{
	
};
struct Date{
	int day;
	int month;
	int year;
};
struct Accounts{
	char email[20];
	char pass[50];
	int status;
};
struct Users{
	char id[20];
	char name[50];
	struct Date birth;
	struct Accounts acc;
	int gender;
	char phone[20];
	char username[50];
	float balance;
};

struct Users user[100];

