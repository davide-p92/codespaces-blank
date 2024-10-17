#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define BUFSZ(arr) (sizeof(arr) / sizeof(arr[0]))
#define LIM 16384

int main(int argc, char **argv) {

  if(argc != 3) {
    printf("uso: %s <infile> <outfile>\n", argv[0]);
    return 0;
  }
  int max_line;
  if(LINE_MAX >= LIM) {
    max_line = LIM;
  } else {
    max_line = LINE_MAX;
  }
  char infile[20], outfile[20];
  char *line;
  line = (char *)malloc(LINE_MAX + 1);
  if(line == NULL) {
    printf("errore malloc per line\n");
    return -1;
  }
  strcpy(infile, argv[1]);
  strcpy(outfile, argv[2]);
  unsigned char buf[1024];
  FILE *fin, *fout;
  if((fin = fopen(infile, "r")) == NULL) {
    printf("errore fopen: %s\n", strerror(errno));
    return -1;
  }
  //leggi da file
  /*if(fread(buf, sizeof(*buf), BUFSZ(buf), fin) < 0) {
    printf("errore fread: %s\n", strerror(errno));
    return -1;
  }*/
  if((fout = fopen(outfile, "w")) == NULL) {
    printf("errore fwrite: %s\n", strerror(errno));
    return -1;
  }
  //leggi a fine file o EOF
  while(fgets(line, max_line + 1, fin) != NULL) { 
    //scrivi contenuto di buf su fout
    if(fputs(line, fout) == EOF) {
      printf("errore fputs: %s\n", outfile);
      return -1;
    }
    //libera memoria alloc
    free(line);
  }

  


  //chiude file
  if(fclose(fin) < 0) {
    printf("errore fclose su fin: %s\n", strerror(errno));
    return -1;
  }
  if(fclose(fout) < 0) {
    printf("errore fclose su fout: %s\n", strerror(errno));
  }
  
}