#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef  __linux__
// Função para verificar variáveis de ambiente sensíveis
void check_environment_linux() {
    printf("\n[*]Verificando variáveis de ambiente sensíveis...\n");

    // Lista de variáveis de ambiente sensíveis
    const char *sensitive_vars[] = {"AWS_SECRET_ACCESS_KEY", "DB_PASSWORD", "SECRET_KEY"};
    size_t num_vars = sizeof(sensitive_vars) / sizeof(sensitive_vars[0]);
    int found = 0;

    for (int i = 0; i < num_vars; i++) {
        // Verificando se a variável de ambiente está definida
        if (getenv(sensitive_vars[i]) != NULL) {
            printf("  [!] Variável sensível encontrada: %s\n", sensitive_vars[i]);
            found = 1;
        }
    }

    // Caso nenhuma variável sensível seja encontrada
    if (!found) {
        printf("  [✓] Nenhuma variável sensível encontrada.\n");
    }
}
#endif 
