/******************************************************************************/
/*!
\file   work.c
\author Paul Huffman
\par    email: huffmanp4\@nku.edu
\par    Course: CSC362
\par    Section: 002
\par    Assignment: 4
\date   11/30/2021
\brief  
    This file contains the implementation of several functions for the 
    4th assignment.
    
    +fileOpenAndCheck
    +fillArr
    +sort
    +output
    +freeMem
    +structInit
    +checkNotNull
    
    Hours spent on this assignment: 6
    
    Specific portions that gave you the most trouble: fillArr
*/
/******************************************************************************/
#include "work.h"

  /*! This is the max line length for a fgets call. */
#define MAX_LINE_LENGTH 80 

  /****************************************************************************/
  /*!
    \brief This function will open a file, check if it is opened, and will 
      return a pointer to the file.
    
    \param filename
      This is a pointer to the string that contains name of the file that 
      will be opened.

    \param openMode
      This is a pointer to the string that contains the mode in which the file 
      will be opened.
    
    \return
      This is a pointer to the file that has been opened.
  */
  /****************************************************************************/
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

  /****************************************************************************/
  /*!
    \brief This function will take in the two file pointers, then will fill the
      array of structs with their data.
    
    \param infile1
      This is a pointer to the file that contains the name, address, ssn, and 
      age of the people.

    \param infile2
      This is a pointer to the file that contains the date of birth of the 
      people.

    \param arr_emp
      This is a pointer to an array of structs of type PERSON.
  */
  /****************************************************************************/
void fillArr(FILE *infile1, FILE *infile2, struct PERSON *arr_emp)
{   
    /* This creates 2 strings used to hold data from the inFiles. */
  char dString[MAX_LINE_LENGTH] = {0};
  char eString[MAX_LINE_LENGTH] = {0};
  int i = 0; /* A counting integer. */

    /* Loops while not at the end of the file. */
  while(!feof(infile2))
  {
      /* Copies a string from the files to the strings created earlier. */
    fgets(eString, MAX_LINE_LENGTH, infile1);
    fgets(dString, MAX_LINE_LENGTH, infile2);

      /* Sets the data from infile2 to the proper data fields.          */
    arr_emp[i].date_of_birth.month = atoi(strtok(dString, ","));
    arr_emp[i].date_of_birth.day = atoi(strtok(NULL, ","));
    arr_emp[i].date_of_birth.year = atoi(strtok(NULL, ","));

      /* Sets the data from infile1 to the proper data fields.          */
    strcpy(arr_emp[i].last_name, strtok(eString, ","));
    arr_emp[i].ssn = atoi(strtok(NULL, ","));
    strcpy(arr_emp[i].street_address, strtok(NULL, ","));
    strcpy(arr_emp[i].city, strtok(NULL, ","));
    arr_emp[i].age = atoi(strtok(NULL, ","));

    i++; /* Increments i. */
  }
}

  /****************************************************************************/
  /*!
    \brief This function implements an inseertion sort for the array of structs
      based on alphabetical order of the datafield last_name.
    
    \param arr_emp
      This is a pointer to the array of structs that will be sorted.

    \param arr_size
      This is an int that contains the number of elements in the array.
  */
  /****************************************************************************/
void sort(struct PERSON *arr_emp, int arr_size)
{
  int i = 0;          /* This int is used to iterate through the array.     */
  struct PERSON temp; /* This PERSON is used to temporarily hold a PERSON.  */
  int location = 0;   /* This int is used to track a location in the array. */
  
    /* This will loop while i is less than arr_size. */
  for(i = 1; i < arr_size; i++)
  {
    temp = arr_emp[i]; /* Sets temp to the data of the current element.    */
    
      /* This checks that temp is not null.                                */
    if(!checkNotNull(temp))
      continue;
    
    location = i-1;      /* Sets location to i-1.                          */

      /* This will loop while location is greater than or equal to 0, and 
        that the value at the array element at location is greater than the 
        value of temp. */
    while(location >= 0 && strcmp(arr_emp[location].last_name, temp.last_name)
           > 0)
    {
        /* This will set the value of the element at location plus 1 to 
          the value of the element at location. */
      arr_emp[location + 1] = arr_emp[location];
      location--; /* This decrements the location. */
    }
      /* This will set the value of the element at location plus 1 to the 
        value of temp. */
    arr_emp[location + 1] = temp;
  }

}

  /****************************************************************************/
  /*!
    \brief This function will output an array of structs to the output file.
    
    \param arr_emp
      This is a pointer to the array that will be outputted.

    \param outFile
      This is a pointer to the file that wil be output to.
  */
  /****************************************************************************/
void output(struct PERSON *arr_emp, FILE *outFile)
{
  int i = 0; /* creates an int for iterating through the array. */

    /* Loops while arr_emp[i] is not null. */
  while(checkNotNull(arr_emp[i]))
  {
      /* Prints all of the necissary information to the outFile. */
    fprintf(outFile, "%-15s%-9d%-28s", arr_emp[i].last_name, arr_emp[i].ssn, 
     arr_emp[i].street_address);
    fprintf(outFile, "%-15s%-7d\n", arr_emp[i].city,arr_emp[i].age);
    fprintf(outFile, "Date of Birth: %d/%d/%d\n\n", 
     arr_emp[i].date_of_birth.month, arr_emp[i].date_of_birth.day,
     arr_emp[i].date_of_birth.year);
    i++; /* Increments i. */
  }
  
}

  /****************************************************************************/
  /*!
    \brief This function will free the memory that had been previously 
      allocated.
    
    \param arr_emp
      This is a pointer to the array that will be freed.
  */
  /****************************************************************************/
void freeMem(struct PERSON *arr_emp)
{
    /* Frees arr_emp, then sets it to null for safty. */
  free(arr_emp);
  arr_emp = NULL;
}

  /****************************************************************************/
  /*!
    \brief This function will initialize all data within the array of structs 
      to either ' ' or 0.
    
    \param arr_emp
      This is a pointer to the array that will be initialized.

    \param num
      This is an int containing the number of elements in the array.
  */
  /****************************************************************************/
void structInit(struct PERSON *arr_emp, int num)
{
  int i = 0; /* Initiaalizes i to 0.   */

    /* Loops while i is less than num. */
  for(i  = 0; i < num; i++)
  {
      /* Initializes all data in the struct. */
    arr_emp[i].last_name[0] = ' ';
    arr_emp[i].date_of_birth.month = 0;
    arr_emp[i].date_of_birth.day = 0;
    arr_emp[i].date_of_birth.year = 0;
    arr_emp[i].ssn = 0;
    arr_emp[i].street_address[0] = ' ';
    arr_emp[i].city[0] = ' ';
    arr_emp[i].age = 0;
  }
}

  /****************************************************************************/
  /*!
    \brief This function will check all data points in a PERSON to see if it is
      empty or not.
    
    \param emp
      This is a person that will be checked to see if it is empty.

    \return
      This function will return 1 if the PERSON is not empty, and 0 otherwise.
  */
  /****************************************************************************/
int checkNotNull(struct PERSON emp)
{
    /* Checks if all of the data in the struct is not set to initial values. */
  if(emp.last_name[0] != ' ')
  {
    if(emp.date_of_birth.month != 0)
    {
      if(emp.date_of_birth.day != 0)
      {
        if(emp.date_of_birth.year != 0)
        {
          if(emp.ssn != 0)
          {
            if(emp.street_address[0] != ' ')
            {
              if(emp.city[0] != ' ')
              {
                if(emp.age != 0)
                {
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
