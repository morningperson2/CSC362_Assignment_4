#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATE
{
    int month;
    int day;
    int year;
};

struct PERSON
{
    char* last_name;
    struct DATE date_of_birth;
    int ssn;
    char* street_address;
    char* city;
    int age;
};

FILE* fileOpenAndCheck(char *filename, char *openMode);

void fillArr(FILE *infile1, FILE *infile2, struct PERSON *arr_emp);

void sort();

void output();

void freeMem();