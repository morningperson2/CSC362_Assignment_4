#include <stdio.h>
#include "work.h"
#define ARR_SIZE 50

int main()
{
    FILE *inFile1;
    FILE *inFile2;
    FILE *outFile;
    struct PERSON *arr_emp = (struct PERSON *) calloc(ARR_SIZE, 
      sizeof(struct PERSON));

    structInit(arr_emp, ARR_SIZE);

    if(arr_emp != NULL)
    {
      inFile1 = fileOpenAndCheck("person.txt", "rb");
      inFile2 = fileOpenAndCheck("dob.txt", "rb");
      outFile = fileOpenAndCheck("output.txt", "wb");

      fillArr(inFile1, inFile2, arr_emp);
      sort(arr_emp, ARR_SIZE);
      output(arr_emp, outFile);
      freeMem(arr_emp);
      fclose(inFile1);
      fclose(inFile2);
      fclose(outFile);
    }
    else
    {
      printf("Failed to allocate memory!\n");
      printf("Quitting now...\n");
    }

    

    return 0;
}
