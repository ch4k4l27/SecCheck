#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

void check_permissions_linux(){
  printf("\n[*] Verificando permissões inseguras...\n");

  const char *critical_files[] = {"/etc/passwd", "/etc/shadow", "/etc/hosts"};
  const char *expected_perm[] = {"664", "600", "644"};

  for (int i = 0; i < 3; i++) {
    struct stat file_stat;
    if(stat(critical_files[i], &file_stat) == 0){
      char perms[4];
      snprintf(perms,  sizeof(perms), "%o", file_stat.st_mode & 0777);
  
      if (strcmp(perms, expected_perm[i]) != 0) {
        printf("Permissões inseguras em %s: %s (esperado: %s)\n", critical_files[i], perms, expected_perm[i]);
      } else{
        printf("Permissões seguras em %s: %s\n", critical_files[i], perms);
      }
    } else{
      printf("Não foi possível verificar %s: %s\n", critical_files[i], strerror(errno));
    }
  }
}
