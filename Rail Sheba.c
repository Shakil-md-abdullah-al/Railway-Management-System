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
