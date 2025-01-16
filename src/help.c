#include <stdio.h>

void display_help(){
  printf("Autor: João Gustavo 'Ch4k4l' Bispo");
  printf("Cada um usa do modo que achar melhor");
  printf("Uso: ./seccheck [opções]\n\n");
  printf("Opções:\n");
  printf("  -h, --help      Mostra esta página de ajuda.\n");
  printf("  -f, --file      Mostra os arquivos com permissões erradas.\n");
  printf("  -p, --port      Mostra se tem portas abertas no localhost.\n");
  printf("  -e, --env       Mostra se tem variáveis de ambiente sensiveis.\n");
}
