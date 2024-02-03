#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <math.h>

// File initialization
FILE *gInputFile;
void usage (char *);

// Get Input From File
const int kLineLength = 81;
bool getLine (char [kLineLength], FILE *);

// Correct Line 
char swapChar (char);
void correctLine (char [kLineLength]);

// Print Line To Terminal
void printLine (char [kLineLength]);

int main(int argc, char *argv[]) {
  /*-------------------------------FILE INITIALIZATION START-----------------------------*/
  if (argc != 2) usage (argv[0]);

  if (NULL == (gInputFile = fopen(argv[1], "r"))) {
    fprintf (stderr, "inputFile: %s: %s\n", argv[1], strerror(errno));
    exit (EXIT_FAILURE);
  }
  else {
    fprintf (stderr, "%s opened for reading.\n\n" , argv[1]);
  }
  /*-------------------------------FILE INITIALIZATION END--------------------------------*/
  /*--------------------------------MAIN PROGRAM START------------------------------------*/

  char line [kLineLength];
  while (getLine (line, gInputFile)) {
    correctLine (line);
    printLine (line);
  }

  

  /*--------------------------------MAIN PROGRAM END--------------------------------------*/
  /*--------------------------------FILE CLEANUP START------------------------------------*/
  fclose (gInputFile);
  /*--------------------------------FILE CLEANUP END--------------------------------------*/
  
  return 0;
}

// File Initialization
void usage (char *cmd) {
  fprintf (stderr, "usage: %s inputFileName\n", cmd);
  exit (EXIT_SUCCESS);
}

// Get Input From File
bool getLine (char line [kLineLength], FILE * fp) {
  if (NULL == fgets (line, kLineLength, fp)) {
    return false;
  }
  else {
    line [strcspn(line, "\n")] = '\0';
    return true;
  }
}


// Correct Line 
char swapChar (char c) {
  switch (c) {
    case 1:
      return '`';
      break;
    case 2:
      return '1';
      break;
    case 3:
      return '2';
      break;
    case 4:
      return '3';
      break;
    case 5:
      return '4';
      break;
    case 6:
      return '5';
      break;
    case 7:
      return '6';
      break;
    case 8:
      return '7';
      break;
    case 9:
      return '8';
      break;
    case 0:
      return '9';
      break;
    case '-':
      return '0';
      break;
    case '=':
      return '-';
      break;
    case 'Q':
      return '\t';
      break;
    case 'W':
      return 'Q';
      break;
    case 'E':
      return 'W';
      break;
    case 'R':
      return 'E';
      break;
    case 'T':
      return 'R';
      break;
    case 'Y':
      return 'T';
      break;
    case 'U':
      return 'Y';
      break;
    case 'I':
      return 'U';
      break;
    case 'O':
      return 'I';
      break;
    case 'P':
      return 'O';
      break;
    case '[':
      return 'P';
      break;
    case ']':
      return '[';
      break;
    case '\\':
      return ']';
      break;
    case 'S':
      return 'A';
      break;
    case 'D':
      return 'S';
      break;
    case 'F':
      return 'D';
      break;
    case 'G':
      return 'F';
      break;
    case 'H':
      return 'G';
      break;
    case 'J':
      return 'H';
      break;
    case 'K':
      return 'J';
      break;
    case 'L':
      return 'K';
      break;
    case ';':
      return 'L';
      break;
    case '\'':
      return ';';
      break;
    case 'X':
      return 'Z';
      break;
    case 'C':
      return 'X';
      break;
    case 'V':
      return 'C';
      break;
    case 'B':
      return 'V';
      break;
    case 'N':
      return 'B';
      break;
    case 'M':
      return 'N';
      break;
    case ',':
      return 'M';
      break;
    case '.': 
      return ',';
      break;
    case '/':
      return '.';
      break;
    case ' ':
      return ' ';
      break;
    default:
      printf ("Error: swapChar(%c)\n", c);
      return '#';
      break;
  }
}
void correctLine (char line [kLineLength]) {
  for (int i = 0; i < strlen(line); i++) {
    line[i] = swapChar(line[i]);
  }
}

// Print Line To Terminal
void printLine (char line [kLineLength]) {
  printf ("%s\n", line);
}