#include "ft_printf.h"

void    output_s(t_box *box, t_tab *tab)
{
    char    *s;

    if ((s = va_arg(box->av, char*)))
        box->str = ft_strdup(s);
    else
        box->str = ft_strdup("(null)");
    tab->len = ft_strlen(box->str);
    if (tab->dot_prec && tab->len > tab->precision)
    {
        box->str[tab->precision] = '\0';
        tab->len = tab->precision;
    }
    if (tab->width > tab->len)
        tab->dif = tab->width - tab->len;
    box->res += tab->len + tab->dif;
    if (tab->flag_min)
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

void    output_c(t_box *box, t_tab *tab)
{
    char    s;

    s = (char)va_arg(box->av, char*);
    tab->len = 1;
    if (tab->width > 1)
        tab->dif = tab->width - 1;
    box->res += 1 + tab->dif;
    if (tab->flag_min)
    {
        ft_putchar(s);
        while (tab->dif--)
            ft_putchar(' ');
    }
    else
    {
        while (tab->dif--)
            ft_putchar(' ');
        ft_putchar(s);
    }
}