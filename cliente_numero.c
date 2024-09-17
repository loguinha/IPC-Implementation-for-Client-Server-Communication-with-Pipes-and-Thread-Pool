#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // Uso de arquivos e pipes
#include <string.h> // Uso de strings
#include <unistd.h> // Funções do SO (read, write, open, close...)

// Caminho para o PIPE
#define PIPE_NUMERO "/tmp/pipe_numero"

int main() {
    char buffer[256]; 
    int fd = open(PIPE_NUMERO, O_WRONLY); // Abrir pipe para escrever

    // verificar se deu pra abrir o pipe
    if (fd == -1) {
        perror("ERRO PRA ABRIR O PIPE");
        exit(1);
    }

    int contador = 1;

    while (1) {
        snprintf(buffer, sizeof(buffer), "%d\n", contador++);  // Adiciona um '\n' (delimitador) após o número
        write(fd, buffer, strlen(buffer)); // Envia a string com o delimitador
        printf("Enviado: %s", buffer);

        sleep(2);
    }

    close(fd);
    return 0;
}