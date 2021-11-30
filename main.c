/******************************************************************************/
/*!
\file   main.c
\author Paul Huffman
\par    email: huffmanp4\@nku.edu
\par    Course: CSC362
\par    Section: 002
\par    Assignment: 4
\date   11/30/2021
\brief  
    This file contains the main function for the 4th assignment.
    
    +main
    
    Hours spent on this assignment: 6
    
    Specific portions that gave you the most trouble: fillArr
*/
/******************************************************************************/
#include "work.h"

#define ARR_SIZE 20 /*!< This is the number of elements in an array */

  /****************************************************************************/
  /*!
    \brief This is the main function for the program, it will allocate memory 
      for an array, open three files, will call all the proper functions, and 
      will close the files that were opened. 

    \return
      This function will return 0.
  */
  /****************************************************************************/
int main()
{
    /* Creates 3 pointers to files that will be used in the program. */
  FILE *inFile1;
  FILE *inFile2;
  FILE *outFile;
    /* Allocates memory for an array of PERSON. */
  struct PERSON *arr_emp = (struct PERSON *) calloc(ARR_SIZE, 
    sizeof(struct PERSON));

    /* Checks if the memory was properly allocated. */
  if(arr_emp != NULL)
  {
      /* Initializes all data within the array. */
    structInit(arr_emp, ARR_SIZE);

      /* Opens all the files, and points the pointers to them. */
    inFile1 = fileOpenAndCheck("person.txt", "rb");
    inFile2 = fileOpenAndCheck("dob.txt", "rb");
    outFile = fileOpenAndCheck("output.txt", "wb");

      /* Fills the array, then sorts the array, then putputs the array, and 
         finally frees the memory of the array.                             */
    fillArr(inFile1, inFile2, arr_emp);
    sort(arr_emp, ARR_SIZE);
    output(arr_emp, outFile);
    freeMem(arr_emp);

      /* Closes the file pointers. */
    fclose(inFile1);
    fclose(inFile2);
    fclose(outFile);
  }
    /* This only happens if the memory is not able to be allocated. */
  else
  {
    printf("Failed to allocate memory!\n");
    printf("Quitting now...\n");
  }
  
  return 0;
}
