#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

// Função de teste com nome de arquivo
void test_file(const char *filename)
{
    printf("=== 📄 Testando arquivo: %s ===\n", filename);

    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char *line;
    int count = 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linha %d: %s", count++, line);
        free(line);
    }

    printf("\n== ✅ Fim do arquivo: %s ==\n\n", filename);
    close(fd);
}

int main(void)
{
    printf("🚀 Iniciando testes com BUFFER_SIZE = %d\n", BUFFER_SIZE);

    // Teste 1: Arquivo normal
    test_file("teste.txt");

    // Teste 2: Arquivo vazio
    test_file("vazio.txt");

    // Teste 3: Só com quebras de linha
    test_file("quebra.txt");

    // Teste 4: Linha longa sem '\n'
    test_file("semquebra.txt");

    // Teste 5: Teste com múltiplos arquivos (se você quiser)
    /*
    int fd1 = open("arquivo1.txt", O_RDONLY);
    int fd2 = open("arquivo2.txt", O_RDONLY);
    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);
    printf("Arquivo1: %s\n", line1);
    printf("Arquivo2: %s\n", line2);
    free(line1);
    free(line2);
    close(fd1);
    close(fd2);
    */

    return 0;
}


/* TESTE:TXT

linha 1
linha 2
linha 3
*/

/* vazio:TXT


*/

/* quebra:TXT


\n
\n

*/

/* sem quebra:TXT
Esta é uma linha muito longa sem quebra de linha no final que deve ser lida até o EOF e ainda assim retornar uma linha válida


*/