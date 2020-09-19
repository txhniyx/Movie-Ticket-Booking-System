
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<time.h>
#include<string.h>
#define MAX_LEN 100 // Length of each line in input file.


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
		{

                printf("\n\nENTER USERNAME:-");
				scanf("%s", &uname);
				printf("\n\nENTER PASSWORD:-");
				while(i<10)
				{
	    		pword[i]=getch();
	    		c=pword[i];
	    		if(c==13)
                    break;
	    		else
                    printf("*");
	    		i++;
				}
				pword[i]='\0';
	//char code=pword;
				i=0;
	//scanf("%s",&pword);
				if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
				{
						printf("\n\n\nLOGIN IS SUCCESSFUL!");
						printf("\n\n\nPress Enter to continue\n");
						getch();//holds the screen
						break;
				}
				else
				{
						printf("\nLOGIN IS UNSUCESSFUL, Press Enter to try again\n");
						a++;
						getch();//holds the screen

				}
			}while(a<=2);

			if (a>2)
			{
					printf("\nSorry, you have entered the wrong username and password four times! Please contact the Admin.");
					getch();
			}
			system("cls");

}


struct book
{
	char code[20];
	char name[20];
	char date[20];
	char timing[15];
	int cost;
}b;

struct book1
{
	char name1[20];
	char date1[20];
	char timing1[15];
	int cost1;
}b1;


int seat = 60 ;
void insert_details();//for inserting movie details
void viewAll(); // for view all data
void find(); // for finding data
void book_ticket(); //for booking tickets
void old_record(); //for view old records of users,booked tickets
void timeNdate();

void timeNdate()
{
char dateStr [9];
char timeStr [9];
_strdate( dateStr );
printf( "The current date is %s \n", dateStr);
_strtime( timeStr );
printf( "The current time is %s \n", timeStr);
}

void main()
{
    login();
    timeNdate();

	 	int ch,opp;
 		do
		{
			printf("\nWelcome to Movie Ticket Booking System!");
			printf("\n\nCopyrights: \nTahniya (1VE17IS055)\nSpandana(1VE17IS050)\n");
			printf("\n--------------------------------------------------------------------");
			printf("\n");
			printf("                    Movie Ticket booking");
			printf("\n");
			printf("\n--------------------------------------------------------------------\n");

			printf("\nEnter >1< To Insert Movie");
            printf("\nEnter >2< To View All Movies");
			printf("\nEnter >3< To Find a Movie ");
			printf("\nEnter >4< To Sort the Movies List ");
			printf("\nEnter >5< To Book Tickets");
			printf("\nEnter >6< To View All Transactions");
		  printf("\nEnter >0< To Exit ");

	   	printf("\nEnter your Choice ::");
	   	scanf("%d",&ch);
		  system("cls");

	   	switch (ch)
	   	{
	    		case 1 :
	    		insert_details();
                break;

                case 2:
	    		viewAll();
                break;

                case 3:
	    		find();
	   			break;

	   			case 4:
	   			    printf("\n1.Sort Movies in ascending order by Movie code\n2.Sort Movies alphabetically by Movie Names\n");
	   			    printf("\nEnter option:");
	   			    scanf("%d",&opp);
	   			    switch(opp)
	   			    {

	   			        case 1:
	   			            sort_movie();
                            break;

                        case 2:
                            sort_movnames();
                            break;
	   			    }
                    break;

                case 5:
                book_ticket();
                break;

                case 6:
                old_record();
                break;

	    		case 0:
	    		exit(0);
	    		break;

	    		default:
	    		printf("INVALID CHOICE");
	    		break;
	   	}
 		}while(ch!=0);
}


void insert_details()
{

	FILE *fp;
	FILE *fp1;
	struct book b;
	struct book1 b1;


	printf("Enter the 4 digit movie code :- ");
	scanf("%s",b.code);
	printf("Enter name without spaces :- ");
	scanf("%s",b.name);
	printf("Enter Release Date in the format DD/MM/YYYY :- ");
	scanf("%s",b.date);
	printf("Enter Show Timing in hrs :- ");
	scanf("%s",b.timing);
	printf("Enter Ticket Price :- ");
	scanf("%d",&b.cost);


	fp=fopen("data.txt","a");
	fp1=fopen("movnames.txt","a");

	if(fp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %s %d  \n",b.code,b.name,b.date,b.timing,b.cost);
		fprintf(fp1,"%s %s %s %d  \n",b.name,b.date,b.timing,b.cost);
		printf("Recorded Successfully");
	}
	printf("\n");
	fclose(fp);

	fclose(fp1);
	system("cls");
}


void find()
{
    bool flag1=false;
    bool flag=false;
    int opt;
    printf("\nChoose an option:-\n\n1. Find by Movie name\n2. Find by Movie code\n");
    printf("\nEnter option:");
    scanf("%d",&opt);
    if(opt==1)
    {
        struct book b;
        FILE *fp;

        char ch[40];
        printf("Enter movie name :- ");
        scanf("%s",ch);

        fp = fopen("data.txt","r");
        if(fp == NULL)
        {
            printf("File not found!");
            exit(1);

        }
        else
        {
            while(getc(fp) != EOF)
            {
                fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.date,b.timing,&b.cost);
                if(strcasecmp(b.name,ch) == 0)
                {
                    flag=true;
                    //printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
                    printf("\n Record Found!\n");
                    printf("\n\tMovie Code ::%s",b.code);
                    printf("\n\tMovie name ::%s",b.name);
                    printf("\n\tMovie date ::%s",b.date);
                    printf("\n\tShow time ::%s",b.timing);
                    printf("\n\tPrice of ticket ::Rs. %d",b.cost);
                    printf("\n\n Press Enter to proceed with booking your ticket\n");
                    getch();
                    book_ticket();
                }
            }
        }
        if(flag==false)
            {
                    printf("\n\nRecord not found.");
                    printf("\nPress Enter to continue.");
                    getch();
            }


	fclose(fp);
	system("cls");
    }

    else
    {

        struct book b;
        FILE *fp;

        char ch[20];
        printf("Enter movie code :-");
        scanf("%s",ch);

        fp = fopen("data.txt","r");
        if(fp == NULL)
        {
            printf("File not found!");
            exit(1);

        }
        else
        {
            while(getc(fp) != EOF)
            {
                fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.date,b.timing,&b.cost);
                if(strcmp(b.code,ch) == 0)
                {
                    flag1=true;
                    //printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
                    printf("\n Record Found!\n");
                    printf("\n\tMovie Code ::%s",b.code);
                    printf("\n\tMovie name ::%s",b.name);
                    printf("\n\tMovie date ::%s",b.date);
                    printf("\n\tShow time ::%s",b.timing);
                    printf("\n\tPrice of ticket ::Rs. %d",b.cost);
                    printf("\n\n Press Enter to proceed with booking your ticket\n");
                    getch();
                    book_ticket();
                }
            }

        }
        if(flag1==false)
            {
                    printf("\n\nRecord not found.");
                    printf("\nPress Enter to continue.");
                    getch();
            }

        fclose(fp);
        system("cls");

    }
}


void viewAll()
{

	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("File not found, press Enter to continue. ");
		getch();
		exit(1);
	}
	else
	{
		system("cls");
		printf("\n-----------------------------------------");
		printf("\nMOVIE   MOVIE     RELEASE  SHOW   TICKET");
		printf("\nCODE    NAME      DATE     TIME   PRICE");
		printf("\n-----------------------------------------\n");

		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);

}


//for ticket booking
void book_ticket()
{
    int n,count;
    struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char cusname[20];


	char ch; //used in display all movies
	char movie_code[4]; //for searching

	// disply all movies by default for movie code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found!");
		exit(1);
	}
	else
	{
		system("cls");
		printf("\n-----------------------------------------");
		printf("\nMOVIE   MOVIE     RELEASE  SHOW   TICKET");
		printf("\nCODE    NAME      DATE     TIME   PRICE");
		printf("\n-----------------------------------------\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);

	//display ends
	printf("\n To book your tickets, choose a Movie:-)\n");
	printf("\n Enter the code of the Movie:-");
	scanf("%s",movie_code);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found!");
		exit(1);
	}
	else
	{
		while(getc(fp) != EOF)
		{
		    fscanf(fp,"%s %s %s %s %d",b.code,b.name,b.date,b.timing,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);

				printf("\n MOVIE DETAILS\n");
				printf("\n\t\tMovie Code ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tDate ::%s",b.date);
				printf("\n\t\tShow time ::%s",b.timing);
				printf("\n\t\tPrice of ticket::%d",b.cost);

				printf("\n\n Dear Customer, Enter your Details  ");
                printf("\n Your name :- ");
                scanf("%s",cusname);
                printf("\n Mobile number (10 digits) :- ");
                scanf("%d",&mobile);
                n=mobile;

                while (n != 0)
                    {
                        n /= 10;     // n = n/10
                        ++count;
                    }
                if(count!=10)
                    {
                        printf("\n Invalid! Please enter a valid 10 digit mobile number:\n");
                        scanf("%d",&mobile);
                    }
                printf("\n Total number of tickets :- ");
                scanf("%d",&total_seat);


                total_amount = b.cost * total_seat;

                    printf("\n YOUR BOOKING DETAILS: \n");
                    printf("\n\t\tName : %s",cusname);
                    printf("\n\t\tMobile Number : %d",mobile);
                    printf("\n\t\tMovie name : %s",b.name);
                    printf("\n\t\tShow time ::%s",b.timing);
                    printf("\n\t\tTotal seats : %d",total_seat);
                    printf("\n\t\tCost per ticket : Rs. %d",b.cost);
                    printf("\n\n\t\tTotal Payable Amount : Rs. %d",total_amount);


                    ufp=fopen("oldTransaction.txt","a");

                    if(ufp == NULL)
                    {
                        printf("File not Found");
                    }
                    else
                    {
                        printf("\n\nDear %s, Your Booking has been made!",cusname);
                        fprintf(ufp,"%s %d %d %d %s %d \n",cusname,mobile,total_seat,total_amount,b.name,b.cost);
                        printf("\n\nTransaction successful, Record insertion successful to the transaction file");

                    }
			}
		}
	}

	printf("\n");
	fclose(ufp);
	fclose(fp);

}


//for view all user transactions
void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");

	fp = fopen("oldTransaction.txt","r");
	if(fp == NULL)
	{
		printf("file not found!");
		exit(1);
	}
	else
	{
		system("cls");
		printf("\n--------------------------------------------------------");
		printf("\nCUSTOMER   MOBILE     NUMBER OF  TOTAL  MOVIE   TICKET");
		printf("\nNAME       NUMBER      TICKETS   AMOUNT NAME    PRICE");
		printf("\n--------------------------------------------------------\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
}



void sort_movie()
{
    char *strFileName = "C:\\Users\\User\\Desktop\\C Programs\\Movie Ticket Booking System 1\\data.txt";
    char *strFileSummary = "C:\\Users\\User\\Desktop\\C Programs\\Movie Ticket Booking System 1\\movie.txt";
    char strTempData[MAX_LEN];
    char **strData = NULL; // String List
    int i, j;
    int noOfLines = 0;

    FILE * ptrFileLog = NULL;
    FILE * ptrSummary = NULL;

    char ch;
	FILE *fp;

    if ( (ptrFileLog = fopen(strFileName, "r")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileName);
        return 1;
    }
    if ( (ptrSummary = fopen(strFileSummary, "w")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileSummary);
        return 1;
    }

    // Read and store in a string list.
    while(fgets(strTempData, MAX_LEN, ptrFileLog) != NULL) {
        // Remove the trailing newline character
        if(strchr(strTempData,'\n'))
            strTempData[strlen(strTempData)-1] = '\0';
        strData = (char**)realloc(strData, sizeof(char**)*(noOfLines+1));
        strData[noOfLines] = (char*)calloc(MAX_LEN,sizeof(char));
        strcpy(strData[noOfLines], strTempData);
        noOfLines++;
    }
    // Sort the array.
    for(i= 0; i < (noOfLines - 1); ++i) {
        for(j = 0; j < ( noOfLines - i - 1); ++j) {
            if(strcmp(strData[j], strData[j+1]) > 0) {
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j+1]);
                strcpy(strData[j+1], strTempData);
            }
        }
    }
    // Write it to outfile. file.
    for(i = 0; i < noOfLines; i++)
        fprintf(ptrSummary,"%s\n",strData[i]);
    // free each string
    for(i = 0; i < noOfLines; i++)
        free(strData[i]);
    // free string list.
    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);

    fp = fopen("movie.txt","r");
	if(fp == NULL)
	{
		printf("file not found!");
		exit(1);
	}
	else
	{
		system("cls");
		printf("\n-----------------------------------------");
		printf("\nMOVIE   MOVIE     RELEASE  SHOW   TICKET");
		printf("\nCODE    NAME      DATE     TIME   PRICE");
		printf("\n-----------------------------------------\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
    return 0;
}



void sort_movnames()
{
    char *strFileName = "C:\\Users\\User\\Desktop\\C Programs\\Movie Ticket Booking System 1\\movnames.txt";
    char *strFileSummary = "C:\\Users\\User\\Desktop\\C Programs\\Movie Ticket Booking System 1\\movie.txt";
    char strTempData[MAX_LEN];
    char **strData = NULL; // String List
    int i, j;
    int noOfLines = 0;

    FILE * ptrFileLog = NULL;
    FILE * ptrSummary = NULL;

    char ch;
	FILE *fp;

    if ( (ptrFileLog = fopen(strFileName, "r")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileName);
        return 1;
    }
    if ( (ptrSummary = fopen(strFileSummary, "w")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileSummary);
        return 1;
    }

    // Read and store in a string list.
    while(fgets(strTempData, MAX_LEN, ptrFileLog) != NULL) {
        // Remove the trailing newline character
        if(strchr(strTempData,'\n'))
            strTempData[strlen(strTempData)-1] = '\0';
        strData = (char**)realloc(strData, sizeof(char**)*(noOfLines+1));
        strData[noOfLines] = (char*)calloc(MAX_LEN,sizeof(char));
        strcpy(strData[noOfLines], strTempData);
        noOfLines++;
    }
    // Sort the array.
    for(i= 0; i < (noOfLines - 1); ++i) {
        for(j = 0; j < ( noOfLines - i - 1); ++j) {
            if(strcmp(strData[j], strData[j+1]) > 0) {
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j+1]);
                strcpy(strData[j+1], strTempData);
            }
        }
    }
    // Write it to outfile. file.
    for(i = 0; i < noOfLines; i++)
        fprintf(ptrSummary,"%s\n",strData[i]);
    // free each string
    for(i = 0; i < noOfLines; i++)
        free(strData[i]);
    // free string list.
    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);



    fp = fopen("movie.txt","r");
	if(fp == NULL)
	{
		printf("file not found!");
		exit(1);
	}
	else
	{
		system("cls");
		printf("\n-------------------------------------");
		printf("\nMOVIE     RELEASE  SHOW   TICKET");
		printf("\nNAME      DATE     TIME   PRICE");
		printf("\n-------------------------------------\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
    return 0;
}
