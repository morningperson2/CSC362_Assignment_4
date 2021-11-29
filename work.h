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
    char last_name[50];
    struct DATE date_of_birth;
    int ssn;
    char street_address[50];
    char city[50];
    int age;
};

FILE* fileOpenAndCheck(char *filename, char *openMode);

void fillArr(FILE *infile1, FILE *infile2, struct PERSON *arr_emp);

void sort(struct PERSON *arr_emp, int arr_size);

void output(struct PERSON *arr_emp, FILE *outFile);

void freeMem(struct PERSON *arr_emp);

void structInit(struct PERSON *arr_emp, int num);

int checkNotNull(struct PERSON emp);