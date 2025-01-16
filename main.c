#include <string.h>
#include <stdio.h>
#include "help.h"

int main(int argc, char *argv[]){
  if (argc >1 && strcmp(argv[1], "--help") == 0) {
    display_help();
    return 0;
  }

  printf("SecCheck - Verificador de Segurança Local\n");
  return 0;
}
