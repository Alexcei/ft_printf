#include "ft_printf.h"

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