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

/*Home End*/
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
