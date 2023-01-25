// CS380L: Advanced Operating Systems
// Jinheng LI (jinhengli@utexas.edu)
// Lab1

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]){
	FILE *pinput, *poutput;
	char *input;
	input = malloc(MAX_LINE);

	if(argc==1){
    pinput = stdin;
    poutput = stdout;
	} else if(argc==2){
		pinput = fopen(argv[1], "r");
		if(pinput == NULL){
			fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
      exit(1);
		}
    poutput = stdout;
	} else if(argc==3){
    //if(argv[1]==argv[2]){
    //  fprintf(stderr, "reverse: input and output file must differ\n");
    //  exit(1);
      //printf("true");
      printf("first:%d",argv[1]==argv[2]);
      printf("second:%s",argv[2]);
    //}
		pinput = fopen(argv[1], "r");
    if(pinput == NULL){
      fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
      exit(1);
    }
		poutput = fopen(argv[2], "w");
    if(poutput == NULL){
      fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
      exit(1);
    }
    if(pinput==poutput){
      fprintf(stderr, "reverse: input and output file must differ\n");
      exit(1);
    }
	} else{
		fprintf(stderr, "usage: reverse <input> <output>\n");
		exit(1);
	}
  // read lines of input file reversely, if number of lines not enough, we will need to realloc
  char **lines = malloc(sizeof(char*));
  int i = 0;
  while(fgets(input, MAX_LINE, pinput) != NULL){
    lines[i] = malloc(MAX_LINE);
    lines[i] = input;
    i++;
    lines = realloc(lines, (i+1)*sizeof(char*));
    input = malloc(MAX_LINE);
  }

  // print lines reversely into output file
  for(int k = i-1; k >= 0; k--){
    fprintf(poutput, "%s", lines[k]);
  }
  // close files
  fclose(pinput);
  fclose(poutput);
  return 0;
}
