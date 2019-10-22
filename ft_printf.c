#include "ft_printf.h"

static void     print_hex(unsigned long n)
{
    if (n >= 16)
        print_hex(n / 16);
    n = n % 16;
    n += n < 10 ? '0' : 'a' - 10;
    write(1, &n, 1);
}

void    output_d(t_box *box, t_tab *tab)
{
    int     n;
    int     n_copy;
    int     gap;

    gap = 0;
    n  = (int)va_arg(box->av, int);
    n_copy = n;
    while (n_copy /= 10)
        tab->len++;
    tab->len += 1;
    if (tab->precision > tab->len)
    {
        gap = tab->precision - tab->len;
        if (n == 0)
            gap++;
        tab->len = tab->precision;
    }
    if (n < 0 || tab->flag_plus)
    {
        tab->len++;
        if (n < 0)
        {
            tab->sign = -1;
            n *= -1;
        }
        else
            tab->sign = 1;
    }
    if (tab->width > tab->len)
        tab->dif = tab->width - tab->len;
    if (((tab->width <= tab->len && tab->sign == 0) || tab->flag_min) && tab->flag_space)
    {
        ft_putchar(' ');
        box->res++;
    }
    box->res += tab->len + tab->dif;
    if (tab->flag_min)
    {
        if (tab->sign == -1)
            ft_putchar('-');
        if (tab->sign == 1)
            ft_putchar('+');
        while (gap--)
            ft_putchar('0');
        if (!(!n && tab->dot_prec))
            ft_putnbr(n);
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
        {
            if (tab->flag_null && !tab->dot_prec)
                ft_putchar('0');
            else
                ft_putchar(' ');
        }
        if (tab->sign == -1)
            ft_putchar('-');
        if (tab->sign == 1)
            ft_putchar('+');
        while (gap--)
            ft_putchar('0');
        if (!(!n && tab->dot_prec))
            ft_putnbr(n);
    }
}

void    output_p(t_box *box, t_tab *tab)
{
    unsigned long    p;
    unsigned long    p_copy;

    p = (unsigned long)va_arg(box->av, unsigned long);
    p_copy = p;
    tab->len += 3;
    while (p_copy /= 16)
        tab->len++;
    if (tab->width > tab->len)
        tab->dif = tab->width - tab->len;
    box->res += tab->len + tab->dif;
    if (tab->flag_min)
    {
        write(1, "0x", 2);
        print_hex(p);
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
            ft_putchar(' ');
        write(1, "0x", 2);
        print_hex(p);
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