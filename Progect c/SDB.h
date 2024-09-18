#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"
bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry (uint32);
bool SDB_ReadEntry (uint32 id);
void SDB_GetList (uint8 *, uint32 *);
bool SDB_IsIdExist (uint32 id);
void SDB_action (uint8);
void SDB_APP ();

typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;

} student;
#endif // SDB_H_INCLUDED
