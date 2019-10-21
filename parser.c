#include "ft_printf.h"

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

