#include <string.h>
#include <stdio.h>

#include "help.h"
#include "permissions.h"

int main(int argc, char *argv[]){
  if (argc >1 && strcmp(argv[1], "--help") == 0) {
    display_help();
    return 0;
  }

  printf("SecCheck - Verificador de Segurança Local\n");

  if (argc >1 && strcmp(argv[1], "--help") == 0) {
    display_help();
    return 0;
  } 
  else if(argc > 1 && strcmp(argv[1], "-f") == 0){
    check_permissions_linux();
    return 0;
  }else{
    display_help();
  }
  return 0;
}
