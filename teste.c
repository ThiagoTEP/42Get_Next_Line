#include <stdio.h>

void contarcomum()
{
    int x = 0;
    x++;
    printf("x comum = %d &x = %p\n", x, &x);
}

void contastatic()
{
    static int x = 0;
    x++;
    printf("x static = %d &x = %p\n", x, &x);
}

int main(void)
{
    contarcomum();
    contarcomum();
    contarcomum();

    puts("\n--------------\n");

    contastatic();
    contastatic();
    contastatic();
	contastatic();
	// so para testar os commits
    
    return 0;
}