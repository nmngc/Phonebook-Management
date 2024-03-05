#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person
{
    char name[30];
    char address[64];
    char mble_no[20];
    char sex[8];
    char mail[100];
};
struct person p;


void remove_all();
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();


void start(void);

int main()
{
    char username[30], password[20];

    while (1)
    {
        printf("Enter your username: ");
        scanf("%[^\n]s", username);
        fflush(stdin);
        printf("Enter your password: ");
        scanf("%[^\n]s", password);
        fflush(stdin);
        if (strcmp(username, "hi") == 0 && strcmp(password, "hi") == 0)
        {
            start();
        }
        else
        {
            printf("Invalid username or password!\n");
        }
    } 
    return 0;
}

void start()
{
    int choice;
    while (1)
    {
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            list_record();
            getchar();
            getchar();
            break;
        case 2:
            add_person();
            getchar();
            break;
        case 3:
            search_person();
            getchar();
            break;
        case 4:
            remove_person();
            getchar();
            break;
        case 5:
            update_person();
            getchar();
            break;
        case 6:
            remove_all();
            getchar();
            getchar();
            break;
        case 7: 
            system("cls");
            printf("Thanks for using phonebook visit again : )\n");
            getchar();
            exit(1);
            break;
        default:
            printf("Please re-enter!!!!\n");
            getchar();
            break;
            
        }
    }
}


void take_input() {

    system("cls");
    getchar();
    printf("Enter name : ");
    gets(p.name);

    printf("Enter address : ");
    gets(p.address);

    printf("Enter mobile no : ");
    gets(p.mble_no);

    printf("Enter sex : ");
    gets(p.sex);

    printf("Enter email : ");
    gets(p.mail);

} 

void print_menu(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  Welcome to my phone book                    *\n");
    printf("\t\t*               Group 6 - VNUIS - Programming 1                *\n");
    printf("\t\t*               Guided by: Teacher Pham Ngoc Thanh             *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) List record\n\n");
    printf("\t\t\t2) Add person\n\n");
    printf("\t\t\t3) Search person details\n\n");
    printf("\t\t\t4) Remove person\n\n");
    printf("\t\t\t5) Update person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) Exit phonebook\n\n\n");
    
    printf("\t\t\t\tEnter your Choice : ");
}

void add_person()
{
    system("cls");
    FILE *fp; 
    fp = fopen("phonebook_db 4.txt", "ab+"); 
    
    if (fp == NULL){
        printf("Error in file opening, Please try again !\n");
        printf("Press any key to continue....\n");
    }
    else{
		take_input(p);
        fwrite(&p, sizeof(p), 1, fp); 
        system("cls"); 
        printf("Record added Successfully\n"); 
        printf("Press any key to continue ....\n");
    }
    fclose(fp);
}


void list_record()
{
    system("cls");
    FILE *fp; 
    fp = fopen("phonebook_db 4.txt", "rb"); 
    if (fp == NULL) 
    {
        printf("Error in file opening, please try again !\n"); 
        printf("Press any key to continue....\n");
        return;
    }
    else 
    {
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in phonebook                   *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t ADDRESS\t\t\t  PHONE NO\t     SEX\t  EMAIL\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
		while (fread(&p, sizeof(p), 1, fp) == 1) 
        {
            int i;
            int len1 = 25 - strlen(p.name);
            int len2 = 33 - strlen(p.address);
            int len3 = 19 - strlen(p.mble_no);
            int len4 = 13 - strlen(p.sex);
            printf("%s", p.name);
            for (i = 0; i < len1; i++)
                printf(" ");

            printf("%s", p.address);
            for (i = 0; i < len2; i++)
                printf(" ");

            printf("%s", p.mble_no);
            for (i = 0; i < len3; i++)
                printf(" ");

            printf("%s", p.sex);
            for (i = 0; i < len4; i++)
                printf(" ");

            printf("%s", p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
    
}

void search_person()  
{
    system("cls"); 
    char namee[30];
	int flag=0;  
    printf("Enter name of the person you want to search : "); 
    fflush(stdin);
	gets(namee); 

    FILE *fp; 
    fp = fopen("phonebook_db 4.txt", "rb"); 
    if (fp == NULL) {
        printf("Error in file opening, Plz try again !\n"); 
        printf("Press any key to continue....\n");
        return;
    }
    rewind(fp);
        while (fread(&p, sizeof(p), 1, fp) == 1) 
        {
            if (strcmp(p.name, namee)==0)  
            {
                flag = 1;
                break;
			}
		}
            if (flag==1){
				printf("  NAME\t\t\t ADDRESS\t\t\t  PHONE NO\t     SEX\t  EMAIL\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
        		printf("------------------------------------------------------------------------------------------------------------------------\n");
                int i;
               
                int len1 = 25 - strlen(p.name);
                int len2 = 33 - strlen(p.address);
                int len3 = 19 - strlen(p.mble_no);
                int len4 = 13 - strlen(p.sex);
                printf("%s", p.name);
                for (i = 0; i < len1; i++)
                    printf(" ");

                printf("%s", p.address);
                for (i = 0; i < len2; i++)
                    printf(" ");

                printf("%s", p.mble_no);
                for (i = 0; i < len3; i++)
                    printf(" ");

                printf("%s", p.sex);
                for (i = 0; i < len4; i++)
                    printf(" ");

                printf("%s", p.mail);
                printf("\n");
            }
            else {
            	system("cls");
            	printf("Person is not in the Phonebook\n");
            }
            fflush(stdin);
        fclose(fp); 
        printf("\n\nPress any key to continue....\n");
}

void remove_person() {
    system("cls");
    char namee[30]; 
	printf("Enter name of the person you want to remove from phonebook : ");
	fflush(stdin);
    gets(namee);
    FILE *fp;
	FILE *tem; 
    fp = fopen("phonebook_db 4.txt", "r"); 
    tem = fopen("tem.txt", "a"); 
    if (fp == NULL) {
        printf("Error in file opening, Plz try again !\n"); 
        printf("Press any key to continue....\n");
        return;
    }
    
    rewind(fp);
    
        int flag = 0; 
        while (fread(&p, sizeof(p), 1, fp) == 1) {
            if(strcmp(p.name, namee)==0)
			{
				flag = 1;
                system("cls");
                printf("Person removed successfully for %s\n", namee); 
                continue;
        	}
            	fwrite(&p, sizeof(p), 1, tem);
        }
    
        if (flag = 0){
            system("cls");
            printf("No record found for %s \n", namee);  
		}
        fclose(fp);
        fclose(tem);
     
		remove("phonebook_db 4.txt"); 
        rename("tem.txt", "phonebook_db 4.txt"); 
        fflush(stdin);
        printf("Press any key to continue....\n");
}

void update_person() 
{
    system("cls");
    char namee[30];  
    printf("Enter name of the person you want to update details : "); 
    
	gets(namee);
	fflush(stdin);

    FILE *fp;
    fp = fopen("phonebook_db 4.txt", "rb+");
    if (fp == NULL) {
        printf("Error in file opening, Please try again !\n");
        printf("Press any key to continue....\n");
        return;
    }

        int flag = 0; 
        while (fread(&p, sizeof(p), 1, fp) == 1) {
            if (strcmp(p.name, namee)==0){
            	int sec;
            	printf("choose sector to modify from 1-5 as name, address, phone, sex, email, respectively\n");
            	scanf("%d", &sec);
            	fflush(stdin);
            	switch(sec) {
					case 1:
						printf("Enter name : ");
    					gets(p.name);
						fseek(fp,-sizeof(p),SEEK_CUR);
						fwrite(&p.name, sizeof(p.name),1,fp);
						break;
					case 2:
						printf("Enter address : ");
    					gets(p.address);
						fseek(fp,-sizeof(p),SEEK_CUR);
						fseek(fp, sizeof(p.name),SEEK_CUR);
						fwrite(&p.address, sizeof(p.address),1,fp);
						break;
					case 3:
						 printf("Enter mobile no : ");
    					gets(p.mble_no);
    					fseek(fp,-sizeof(p.mail),SEEK_CUR);
    					fseek(fp,-sizeof(p.sex),SEEK_CUR);
    					fseek(fp,-sizeof(p.mble_no),SEEK_CUR);
    					fwrite(&p.mble_no,sizeof(p.mble_no),1,fp);
    					break;
    				case 4:
						printf("Enter sex : ");
    					gets(p.sex);
    					fseek(fp,-sizeof(p.mail),SEEK_CUR);
    					fseek(fp,-sizeof(p.sex),SEEK_CUR);
    					fwrite(&p.sex,sizeof(p.sex),1,fp);
    					break;
    				case 5:
    					printf("Enter email : ");
						gets(p.mail);
						fseek(fp,-sizeof(p.mail),SEEK_CUR);
						fwrite(&p.mail,sizeof(p.mail),1,fp);
						break;
				}
                system("cls");
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            system("cls");
            printf("No record found for %s \n", namee); 
        }else{
        	printf("Data updated successfully\n");
        }
        fclose(fp); 
        printf("Press any key to continue....\n");
}

void remove_all()  {
    system("cls");
    remove("./phonebook_db 4.txt"); 
    printf("All data in the phonebook deleted successfully\n");
    printf("Press any key to continue ... \n");
}
