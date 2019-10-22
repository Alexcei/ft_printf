#include "ft_printf.h"

int     main(void)
{
    int i = 1;

    printf("%d\n", printf("% 0+8.5d\n", 0));
    printf("%d\n", ft_printf("% 0+8.5d\n", 0));

    printf("%d\n", printf("<%20.10d>\n", i));
    ft_printf("%d\n", printf("<%20.10d>\n", i));

    printf("%d\n", printf("<%-20.10d>\n", i));
    ft_printf("%d\n", printf("<%-20.10d>\n", i));

    printf("%d\n", printf("<%010.10d>\n", i));
    printf("%d\n", ft_printf("<%010.10d>\n", i));

    printf("%d\n", printf("<% 3i>\n", 0));
    printf("%d\n", ft_printf("<% 3i>\n", 0));

    /*char str[] = "Hello world!";
    int i = 1;
    int *p = &i;

    printf("<-%%->\n");
    ft_printf("<-%%->\n");
    printf("%c%c\n", '1', '2');
    ft_printf("%c%c\n", '1', '2');
    printf(("<-%5%->\n"));
    ft_printf(("<-%5%->\n"));
    ft_printf("%%\n");
    printf("%d\n", printf("<-%-15.p->\n", p));
    printf("%d\n", ft_printf("<-%-15.p->\n", p));
    printf("p<-%-2.c->\n", '2');
    ft_printf("f<-%-2.1c->\n", '2');
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
    printf("%6.5s", "Hello world");*/
    return 0;
}
