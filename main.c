#include <stdio.h>
#include "work.h"
#define ARR_SIZE 50

int main()
{
    FILE *inFile1;
    FILE *inFile2;
    /*FILE *outFile;*/
    struct PERSON *arr_emp = (struct PERSON *) calloc(ARR_SIZE, sizeof(struct PERSON));

    if(arr_emp != NULL)
    {
      inFile1 = fileOpenAndCheck("person.txt", "rb");
      inFile2 = fileOpenAndCheck("dob.txt", "rb");
      /*outFile = fileOpenAndCheck("output.txt", "wb");*/

      fillArr(inFile1, inFile2, arr_emp);
      output(arr_emp);
      sort(arr_emp, ARR_SIZE);
      printf("After Sort:\n");
      output(arr_emp);
      freeMem(arr_emp);
    }

    

    return 0;
}
