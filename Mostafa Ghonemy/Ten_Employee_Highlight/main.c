#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"
#include "textattr.h"
#include <string.h>

/** @file main.c
 *  @brief An initial main.c
 *
 *  This file contains the
 *  main() function.
 *
 *
 *  @author Mostafa Ghonemy
 *  @bug No known bugs.
 */


//defines
#define null -32
#define esc 27
#define tab 9
#define up 72
#define down 80
#define home 71
#define end 79
#define enter 13


struct Employee
{
    int id;
    int age;
    int salary;
    int commission;
    char name[20];
    int deduction;

};


int main()
{
    struct Employee p[10];
    int check[10]= {0};
    char ch;
    int cursor=0;
    char name[20];
    char menu [8][20]= {"New",
                        "Display All",
                        "Display By Id",
                        "Display By Name",
                        "Delete All",
                        "Delete By Name",
                        "Delete By ID",
                        "Exit"
                       };

    int flag=0;
    int index;


    do
    {
        system("cls");
        for (int i=0; i<8; i++)
        {
            if(i == cursor) textattr(3);
            else textattr(7);
            gotoxy(15,5+i*2);
            _cprintf("%s",menu[i]);
        }
        ch = getch();
        switch(ch)
        {
        case null:
            ch = getch();
            switch(ch)
            {
            case up:
                cursor--;
                if (cursor<0) cursor=3;
                break;
            case down:
                cursor++;
                if (cursor>7) cursor=0;
                break;
            case home:
                cursor = 0;
                break;
            case end:
                cursor = 7;
                break;
            }
            break;
        case tab:
            cursor++;
            if (cursor>7) cursor=0;
            break;
        case enter:
            switch(cursor)
            {
            case 0:
                system("cls");
                dataEntry();


                _flushall();

                //get id
                gotoxy(15,10);
                scanf("%i",&index);

                p[index].id=index;
                while(p[index].id<1 || p[index].id>10)
                {
                    gotoxy(10,11);
                    textattr(4);
                    printf("wrong id limit [1~10]");
                    gotoxy(15,10);
                    printf("               ");
                    gotoxy(15,10);
                    textattr(7);
                    scanf("%i",&index);
                    p[index].id=index;
                }


                while(check[index]==1)
                {
                    gotoxy(10,11);
                    textattr(4);
                    printf("id is used  please try another");
                    gotoxy(15,10);
                    printf("                              ");
                    gotoxy(15,10);
                    textattr(7);
                    scanf("%i",&index);
                    p[index].id=index;
                }
                gotoxy(10,11);
                textattr(10);
                printf("id is free               ");
                textattr(7);

                _flushall();

                //get name
                gotoxy(47,10);
                gets(p[index].name);

                _flushall();


                //get age
                gotoxy(16,15);
                scanf("%i",&p[index].age);
                while(p[index].age<18 || p[index].age>60)
                {
                    gotoxy(10,16);
                    textattr(4);
                    printf("wrong age limit [18~60]");
                    gotoxy(16,15);
                    printf("          ");
                    gotoxy(16,15);
                    textattr(7);
                    scanf("%i",&p[index].age);
                }
                gotoxy(10,16);
                printf("                       ");


                _flushall();

                //get salary
                gotoxy(49,15);
                scanf("%i",&p[index].salary);

                _flushall();

                //get commission
                gotoxy(23,20);
                scanf("%i",&p[index].commission);

                //get deduction
                gotoxy(52,20);
                scanf("%i",&p[index].deduction);
                _flushall();

                check[index]=1;

                getch();
                break;
            case 1:
                system("cls");
                for (int i =0;i<10;i++)
                {
                    if (check[i]==1)
                    {
                        printSalary(p[i],i);
                    }
                }
                getch();
                break;
            case 2:
                system("cls");
                printf("Enter id : ");
                scanf("%i",&index);
                printSalary(p[index],index);
                getch();
                break;
            case 3:
                system("cls");
                printf("Enter Name : ");
                gets(name);
                for (int i =0;i<10;i++)
                {
                    if (!strcmp(p[i].name,name)&&check[i]==1)
                    {
                        printSalary(p[i],i);
                    }
                }
                getch();
                break;
            case 4:
                for (int i=0;i<10;i++)
                {
                    check[i]=0;
                }
                system("cls");
                printf("Deleting is done!!");
                getch();
                break;
            case 5:
                system("cls");
                printf("Enter Name to Delete : ");
                gets(name);
                for (int i =0;i<10;i++)
                {
                    if (!strcmp(p[i].name,name)&&check[i]==1)
                    {
                        check[i]=0;
                    }
                }
                getch();
                break;
            case 6:
                system("cls");
                printf("Enter id to delete: ");
                scanf("%i",&index);
                check[index]=0;
                getch();
                break;
            case 7:
                flag = 1;
                break;
            }
            break;
        case esc:
            flag=1;



        }
    }
    while(flag == 0);
    textattr(7);

    printf("\n\n        ======================\n           Thanks for using\n        ======================\n\n");







    return 0;
}





void dataEntry()
{
    gotoxy(20,5);
    printf("DATA ENTRY SCREEN\n======================================================");
    gotoxy(10,10);
    printf("id : ");
    gotoxy(40,10);
    printf("Name : ");
    gotoxy(10,15);
    printf("Age : ");
    gotoxy(40,15);
    printf("Salary : ");
    gotoxy(10,20);
    printf("Commission : ");
    gotoxy(40,20);
    printf("Deduction : ");

}

void printSalary(struct Employee p,int i)
{

    int NetSalary = p.salary+p.commission-p.deduction;

    printf("Employee %i Salary\n======================================================\n       Name: %s            NetSalary: %i\n======================================================\n",i,p.name,NetSalary);
}

