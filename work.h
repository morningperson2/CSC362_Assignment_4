/******************************************************************************/
/*!
\file   work.h
\author Paul Huffman
\par    email: huffmanp4\@nku.edu
\par    Course: CSC362
\par    Section: 002
\par    Assignment: 4
\date   11/30/2021
\brief  
    This file contains the declaration of several functions for the 4th 
    assignment.

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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  /****************************************************************************/
  /*!
    \struct DATE

    \brief This Structure contains three data fields, month, day, year.
  */
  /****************************************************************************/
struct DATE
{
    int month; /*!< The month of the date. */
    int day;   /*!< The day of the date.   */
    int year;  /*!< The year of the date.  */
};

  /****************************************************************************/
  /*!
    \struct PERSON

    \brief This Structure contains siz data fields, last_name, date_of_birth,
      ssn, street_address, city, and age.
  */
  /****************************************************************************/
struct PERSON
{
    char last_name[20];        /*!< The last name of the person.         */
    struct DATE date_of_birth; /*!< The person's date of birth.          */
    int ssn;                   /*!< The person's social security number. */
    char street_address[30];   /*!< The person's street address.         */
    char city[20];             /*!< The city the person lives in.        */
    int age;                   /*!< The age of the person.               */
};

FILE* fileOpenAndCheck(char *filename, char *openMode);

void fillArr(FILE *infile1, FILE *infile2, struct PERSON *arr_emp);

void sort(struct PERSON *arr_emp, int arr_size);

void output(struct PERSON *arr_emp, FILE *outFile);

void freeMem(struct PERSON *arr_emp);

void structInit(struct PERSON *arr_emp, int num);

int checkNotNull(struct PERSON emp);