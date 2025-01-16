#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#ifdef __linux__
// Função para converter a permissão numérica em string
void get_permissions_str(int perm, char *str) {
  str[0] = (perm & 0400) ? 'r' : '-';
  str[1] = (perm & 0200) ? 'w' : '-';
  str[2] = (perm & 0100) ? 'x' : '-';
  str[3] = (perm & 0040) ? 'r' : '-';
  str[4] = (perm & 0020) ? 'w' : '-';
  str[5] = (perm & 0010) ? 'x' : '-';
  str[6] = (perm & 0004) ? 'r' : '-';
  str[7] = (perm & 0002) ? 'w' : '-';
  str[8] = (perm & 0001) ? 'x' : '-';
  str[9] = '\0';
}

void check_permissions_linux() {
  printf("\n[*] Verificando permissões inseguras nos arquivos críticos...\n");

  // Lista de arquivos críticos e permissões esperadas
  const char *critical_files[] = {"/etc/passwd", "/etc/shadow", "/etc/hosts", "/etc/hostname", "/etc/sudoers"};
  const char *expected_perm[] = {"644", "600", "644", "644", "440"};

  int num_files = sizeof(critical_files) / sizeof(critical_files[0]);

  for (int i = 0; i < num_files; i++) {
    struct stat file_stat;

    if (stat(critical_files[i], &file_stat) == 0) {
      // Obtendo as permissões numéricas do arquivo
      int perms = file_stat.st_mode & 0777;

      // Obtendo as permissões em formato de string (ex: rwxr-xr-x)
      char perms_str[10];
      get_permissions_str(perms, perms_str);

      // Verificando as permissões contra as esperadas
      int expected = strtol(expected_perm[i], NULL, 8); // Convertendo as permissões esperadas para octal
      if (perms != expected) {
        printf("  [!] Permissões inseguras em %s: %s (esperado: %s)\n", critical_files[i], perms_str, expected_perm[i]);
      } else {
        printf("  [✓] Permissões seguras em %s: %s\n", critical_files[i], perms_str);
      }
    } else {
      printf("  [!] Não foi possível verificar %s: %s\n", critical_files[i], strerror(errno));
    }
  }
}
#endif

#ifdef _WIN32
void check_permissions_windows(){
  printf("\n[*] Verificando permissões inseguras nos arquivos críticos (Windows)...\n");

  const char *critical_files[] = {"C:\\Windows\\System32\\config\\SAM", "C:\\Windows\\System32\\config\\SYSTEM"};

  for (int i = 0; i < 2; i++) {
    DWORD attributes = GetFileAttributes(critical_files[i]);

    if (attributes == INVALID_FILE_ATTRIBUTES) {
      printf("  [!] Não foi possível verificar %s: %s\n", critical_files[i], strerror(errno));
    } else {
      printf("  [✓] %s está acessível (atributos: 0x%X)\n", critical_files[i], attributes);
    }
  }
}
#endif

void check_permissions_from_file(const char *file_path) {
  printf("\n[*] Verificando permissões para arquivos fornecidos em %s...\n", file_path);

  FILE *file = fopen(file_path, "r");
  if (!file) {
    printf("[!] Não foi possível abrir o arquivo %s: %s\n", file_path, strerror(errno));
    return;
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = '\0'; // Remove o caractere de nova linha

    struct stat file_stat;
    if (stat(line, &file_stat) == 0) {
      int perms = file_stat.st_mode & 0777;

      char perms_str[10];
      get_permissions_str(perms, perms_str);

      printf("  [✓] Permissões para %s: %s\n", line, perms_str);
    } else {
      printf("  [!] Não foi possível verificar %s: %s\n", line, strerror(errno));
    }
  }

  fclose(file);
}
