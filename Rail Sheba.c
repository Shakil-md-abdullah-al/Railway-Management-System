#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

/*Home Start*/
int home()
{
    system("COLOR 07");
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::       Home Menu       :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\t\t\t\t\t\tSelect an Option From Below:\n");
    printf("\t\t\t\t\t\t1. ADMIN LOGIN\n");
    printf("\t\t\t\t\t\t2. USER LOGIN\n");
    printf("\t\t\t\t\t\t3. OPTION\n");
    int ch;
    printf("\n\t\t\t\t\t\tEnter Your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Admin_menu(); // Log in Replace
        break;
    case 2:
        User_menu();
        break;
    case 3:
        option();
        break;

    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
        printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        home();
    }

}

/*Home End*/



//Display File all Content
int print_file(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
        putchar(ch);
}

//Delete or Remove File Row
int delete_file_row(FILE *main_file, FILE *temp_file, const int delete_line)
{
    char buffer[255];
    int count = 1;

    while ((fgets(buffer, 255, main_file)) != NULL)
    {
        if (delete_line != count)
            fputs(buffer, temp_file);

        count++;
    }
}

//Update or Replace File Row
int replace_row(char filename[], int delete_line)
{
    FILE *main_file;
    FILE *temp_file;
    FILE *repl_file;

    int count=1;
    char buffer[255];
    char replace[255];

    main_file = fopen(filename, "r");
    repl_file = fopen("rep-file.tmp", "r");
    temp_file = fopen("temp-file.tmp", "w");

    if (main_file == NULL || temp_file == NULL || repl_file == NULL)
    {
        printf("\n\nUnable to open file.\n");
        exit(1);
    }

    fgets(replace, 250, repl_file);

    rewind(main_file);

    while ((fgets(buffer, 250, main_file)) != NULL)
    {
        if (delete_line != count)
            fputs(buffer, temp_file);
        else
            fputs(replace, temp_file);

        count++;
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    remove("rep-file.tmp");

    rename("temp-file.tmp", filename);

    printf("\n\n\t\t\tUpdated List (%d no Row).\n\n", delete_line);
    main_file = fopen(filename, "r");
    print_file(main_file);

    fclose(main_file);
}
/*Admin Start*/
/*Admin Menu Start*/
int Admin_menu()
{
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t:::::::::      Admin Section       :::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
  printf("\t\t\t\t\t\tPress 1 to Log In \n");
  printf("\t\t\t\t\t\tPress 2 to Go Back \n");

  int ch;
    printf("\n\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        admin_login();
        break;
    case 2:
        home();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
        printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        home();

    }
}
/*Admin Menu End*/

/* Admin Option Start*/
int Admin()
{
    system("CLS");//Clear Window
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::      Admin Section     ::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\t\t\t\t\t\t1. Upcoming Train Schedule \n");
    printf("\t\t\t\t\t\t2. Train List \n");
    printf("\t\t\t\t\t\t3. Ticket Purchase \n");
    printf("\t\t\t\t\t\t4. Users Account\n");
    //printf("\t\t\t\t\t\t5. Passenger Information \n");
    printf("\t\t\t\t\t\t5. Complain Center \n");
    printf("\t\t\t\t\t\t6. Helpline \n");
     printf("\t\t\t\t\t\t7. Notice Bord \n");
    printf("\t\t\t\t\t\t8. Home\n");
    printf("\t\t\t\t\t\t9. Exit \n");

    int ch;
    printf("\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        train_Schedule();
        break;
    case 2:
        train_list();
        break;
    case 3:
        ticketPurchase();
        break;
    case 4:
        usr_details();
        break;
    case 5:
        User_Report();
        break;
    case 6:
        Complain_Contact();
        break;
    case 7:
        NoticeBoard();
        break;
    case 8:
        home();
        break;
     case 9:
        DisplayResourceNAMessageBox();
        break;

    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        Admin();

    }
}


/* Admin Option End*/

/*Train Schedule Start*/
/*Train Schedule font page Start*/
int train_Schedule()
{
    system("CLS");//Clear Window
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t:::::     Upcoming Train Schedule      :::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    printf("\t\t\t\t\t\t1. Add/Update Info \n");
    printf("\t\t\t\t\t\t2. Show Train List \n");
    printf("\t\t\t\t\t\t3. Delete Info\n");
    printf("\t\t\t\t\t\t4. Admin Section\n");
    printf("\t\t\t\t\t\t5. Home\n");



    int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        add_train_list();
        break;
    case 2:
        t_list();
        break;
    case 3:
         del_train_list();
        break;
    case 4:
         Admin();
        break;
    case 5:
         home();
        break;

    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        train_Schedule();

    }

}
/*Train Schedule font page End*/

/*Upcoming Train List Start*/
struct train_list
{
    char code[25];
    char name[80];
    char dest[200];
    char time[25];
    int price;
    char tm[30];
    char con[30];
    char offday[30];
};

int add_train_list()
{
    system("CLS");
    FILE *fptr;
    fptr = fopen("Train-Schedule.txt", "a");

    struct train_list add;

    printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                         ::\n");
    printf("\t\t\t\t\t\t::::: Update Upcoming Train Schedule  :::::::\n");
    printf("\t\t\t\t\t\t::                                         ::\n");
    printf("\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    gets(add.code);
    printf("\t\t\t\t\t\tEnter Train Code: "); gets(add.code);
    printf("\t\t\t\t\t\tEnter Train Name: "); scanf("%[^\n]%*c", add.name);
    printf("\t\t\t\t\t\tEnter Train Destination: "); scanf("%[^\n]%*c", add.dest);
    printf("\t\t\t\t\t\tEnter Condition(Arrival/Departure): "); scanf("%[^\n]%*c", add.con);
    printf("\t\t\t\t\t\tEnter Time Left: "); scanf("%[^\n]%*c", add.tm);



    fprintf(fptr,"Train Code: %s\t|\tTrain Name: %s\t|\tTrain Destination: %s\t|\tStatus: %s\t|\tTime:%s\n", add.code, add.name, add.dest,add.con,add.tm);
    fclose(fptr);
    t_list();

    printf("\n\n\t\t\t\t\t\tTrain Added Successful!\nPress Any Key to Go Admin Section. ");
    getch();
    Admin();
}



int t_list()
{
    system("CLS");
    FILE *fp = fopen("Train-Schedule.txt", "r");
    char buff_train_list[255];

    if(fp == NULL)
    {
        printf("Unable to open file!\n");
        printf("Press any key to Continue\n\n");
        getch();
        Admin();
    }

    printf("\n\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t\t\t::::::::::  Upcoming Train List   ::::::::::\n");
    printf("\t\t\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "\t\t\t\t\t\t\t\tCurrent Time & Date: %s", asctime (timeinfo) );
  printf("\n\n");

    while(fgets(buff_train_list, sizeof(buff_train_list), fp) != NULL)
        {
            fputs(buff_train_list, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
    back();

}


int del_train_list()
{

    system("CLS");
    printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                         ::\n");
    printf("\t\t\t\t\t\t::::::::     Delete Train List     ::::::::::\n");
    printf("\t\t\t\t\t\t::                                         ::\n");
    printf("\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
     FILE *fileptr1, *fileptr2;

    char filename[40];

    char ch;

    int delete_line, temp = 1;



    printf("\t\t\t\t\t\tEnter File Name: ");

    scanf("%s", filename);

    //open file in read mode

    fileptr1 = fopen(filename, "r");

    ch = getc(fileptr1);

   while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    //rewind

    rewind(fileptr1);

    printf(" \n\t\t\t\t\t\t Enter Line Number of The Line to Be Deleted:");

    scanf("%d", &delete_line);

    //open new file in write mode

    fileptr2 = fopen("replica.c", "w");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        ch = getc(fileptr1);

        if (ch == '\n')

            temp++;

            //except the line to be deleted

            if (temp != delete_line)

            {

                //copy all lines in file replica.c

                putc(ch, fileptr2);

            }

    }

    fclose(fileptr1);

    fclose(fileptr2);

    remove(filename);

    //rename the file replica.c to original name

    rename("replica.c", filename);

    printf("\n\t\t\t\t\t\t The Contents of File After Being Modified Are As Follows:\n");

    fileptr1 = fopen(filename, "r");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    fclose(fileptr1);

    return 0;
}



/*Upcoming Train List End*/

/*Train List Start*/
int train_list()
{
    system("CLS");//Clear Window
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::      Train List       :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\n\t\t\t\t\t\t1. Add/Update Info \n");
    printf("\t\t\t\t\t\t2. Show List \n");
    printf("\t\t\t\t\t\t3. Delete Train\n");
    printf("\t\t\t\t\t\t4. Admin Section\n");
    printf("\t\t\t\t\t\t5. Home\n");



    int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        add_t_list();
        break;
    case 2:
        tl_list();
        break;
    case 3:
        del_tl_list();
        break;
    case 4:
        Admin();
        break;
    case 5:
        home();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        train_list();

    }

}

/*Final Train List*/
int add_t_list()
{
 system("CLS");
    FILE *fptr;
    fptr = fopen("Add-Train-List.txt", "a");

    struct train_list add;

    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::      Add New Train     ::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    gets(add.code);
    printf("\t\t\t\t\t\tEnter Train Code: "); gets(add.code);
    printf("\t\t\t\t\t\tEnter Train Name: "); scanf("%[^\n]%*c", add.name);
    printf("\t\t\t\t\t\tEnter Train Destination: "); scanf("%[^\n]%*c", add.dest);
    printf("\t\t\t\t\t\tEnter train Time: "); gets(add.time);
    printf("\t\t\t\t\t\tEnter train Off-day: "); gets(add.offday);
    printf("\t\t\t\t\t\tEnter Ticket Price: ");scanf("%d", &add.price);


    fprintf(fptr,"\t\tCode: %s\t|  Name: %s\t|  Destination: %s\t|  Time: %s \t|  Off-Day: %s\t|  Price: %d Tk\n", add.code, add.name, add.dest, add.time,add.offday,add.price);
    //tl_list();
    fclose(fptr);

    printf("\n\n\t\t\t\t\t\tTrain Added Successful!\nPress any key to go Admin Menu\n");
    getch();
    Admin();
}



int tl_list()
{
    system("CLS");
    FILE *fp = fopen("Add-Train-List.txt", "r");
    char buff_train_list[255];

    if(fp == NULL)
    {
       printf("Unable to open file!");
       printf("Press any key to continue");
       getch();
       Admin();
    }

    printf("\t\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t\t\t\t::::::::::    Show Train List     ::::::::::\n");
    printf("\t\t\t\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    while(fgets(buff_train_list, sizeof(buff_train_list), fp) != NULL)
        {
            fputs(buff_train_list, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
    back();

}

int del_tl_list()
{
    system("CLS");
     FILE *fileptr1, *fileptr2;

    char filename[40];

    char ch;

    int delete_line, temp = 1;
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::   Delete Train List    ::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");




    printf("\n\n\t\t\t\t\t\tEnter File Name: ");

    scanf("%s", filename);

    //open file in read mode

    fileptr1 = fopen(filename, "r");

    ch = getc(fileptr1);

   while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    //rewind

    rewind(fileptr1);

    printf("\n\t\t\t\t\t\tEnter Line Number of The Line to Be Deleted:");

    scanf("%d", &delete_line);

    //open new file in write mode

    fileptr2 = fopen("replica.c", "w");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        ch = getc(fileptr1);

        if (ch == '\n')

            temp++;

            //except the line to be deleted

            if (temp != delete_line)

            {

                //copy all lines in file replica.c

                putc(ch, fileptr2);

            }

    }

    fclose(fileptr1);

    fclose(fileptr2);

    remove(filename);

    //rename the file replica.c to original name

    rename("replica.c", filename);

    printf("\n\t\t\t\t\t\tThe Contents of File After Being Modified Are As Follows:\n");

    fileptr1 = fopen(filename, "r");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    fclose(fileptr1);

    return 0;
}



/*Train List End*/


/*Ticket Purchase Start*/
int ticketPurchase()
{
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::    Ticket Purchase    :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\n\t\t\t\t\t\t1. Purchase \n");
    printf("\t\t\t\t\t\t2. Admin Section\n");
    printf("\t\t\t\t\t\t3. Home\n");



    int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        admin_purchase();
        break;
    case 2:
         Admin();
        break;
    case 3:
        home();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back. ");
        getch();
        system("CLS");
        ticketPurchase();

    }

}
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}fs;

void admin_purchase(void)
{
	char confirm;
	int i=0;
	float charges;
	fs passdetails;
	FILE *fp;
	fp=fopen("Admin-Purchase.txt","a");
	system("cls");

	printf("\n\t\t\t\t\t\tEnter Your Name: ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name
	printf("\n\t\t\t\t\t\tEnter Number of seats: ");
	scanf("%d",&passdetails.num_of_seats);
	if(passdetails.num_of_seats>=5)
    {
        printf("\n\nYou can not buy more then 4 Tickets at one time. Please try again.");
        getch();
        system("CLS");
        admin_purchase();
    }
	printf("\n\n\t\t\t\t\t\tPress Enter To View Available Trains ");
	getch();
	system("cls");
	view_list();
	printf("\n\n\t\t\t\t\t\tEnter Train number: ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=701 && passdetails.train_num<=735)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\n\t\t\t\t\t\tInvalid Train Number! Enter again. ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y'||confirm == 'Y')
	{
		fprintf(fp,"Name:%s\t\tNumber of Seats:%d\t\tTrain Number: %d\t\tCharges: %.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);



		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("\n");
        printf("\nThank You, Your Ticket Purchase complete \n");
        printf("\nPress Enter to Continue.......");
	}
	else
	{
		if(confirm=='n' || confirm == 'N'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}


/*Ticket purchase list start*/
int purchaselist()
{
    FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("purchase.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s \n", buff);
   }
   fclose(fp);
    back();

}
/*Ticket purchase list end*/


/*return request start*/
/*return request end*/
/*Ticket Purchase end*/

/*Complain Start*/
int Complain_Contact()
{
        system("cls");
        printf("\n\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::::      Helpline     :::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
        printf("\n\n\t\t\t\t\t\t\tFeel Free to Contact To Us\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::\n");



        printf("\n\t\t\t\t\t\tPolice\t\t : %s\n","999");
        printf("\n\t\t\t\t\t\tMedical\t\t : %s\n","16247");
        printf("\n\t\t\t\t\t\tFire-Service\t : %s\n","121");
        printf("\n\t\t\t\t\t\tNational Emergency Number: %s\n\n","121");
        printf("\n\t\t\t\t\t\tTelephone: %s\n","+88025003825");
        printf("\n\t\t\t\t\t\tHotline: %s\n","167222");
        printf("\n\t\t\t\t\t\tEmail: %s\n","help@railsheba.gov.bd\n");

        printf("\n\t\t\t\t\t\t                Account Section\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\n\t\t\t\t\t\tMobile Number: %s\n","+8801959981909");
        printf("\n\t\t\t\t\t\tEmail Address: %s\n","account.section@railsheba.gov.bd\n");


        printf("\n\t\t\t\t\t\t                General Section\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\n\t\t\t\t\t\tMobile Number: %s\n","+8801784918947");
        printf("\n\t\t\t\t\t\tEmail Address: %s\n","g.section@railsheba.gov.bd\n");

        printf("\n\t\t\t\t\t\t             Train Schedule Scetion\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\n\t\t\t\t\t\tMobile Number: %s\n","+8801794300754");
        printf("\n\t\t\t\t\t\tEmail Address: %s\n","ts.section@railsheba.gov.bd\n");

back();
}


struct comp
{
    char name[85];
    char phone[20];
    char disc[700];
};
//Admin showing User complain list start
 int User_Report()
 {
     system("cls");
    FILE *fp = fopen("User_Complain.txt", "r");
    char buff_comp[255];
    struct comp add;

    if(fp == NULL)
    {
       printf("\n\t\t\t\t\t\tUnable to open file!");
       printf("\n\t\t\t\t\t\tPress any key to continue");
       getch();
       User();
    }

    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::     User Complain     :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");


    while(fgets(buff_comp, sizeof(buff_comp), fp) != NULL)
        {
            fputs(buff_comp, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
    back();
 }


struct notice
{
    char notice_no[50];
    char notice_desc[700];
};
int viwe_notice_admin()
{
     system("cls");
    FILE *fp = fopen("Notice.txt", "r");
    char buff_notice[255];
    struct notice ntc;

    if(fp == NULL)
    {
       printf("\n\t\t\t\t\t\tUnable to open file!");
       printf("\n\t\t\t\t\t\tPress any key to continue");
       getch();
       Admin();
    }

     system("cls");
        printf("\n\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t:::::::::::       Notice  ::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n");


    while(fgets(buff_notice, sizeof(buff_notice), fp) != NULL)
        {
            fputs(buff_notice, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
    back();
}





 /*Admin End*/

int User_menu()
{
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t:::::::::       User Section       :::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\t\t\t\t\t\tPress 1 to Log In \n");
    printf("\t\t\t\t\t\tPress 2 to Registration \n");
    printf("\t\t\t\t\t\tPress 3 to Go Back \n");

  int ch;
    printf("\n\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        user_login();
        break;
    case 2:
        reg();
        break;
    case 3:
        home();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        User_menu();

    }
}
/*User Start*/

int User()
{
    system("CLS");//Clear Window
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::     User Section      :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\t\t\t\t\t\t1. Train Information \n");
    printf("\t\t\t\t\t\t2. Ticket Purchase \n");
    printf("\t\t\t\t\t\t3. My Account\n");
    printf("\t\t\t\t\t\t4. Food \n");
    printf("\t\t\t\t\t\t5. Complain\n");
    printf("\t\t\t\t\t\t6. Helpline\n");
    printf("\t\t\t\t\t\t7. Notice Bord\n");
    printf("\t\t\t\t\t\t8. Home \n");
    printf("\t\t\t\t\t\t9. Logout \n");
    printf("\t\t\t\t\t\t10. Exit \n");
    int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice:  ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        train_information();
        break;
    case 2:
        buy_ticket();
        break;
    case 3:
        user_account();
        break;
    case 4:
        foodpurchase();
        break;
    case 5:
         User_Complain_Contact();
        break;
    case 6:
        usr_helpline();
        break;
    case 7:
        view_notice();
        break;
    case 8:
        home();
        break;
     case 9:
        DisplayResourceNAMessageBox3();
        break;
    case 10:
         DisplayResourceNAMessageBox2();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        User();

}
}
/*User End*/

/*Train Information Start*/
int train_information()
{
    system("CLS");//Clear Window
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::   Train Information    ::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\n\n\t\t\t\t\t\tEnter Your Choice: ");
    printf("\n\n\t\t\t\t\t\t1.Train Schedule\n");
    printf("\t\t\t\t\t\t2.Train List\n");
    printf("\t\t\t\t\t\t3.Back\n");

   int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        tu_list();
        break;
    case 2:
        user_tlist();
        break;
    case 3:
        User();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        train_information();

    }

}
/*Train Information End*/
int tu_list()
{
    system("CLS");
    FILE *fp = fopen("Train-Schedule.txt", "r");
    char buff_train_list[255];

    if(fp == NULL)
    {
        printf("Unable to open file!\n");
        printf("Press any key to Continue\n\n");
        getch();
        User();
    }

    printf("\n\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t\t\t::::::::::  Upcoming Train List   ::::::::::\n");
    printf("\t\t\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "\t\t\t\t\t\t\t\tCurrent Time & Date: %s", asctime (timeinfo) );
  printf("\n\n");

    while(fgets(buff_train_list, sizeof(buff_train_list), fp) != NULL)
        {
            fputs(buff_train_list, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
    back2();

}
/*Train List start*/
int user_tlist()
{
    //Train list by file
    system("cls");
  	printf("\t\t\t---------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\tTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\t\tOff-Day\n");
	printf("\t\t\t---------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t701\tSubarna Express\t\tDhaka to chittagong\tTk.750\t\t9:30am\t\tMonday\n");
    printf("\t\t\t711\tSubarna Express\t\tchittagong To Dhaka\tTk.750\t\t12:00pm\t\tMonday\n");

    printf("\t\t\t703\tTista Express\t\tDhaka To Dewangonj\tTk.790\t\t8:30am\t\tNo Off Day\n");
    printf("\t\t\t713\tTista Express\t\tDewangonj To Dhaka\tTk.790\t\t4:30pm\t\tNo Off Day\n");

    printf("\t\t\t705\tKapotaskh Express\tDhaka To Rajhshahi\tTk.730\t\t7:30am\t\tThursday\n");
    printf("\n\t\t\t715\tKapotaskh Express\tRajhshahi To Dhaka\tTk.730\t\t10:30pm\t\tThursday\n");

    printf("\n\t\t\t707\tPanchagarh Express\tDhaka To Panchagarh\tTk.760\t\t9:00am\t\tSunday\n");
    printf("\t\t\t717\tPanchagarh Express\tPanchagarh To Dhaka\tTk.760\t\t10:30pm\t\tSunday\n");

    printf("\t\t\t711\tChittra Express\t\tDhaka To Khulna\t\tTk.780\t\t6:30am\t\tWednesday\n");
    printf("\t\t\t731\tChittra Express\t\tKhulna To Dhaka\t\tTk.780\t\t5:30pm\t\tWednesday\n");

    printf("\t\t\t712\tMoitree Express\t\tDhaka To Kolkata\tTk.740\t\t6:30am\t\tTuesday\n");
    printf("\t\t\t733\tMoitree Express\t\tKolkata To Dhaka\tTk.740\t\t6:30am\t\tTuesday\n");

    printf("\t\t\t720\tUpaban Express\t\tDhaka To Sylhet\t\tTk.770\t\t9:30pm\t\tNo Off Day\n");
    printf("\t\t\t734\tUpaban Express\t\tSylhet To Dhaka\t\tTk.770\t\t10:30am\t\tNo Off Day\n");
    printf("\n\n");
    back2();
}
/*Train List start*/
/*Train Information End*/

int view_list()
{
    //Train list by file
    system("cls");
	printf("\t\t\t---------------------------------------------------------------------------------------");
	printf("\n\t\t\tTr.No\tName\t\t\tDestinations\t\tCharges\t\t\tTime\n");
	printf("\t\t\t---------------------------------------------------------------------------------------");
	printf("\n\t\t\t701\tSubarna Express\t\tDhaka to chittagong\tTk.750\t\t\t9:30am");
    printf("\n\t\t\t711\tSubarna Express\t\tchittagong To Dhaka\tTk.750\t\t\t12:00pm");

    printf("\n\t\t\t703\tTista Express\t\tDhaka To Dewangonj\tTk.790\t\t\t8:30am");
    printf("\n\t\t\t713\tTista Express\t\tDewangonj To Dhaka\tTk.790\t\t\t4:30pm");

    printf("\n\t\t\t705\tKapotaskh Express\tDhaka To Rajhshahi\tTk.730\t\t\t7:30am");
    printf("\n\t\t\t715\tKapotaskh Express\tRajhshahi To Dhaka\tTk.730\t\t\t10:30pm");

    printf("\n\t\t\t707\tPanchagarh Express\tDhaka To Panchagarh\tTk.760\t\t\t9:00am");
    printf("\n\t\t\t717\tPanchagarh Express\tPanchagarh To Dhaka\tTk.760\t\t\t10:30pm");

    printf("\n\t\t\t711\tChittra Express\t\tDhaka To Khulna\t\tTk.780\t\t\t6:30am");
    printf("\n\t\t\t731\tChittra Express\t\tKhulna To Dhaka\t\tTk.780\t\t\t5:30pm");

    printf("\n\t\t\t712\tMoitree Express\t\tDhaka To Kolkata\tTk.740\t\t\t6:30am");
    printf("\n\t\t\t733\tMoitree Express\t\tKolkata To Dhaka\tTk.740\t\t\t6:30am");

    printf("\n\t\t\t720\tUpaban Express\t\tDhaka To Sylhet\t\tTk.770\t\t\t9:30pm");
    printf("\n\t\t\t734\tUpaban Express\t\tSylhet To Dhaka\t\tTk.770\t\t\t10:30am");
    printf("\n\n");
}
/*Buy Ticket Start*/
int buy_ticket()
{
  system("CLS");//Clear Window
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::       Buy Ticket      :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
  printf("\t\t\t\t\t\t1. Buy Now\n");
  printf("\t\t\t\t\t\t2. Back\n");

  int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
         usrpurchase();
        break;
    case 2:
        User();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        buy_ticket();
    }
back2();
}

/*Structure for purchases Start*/
struct pd{
	char name[50];
	int train_num;
	int num_of_seats;
};
/*Structure for purchases End*/

/*Ticket Purchase Start*/

void usrpurchase(void)
{
	char confirm;
	int i=0;
	float charges;
	struct pd passdetails;
	FILE *fp;
	fp=fopen("User-Purchase.txt","a");
	system("cls");

	printf("\n\t\t\t\t\t\tEnter Your Name: ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name
	printf("\n\t\t\t\t\t\tEnter Number of Seats: ");
	scanf("%d",&passdetails.num_of_seats);
	if(passdetails.num_of_seats>=5)
    {
        printf("\n\nYou can not buy more then 4 tickets at once. Please try again. ");
        getch();
        system("CLS");
        usrpurchase();
    }
	printf("\n\n\t\t\t\t\t\tPress Enter To View Available Trains ");
	getch();
	system("cls");
	view_list();
	printf("\n\n\t\t\t\t\t\tEnter Train Number: ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=701 && passdetails.train_num<=735)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\n\t\t\t\t\t\tInvalid Train Number! Enter Again. ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y'||confirm == 'Y')
	{
		fprintf(fp,"Name:%s\t\tNumber of Seats:%d\t\tTrain Number: %d\t\tCharges: %.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);



		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("\n");
        printf("\nThank You, Your Ticket Purchase complete \n");
        printf("\nPress Enter to Continue.......");
        getch();
        payment();
	}
	else
	{
		if(confirm=='n' || confirm == 'N'){
			printf("\nReservation is Not Done!\nPress Any Key to Go back. ");
		}
		else
		{
			printf("\nInvalid Choice! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*Ticket Purchase End*/

int charge(int train_num,int num_of_seats)
{
		if ((train_num==701 || train_num==711) && num_of_seats==1)
	{
		printf("\t\t\t%f",750.0*1);
	}
	else if ((train_num==701 || train_num==711) && num_of_seats==2)
	{
		printf("\t\t\t%f",750.0*2);
	}
	else if ((train_num==701 || train_num==711) && num_of_seats==3)
	{
		printf("\t\t\t%f",750.0*3);
	}
	else if ((train_num==701 || train_num==711) && num_of_seats==4)
	{
		printf("\t\t\t%f",750.0*4);
	}


	else if ((train_num==703 || train_num==713) && num_of_seats==1)
	{
		printf("\t\t\t%f",790.0*1);
	}

    else if ((train_num==703 || train_num==713) && num_of_seats==2)
	{
		printf("\t\t\t%f",790.0*2);
	}
	else if ((train_num==703 || train_num==713) && num_of_seats==3)
	{
		printf("\t\t\t%f",790.0*3);
	}
	else if ((train_num==703 || train_num==713) && num_of_seats==4)
	{
		printf("\t\t\t%f",790.0*4);
	}


	else if ((train_num==705 || train_num==715) && num_of_seats==1)
	{
		printf("\t\t\t%f",730.0*1);
	}
	else if ((train_num==705 || train_num==715) && num_of_seats==2)
	{
		printf("\t\t\t%f",730.0*2);
	}
	else if ((train_num==705 || train_num==715) && num_of_seats==3)
	{
		printf("\t\t\t%f",730.0*3);
	}
	else if ((train_num==705 || train_num==715) && num_of_seats==4)
	{
		printf("\t\t\t%f",730.0*4);
	}


	else if ((train_num==707 || train_num==717) && num_of_seats==1)
	{
		printf("\t\t\t%f",760.0*1);
	}
	else if ((train_num==707 || train_num==717) && num_of_seats==2)
	{
		printf("\t\t\t%f",760.0*2);
	}
	else if ((train_num==707 || train_num==717) && num_of_seats==3)
	{
		printf("\t\t\t%f",760.0*3);
	}
	else if ((train_num==707 || train_num==717) && num_of_seats==4)
	{
		printf("\t\t\t%f",760.0*4);
	}


	else if ((train_num==711 || train_num==731) && num_of_seats==1)
	{
		printf("\t\t\t%f",780.0*1);
	}
	else if ((train_num==711 || train_num==731) && num_of_seats==2)
	{
		printf("\t\t\t%f",780.0*2);
	}
	else if ((train_num==711 || train_num==731) && num_of_seats==3)
	{
		printf("\t\t\t%f",780.0*3);
	}
	else if ((train_num==711 || train_num==731) && num_of_seats==4)
	{
		printf("\t\t\t%f",780.0*4);
	}


	else if ((train_num==712 || train_num==733) && num_of_seats==1)
	{
		printf("\t\t\t%f",740.0*1);
	}
	else if ((train_num==712 || train_num==733) && num_of_seats==2)
	{
		printf("\t\t\t%f",740.0*2);
	}
	else if ((train_num==712 || train_num==733) && num_of_seats==3)
	{
		printf("\t\t\t%f",740.0*3);
	}
	else if ((train_num==712 || train_num==733) && num_of_seats==4)
	{
		printf("\t\t\t%f",740.0*4);
	}


	else if ((train_num==720 || train_num==734) && num_of_seats==1)
	{
		printf("\t\t\t%f",770.0*1);
	}
	else if ((train_num==720 || train_num==734) && num_of_seats==2)
	{
		printf("\t\t\t%f",770.0*2);
	}
	else if ((train_num==720 || train_num==734) && num_of_seats==3)
	{
		printf("\t\t\t%f",770.0*3);
	}
	else if ((train_num==720 || train_num==734) && num_of_seats==4)
	{
		printf("\t\t\t%f",770.0*4);
	}


}

int payment()
{
    system("CLS");//Clear Window
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::        Payment        :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\t\t\t\t\t\tSelect a Payment Method\n");

    printf("\t\t\t\t\t\t1. Bkash\n");
    printf("\t\t\t\t\t\t2. Rocket\n");
    printf("\t\t\t\t\t\t3. Nagad\n");
    printf("\t\t\t\t\t\t4. Visa Card\n");

  int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice:  ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
    case 2:
    case 3:
        payment_1();
        break;
    case 4:
        payment_2();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        payment();
    }
}

/*Mobile Payment*/

int payment_food()
{
    system("CLS");//Clear Window
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::        Payment        :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\t\t\t\t\t\tSelect a Payment Method\n");

    printf("\t\t\t\t\t\t1. Bkash\n");
    printf("\t\t\t\t\t\t2. Rocket\n");
    printf("\t\t\t\t\t\t3. Nagad\n");
    printf("\t\t\t\t\t\t4. Visa Card\n");
    printf("\t\t\t\t\t\t5. Cash On Delivery\n");

  int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice:  ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
    case 2:
    case 3:
        payment_1();
        break;
    case 4:
        payment_2();
        break;
    case 5:
        payment_3();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        payment_food();
    }
}

/*Payment Start*/
int payment_1()
{
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t:::::::::     Mobile Banking     :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
 char num[11],pass[5],otp[4],amm[4];

 printf("\t\t\t\t\t\tEnter Your Number: ");
 scanf("%s",&num);
 printf("\n\t\t\t\t\t\tEnter Amount: ");
 scanf("%s",&amm);
 printf("\n\t\t\t\t\t\tEnter OTP: ");
 scanf("%s",&otp);
 printf("\n\t\t\t\t\t\tEnter Password: ");
 scanf("%s",&pass);


ccolor(26);
printf("\n\t"); ccolor(240);
 printf("\n\t\t\t\tPayment Successful!!!. Have a Safe Journey");ccolor(26);

//printf("\n\t"); ccolor(240);
	//printf("_______________________________________________________");
	ccolor(26);
	printf("\n\t"); ccolor(240);
	printf("\n\t\t\t\tYou will get Your Ticket Purchase form in Your mail  within  30 mint. Be patience!");ccolor(26);
	printf("\n\t"); ccolor(07);
	//printf("-------------------------------------------------------");ccolor(26);
 back2();
 system("CLS");
}
/* Card Paymment*/

int payment_2()
{
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::      Using Card       :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
 char num[16],pass[5],otp[6],amm[4];

 printf("\t\t\t\t\t\tEnter Your Card Number: ");
 scanf("%s",&num);
 printf("\n\t\t\t\t\t\tEnter Amount: ");
 scanf("%s",&amm);
 printf("\n\t\t\t\t\t\tEnter OTP: ");
 scanf("%s",&otp);
 printf("\n\t\t\t\t\t\tEnter Password: ");
 scanf("%s",&pass);



//printf("\n\t"); ccolor(240);
	//printf("_______________________________________________________");
	ccolor(26);
	printf("\n\t"); ccolor(240);
	printf("\n\t\t\t\tYou will get Your Ticket Purchase form in Your mail  within  30 mint. Be patience!");ccolor(26);
	printf("\n\t"); ccolor(07);


    back2();
}

int payment_3()
{
    ccolor(26);
	printf("\n\t"); ccolor(240);
	printf("\n\t\t\t\tWe have received your request. We will be there within  10 mint. Be patience!");ccolor(26);
	printf("\n\t"); ccolor(07);

    back2();
}
/*Payment End*/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	 if(num_of_seats>=5)
    {

        printf("\n\nYou can not buy more then 4 Tickets at one time. Please try again.");
        getch();
        system("CLS");
        usrpurchase();
    }
	printf("-----------------------------------\n");
	printf("\t   TICKET\n");
	printf("-----------------------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charge);



}


void specifictrain(int train_num)//Edit
{

	if (train_num==701)
	{
		printf("\nTrain:\t\t\tSubarna Express");
		printf("\nDestination:\t\tDhaka to Chittagong");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==711)
	{
		printf("\nTrain:\t\t\tSubarna Express");
		printf("\nDestination:\t\tChittagong to Dhaka ");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==703)
	{
		printf("\nTrain:\t\t\tTista Express");
		printf("\nDestination:\t\tDhaka to Dewangonj");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==713)
	{
		printf("\nTrain:\t\t\tTista Express");
		printf("\nDestination:\t\tDewangonj to Dhaka");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==705)
	{
		printf("\nTrain:\t\t\tKapotaskh Express");
		printf("\nDestination:\t\tDhaka To Rajhshahi");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==715)
	{
		printf("\ntrain:\t\t\tKapotaskh Express");
		printf("\nDestination:\t\tRajhshahi To Dhaka");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==707)
	{
		printf("\ntrain:\t\t\tPanchagarh Express");
		printf("\nDestination:\t\tDhaka to ");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==717)
	{
		printf("\ntrain:\t\t\tPanchagarh Express");
		printf("\n Destination:\t\tPanchagarh to Dhaka");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==711)
	{
		printf("\ntrain:\t\t\tChittra Express");
		printf("\nDestination:\t\tDhaka To Khulna");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==731)
	{
		printf("\ntrain:\t\t\tChittra Express");
		printf("\nDestination:\t\tKhulna To Dhaka");
		printf("\nDeparture:\t\t1.15pm ");
	}
	if (train_num==712)
	{
		printf("\ntrain:\t\t\tMoitree Express");
		printf("\nDestination:\t\tDhaka To Kolkata");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (train_num==733)
	{
		printf("\ntrain:\t\t\tMoitree Express");
		printf("\nDestination:\t\tKolkata to Dhaka");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (train_num==720)
	{
		printf("\ntrain:\t\t\tUpaban Express");
		printf("\nDestination:\t\tDhaka to Syhlet");
		printf("\nDeparture:\t\t09:30pm ");
	}
	if (train_num==734)
	{
		printf("\ntrain:\t\t\tUpaban Express");
		printf("\nDestination:\t\tSyhlet to Dhaka");
		printf("\nDeparture:\t\t10:30pm ");
	}
}

int food_ct()
{
   system("CLS");//Clear Window
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t:::::::::::::   Food Menu    :::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    printf("\n\n\t\t\t\t\t\tEnter Your Choice: ");
    printf("\n\n\t\t\t\t\t\t1.Breakfast\n");
    printf("\t\t\t\t\t\t2.Lunch\n");
    printf("\t\t\t\t\t\t3.Snack\n");
    printf("\t\t\t\t\t\t4.Drinks\n");

   int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        breakfast_list();
        break;
    case 2:
        lunch_list();
        break;
     case 3:
        snack_list();
        break;
     case 4:
        drink_list();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        food_ct();

    }



}

/*Structure for food Start*/
struct food{
	char name[50];
	int seat_num;
	int couch_no;
	int quantity;
	int food_code;
	int train_code;
};
/*Structure End*/

/*Ticket Purchase Start*/
void foodpurchase(void)
{
	char confirm;
	int i=0;
	float charges;
	struct food passdetails;
	FILE *fp;
	fp=fopen("Food.txt","a");
	system("cls");

	printf("\nEnter Your Name: ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name
	printf("\nEnter Your Train Number: ");
	scanf("%d",&passdetails.train_code);
	printf("\nEnter Your Couch Number: ");
	scanf("%d",&passdetails.couch_no);
	printf("\nEnter Your Seat Number: ");
	scanf("%d",&passdetails.seat_num);
	printf("\n\nPress Enter To See Food Menu ");
	getch();
	system("cls");
	food_ct();
	printf("\n\nEnter Item Number: ");
	start1:
	scanf("%d",&passdetails.food_code);
	printf("\nEnter Food Quantity: ");
	scanf("%d",&passdetails.quantity);
	if(passdetails.quantity>=6)
    {
        printf("\n\nYou can not buy more then 5 Items at once. Please try again. ");
        getch();
        system("CLS");
        foodpurchase();
    }
	if(passdetails.food_code>=101 && passdetails.food_code<=130)
	{
		charges=cost(passdetails.food_code,passdetails.quantity);
		printdetails(passdetails.name,passdetails.food_code,passdetails.quantity,charges);
	}
	else
	{
		printf("\nInvalid Train Number! Enter Again. ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y'||confirm == 'Y')
	{
		fprintf(fp,"Name: %s\t\tFood Code: %d\t\tQuantity: %d\t\tCharge:%.2f\n",&passdetails.name,passdetails.food_code,passdetails.quantity,charges);

		printf("\nThank You, Your Ticket Purchase complete \n");
		printf("\nProceed for Payment........");
		payment_food();
	}
	else
	{
		if(confirm=='n'||confirm == 'N'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

int cost(int food_code,int item)
{
		if (food_code==101 && item==1)
	{
		printf("\t\t\t%f",90.0*1);
	}

	else if (food_code==101 && item==2)
	{
		printf("\t\t\t%f",90.0*2);
	}
	else if (food_code==101 && item==3)
	{
		printf("\t\t\t%f",90.0*3);
	}
	else if (food_code==101 && item==4)
	{
		printf("\t\t\t%f",90.0*4);
	}
	else if (food_code==101 && item==5)
	{
		printf("\t\t\t%f",90.0*5);
	}


	else if (food_code==102 && item==1)
	{
		printf("\t\t\t%f",70.0*1);
	}
	else if (food_code==102 && item==2)
	{
		printf("\t\t\t%f",70.0*2);
	}
	else if (food_code==102 && item==3)
	{
		printf("\t\t\t%f",70.0*3);
	}
	else if (food_code==102 && item==4)
	{
		printf("\t\t\t%f",70.0*4);
	}
	else if (food_code==102 && item==5)
	{
		printf("\t\t\t%f",70.0*5);
	}


	else if (food_code==103 && item==1)
	{
		printf("\t\t\t%f",40.0*1);
	}
	else if (food_code==103 && item==2)
	{
		printf("\t\t\t%f",40.0*2);
	}
	else if (food_code==103 && item==3)
	{
		printf("\t\t\t%f",40.0*3);
	}
	else if (food_code==103 && item==4)
	{
		printf("\t\t\t%f",40.0*4);
	}
	else if (food_code==103 && item==5)
	{
		printf("\t\t\t%f",40.0*5);
	}


	else if (food_code==104 && item==1)
	{
		printf("\t\t\t%f",50.0*1);
	}
	else if (food_code==104 && item==2)
	{
		printf("\t\t\t%f",50.0*2);
	}
	else if (food_code==104 && item==3)
	{
		printf("\t\t\t%f",50.0*3);
	}
	else if (food_code==104 && item==4)
	{
		printf("\t\t\t%f",50.0*4);
	}
	else if (food_code==104 && item==5)
	{
		printf("\t\t\t%f",50.0*5);
	}


	else if (food_code==105 && item==1)
	{
		printf("\t\t\t%f",110.0*1);
	}
	else if (food_code==105 && item==2)
	{
		printf("\t\t\t%f",110.0*2);
	}
	else if (food_code==105 && item==3)
	{
		printf("\t\t\t%f",110.0*3);
	}
	else if (food_code==105 && item==4)
	{
		printf("\t\t\t%f",110.0*4);
	}
	else if (food_code==105 && item==5)
	{
		printf("\t\t\t%f",110.0*5);
	}


	else if (food_code==106 && item==1)
	{
		printf("\t\t\t%f",140.0*1);
	}
	else if (food_code==106 && item==2)
	{
		printf("\t\t\t%f",140.0*2);
	}
	else if (food_code==106 && item==3)
	{
		printf("\t\t\t%f",140.0*3);
	}
	else if (food_code==106 && item==4)
	{
		printf("\t\t\t%f",140.0*4);
	}
	else if (food_code==106 && item==5)
	{
		printf("\t\t\t%f",140.0*5);
	}


	else if (food_code==107 && item==1)
	{
		printf("\t\t\t%f",90.0*1);
	}
	else if (food_code==107 && item==2)
	{
		printf("\t\t\t%f",90.0*2);
	}
	else if (food_code==107 && item==3)
	{
		printf("\t\t\t%f",90.0*3);
	}
	else if (food_code==107 && item==4)
	{
		printf("\t\t\t%f",90.0*4);
	}
	else if (food_code==107 && item==5)
	{
		printf("\t\t\t%f",90.0*5);
	}


	else if (food_code==108 && item==1)
	{
		printf("\t\t\t%f",130.0*1);
	}
	else if (food_code==108 && item==2)
	{
		printf("\t\t\t%f",130.0*2);
	}
	else if (food_code==108 && item==3)
	{
		printf("\t\t\t%f",130.0*3);
	}
	else if (food_code==108 && item==4)
	{
		printf("\t\t\t%f",130.0*4);
	}
	else if (food_code==108 && item==5)
	{
		printf("\t\t\t%f",130.0*5);
	}


	else if (food_code==109 && item==1)
	{
		printf("\t\t\t%f",180.0*1);
	}
	else if (food_code==109 && item==2)
	{
		printf("\t\t\t%f",180.0*2);
	}
	else if (food_code==109 && item==3)
	{
		printf("\t\t\t%f",180.0*3);
	}
	else if (food_code==109 && item==4)
	{
		printf("\t\t\t%f",180.0*4);
	}
	else if (food_code==109 && item==5)
	{
		printf("\t\t\t%f",180.0*5);
	}


	else if (food_code==110 && item==1)
	{
		printf("\t\t\t%f",70.0*1);
	}
	else if (food_code==110 && item==2)
	{
		printf("\t\t\t%f",70.0*2);
	}
	else if (food_code==110 && item==3)
	{
		printf("\t\t\t%f",70.0*3);
	}
	else if (food_code==110 && item==4)
	{
		printf("\t\t\t%f",70.0*4);
	}
	else if (food_code==110 && item==5)
	{
		printf("\t\t\t%f",70.0*5);
	}


	else if (food_code==111 && item==1)
	{
		printf("\t\t\t%f",30.0*1);
	}
	else if (food_code==111 && item==2)
	{
		printf("\t\t\t%f",30.0*2);
	}
	else if (food_code==111 && item==3)
	{
		printf("\t\t\t%f",30.0*3);
	}
	else if (food_code==111 && item==4)
	{
		printf("\t\t\t%f",30.0*4);
	}
	else if (food_code==111 && item==5)
	{
		printf("\t\t\t%f",30.0*5);
	}


	else if (food_code==112 && item==1)
	{
		printf("\t\t\t%f",30.0*1);
	}
	else if (food_code==112 && item==2)
	{
		printf("\t\t\t%f",30.0*2);
	}
	else if (food_code==112 && item==3)
	{
		printf("\t\t\t%f",30.0*3);
	}
	else if (food_code==112 && item==4)
	{
		printf("\t\t\t%f",30.0*4);
	}
	else if (food_code==112 && item==5)
	{
		printf("\t\t\t%f",30.0*5);
	}


	else if (food_code==113 && item==1)
	{
		printf("\t\t\t%f",20.0*1);
	}
	else if (food_code==113 && item==2)
	{
		printf("\t\t\t%f",20.0*2);
	}
	else if (food_code==113 && item==3)
	{
		printf("\t\t\t%f",20.0*3);
	}
	else if (food_code==113 && item==4)
	{
		printf("\t\t\t%f",20.0*4);
	}
	else if (food_code==113 && item==5)
	{
		printf("\t\t\t%f",20.0*5);
	}


	else if (food_code==114 && item==1)
	{
		printf("\t\t\t%f",10.0*1);
	}
	else if (food_code==114 && item==2)
	{
		printf("\t\t\t%f",10.0*2);
	}
	else if (food_code==114 && item==3)
	{
		printf("\t\t\t%f",10.0*3);
	}
	else if (food_code==114 && item==4)
	{
		printf("\t\t\t%f",10.0*4);
	}
	else if (food_code==114 && item==5)
	{
		printf("\t\t\t%f",10.0*5);
	}


	else if (food_code==115 && item==1)
	{
		printf("\t\t\t%f",25.0*1);
	}
	else if (food_code==115 && item==2)
	{
		printf("\t\t\t%f",25.0*2);
	}
	else if (food_code==115 && item==3)
	{
		printf("\t\t\t%f",25.0*3);
	}
	else if (food_code==115 && item==4)
	{
		printf("\t\t\t%f",25.0*4);
	}
	else if (food_code==115 && item==5)
	{
		printf("\t\t\t%f",25.0*5);
	}


	else if (food_code==116 && item==1)
	{
		printf("\t\t\t%f",15.0*1);
	}
	else if (food_code==116 && item==2)
	{
		printf("\t\t\t%f",15.0*2);
	}
	else if (food_code==116 && item==3)
	{
		printf("\t\t\t%f",15.0*3);
	}
	else if (food_code==116 && item==4)
	{
		printf("\t\t\t%f",15.0*4);
	}
	else if (food_code==116 && item==5)
	{
		printf("\t\t\t%f",15.0*5);
	}


	else if (food_code==117 && item==1)
	{
		printf("\t\t\t%f",15.0*1);
	}
	else if (food_code==117 && item==2)
	{
		printf("\t\t\t%f",15.0*2);
	}
	else if (food_code==117 && item==3)
	{
		printf("\t\t\t%f",15.0*3);
	}
	else if (food_code==117 && item==4)
	{
		printf("\t\t\t%f",15.0*4);
	}
	else if (food_code==117 && item==5)
	{
		printf("\t\t\t%f",15.0*5);
	}


	else if (food_code==118 && item==1)
	{
		printf("\t\t\t%f",20.0*1);
	}
	else if (food_code==118 && item==2)
	{
		printf("\t\t\t%f",20.0*2);
	}
	else if (food_code==118 && item==3)
	{
		printf("\t\t\t%f",20.0*3);
	}
	else if (food_code==118 && item==4)
	{
		printf("\t\t\t%f",20.0*4);
	}
	else if (food_code==118 && item==5)
	{
		printf("\t\t\t%f",20.0*5);
	}


	else if (food_code==119 && item==1)
	{
		printf("\t\t\t%f",10.0*1);
	}
	else if (food_code==119 && item==2)
	{
		printf("\t\t\t%f",10.0*2);
	}
	else if (food_code==119 && item==3)
	{
		printf("\t\t\t%f",10.0*3);
	}
	else if (food_code==119 && item==4)
	{
		printf("\t\t\t%f",10.0*4);
	}
	else if (food_code==119 && item==5)
	{
		printf("\t\t\t%f",10.0*5);
	}



	else if (food_code==120 && item==1)
	{
		printf("\t\t\t%f",15.0*1);
	}
	else if (food_code==120 && item==2)
	{
		printf("\t\t\t%f",15.0*2);
	}
	else if (food_code==120 && item==3)
	{
		printf("\t\t\t%f",15.0*3);
	}
	else if (food_code==120 && item==4)
	{
		printf("\t\t\t%f",15.0*4);
	}
	else if (food_code==120 && item==5)
	{
		printf("\t\t\t%f",15.0*5);
	}



	else if (food_code==121 && item==1)
	{
		printf("\t\t\t%f",30.0*1);
	}
	else if (food_code==121 && item==2)
	{
		printf("\t\t\t%f",30.0*2);
	}
	else if (food_code==121 && item==3)
	{
		printf("\t\t\t%f",30.0*3);
	}
	else if (food_code==121 && item==4)
	{
		printf("\t\t\t%f",30.0*4);
	}
	else if (food_code==121 && item==5)
	{
		printf("\t\t\t%f",30.0*5);
	}



	else if (food_code==122 && item==1)
	{
		printf("\t\t\t%f",20.0*1);
	}
	else if (food_code==122 && item==2)
	{
		printf("\t\t\t%f",20.0*2);
	}
	else if (food_code==122 && item==3)
	{
		printf("\t\t\t%f",20.0*3);
	}
	else if (food_code==122 && item==4)
	{
		printf("\t\t\t%f",20.0*4);
	}
	else if (food_code==122 && item==5)
	{
		printf("\t\t\t%f",20.0*5);
	}


		else if (food_code==123 && item==1)
	{
		printf("\t\t\t%f",35.0*1);
	}
		else if (food_code==123 && item==2)
	{
		printf("\t\t\t%f",35.0*2);
	}
		else if (food_code==123 && item==3)
	{
		printf("\t\t\t%f",35.0*3);
	}
		else if (food_code==123 && item==4)
	{
		printf("\t\t\t%f",35.0*4);
	}
		else if (food_code==123 && item==5)
	{
		printf("\t\t\t%f",35.0*5);
	}


		else if (food_code==124 && item==1)
	{
		printf("\t\t\t%f",60.0*1);
	}
		else if (food_code==124 && item==2)
	{
		printf("\t\t\t%f",60.0*2);
	}
		else if (food_code==124 && item==3)
	{
		printf("\t\t\t%f",60.0*3);
	}
		else if (food_code==124 && item==4)
	{
		printf("\t\t\t%f",60.0*4);
	}
		else if (food_code==124 && item==5)
	{
		printf("\t\t\t%f",60.0*5);
	}


}



void printdetails(char name[],int food_code,int item,float charges)
{
	system("cls");
	printf("-----------------------------------\n");
	printf("\t   Total Amount\n");
	printf("-----------------------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nFood Code:\t\t%d",food_code);
	printf("\nQuantity:\t\t%d",item);
	food_spec(food_code);
	printf("\nCharges:\t\t%.2f",cost);
}

void food_spec(int food_code)
{

	if (food_code==101)
	{
		printf("\nFood: \t\t\tSpecial Naan With Chicken curry");
		printf("\nUnit Price:\t\t90 Tk");
	}

	else if (food_code==102)
	{
		printf("\nFood: \t\t\tBrown bread with eggs");
		printf("\nUnit Price:\t\t70 Tk");
	}
	else if (food_code==103)
	{
		printf("\nFood: \t\t\tPorota with special vegetable curry");
		printf("\nUnit Price:\t\t40 Tk");
	}
	else if (food_code==104)
	{
		printf("\nFood: \t\t\tCreamy Omlates with bread ");
		printf("\nUnit Price:\t\t50 Tk");
	}
	else if (food_code==105)
	{
		printf("\nFood: \t\t\tFried Rice with Chicken Carry  ");
		printf("\nUnit Price:\t\t110 Tk");
	}
	else if (food_code==106)
	{
		printf("\nFood: \t\t\tFried rice with beef curry  ");
		printf("\nUnit Price:\t\t140 Tk");
	}

	else if (food_code==107)
	{
		printf("\nFood: \t\t\tBhuna khichuri with egg  ");
		printf("\nUnit Price:\t\t190 Tk");
	}
else if (food_code==108)
	{
		printf("\nFood: \t\t\tChicken Biriyani  ");
		printf("\nUnit Price:\t\t130 Tk");
	}
else if (food_code==109)
	{
		printf("\nFood: \t\t\tBeef Biriyani  ");
		printf("\nUnit Price:\t\t180 Tk");
	}
else if (food_code==110)
	{
		printf("\nFood: \t\t\tChicken Sorma Role  ");
		printf("\nUnit Price:\t\t70 Tk");
	}
else if (food_code==111)
	{
		printf("\nFood: \t\t\tHandmade Chips   ");
		printf("\nUnit Price:\t\t30 Tk");
	}
else if (food_code==112)
	{
		printf("\nFood: \t\t\tVegetable Role   ");
		printf("\nUnit Price:\t\t30 Tk");
	}
	else if (food_code==113)
	{
		printf("\nFood: \t\t\tCup Cake   ");
		printf("\nUnit Price:\t\t20 Tk");
	}
	else if (food_code==114)
	{
		printf("\nFood: \t\t\tPopcorn   ");
		printf("\nUnit Price:\t\t10 Tk");
	}
	else if (food_code==115)
	{
		printf("\nFood: \t\t\tChocolate Box   ");
		printf("\nUnit Price:\t\t25 Tk");
	}
	else if (food_code==116)
	{
		printf("\nFood: \t\t\tPotato Chips   ");
		printf("\nUnit Price:\t\t15 Tk");
	}
	else if (food_code==117)
	{
		printf("\nFood: \t\t\tMineral Water(500ml)   ");
		printf("\nUnit Price:\t\t15 Tk");
	}
	else if (food_code==118)
	{
		printf("\nFood: \t\t\tMineral Water(1 Liter)   ");
		printf("\nUnit Price:\t\t20 Tk");
	}
	else if (food_code==119)
	{
		printf("\nFood: \t\t\tRed Te   ");
		printf("\nUnit Price:\t\t10 Tk");
	}
	else if (food_code==120)
	{
		printf("\nFood: \t\t\tMilk Tea   ");
		printf("\nUnit Price:\t\t15 Tk");
	}
	else if (food_code==121)
	{
		printf("\nFood: \t\t\tcoffee  ");
		printf("\nUnit Price:\t\t30 Tk");
	}
	else if (food_code==122)
	{
		printf("\nFood: \t\t\tCold Drinks (250ml)  ");
		printf("\nUnit Price:\t\t20 Tk");
	}
	else if (food_code==123)
	{
		printf("\nFood: \t\t\tCold Drinks (500ml)  ");
		printf("\nUnit Price:\t\t35 Tk");
	}
	else if (food_code==124)
	{
		printf("\nFood: \t\t\tCold Drinks (1 Liter)   ");
		printf("\nUnit Price:\t\t60 Tk");
	}

}


int breakfast_list()
{
    //Train list by file
    system("CLS");
	printf("\t\t\t---------------------------------------------------------------------------------------");
	printf("\n\t\t\tItem No.\tFood Name\t\t\tCharges\t\tQuantity\n");
	printf("\t\t\t---------------------------------------------------------------------------------------");
	printf("\n\t\t\t101\tSpecial Naan With Chicken curry \t  90\t\t   01\n");
	printf("\n\t\t\t102\tBrown bread with eggs \t\t\t  70\t\t   01\n");
	printf("\n\t\t\t103\tPorota with special vegetable curry \t  40\t\t   01\n");
	printf("\n\t\t\t104\tCreamy Omlates with bread \t\t  50\t\t   01\n");
    printf("\n\n");
}

int lunch_list()
{
    //Train list by file
    system("CLS");
    system("cls");
	printf("\t\t\t---------------------------------------------------------");
	printf("\n\t\t\tItem No.\tFood Name\t\t\tCharges\n");
	printf("\t\t\t---------------------------------------------------------");
	printf("\n\t\t\t105\tFried Rice with Chicken Carry \t\t\ 110\n");
	printf("\n\t\t\t106\tFried rice with beef curry \t\t 140\n");
	printf("\n\t\t\t107\tBhuna khichuri with egg \t\t 90\n");
	printf("\n\t\t\t108\tChicken Biriyani \t\t\t 130\n");
	printf("\n\t\t\t109\tBeef Biriyani \t\t\t\t 180\n");
    printf("\n\n");
}

int snack_list()
{
    //Train list by file
    system("cls");
	printf("\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\tItem No.\tFood Name\t\t\tCharges\n");
	printf("\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\t110\tChicken Sorma Role \t\t\t   70\n");
	printf("\n\t\t\t111\tHandmade Chips \t\t\t\t   30\n");
	printf("\n\t\t\t112\tVegetable Role \t\t\t\t   30\n");
	printf("\n\t\t\t113\tCup Cake \t\t\t\t   20\n");
	printf("\n\t\t\t114\tPopcorn \t\t\t\t   10\n");
	printf("\n\t\t\t115\tChocolate Box \t\t\t\t   25\n");
	printf("\n\t\t\t116\tPotato Chips \t\t\t\t   15\n");
    printf("\n\n");
}

int drink_list()
{
    //Train list by file
    system("cls");
	printf("\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\tItem No.\tFood Name\t\t\tCharges\n");
	printf("\t\t\t--------------------------------------------------------------");
	printf("\n\t\t\t117\tMineral Water(500ml) \t\t\t  15\n");
	printf("\n\t\t\t118\tMineral Water(1 Liter) \t\t\t  20\n");
	printf("\n\t\t\t119\tRed Tea \t\t\t\t  10\n");
	printf("\n\t\t\t120\tMilk Tea \t\t\t\t  15\n");
	printf("\n\t\t\t121\tCoffee \t\t\t\t\t  30\n");
	printf("\n\t\t\t122\tCold Drinks (250ml) \t\t\t  20\n");
	printf("\n\t\t\t123\tCold Drinks (500ml) \t\t\t  35\n");
	printf("\n\t\t\t124\tCold Drinks (1 Liter) \t\t\t  60\n");
    printf("\n\n");
}


/*My account Start*/
int user_account()
{
    system("CLS");//Clear Window
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::       My Account      :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("\n\t\t\t\t\t\t1. General \n");
    printf("\t\t\t\t\t\t2. Back \n");
   int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        general();
        break;
    case 2:
        User();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        user_account();
    }
}

/*General Setting Start*/
int general()
{
    printf("\n\n\t\t\t\t\t\t\t\t\tGeneral\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n\t\t\t\t\t\t   General Information: \n");
    usr_details();
    back2();

}
/*General Setting End*/

/*My account End*/

/* Complain Start*/

/* Complain End*/
int User_Complain_Contact()
{
        system("cls");
        printf("\n\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::       Complain  :::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("\n\n\t\t\t\t\t\t\tFeel Free to Contact To Us\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::\n");


        printf("\n\n\n\t\t\t\t\t\t1.Report a Complain\n");
        printf("\n\t\t\t\t\t\t2.My complain\n");
        printf("\n\t\t\t\t\t\t3.User\n");
        printf("\n\t\t\t\t\t\t4.Home\n");

        int ch;
        printf("\n\n\n\t\t\t\t\t\tEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            Report();
            break;
        case 2:
            My_Report();
            break;
        case 3:
            User();
            break;
        case 4:
            home();
        default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        User_Complain_Contact();
        }
}

int usr_helpline()
{
   system("cls");
        printf("\n\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::       Helpline     ::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("\n\n\t\t\t\t\t\t\tFeel Free to Contact To Us\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::\n");



        printf("\n\t\t\t\t\t\tPolice\t\t :%s\n","999");
        printf("\n\t\t\t\t\t\tMedical\t\t : %s\n","16247");
        printf("\n\t\t\t\t\t\tFire-Service\t : %s\n","121");
        printf("\n\t\t\t\t\t\tNational Emergency Number: %s\n\n","121");
        printf("\n\t\t\t\t\t\tTelephone: %s\n","+88025003825");
        printf("\n\t\t\t\t\t\tHotline: %s\n","167222");
        printf("\n\t\t\t\t\t\tEmail: %s\n","help@railsheba.gov.bd\n");

        printf("\n\t\t\t\t\t\t                Account Section\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\n\t\t\t\t\t\tMobile Number: %s\n","+8801959981909");
        printf("\n\t\t\t\t\t\tEmail Address: %s\n","account.section@railsheba.gov.bd\n");


        printf("\n\t\t\t\t\t\t                General Section\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\n\t\t\t\t\t\tMobile Number: %s\n","+8801784918947");
        printf("\n\t\t\t\t\t\tEmail Address: %s\n","g.section@railsheba.gov.bd\n");

        printf("\n\t\t\t\t\t\t             Train Schedule Scetion\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\n\t\t\t\t\t\tMobile Number: %s\n","+8801794300754");
        printf("\n\t\t\t\t\t\tEmail Address: %s\n","ts.section@railsheba.gov.bd\n");

        back2();
}

int Report()
{
    FILE *fptr;
    fptr = fopen("User_Complain.txt", "a");
    struct comp add;

    gets(add.name);
    printf("\n\t\t\t\t\t\tEnter Your Name: "); gets(add.name);
    printf("\t\t\t\t\t\tEnter Your Phone Number: "); scanf("%[^\n]%*c", add.phone);
    printf("\t\t\t\t\t\tWrite your  complain Below 100 words: "); scanf("%[^\n]%*c", add.disc);

    fprintf(fptr,"\t\t\t\t\t\tName: %s\n\t\t\t\t\t\tPhone no: %s\n\t\t\t\t\t\tComplain: %s\n", add.name, add.phone, add.disc);
    //tl_list();
    fclose(fptr);
    back2();
}
int My_Report()
{
    system("cls");
    FILE *fp = fopen("User_Complain.txt", "r");
    char buff_comp[255];

    if(fp == NULL)
    {
       printf("Unable to open file!");
       printf("Press any key to continue");
       getch();
       User();
    }

    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::      My Complain      :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    while(fgets(buff_comp, sizeof(buff_comp), fp) != NULL)
        {
            fputs(buff_comp, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
    back2();
}

/*Back Function Start*/

int NoticeBoard()
{
    system("cls");
        printf("\n\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t:::::::::::       Notice  ::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n");


        printf("\n\n\n\t\t\t\t\t\t1.Add Notice\n");
        printf("\n\t\t\t\t\t\t2.View Notice\n");
        printf("\n\t\t\t\t\t\t3.Delete Notice\n");
        printf("\n\t\t\t\t\t\t4.Back\n");

        int ch;
        printf("\n\n\n\t\t\t\t\t\tEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            add_notice();
            break;
        case 2:
            view_notice();
            break;
        case 3:
            del_notice();
            break;
        case 4:
            Admin();
            break;
        default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
       getch();
        system("CLS");
        NoticeBoard();
        }
}
int add_notice()
{
    FILE *fptr;
    fptr = fopen("Notice.txt", "a");
    struct notice ntc;

    gets(ntc.notice_no);
    printf("\n\t\t\t\t\t\tEnter Notice Number: "); gets(ntc.notice_no);
    printf("\t\t\t\t\t\tWrite Notice Below 100 words: "); scanf("%[^\n]%*c", ntc.notice_desc);

    fprintf(fptr,"\t\t\t\t\t\tNotice No: %s\n\t\t\t\t\t\tNotice: %s\n", ntc.notice_no, ntc.notice_desc);
    //tl_list();
    fclose(fptr);
    back2();
}


int view_notice()
{
    system("cls");
    FILE *fp = fopen("Notice.txt", "r");
    char buff_notice[255];

    if(fp == NULL)
    {
       printf("Unable to open file!");
       printf("Press any key to continue");
       getch();
       User();
    }

    printf("\n\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t:::::::::::       Notice  ::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n");

    while(fgets(buff_notice, sizeof(buff_notice), fp) != NULL)
        {
            fputs(buff_notice, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);
    back2();
}


int del_notice()
{

    system("CLS");
    printf("\n\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                         ::\n");
    printf("\t\t\t\t\t\t::::::::     Delete Train List     ::::::::::\n");
    printf("\t\t\t\t\t\t::                                         ::\n");
    printf("\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
     FILE *fileptr1, *fileptr2;

    char filename[40];

    char ch;

    int delete_line, temp = 1;



    printf("\t\t\t\t\t\tEnter File Name: ");

    scanf("%s", filename);

    //open file in read mode

    fileptr1 = fopen(filename, "r");

    ch = getc(fileptr1);

   while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    //rewind

    rewind(fileptr1);

    printf(" \n\t\t\t\t\t\t Enter Line Number of The Line to Be Deleted:");

    scanf("%d", &delete_line);

    //open new file in write mode

    fileptr2 = fopen("replica.c", "w");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        ch = getc(fileptr1);

        if (ch == '\n')

            temp++;

            //except the line to be deleted

            if (temp != delete_line)

            {

                //copy all lines in file replica.c

                putc(ch, fileptr2);

            }

    }

    fclose(fileptr1);

    fclose(fileptr2);

    remove(filename);

    //rename the file replica.c to original name

    rename("replica.c", filename);

    printf("\n\t\t\t\t\t\t The Contents of File After Being Modified Are As Follows:\n");

    fileptr1 = fopen(filename, "r");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    fclose(fileptr1);

    return 0;
}

 int back()
 {
    printf("\n\t\t\t\t\t\t1. Admin Section\n");
    printf("\t\t\t\t\t\t2. Home \n");
   int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Admin();
        break;
    case 2:
        home();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        back();
    }
 }
 /*Back Function End*/

 /*Back Function Start*/
 int back2()
 {
    printf("\n\t\t\t\t\t\t1. User Section \n");
    printf("\t\t\t\t\t\t2. Home \n");
   int ch;
    printf("\n\t\t\t\t\t\tEnter your Choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        User();
        break;
    case 2:
        home();
        break;
    default:
        printf("\a\n\t\t\t\t\t\tWrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        back2();
    }
 }
 /*Back Function End*/

/*Exit Start*/
    int DisplayResourceNAMessageBox()
{
    int msgboxID = MessageBox(
        0,"Want to Exit?","Exit",MB_ICONQUESTION | MB_OKCANCEL | MB_DEFBUTTON1
    );

    switch (msgboxID)
    {
    case IDOK:
        {
            system("taskkill/IM cb_console_runner.exe");
        }
        // TODO: add code
        break;
    case IDCANCEL:
        Admin();
        break;
    }

    return msgboxID;
}


    int DisplayResourceNAMessageBox2()
{
    int msgboxID = MessageBox(
        0,"Want to Exit?","Exit",MB_ICONQUESTION | MB_OKCANCEL | MB_DEFBUTTON1
    );

    switch (msgboxID)
    {
    case IDOK:
        {
            system("taskkill/IM cb_console_runner.exe");
        }
        // TODO: add code
        break;
    case IDCANCEL:
       User();
        break;
    }

    return msgboxID;
}

 /*Exit End*/

struct log{
char fname[80];
char email[50];
char phone[15];
char nid[20];
char password[32];
char username[30];
char dob[20];
char dd[5],mm[12];
int yy[10];

}*pUser;

void user_login(void)
{
    FILE *fp;
    char uName[30], pwd[30];int i;char c;

    pUser=(struct log *)malloc(sizeof(struct log));
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::      Login Menu       :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    if ( ( fp=fopen("user_info.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user_info.dat", "w+")) == NULL) {
                    printf ("\n\t\t\t\t\t\tCould not open file\n");
                    printf("\n\t\t\t\t\t\tPress any key to continue");
                    getch();
                    home();
                }
            }
            printf("\n\t\t\t\t\t\tUser_Name: ");
            scanf("%s",uName);
            printf("\n\t\t\t\t\t\tPassword: ");
            scanf("%s",pwd);
             while ( fread (pUser, sizeof(struct log), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
                    if( strcmp ( pUser->password, pwd) == 0) {
                            User();

                    }
                    User();
                }

                  else
                {
                  printf("\n\t\t\t\tInvalid Username or Password. Please Try again....\n");
                  getch();
                  printf("\n\n");
                  user_login();
                }
            }


}


int reg()
{
    system("cls");
    FILE *fp;
    char uName[30], pwd[30];int i;char c;
    char fname[80],phone[15],email[50],nid[20],dob[30];

    pUser=(struct log *)malloc(sizeof(struct log));
    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::   Registration Menu   :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
     do
            {
                if ( ( fp=fopen("user_info.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user_info.dat", "w+")) == NULL) {
                        printf ("\n\t\t\t\t\t\tCould not open file\n");
                        printf("\n\t\t\t\t\t\tPress any key to continue");
                        getch();
                        home();
                    }
                }
                fgets(fname, 80, stdin);//bug
                printf("\n\t\t\t\t\t\tFull Name: ");
                gets(pUser->fname);
                printf("\n\t\t\t\t\t\tPhone Number : ");
                gets(pUser->phone);
                printf("\n\t\t\t\t\t\tEmail Address: ");
                gets(pUser->email);
                printf("\n\t\t\t\t\t\tEnter Date of Birth: ");
                gets(pUser->dob);
                printf("\n\t\t\t\t\t\tYour NID Number (13/17 Digit): ");
                gets(pUser->nid);
                printf("\n\t\t\t\t\t\tChoose A User_Name: ");
                scanf("%9s",pUser->username);
                printf("\n\t\t\t\t\t\tChoose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct log), 1, fp);
                //printf("\n\t\t\tYour Information: \n");
                //fprintf(fp,"Name: %s\nPhone: %s\nEmail: %s\nNID: %s tk\nDate of Birth: %s\nUsername:%s,\nPassword:%s", pUser->fname, pUser->phone, pUser->email,pUser->nid,pUser->dob,pUser->username, pUser->password);
                //show_item();
                fclose(fp);
                printf("\n\n");
                printf("\n\t\t\t\t\t\tWould You Like To Add Another Account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace


            }while(c=='Y'||c=='y');
            if (c=='N'||c=='n')
            {
                system("CLS");
                User_menu();
            }
}

int usr_details()
{

    system("CLS");
   FILE *fp;
    printf("\n\n\t\t\t\t\t\t\t\t General Account\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::\n");
    pUser=(struct log *)malloc(sizeof(struct log));

    if ( ( fp=fopen("user_info.dat", "r")) == NULL) {
                if ( ( fp=fopen("user_info.dat", "w")) == NULL) {
                    printf ("Could not open file\n");
                    printf("Press any key to continue");
                    getch();
                    User();
                }
            }
             while ( fread (pUser, sizeof(struct log), 1, fp) == 1) {
                printf("\n\t\t\t\t\t\tName: %s",pUser->fname);
                printf("\n\t\t\t\t\t\tEmail: %s",pUser->email);
                printf("\n\t\t\t\t\t\tPhone: %s",pUser->phone);
                printf("\n\t\t\t\t\t\tNID: %s",pUser->nid);
                printf("\n\n");
            }

            fclose(fp);

            printf("\n\t\t\t\t\t\tPress Any key to Go Back.... ");
            getch();
            printf("\n");
            //User();

}



int show_item()
{
   FILE *fp = fopen("user_info.dat", "r");
    char buff_log[255];

    if(fp == NULL)
    {
       printf("\n\t\t\t\t\t\tUnable to open file!");
       exit(1);
    }

    printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::       Train List       :::::::::::\n");
    printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

    while(fgets(buff_log, sizeof(buff_log), fp) != NULL)
        {
            fputs(buff_log, stdout);
            fputs("\n\n", stdout);
        }
    fclose(fp);

}

int admin_details()
{
   FILE *fp;

    pUser=(struct log *)malloc(sizeof(struct log));

    if ( ( fp=fopen("user_info.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user_info.dat", "w+")) == NULL) {
                    printf ("\n\t\t\t\t\t\tCould not open file\n");
                    printf("\n\t\t\t\t\t\tPress any key to continue");
                    getch();
                    home();
                }
            }
             while ( fread (pUser, sizeof(struct log), 1, fp) == 1) {
                printf("\n\t\t\t\t\t\tName: %s",pUser->fname);
                printf("\n\t\t\t\t\t\tEmail: %s",pUser->email);
                printf("\n\t\t\t\t\t\tNID: %s",pUser->nid);
            }

            fclose(fp);

            printf("\n\t\t\t\t\t\tPress Any key to Go home.... ");
            getch();
            home();

}


void admin_login(void){
    char uName[30], pwd[30];int i;char c;
        printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
        printf("\t\t\t\t\t\t::::::::::      Login Menu       :::::::::::\n");
        printf("\t\t\t\t\t\t::                                        ::\n");
    printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

            printf("\n\t\t\t\t\t\tEnter Your User_Name: ");
            scanf("%s",uName);
            printf("\n\t\t\t\t\t\tEnter Your Password: ");
            scanf("%s",pwd);
          while(( strcmp(uName,"Shakil")==0 && strcmp(pwd,"1234")==0)||( strcmp(uName,"Rashad")==0 && strcmp(pwd,"1234")==0)||( strcmp(uName,"Shovon")==0 && strcmp(pwd,"1234")==0)||( strcmp(uName,"Meer")==0 && strcmp(pwd,"1234")==0))
            {
                        Admin();
            }
}


int Logout()
{
    system("CLS");
    home();
}
int DisplayResourceNAMessageBox3()
{
    int msgboxID = MessageBox(
        0,"Are You Want to Log Out?","Logout",MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON1
    );

    switch (msgboxID)
    {
    case IDYES:
        {
            home();
        }
        // TODO: add code
        break;
    case IDNO:
        User();
        break;
    }

    return msgboxID;
}




/*Option Start*/
int option()
{
    printf("\n\n\t\t\t\t\t\t\t\t\t    Option Menu\n\n");
    printf("\t\t\t\t\t\t1. Sign In\n");
    printf("\t\t\t\t\t\t2. About\n");
    printf("\t\t\t\t\t\t3. Home\n");


     int ch;
    printf("\n\t\t\t\t\t\tEnter Your Choice:");
    printf("\t\t\t\t\t\t");
    scanf("%d", &ch);
     switch(ch)
    {
    case 1:
       user_login();
        break;
    case 2:
    about();
        break;
    case 3:
    home();
        break;
     default:
        printf("Wrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        option();
    }
}

int about()
{
     printf("\n\n");
     printf("\t\t\t\t\t\tRail Sheba\n");
     printf("\t\t\t\t\t\tVersion 1.0\n");
     printf("\t\t\t\t\t\t© All Rights Reserved by INFINITY-2021\n");

    printf("\n\t\t\t\t\t\t1. Visit our Website\n");
    printf("\t\t\t\t\t\t2.Back\n");


     int ch;
    printf("\n\t\t\t\t\t\tEnter Your Choice:");
    printf("\t\t\t\t\t\t");
    scanf("%d", &ch);
     switch(ch)
    {
    case 1:
       website();
        break;
    case 2:
        home();
        break;
     default:
        printf("Wrong Input\n");
         printf("\t\t\t\t\t\tPress any key to go back.");
        getch();
        system("CLS");
        about();
    }
}

int website()
{
    system("explorer https://sites.google.com/view/rail-sheba");
    return 0;
}
/*Option End*/
int login()
{

}

void ccolor(int clr)
{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);

}
int main()
{
    system("color 07");

int n;

    int x; double y;
    char text1[]=    "\n\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\t\t\t\t\t\t::                                         ::\n\t\t\t\t\t\t:::::::     PROJECT : RAIL SHEBA      :::::::\n\t\t\t\t\t\t::                                         ::\n\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n\n";
    for(x=0; text1[x]!=NULL; x++)
    {
        printf("%c",text1[x]);
        for(y=0; y<=1111111; y++)
        {
        }
    }
    home();
    return 0;
}
