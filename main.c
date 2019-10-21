#include "ft_printf.h"

int     main(void)
{
    char str[] = "Hello world!";

    printf("%d\n", printf("hello, -%6.3s.", NULL));
    printf("%d\n", ft_printf("hello, -%6.3s.", NULL));

    printf("%20.5s->\n", str);
    ft_printf("%20.5s->\n", str);
    printf("<-%%%s->\n", str);
    ft_printf("<-%%%s->\n", str);

    printf("%%<-%20.s->%%\n", str);
    ft_printf("%%<-%20.s->%%\n", str);

    printf("%%<-%3.2s->\n", str);
    ft_printf("%%<-%3.2s->\n", str);

    printf("%d\n", ft_printf("%.10s\n", "Hello world"));
    printf("%d\n", printf("%.10s\n", "Hello world"));
    printf("%d\n", ft_printf("%s\n", "ksdjfk"));
    printf("%d\n", printf("%s\n", "ksdjfk"));
    ft_printf("%s %s\n", "Hello", "world!");

    ft_printf("Hi%sHi\nhi : hi\n%s\n", "Hello world!", str);
    printf("Hi%sHi\nhi : hi\n%s\n", "Hello world!", str);

    ft_printf("\nft_printf(\"{%%s}\", \"abc\")\n");
    printf("\nprintf(\"{%%s}\", \"abc\")\n");

    ft_printf("\120\n");
    printf("\120\n");
    ft_printf("<--%s %s %s-->\n", "\63", "3", "qw");
    printf("<--%s %s %s-->\n", "\63", "3", "qw");
    ft_printf("%s %s\n", "3", "qw");
    printf("%s %s\n", "3", "qw");

    ft_printf("%6.5s", "Hello world");
    printf("%6.5s", "Hello world");
    return 0;
}
