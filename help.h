#include <stdio.h>

void display_help(){
  printf("SecCheck - Verificador de Segurança Local");
  printf("Uso: ./seccheck [opções]\n\n");
  printf("Opções:\n");
  printf("  --help          Mostra esta página de ajuda.\n");
  printf("\nFuncionalidades:\n");
  printf("  - Verificação de permissões inseguras em arquivos críticos.\n");
  printf("  - Escaneamento de portas abertas no localhost.\n");
  printf("  - Verificação de variáveis de ambiente sensíveis.\n\n");
}
