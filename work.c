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
    while(!feof(infile2))
    {
      fgets(eString, MAX_LINE_LENGTH, infile1);
      fgets(dString, MAX_LINE_LENGTH, infile2);
      arr_emp[i].date_of_birth.month = atoi(strtok(dString, ","));
      arr_emp[i].date_of_birth.day = atoi(strtok(NULL, ","));
      arr_emp[i].date_of_birth.year = atoi(strtok(NULL, ","));

      strcpy(arr_emp[i].last_name, strtok(eString, ","));
      arr_emp[i].ssn = atoi(strtok(NULL, ","));
      strcpy(arr_emp[i].street_address, strtok(NULL, ","));
      strcpy(arr_emp[i].city, strtok(NULL, ","));
      arr_emp[i].age = atoi(strtok(NULL, ","));
      i++;
    }
}

void sort(struct PERSON *arr_emp, int arr_size)
{
  int i = 0;          /* This int is used to iterate through the array.     */
  struct PERSON temp; /* This int is used to temporarily hold a value.      */
  int location = 0;   /* This int is used to track a location in the array. */
  
    /* This will loop while i is less than n. */
  for(i = 1; i < arr_size; i++)
  {
    temp = arr_emp[i]; /* Sets temp to the value of the current pointer. */
    if(temp.ssn == NULL)
      continue;
    location = i-1;      /* Sets location to i-1.                          */

      /* This will loop while location is greater than or equal to 0, and 
        that the value at the array pointer at location is greater than the 
        value of temp. */
    while(location >= 0 && strcmp(arr_emp[location].last_name, temp.last_name) > 0)
    {
        /* This will set the value of the pointer at location plus 1 to 
          the value of the pointer at location. */
      arr_emp[location + 1] = arr_emp[location];
      location--; /* This decrements the location. */
    }
      /* This will set the value of the pointer at location plus 1 to the 
        value of temp. */
    arr_emp[location + 1] = temp;
  }

}

void output(struct PERSON *arr_emp)
{
  int i = 0;
  while(arr_emp[i].ssn != NULL)
  {
    printf("%s, %d/%d/%d, %d, %s, %s, %d\n", arr_emp[i].last_name, arr_emp[i].date_of_birth.month, arr_emp[i].date_of_birth.day, arr_emp[i].date_of_birth.year, arr_emp[i].ssn, arr_emp[i].street_address, arr_emp[i].city, arr_emp[i].age);
    i++;
  }
  
}

void freeMem(struct PERSON *arr_emp)
{
  free(arr_emp);
}