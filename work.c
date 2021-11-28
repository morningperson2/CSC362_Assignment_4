#include "work.h"

#define MAX_LINE_LENGTH 80

FILE* fileOpenAndCheck(char *filename, char *openMode)
{
  FILE *temp; /* This is a temporary pointer to a file. */

    /* This opens a file and points it to temp. */
  temp = fopen(filename, openMode);
   
    /* This checks to make sure that temp is not NULL, and if it is, then **
    ** it will print an error.                                            */
  if(temp == NULL)
  {
    perror("Cant open file");
  }

  return temp;
}

void fillArr(FILE *infile1, FILE *infile2, struct PERSON *arr_emp)
{   
    char dString[MAX_LINE_LENGTH] = {0};
    char eString[MAX_LINE_LENGTH] = {0};
    int i = 0;
    while(!feof(infile1) || !feof(infile2))
    {
      fgets(eString, MAX_LINE_LENGTH, infile1);
      fgets(dString, MAX_LINE_LENGTH, infile2);
      arr_emp[i].date_of_birth.month = atoi(strtok(dString, ","));
      arr_emp[i].date_of_birth.day = atoi(strtok(NULL, ","));
      arr_emp[i].date_of_birth.year = atoi(strtok(NULL, ","));

      arr_emp[i].last_name = strtok(eString, ",");
      arr_emp[i].ssn = atoi(strtok(NULL, ","));
      arr_emp[i].street_address = strtok(NULL, ",");
      arr_emp[i].city = strtok(NULL, ",");
      arr_emp[i].age = atoi(strtok(NULL, ","));
      i++;
    }
}

void sort()
{

}

void output()
{

}

void freeMem()
{

}