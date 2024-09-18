#include "STD.h"
#include <stdio.h>
#include <stdlib.h>

void SDB_action (uint8 choice)
{
    bool full;
    uint8 stuNum,add;
    if((uint32)choice == 1)
    {
        uint8 i;
        if(SDB_GetUsedSize() < 3)
        {
            printf("\033[1;31mThe Database is Empty, Please add 3 student one time!\033[0m\n");
            for(i=0; i<3; i++)
            {
                add = SDB_AddEntry();
                while(!add)
                {
                    printf("\033[1;31mError Input!\033[0m\n");
                    add = SDB_AddEntry();
                }
                if(add) printf("\033[1;32mAdding Done!\033[0m\n");
            }
        }
        else if(SDB_GetUsedSize() <10)
        {
            add = SDB_AddEntry();
            if(add) printf("\033[1;32mAdding Done!\033[0m\n");
            else printf("\033[1;31mError Input!\033[0m\n");
        }
        else
            printf("\033[1;31mThe Database is Full , No locations To Add new Students!\033[0m\n");
    }
    else if((uint32)choice == 2)
    {
        stuNum = SDB_GetUsedSize();
        printf("\033[1;32mThe Number of Students in Database is %d\033[0m\n",stuNum);
    }
    else if((uint32)choice == 3)
    {
        bool dataStatus;
        uint32 ID;
        printf("Enter ID of Student!\n");
        fflush(stdin);
        scanf("%d",&ID);
        dataStatus = SDB_ReadEntry(ID);
    }
    else if((uint32)choice == 4)
    {
        uint8 num = SDB_GetUsedSize(),i;
        uint32 Group[10];
        SDB_GetList(&num,Group);
        if(Group[0]!=0)
            for(i=0;i<num;i++)
                printf("\033[1;31mID %d : %d\033[0m\n",i,Group[i]);
    }
    else if((uint32)choice == 5)
    {
        uint32 idStatus,ID;
        printf("Enter ID of Student!\n");
        fflush(stdin);
        scanf("%d",&ID);
        idStatus = SDB_IsIdExist(ID);
        if(idStatus) printf("\033[1;32mFound!\033[0m\n");
        else printf("\033[1;31mNot Found!\033[0m\n");
    }
    else if((uint32)choice == 6)
    {
        uint32 ID;
        printf("Enter ID of Student!\n");
        fflush(stdin);
        scanf("%d",&ID);
        SDB_DeletEntry(ID);
    }
    else if((uint32)choice == 7)
    {
        full = SDB_IsFull();
        if (full) printf("\033[1;31mThe Data Base is Full!\033[0m\n");
        else printf("\033[1;32mThe Data Base isn't Full!\033[0m\n");
    }
    else if ((uint32)choice!=0) printf("\033[1;31mNot Valid Choice!\nEnter a Valid Number!\033[0m\n");
}

void SDB_APP ()
{
    uint8 chossedNum;
    do
    {
        printf("0. exit\n");
        printf("1. add Student\n");
        printf("2. Number of Students in Database\n");
        printf("3. read student data\n");
        printf("4. get the list of all student IDs\n");
        printf("5. check is ID is existed\n");
        printf("6. delete student data\n");
        printf("7. check is database is full\n");
        printf("Enter Your Choice(from 0 To 7) : \n");
        fflush(stdin);
        if(scanf("%u",&chossedNum)== 1)
            SDB_action(chossedNum);
        else // To avoid Character Input
        {
            chossedNum = 8; // Out of range as Equivalent as character
            SDB_action(chossedNum);
        }
    }
    while((uint32)chossedNum != 0);
}
