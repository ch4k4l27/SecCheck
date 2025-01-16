#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "help.h"
#include "permissions.h"
#include "scan_open_ports.h"
#include "check_environment.h"

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

// Função para exibir o help
void handle_flags(int argc, char *argv[]) {
    // Se o usuário passar a flag de ajuda, exibe o help
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        display_help();
        return;
    }

    // Flags de verificação de permissões, portas e variáveis de ambiente
    int check_permissions_flag = 0;
    int scan_ports_flag = 0;
    int check_environment_flag = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
            check_permissions_flag = 1;
        }
        else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--port") == 0) {
            scan_ports_flag = 1;
        }
        else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--env") == 0) {
            check_environment_flag = 1;
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--hel´p") == 0) {
            display_help();
            return;
        }
    }

    // Chamando as funções de acordo com as flags
    if (check_permissions_flag) {
        check_permissions_linux();
    }
    if (scan_ports_flag) {
        scan_open_ports();
    }
    if (check_environment_flag) {
        check_environment();
    }
    if (!check_permissions_flag && !scan_ports_flag && !check_environment_flag) {
        printf("\n[!] Nenhuma opção válida fornecida. Tente --help para mais informações.\n");
    }
}

int main(int argc, char *argv[]) {
    // Imprime o logo do SecCheck
    print_sec_check_logo();

    printf("SecCheck - Verificador de Segurança Local\n");

    // Verifica as flags passadas para o programa
    handle_flags(argc, argv);

    return 0;
}

