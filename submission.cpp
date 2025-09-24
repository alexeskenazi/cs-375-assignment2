#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cassert>
#include <cmath>

using namespace std;

#define BUFSIZE 1000


long long findNumLines(FILE *fp);



FILE *srcFP, *destFP;
long long numLines, *data;

int main(int argc, char *argv[]) {

  int i;
  char str[BUFSIZE];

  // check command line args
  if(argc<3) {
    printf("Usage: progname <input_file> <output_file>");
    exit(0);
  }

  // run tests if "test" argument provided
  if(argc>3) {
    if(strcmp(argv[3], "test") == 0) {
      // testSortABCarray();
      // testFindKeyAsDifference();
      exit(0);
    }
  }
  
  // open input and output files
  if((srcFP =fopen(argv[1], "r")) == NULL) {
    perror("Error opening input file");
    exit(0);
  }

  if((destFP = fopen(argv[2], "w")) == NULL) {
    perror("Error opening output file");
    exit(0);
  }
  
  // count lines in file
  numLines = findNumLines(srcFP);
  

  // find first real line (skip blanks and comments)
  for(i=0; i<numLines; i++) {
    fgets(str, BUFSIZE, srcFP);

    // skip blank lines and comments
    if((str[0] == '\n') || (str[0] == ' ') || ((str[0] == '/') && (str[1] == '/'))) {
      i--;
      continue;
    }

    break;
  }


  // Part B.1 - sort ABC strings
  fprintf(destFP, "//Part B.1 \n\n");
  printf("//Part B.1 \n\n");
  
  while(!feof(srcFP)) {

    // process the line we already read
    int len = strlen(str);
    if (len > 0) { 
      // sortABCarray(destFP, str, len);
    }
    
    fgets(str, BUFSIZE, srcFP);

    // skip blank lines
    if(( str[0] == '\n') || (str[0] == ' ') ) {
      str[0] = '\0';
      continue;
    }

    // stop when we hit Part B.2
    if(strncmp(str, "//Part B.2", 10) == 0) {
      break;
    }

  }

  // Part B.2 - read numbers into array
  data = (long long *) malloc(numLines * sizeof(long long));
  int dataIndex = 0;

  // read numbers from file
  for(i=0; i<numLines; i++) {

    for(int j=0; j<100; j++) {
      str[j] = '\0';
    }

    fgets(str, 100, srcFP);

    // skip blank lines and comments
    if((str[0] == '\n') || (str[0] == ' ') || ((str[0] == '/') && (str[1] == '/'))) {
      i--;
      continue;
    }

    // stop at end of file
    if(feof(srcFP)) {
      break;
    }

    // convert string to number and store
    sscanf(str, "%lld", &(data[dataIndex]));
    dataIndex++;
  }

  fprintf(destFP, "\n\n// Part B.2\n\n");
  printf("\n\n// Part B.2\n\n");

  // findKeyAsDifference(destFP, data, dataIndex);

  fclose(srcFP);
  fclose(destFP);
}


// count how many lines are in the file
long long findNumLines(FILE *fp) {

  long long numLines = 0;
  char str[100];

  // count each line
  while(!feof(fp)) {
    fgets(str, 100, fp);
    numLines++;
  }
  
  numLines--; // fix off-by-one from EOF
  
  // go back to start of file
  if(fseek(fp, 0L, SEEK_SET) == EOF) {
    perror("Error while seeking to begining of file");
    exit(0);
  }

  return numLines;
}   

