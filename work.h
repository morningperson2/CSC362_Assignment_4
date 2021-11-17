#include <stdio.h>

struct DATE
{
    int month;
    int day;
    int year;
};

struct PERSON
{
    char* last_name;
    DATE* date_of_birth;
    int ssn;
    char* street_address;
    char* city;
    int age;
};

void free();

void sort();

void output();

void freeMem();