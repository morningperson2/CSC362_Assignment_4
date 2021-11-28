#include <stdio.h>
#include "work.h"

int main()
{
    FILE *inFile1;
    FILE *inFile2;
    /*FILE *outFile;*/
    struct PERSON *arr_emp = (struct PERSON *) malloc(50 * sizeof(struct PERSON));

    if(arr_emp != NULL)
    {
      inFile1 = fileOpenAndCheck("person.txt", "rb");
      inFile2 = fileOpenAndCheck("dob.txt", "rb");
      /*outFile = fileOpenAndCheck("output.txt", "wb");*/

      fillArr(inFile1, inFile2, arr_emp);
    }

    

    return 0;
}
