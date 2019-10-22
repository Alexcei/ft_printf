#include "ft_printf.h"

static void     print_hex(unsigned long n)
{
    if (n >= 16)
        print_hex(n / 16);
    n = n % 16;
    n += n < 10 ? '0' : 'a' - 10;
    write(1, &n, 1);
}

void    output_p(t_box *box, t_tab *tab)
{
    unsigned long    s;
    unsigned long    s_copy;

    s = (unsigned long)va_arg(box->av, unsigned long);
    s_copy = s;
    tab->len +=3;
    while (s_copy /= 16)
        tab->len++;
    if (tab->width > tab->len)
        tab->dif = tab->width - tab->len;
    box->res += tab->len + tab->dif;
    if (tab->flag_min)
    {
        write(1, "0x", 2);
        print_hex(s);
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
            ft_putchar(' ');
        write(1, "0x", 2);
        print_hex(s);
    }
}

void    output_persent(t_box *box, t_tab *tab)
{
    tab->len = 1;
    if (tab->width > 1)
        tab->dif = tab->width - 1;
    box->res += 1 + tab->dif;
    if (tab->flag_min)
    {
        ft_putchar('%');
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
        {
            if (tab->flag_null)
                ft_putchar('0');
            else
                ft_putchar(' ');
        }
        ft_putchar('%');
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