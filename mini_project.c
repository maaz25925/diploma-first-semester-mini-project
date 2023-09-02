#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<windows.h>
char filename[15];
int Password();
int AddRecord();
int ViewRecord();
int ListAllRecords();
int EditRecord();
int EditPassword();
int DeleteRecord();
int MainMenu();
char Encrypt();
char Decrypt();
struct Record
{
    char time[6];
    char place[25];
    char note[1000];
    char exitTime[6];
} ar, vr, er, dr;
int main()
{
    system("cls");
    MainMenu();
    return 0;
}
int MainMenu()
{
    int ch;
    printf("\n\t04-01-2022.P27.B3");    //DATE.PROTOTYPE-VERSION.BUILD-VERSION
    printf("\n\t");
    printf("\n\n\t-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t            PERSONAL DIARY         \n");
    printf("\t-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\n\n");
    while(1)
    {
        printf("\t          ___              _\n");
        printf("\t|\\/|  /\\   |  |\\ |   |\\/| |_ |\\ | | | \n");
        printf("\t|  | /--\\ _|_ | \\|   |  | |_ | \\| |_| \n");
        printf("                                       \n");
        printf("\n\n\tMAIN MENU:");
        printf("\n\n\tADD RECORD\t\t[1]");
        printf("\n\tVIEW RECORD\t\t[2]");
        printf("\n\tLIST ALL RECORDS\t[3]");
        printf("\n\tEDIT RECORD\t\t[4]");
        printf("\n\tDELETE RECORD\t\t[5]");
        printf("\n\tEDIT PASSWORD\t\t[6]");
        printf("\n\tQUICK TUTORIAL\t\t[7]");
        printf("\n\tEXIT\t\t\t[8]");
        printf("\n\n\tENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            AddRecord();
            break;
        case 2:
            ViewRecord();
            break;
        case 3:
            ListAllRecords();
            break;
        case 4:
            EditRecord();
            break;
        case 5:
            DeleteRecord();
            break;
        case 6:
            EditPassword();
            break;
        case 7:
            system("cls");
            printf("\n\t");
            printf("\n\t==============");
            printf("\n\tQUICK TUTORIAL");
            printf("\n\t==============");
            printf("\n\t");
            printf("\n\tKINDLY FOLLOW THE FOLLOWING THINGS TO ASSURE THAT THE PROGRAM WORKS PROPERLY");
            printf("\n\t");
            printf("\n\tPlace this program in a separete folder.");
            printf("\n\tCreate a New Folder on your Desktop and place this program there.");
            printf("\n\tFor multiple users, just create multiple folders inside the New Folder on your desktop and rename them as your name.");
            printf("\n\t(Continue for multiple users)Just copy this program into each of the subfolders, rename them as your names, add a shortcut to your desktop and you're done!");
            printf("\n\tIf you're using this program for the very first time then kindly change your password.");
            printf("\n\t");
            printf("\n\tKeep the format consistent whilst writing the date and time(preferably as mentioned)");
            printf("\n\tDATE FORMAT: dd:mm:yyyy --  01-01-2022 (Don't use spaces in between)");
            printf("\n\tTIME FORMAT: hh:mm (24 hour format) --  17:40 (Don't use spaces in between)");
            printf("\n\tPLACE: Should be under 49 words");
            printf("\n\tNOTE: Under 1000 words");
            printf("\n\t");
            printf("\n\tKeep in mind that whilst writing, if you press the enter key, that means that data will be stored.");
            printf("\n\tThat acts as a signal for indicating that the job for this line is done, let's move on to the next one");
            printf("\n\tOR");
            printf("\n\tBasically, you cannot divide it into paragraphs or leave lines.");
            printf("\n\tThis applies to every function/utility");
            printf("\n\t");
            printf("\n\tThank You for taking the time to read and follow the instructions");
            printf("\n\t");
            printf("\n\t~Maaz");
            printf("\n\t");
            printf("\n\tPress any key twice to exit");
            getch();
            getch();
            break;
        case 8:
            printf("\n\n\tTHANK YOU FOR USING THIS SOFTWARE ");
            getch();
            exit(0);
        default:
            printf("\n\tYOU ENTERED WRONG CHOICE...");
            printf("\n\tPRESS ANY KEY TO TRY AGAIN");
            getch();
            break;
        }
        system("cls");
    }
}
int Password()
{
    char pass[15]= {0},check[15]= {0},ch;
    FILE *fpp;
    int i=0,j;
    for(j=0; j<3; j++)
    {
        i=0;
        printf("\n\n\tENTER THE PASSWORD:");
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
                pass[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass[i]=getch();
            }
        }
        pass[i]='\0';
        fpp=fopen("SE","r");
        if (fpp==NULL)
        {
            printf("\n\tERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");
            getch();
            return 1;
        }
        else
            i=0;
        while(1)
        {
            ch=fgetc(fpp);
            if(ch==EOF)
            {
                check[i]='\0';
                break;
            }
            check[i]=ch-10;
            i++;
        }
        if(strcmp(pass,check)==0)
        {
            printf("\n\n\tACCESS GRANTED...\n");
            return 0;
        }
        else
        {
            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
        }
    }
    printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
    return 1;
}
int AddRecord()
{
    system("cls");
    FILE *filepointer ;
    char AddAnotherRecord = 'Y' ,time[10];
    // char filename[15];
    int choice;
    printf("\n\t        _   _          _          \n");
    printf("\t   /\\  | \\ | \\   |\\/| |_ |\\ | | | \n");
    printf("\t  /--\\ |_/ |_/   |  | |_ | \\| |_| \n");
    printf("\t                                 \n");
    printf("\n\t\tADD MENU\n");
    printf("\n\n\tENTER DATE OF YOUR RECORD[dd-mm-yyyy]: ");
    fflush(stdin);
    gets(filename);
    filepointer = fopen (filename, "ab+" ) ;
    if ( filepointer == NULL )
    {
        filepointer=fopen(filename,"wb+");
        if(filepointer==NULL)
        {
            printf("\n\tSYSTEM ERROR");
            printf("\n\tPRESS ANY KEY TO EXIT");
            getch();
            return 0;
        }
    }
    while ( AddAnotherRecord == 'Y'|| AddAnotherRecord=='y' )
    {
        Decrypt();
        choice=0;
        fflush(stdin);
        printf ( "\tENTER TIME[hh:mm]:");
        scanf("%s",time);
        rewind(filepointer);
        while(fread(&ar,sizeof(ar),1,filepointer)==1)
        {
            if(strcmp(ar.time,time)==0)
            {
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;
            }
        }
        if(choice==0)
        {
            strcpy(ar.time,time);
            printf("\tENTER PLACE:");
            fflush(stdin);
            gets(ar.place);
            printf("\tNOTE:");
            fflush(stdin);
            gets(ar.note);
            printf("\tEXIT-TIME[hh:mm]:");
            fflush(stdin);
            gets(ar.exitTime);
            fwrite ( &ar, sizeof (ar), 1, filepointer ) ;
            printf("\n\tYOUR RECORD IS ADDED\n");
            fclose (filepointer) ;
            Encrypt();
        }
        printf ( "\n\tADD ANOTHER RECORD?(Y/N): " ) ;
        fflush ( stdin ) ;
        AddAnotherRecord = getchar( ) ;
    }
    printf("\n\n\tPRESS ANY KEY TO EXIT");
    getch();
}
int ListAllRecords()
{
    system("cls");
    struct dirent *de; // Pointer for directory entry
	// opendir() returns a pointer of DIR type.
	DIR *dr = opendir(".\\");
	if (dr == NULL) // opendir returns NULL if couldn't open directory
	{
		printf("Could not open current directory" );
		return 0;
	}
	// Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
	// for readdir()
    printf("\n\tIGNORE ANYTHING OTHER THAN RECORD(/DATE)\n");
    printf("\n\tPRESENT RECORDS: \n\n");
	while ((de = readdir(dr)) != NULL)
		printf("\t%s\n", de->d_name);
	closedir(dr);
    printf("\n\tPress any key to exit\t");
    getch();
	return 0;
}
int ViewRecord()
{
    FILE *filepointertoview ;
    system("cls");
    char time[6], selection;
    // char filename[15];
    int ch;
    printf("\t    ___  _                _\n");
    printf("\t\\  / |  |_ \\    /   |\\/| |_ |\\ | | | \n");
    printf("\t \\/ _|_ |_  \\/\\/    |  | |_ | \\| |_| \n");
    printf("\t                                      \n");
    printf("\n\tVIEW MENU\n");
    selection = Password();
    if(selection  != 0)
    {
        return 0;
    }
    do
    {
        printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED[dd-mm-yyyy]: ");
        fflush(stdin);
        gets(filename);
        filepointertoview = fopen ( filename, "rb" ) ;
        if ( filepointertoview == NULL )
        {
            puts ( "\n\tTHE RECORD DOES NOT EXIST\n" ) ;
            printf("\tPRESS ANY KEY TO EXIT");
            getch();
            return 0;
        }
        Decrypt();
        system("cls");
        printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");
        printf("\n\t1.WHOLE RECORD OF THE DAY.");
        printf("\n\t2.RECORD OF FIX TIME.");
        printf("\n\tENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n\tTHE WHOLE RECORD FOR %s IS:",filename);
            while ( fread ( &vr, sizeof ( vr ), 1, filepointertoview ) == 1 )
            {
                printf("\n");
                printf("\n\tTIME: %s",vr.time);
                printf("\n\tPLACE: %s",vr.place);
                printf("\n\tNOTE: %s",vr.note);
                printf("\n\tEXIT-TIME[hh:mm]: %s", vr.exitTime);
                printf("\n");
            }
            break;
        case 2:
            fflush(stdin);
            printf("\n\tENTER TIME[hh:mm]:");
            gets(time);
            while ( fread ( &vr, sizeof ( vr ), 1, filepointertoview ) == 1 )
            {
                if(strcmp(vr.time, time) == 0)
                {
                    printf("\n\tYOUR RECORD IS:");
                    printf("\n\tTIME: %s",vr.time);
                    printf("\n\tPLACE: %s",vr.place);
                    printf("\n\tNOTE: %s",vr.note);
                    printf("\n\tEXIT-TIME[hh:mm]: %s", vr.exitTime);
                }
            }
            break;
        default:
            printf("\n\tYOU TYPED SOMETHING ELSE\n");
            break;
        }
        fclose ( filepointertoview ) ;
        Encrypt();
        printf("\n\n\tWOULD YOU LIKE TO CONTINUE VIEWING?(Y/N): ");
        fflush(stdin);
        scanf("%c",&selection);
    }
    while(selection == 'Y' || selection == 'y');
    return 0;
}
int EditRecord()
{
    system("cls");
    FILE *filetopointertoedit;
    char time[6], selection;
    // char filename[15];
    int num, count = 0;
    printf("\n\t  _  _  ___ ___         _          \n");
    printf("\t |_ | \\  |   |    |\\/| |_ |\\ | | | \n");
    printf("\t |_ |_/ _|_  |    |  | |_ | \\| |_| \n");
    printf("                                   \n");
    printf("\tEDIT MENU\n");
    selection = Password();
    if(selection != 0)
    {
        return 0;
    }
    do
    {
        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED[dd-mm-yyyy]: ");
        fflush(stdin);
        gets(filename);
        printf("\n\tENTER TIME[hh:mm]: ");
        gets(time);
        filetopointertoedit = fopen ( filename, "rb+" );
        if ( filetopointertoedit == NULL )
        {
            printf( "\n\tRECORD DOES NOT EXISTS" ) ;
            printf("\n\tPRESS ANY KEY TO GO BACK");
            getch();
            return 0;
        }
        while ( fread ( &er, sizeof ( er ), 1, filetopointertoedit ) == 1 )
        {
            Decrypt();
            if(strcmp(er.time, time) == 0)
            {
                printf("\n\tYOUR OLD RECORD WAS AS:");
                printf("\n\tTIME: %s",er.time);
                printf("\n\tPLACE: %s",er.place);
                printf("\n\tNOTE: %s",er.note);
                printf("\n\tEXIT-TIME[hh:mm]: %s", er.exitTime);
                printf("\n\n\tWHAT WOULD YOU LIKE TO EDIT?");
                printf("\n\t1.TIME.");
                printf("\n\t2.PLACE.");
                printf("\n\t3.NOTE.");
                printf("\n\t4.EXIT-TIME.");
                printf("\n\t5.WHOLE RECORD.");
                printf("\n\t6.GO BACK TO MAIN MENU.");
                do
                {
                    printf("\n\tENTER YOUR CHOICE:\n");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);
                    switch(num)
                    {
                    case 1:
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tNEW TIME[hh:mm]:");
                        gets(er.time);
                        break;
                    case 2:
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tPLACE:");
                        gets(er.place);
                        break;
                    case 3:
                        printf("\tENTER THE NEW DATA:");
                        printf("\n\tNOTE:");
                        gets(er.note);
                        break;
                    case 4:
                        printf("\tENTER THE NEW DATA:");
                        printf("\n\tEXIT-TIME[hh:mm]:");
                        gets(er.exitTime);
                        break;
                    case 5:
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tNEW TIME[hh:mm]:");
                        gets(er.time);
                        printf("\n\tNEW MEETING PLACE:");
                        gets(er.place);
                        printf("\n\tNOTE:");
                        gets(er.note);
                        printf("\n\tEXIT-TIME[hh:mm]:");
                        gets(er.exitTime);
                        break;
                    case 6:
                        printf("\n\tPRESS ANY KEY TO GO BACK.\n");
                        getch();
                        return 0;
                        break;
                    default:
                        printf("\n\tYOU TYPED SOMETHING ELSE.TRY AGAIN\n");
                        break;
                    }
                }
                while(num < 1 || num > 6);
                fseek(filetopointertoedit,-sizeof(er),SEEK_CUR);
                fwrite(&er,sizeof(er),1,filetopointertoedit);
                fseek(filetopointertoedit,-sizeof(er),SEEK_CUR);
                fread(&er,sizeof(er),1,filetopointertoedit);
                selection = 5;
                break;
            }
        }
        if(selection == 5)
        {
            system("cls");
            printf("\n\ttEDITING COMPLETED.\n");
            printf("\t--------------------\n");
            printf("\tTHE NEW RECORD IS:\n");
            printf("\t--------------------\n");
            printf("\n\tTIME: %s",er.time);
            printf("\n\tPLACE: %s",er.place);
            printf("\n\tNOTE: %s",er.note);
            printf("\n\tEXIT-TIME[hh:mm]: %s", er.exitTime);
            fclose(filetopointertoedit);
            Encrypt();
            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N): ");
            scanf("%c",&selection);
            count++;
        }
        else
        {
            printf("\n\tTHE RECORD DOES NOT EXIST\n");
            printf("\n\tWOULD YOU LIKE TO TRY AGAIN?(Y/N): ");
            scanf("%c",&selection);
        }
    }
    while(selection == 'Y' || selection == 'y');
    fclose ( filetopointertoedit ) ;
    if(count == 1)
        printf("\n\t%d FILE IS EDITED.\n",count);
    else if(count > 1)
        printf("\n\t%d FILES ARE EDITED\n",count);
    else
        printf("\n\tNO FILES EDITED.\n");
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();
}
int EditPassword()
{
    system("cls");
    printf("\n");
    char pass[15]= {0},confirm[15]= {0},ch;
    int choice,i,check;
    FILE *fp;
    fp=fopen("SE","rb");
    if(fp==NULL)
    {
        fp=fopen("SE","wb");
        if(fp==NULL)
        {
            printf("\n\tSYSTEM ERROR...");
            getch();
            return 0;
        }
        fclose(fp);
        printf("\n\tSYSTEM RESTORED...\n\tYOUR PASSWORD IS 'ENTER'\n\t PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
    fclose(fp);
    check=Password();
    if(check==1)
    {
        return 0;
    }
    do
    {
        if(check==0)
        {
            i=0;
            choice=0;
            printf("\n\n\tENTER THE NEW PASSWORD:");
            fflush(stdin);
            pass[0]=getch();
            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    pass[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    pass[i]=getch();
                }
            }
            pass[i]='\0';
            i=0;
            printf("\n\tCONFIRM PASSWORD:");
            confirm[0]=getch();
            while(confirm[i]!='\r')
            {
                if(confirm[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    confirm[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    confirm[i]=getch();
                }
            }
            confirm[i]='\0';
            if(strcmp(pass,confirm)==0)
            {
                fp=fopen("SE","wb");
                if(fp==NULL)
                {
                    printf("\n\ttSYSTEM ERROR");
                    getch();
                    return 0;
                }
                i=0;
                while(pass[i]!='\0')
                {
                    ch=pass[i];
                    putc(ch+10,fp);
                    i++;
                }
                putc(EOF,fp);
                fclose(fp);
            }
            else
            {
                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                choice=1;
            }
        }
    }
    while(choice==1);
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
}
int DeleteRecord()
{
    system("cls");
    FILE *filepointer,*filepointertodelete;
    // char filename[15];
    char AnotherRecord = 'Y' , time[10];
    int selection, check;
    printf("\n\t  _   _     _ ___ _         _          \n");
    printf("\t | \\ |_ |  |_  | |_   |\\/| |_ |\\ | | | \n");
    printf("\t |_/ |_ |_ |_  | |_   |  | |_ | \\| |_| \n");
    printf("                                       \n");
    printf("\ttDELETE MENU\n");
    check = Password();
    if(check==1)
    {
        return 0;
    }
    while ( AnotherRecord == 'Y' )
    {
        printf("\n\n\tHOW WOULD YOU LIKE TO DELETE?");
        printf("\n\n\tDELETE WHOLE RECORD\t\t\t[1]");
        printf("\n\tDELETE A PARTICULAR RECORD BY TIME\t[2]");
        do
        {
            printf("\n\tENTER YOU CHOICE:\n");
            scanf("%d",&selection);
            switch(selection)
            {
            case 1:
                printf("\n\tENTER THE DATE OF RECORD TO BE DELETED[dd-mm-yyyy]: ");
                fflush(stdin);
                gets(filename);
                filepointer = fopen (filename, "wb" ) ;
                if ( filepointer == NULL )
                {
                    printf("\n\tTHE FILE DOES NOT EXISTS");
                    printf("\n\tPRESS ANY KEY TO GO BACK.");
                    getch();
                    return 0;
                }
                fclose(filepointer);
                remove(filename);
                printf("\n\tDELETED SUCCESSFULLY");
                break;
            case 2:
                printf("\n\tENTER THE DATE OF RECORD:[dd-mm-yyyy]: ");
                fflush(stdin);
                gets(filename);
                filepointer = fopen (filename, "rb" ) ;
                if ( filepointer == NULL )
                {
                    printf("\n\tTHE FILE DOES NOT EXISTS");
                    printf("\n\tPRESS ANY KEY TO GO BACK.");
                    getch();
                    return 0;
                }
                filepointertodelete=fopen("temp","wb");
                if(filepointertodelete==NULL)
                {
                    printf("\n\tSYSTEM ERROR");
                    printf("\n\tPRESS ANY KEY TO GO BACK");
                    getch();
                    return 0;
                }
                Decrypt();
                printf("\n\tENTER THE TIME OF RECORD TO BE DELETED[hh:mm]: ");
                fflush(stdin);
                gets(time);
                while(fread(&dr,sizeof(dr),1,filepointer)==1)
                {
                    if(strcmp(dr.time,time)!=0)
                        fwrite(&dr,sizeof(dr),1,filepointertodelete);
                }
                fclose(filepointer);
                fclose(filepointertodelete);
                remove(filename);
                rename("temp",filename);
                printf("\n\tDELETED SUCCESSFULLY");
                break;
            default:
                printf("\n\tYOU ENTERED WRONG CHOICE");
                break;
            }
            Encrypt();
        }
        while(selection<1||selection>2);
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD?(Y/N):");
        fflush(stdin);
        scanf("%c",&AnotherRecord);
    }
    printf("\n\n\tPRESS ANY KEY TO EXIT");
    getch();
}
char Encrypt()
{
    char ch;
    FILE *fps, *fpt;
    fps = fopen(filename, "rb");
    if(fps == NULL)
    {
        return 0;
    }
    fpt = fopen("SecurityTemporary.txt", "wb");
    if(fpt == NULL)
    {
        return 0;
    }
    ch = fgetc(fps);
    while(ch != EOF)
    {
        ch = ch+100;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(filename, "wb");
    if(fps == NULL)
    {
        return 0;
    }
    fpt = fopen("SecurityTemporary.txt", "rb");
    if(fpt == NULL)
    {
        return 0;
    }
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    remove("SecurityTemporary.txt");
    // getch();
    return 0;
}
char Decrypt()
{
    char ch;
    FILE *fps, *fpt;
    fps = fopen(filename, "rb");
    if(fps == NULL)
    {
        return 0;
    }
    fpt = fopen("SecurityTemporary.txt", "wb");
    if(fpt == NULL)
    {
        return 0;
    }
    ch = fgetc(fps);
    while(ch != EOF)
    {
        ch = ch-100;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fpt);
    fclose(fps);
    fps = fopen(filename, "wb");
    if(fps == NULL)
    {
        return 0;
    }
    fpt = fopen("SecurityTemporary.txt", "rb");
    if(fpt == NULL)
    {
        return 0;
    }
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    remove("SecurityTemporary.txt");
    // getch();
    return 0;
}