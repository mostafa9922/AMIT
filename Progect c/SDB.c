#include "SDB.h"
#include <stdio.h>
student G1[10]; // Database

bool SDB_IsFull ()
{
    uint8 i,freeNum;
    for(i = 0; i < 10; i++)
    {
        if(G1[i].Student_ID != 0) freeNum++;
    }
    if((uint32)freeNum == 10) return true;
    else return false;
}

uint8 SDB_GetUsedSize()
{
    uint8 i,stuNum=0;
    for(i = 0; i < 10; i++)
    {
        if(G1[i].Student_ID != 0) stuNum++;
    }
    return stuNum;
}

bool SDB_IsIdExist (uint32 id)
{
    uint8 i;
    for(i=0; i<10; i++)
    {
        if(G1[i].Student_ID == id)
            return true;
    }
    return false;
}

bool SDB_AddEntry()
{
    uint8 i,copyI;
    uint32 ID_c;
    bool flag = SDB_IsFull();
    if(!flag)
    {
        for(i = 0; i < 10; i++)
        {
            if(G1[i].Student_ID == 0) // To Know Where Add new student
            {
                copyI = i;
                break;
            }
        }
        printf("Enter Student ID : \n");

        if(scanf("%d",&ID_c) != 1) // To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        if(SDB_IsIdExist(ID_c))
        {
            printf("\033[1;31mEntered ID Is Existed Before!\033[0m\n");
            return false;
        }
        else G1[i].Student_ID = ID_c;
        printf("Enter Student Year\n");
        if(scanf("%d",&G1[copyI].Student_year) !=1)// To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        printf("Enter Course1_ID : \n");
        if(scanf("%d",&G1[copyI].Course1_ID)!=1)// To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        printf("Enter Course1_Grade : \n");
        if(scanf("%d",&G1[copyI].Course1_grade)!=1)// To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        printf("Enter Course2_ID : \n");
        if(scanf("%d",&G1[copyI].Course2_ID)!=1)// To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        printf("Enter Course2_Grade : \n");
        if(scanf("%d",&G1[copyI].Course2_grade)!=1)// To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        printf("Enter Course3_ID : \n");
        if(scanf("%d",&G1[copyI].Course3_ID)!=1)// To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        printf("Enter Course3_Grade : \n");
        if(scanf("%d",&G1[copyI].Course3_grade)!=1)// To Avoid Character Input
        {
            fflush(stdin);
            return false;
        }
        return true;
    }
    else
    {
        printf("\033[1;31mDatabase Has Maximum Number of Students!\033[0m\n");
        return false;
    }
}

void SDB_DeletEntry (uint32 id)
{
    uint8 limit = SDB_GetUsedSize(),i;
    bool flag = SDB_IsIdExist(id);
    for(i=0; i<10; i++)
        if (G1[i].Student_ID == id) break;
    if(flag && limit > 3)
    {
        G1[i].Student_ID = 0;
        G1[i].Student_year = 0;
        G1[i].Course1_ID = 0;
        G1[i].Course1_grade = 0;
        G1[i].Course2_ID = 0;
        G1[i].Course2_grade = 0;
        G1[i].Course3_ID = 0;
        G1[i].Course3_grade = 0;
        printf("\033[1;32mDeleted Done!\033[0m\n");
    }
    else if (!flag) printf("\033[1;31mNot Found!\033[0m\n");
    else if(limit <=3) printf("\033[1;31mThere are only minimum number of students! Not Deleted\033[0m\n");
}

bool SDB_ReadEntry (uint32 id)
{
    uint8 i;
    bool flag=SDB_IsIdExist(id);
    for(i=0; i<10; i++)
        if (G1[i].Student_ID == id) break;
    if(flag)
    {
        printf("\033[1;32mStudent ID is : %d\n",G1[i].Student_ID);
        printf("Student Year is : %d\n",G1[i].Student_year);
        printf("Course1 ID is : %d\n",G1[i].Course1_ID);
        printf("Course1 Grade is : %d\n",G1[i].Course1_grade);
        printf("Course2 ID is : %d\n",G1[i].Course2_ID);
        printf("course2 Grade is : %d\n",G1[i].Course2_grade);
        printf("course3 ID is : %d\n",G1[i].Course3_ID);
        printf("course3 Grade is : %d\n\033[0m",G1[i].Course3_grade);
        return true;
    }
    else
    {
        printf("\033[1;31mNot Found!\033[0m\n");
        return false;
    }
}

void SDB_GetList (uint8 * count, uint32 * list)
{
    uint8 i;
    if(*count > 0)
    {
        for(i=0; i<*count; i++)
        {
            list[i] = G1[i].Student_ID;
        }
    }
    else printf("\033[1;31mDatabase is empty!\033[0m\n");
}
