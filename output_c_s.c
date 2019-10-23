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
        tab->width -= tab->len;
    else
    	tab->width = 0;
    box->res += tab->len;
    if (tab->flag_min)
        ft_putstr(box->str);
    while (tab->width--)
		ft_putchar_count(box, ' ');
	if (!tab->flag_min)
		ft_putstr(box->str);
    free(box->str);
}

void    output_c(t_box *box, t_tab *tab)
{
	char    s;

	s = (char)va_arg(box->av, char*);
	if (tab->width > 0)
		tab->width--;
	if (tab->flag_min)
		ft_putchar_count(box, s);
	while (tab->width--)
		ft_putchar_count(box, ' ');
	if (!tab->flag_min)
		ft_putchar_count(box, s);
}