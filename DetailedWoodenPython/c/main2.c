#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv) {
  int opt;
  char name[256];
  char surname[256];
  bool toup = false;
  bool tolow = false;
  while((opt = getopt(argc, argv, "n:s:ul")) != -1) {
    switch(opt) {
      case 'n': {
        strcpy(name, optarg);
      }
      case 's': {
        strcpy(surname, optarg);
      }
      case 'u': {
        toup = true;
      }
      case 'l': {
        tolow = true;
      }
      default: {
        printf("Unknown option: %c\n", opt);
      }
    }
  }
  if(tolow == true) {
    for(int i = 0; i < strlen(name); i++) {
      name[i] = tolower(name[i]);
    }
    for(int i = 0; i < strlen(surname); i++) {
      surname[i] = tolower(surname[i]);
    }
  }
  
}