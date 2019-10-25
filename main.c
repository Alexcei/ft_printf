#include "ft_printf.h"

int     main(void)
{
	printf("%d\n", printf("%.5p\n", 0));
	printf("%d\n", ft_printf("%.5p\n", 0));
	printf("\n");
	printf("%d\n", printf("<%hhu, %hhu>\n", 0, 255 + 42));
	printf("%d\n", ft_printf("<%hhu, %hhu>\n", 0, 255 + 42));
	printf("\n");
	printf("<%-05d>\n", -42);
	ft_printf("<%-05d>\n", -42);
	printf("\n");
	printf("<%#-08x>\n", 42);
	ft_printf("<%#-08x>\n", 42);
	printf("\n");
	printf("<%-05o>\n", 2500);
	ft_printf("<%-05o>\n", 2500);
	printf("\n");
	printf("<%lu>\n", -42);
	ft_printf("<%lu>\n", -42);
	printf("\n");
	printf("<%2p>\n", 0);
	ft_printf("<%2p>\n", 0);
	printf("\n");
	printf("<%10i>\n", -12345);
	ft_printf("<%10i>\n", -12345);
	printf("\n");
	printf("<%lld>\n", -9223372036854775808);
	ft_printf("<%lld>\n", -9223372036854775808);
	/*
	double i = 1.025978548534310532934;
	double long l = -1.012;

	printf("%d\n", printf("<%.19f>\n", i));
	printf("%d\n", ft_printf("<%.19f>\n", i));
	printf("\n");
	printf("%d\n", printf("<%.3Lf>\n", l));
	printf("%d\n", ft_printf("<%.3Lf>\n", l));
	printf("\n");
	printf("%d\n", printf("<%+10.f>\n", i));
	printf("%d\n", ft_printf("<%+10.f>\n", i));
	printf("\n");
	printf("%d\n", printf("<%+010.f>\n", i));
	printf("%d\n", ft_printf("<%+010.f>\n", i));
	printf("\n");
	printf("%d\n", printf("<%.f>\n", i));
	printf("%d\n", ft_printf("<%.f>\n", i));
	printf("\n");
	printf("%d\n", printf("<% .f>\n", i));
	printf("%d\n", ft_printf("<% .f>\n", i));
	printf("\n");
	printf("%d\n", printf("<%#.f>\n", i));
	printf("%d\n", ft_printf("<%#.f>\n", i));
	printf("\n");
	printf("%d\n", printf("<%-#5.f>\n", i));
	printf("%d\n", ft_printf("<%-#5.f>\n", i));
	printf("\n");
	printf("%d\n", printf("<%0+#10.f>\n", i));
	printf("%d\n", ft_printf("<%0+#10.f>\n", i));
	printf("\n");
	printf("\n");
	printf("<%10f>\n", i);
	ft_printf("<%10f>\n", i);
	printf("\n");
	printf("<%+-10f>\n", i);
	ft_printf("<%+-10f>\n", i);
	printf("\n");
	printf("<%+10f>\n", i);
	ft_printf("<%+10f>\n", i);
	printf("\n");
	printf("<%+010f>\n", i);
	ft_printf("<%+010f>\n", i);
	printf("\n");
	printf("<%f>\n", i);
	ft_printf("<%f>\n", i);
	printf("\n");
	printf("<% f>\n", i);
	ft_printf("<% f>\n", i);
	printf("\n");
	printf("<%#f>\n", i);
	ft_printf("<%#f>\n", i);
	printf("\n");
	printf("<%-#5f>\n", i);
	ft_printf("<%-#5f>\n", i);
	printf("\n");
	printf("<%0+#10f>\n", i);
	ft_printf("<%0+#10f>\n", i);
	printf("\n");*/
/*
	printf("%d\n", printf("<%#X>\n", i));
	printf("%d\n", ft_printf("<%#X>\n", i));
	printf("\n");
	printf("%d\n", printf("<%#.o>\n", 0));
	printf("%d\n", ft_printf("<%#.o>\n", 0));
	printf("\n");
	printf("%d\n", printf("<%#5.x>\n", i));
	printf("%d\n", ft_printf("<%#5.x>\n", i));
	printf("\n");
	printf("%d\n", printf("<%#-5.x>\n", i));
	printf("%d\n", ft_printf("<%#-5.x>\n", i));
	printf("\n");


	printf("%d\n", printf("<%05i>\n", i));
	printf("%d\n", ft_printf("<%05i>\n", i));
	printf("\n");
	printf("%d\n", printf("<%+-5.i>\n", i));
	printf("%d\n", ft_printf("<%+-5.i>\n", i));
	printf("\n");
	printf("%d\n", printf("<%0+5.3d>\n", i));
	printf("%d\n", ft_printf("<%0+5.3d>\n", i));
	printf("\n");
	printf("%d\n", printf("<%+5.i>\n", i));
	printf("%d\n", ft_printf("<%+5.i>\n", i));
	printf("\n");
	printf("%d\n", printf("<%+.d>\n", i));
	printf("%d\n", ft_printf("<%+.d>\n", i));
	printf("\n");
	printf("%d\n", printf("<% -3i>\n", i));
	printf("%d\n", ft_printf("<% -3i>\n", i));
	printf("\n");
	printf("%d\n", printf("<% 3i>\n", i));
	printf("%d\n", ft_printf("<% 3i>\n", i));
	printf("\n");
    printf("%d\n", printf("<% 010i>\n", i));
    printf("%d\n", ft_printf("<% 010i>\n", i));
    printf("\n");
    printf("%d\n", printf("<% d>\n", i));
    printf("%d\n", ft_printf("<% d>\n", i));
    printf("\n");
    printf("%d\n", printf("<%20.10d>\n", i));
    ft_printf("%d\n", printf("<%20.10d>\n", i));
    printf("\n");
    printf("%d\n", printf("<%-20.10d>\n", i));
    ft_printf("%d\n", printf("<%-20.10d>\n", i));
*/
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
