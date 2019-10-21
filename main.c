#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

typedef struct  s_box
{
    const char  *format;
    char        *str;
    int         res;
    int         i;
    va_list     av;

}               t_box;

typedef struct  s_tab
{
    int         len;
    int         width;
    int         dif;
    int         precision;
    int         flag_prec;
    int         flag;
}               t_tab;

void    output_s(t_box *box, t_tab *tab)
{
    if (tab->flag_prec && tab->len > tab->precision)
    {
        box->str[tab->precision] = '\0';
        tab->len = tab->precision;
    }
    if (tab->width > tab->len)
        tab->dif = tab->width - tab->len;
    box->res += (tab->len + tab->dif);
    if (tab->flag)
    {
        ft_putstr(box->str);
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
            ft_putchar(' ');
        ft_putstr(box->str);
    }
    free(box->str);
}

void    parser_form(t_box *box, t_tab *tab)
{
    if (box->format[box->i] == '-' && ++box->i)
        tab->flag = 1;
    if (ft_isdigit(box->format[box->i]))
    {
        while (ft_isdigit(box->format[box->i]))
        {
            tab->width *= 10;
            tab->width += box->format[box->i] - '0';
            box->i++;
        }
    }
    if (box->format[box->i] == '.' && ++box->i)
    {
        tab->flag_prec = 1;
        if (ft_isdigit(box->format[box->i])) {
            while (ft_isdigit(box->format[box->i])) {
                tab->precision *= 10;
                tab->precision += box->format[box->i] - '0';
                box->i++;
            }
        }
    }
    if (box->format[box->i] == 's' && ++box->i)
    {
        output_s(box, tab);
    }
}

void    parser(t_box *box, t_tab *tab)
{
    char    *s;

    while (box->format[box->i])
    {
        if (box->format[box->i] == '%' && ++box->i && box->format[box->i] != '%')
        {
            if ((s = va_arg(box->av, char*)))
                box->str = ft_strdup(s);
            else
                box->str = ft_strdup("(null)");
            ft_bzero(tab, sizeof(t_tab));
            tab->len = ft_strlen(box->str);
            parser_form(box, tab);
        }
        else
        {
            ft_putchar(box->format[box->i]);
            box->res++;
            box->i++;
        }
    }
}


int     ft_printf(const char *format, ...)
{
    t_box   box;
    t_tab   tab;

    ft_bzero(&box, sizeof(t_box));
    box.format = format;
    va_start(box.av, format);
    parser(&box, &tab);
    va_end(box.av);
    return (box.res);
}
/*
int main(void)
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
}*/
