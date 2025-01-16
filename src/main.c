#include <stdio.h>
#include <stdlib.h>

#include "help.h"
#include "permissions.h"
#include "ports.h"
#include "environment.h"

#define PAUSE getchar();

// Função para imprimir "SecCheck" com caracteres
void print_sec_check_logo() {
  printf("\n");
  printf(" SSSSS  EEEEE  CCCCC  CCCCC  H   H  EEEEE  CCCCC  K   K \n");
  printf("S       E      C      C      H   H  E      C      K  K  \n");
  printf(" SSS    EEEE   C      C      HHHHH  EEEE   C      KKK   \n");
  printf("    S   E      C      C      H   H  E      C      K  K  \n");
  printf("SSSS    EEEEE  CCCCC  CCCCC  H   H  EEEEE  CCCCC  K   K \n");
  printf("\n");
  printf("Use com conciência\n\n");
}

void display_menu(){
  printf("1 - Verificar permissões dos arquivos\n");
  printf("2 - Verificar portas locais abertas\n");
  printf("3 - Verificar variáveis de ambiente\n");
  printf("0 - Sair\n");
}
void menu() {
  int opcao;

  do {
    print_sec_check_logo();
    printf("\nSecCheck - Verificador de Segurança Local\n");
    printf("Escolha uma opção:\n");
    display_menu();
    printf("> ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        check_permissions_linux();
        break;
      case 2:
        scan_open_ports();
        break;
      case 3:
        check_environment_linux();
        break;
      case 0:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida. Digite um número entre 0 e 3.\n");
    }
    PAUSE;
  } while (opcao != 0);
}

int main() {
  print_sec_check_logo();
  printf("SecCheck - Verificador de Segurança Local\n");
  menu();
  return 0;
}

