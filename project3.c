/******************************************
** File: project3.c
** Author: Rob Avery
** Date: 2/29/2012
** Section: 02
** Email: pw97976@gmail.com
**
**   This program will read in a text file that includes
** a bunch of commands and will process them accordingly.
** From the commands given, the program will store multiple
** polynomials and display the results.
**
** Other files:
**      1.polynomials.h -- includes prototypes of ofile.c
**      2.polynomials.c -- functions that help this program
**
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "polynomials.h"

#define TRUE 1
#define FALSE 0
#define TERMLEN 20
#define POLYLEN 8
#define CMDLEN 16

int main( int argc, char *argv[] ) {

   FILE* inFile;
   int i;
   POLY poly[POLYLEN];
   char tempCmd[CMDLEN];
   int tempIndex, tempVal1, tempVal2;

   // Error statements if they don't enter a command line argument
   // or if they enter too many
   if( argc < 2 ) {
      printf("Missing command line arguments.\n");
      exit( -1 );
   }
   if( argc > 2 ) {
      printf("Too many command line arguments.\n");
      exit( -2 );
   }

   //Opens file
   inFile = fopen( argv[1], "r" );

   //Error statement if the file doesn't exist
   if( inFile == NULL ) {
      printf("Permission denied or file does not exist.\n");
      exit( -3 );
   }

   //Error statement if the file is empty
   if( getc( inFile ) == EOF ) {
      printf("File is empty.\n");
      exit( -4 );
   }
   fclose( inFile );

   inFile = fopen( argv[1], "r" );

   //Makes all the polynomials empty
   for( i = 0; i < POLYLEN; i++ ) {
      poly[i] = emptyPoly( poly[i] );
   }

   while( fscanf( inFile, "%s", tempCmd ) != EOF ) {

 
     if( strcmp( tempCmd, "ADDTERM" ) == FALSE ) {
         //ADDTERM
         fscanf( inFile, "%d", &tempIndex );
         fscanf( inFile, "%d", &tempVal1 );
         fscanf( inFile, "%d", &tempVal2 );
         printf("\nCMD: %s, Poly: %d, Coeff: %d, Exp: %d\n", tempCmd, tempIndex, tempVal1, tempVal2 );
         printf("Proj%d: ", tempIndex);

         poly[tempIndex] = addTerm( poly[tempIndex], tempVal1, tempVal2 );
         displayPoly( poly[tempIndex] );

      } else if( strcmp( tempCmd, "ADD" ) == FALSE ) {
         //ADD command
         fscanf( inFile, "%d", &tempIndex );
         fscanf( inFile, "%d", &tempVal1 );
         fscanf( inFile, "%d", &tempVal2 );
         printf("\nCMD: %s, Sum: %d, Op1: %d, Op2: %d\n", tempCmd, tempIndex, tempVal1, tempVal2 );
         printf("Proj%d: ", tempIndex);

         poly[tempIndex] = add( poly[tempVal1], poly[tempVal2] );
         displayPoly( poly[tempIndex] );

      } else if( strcmp( tempCmd, "MULTIPLY" ) == FALSE ) {
         //MULTIPLY command
         fscanf( inFile, "%d", &tempIndex );
         fscanf( inFile, "%d", &tempVal1 );
         printf("\nCMD: %s, Poly: %d, Multiplier: %d\n", tempCmd, tempIndex, tempVal1 );
         printf("Proj%d: ", tempIndex);

         poly[tempIndex] = multiply( poly[tempIndex], tempVal1 );
         displayPoly( poly[tempIndex] );

      } else if( strcmp( tempCmd, "SUBTRACT" ) == FALSE ) {
         //SUBTRACT command
         fscanf( inFile, "%d", &tempIndex );
         fscanf( inFile, "%d", &tempVal1 );
         fscanf( inFile, "%d", &tempVal2 );
         printf("\nCMD: %s, Diff: %d, Op1: %d, Op2: %d\n", tempCmd, tempIndex, tempVal1, tempVal2 );
         printf("Proj%d: ", tempIndex);

         poly[tempIndex] = subtract( poly[tempVal1], poly[tempVal2] );
         displayPoly( poly[tempIndex] );

      } else if( tempCmd[0] == '#' ) {
         //Skips comments
         while( fgetc( inFile ) != '\n' ) {
            /*Not a new line
             *Nothing to do
             *Keep looping until new line found
             */
         }
      } else {
         //ERROR statement if there isn't valid command
         printf("Command not recognized.\n");

         while( fgetc( inFile ) != '\n' ) {
            /*Not a new line
             *Nothing to do
             *Keep looping until new line found
             */
         }
      }
   }

   fclose( inFile );
   return 0;
}
