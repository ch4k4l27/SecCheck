#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Função para escanear portas abertas no localhost
void scan_open_ports() {
    printf("\n[*] Escaneando portas abertas no localhost (127.0.0.1)...\n");

    // Verifica portas de 1 a 1024
    for (int port = 1; port <= 1024; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Erro ao criar socket");
            return;
        }

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        // Tenta conectar à porta
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("  [!] Porta aberta: %d\n", port);
        }

        close(sock);
    }
    
    printf("  [✓] Escaneamento concluído.\n");
}
