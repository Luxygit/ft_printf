#include <stdio.h>
#include <unistd.h>
int ft_printf(const char *, ...);

int main(void)
{
    int r1, r2;
    void	*ptr = NULL;
	char *str = NULL;
    r1 = ft_printf("Hello %s, num=%d, hex=%x, ptr=%p\n", "World", 42, 42, (void*)42);
    r2 = printf("Hello %s, num=%d, hex=%x, ptr=%p\n", "World", 42, 42, (void*)42);

    printf("Return values: ft_printf = %d | printf = %d\n", r1, r2);

    return (0);
}

