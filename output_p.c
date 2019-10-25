#include "ft_printf.h"

void    output_p(t_box *box, t_tab *tab)
{
	tab->n = (unsigned long)va_arg(box->av, unsigned long);
	tab->len = ft_figure_len(tab->n, 16);
	if (!tab->n && tab->dot_prec)
		tab->precision++;
	box->res += 2;
	tab->width -= 2;
	if (tab->precision > tab->len)
	{
		tab->width -= tab->precision;
		tab->precision -= tab->len;
	}
	else
	{
		tab->width -= tab->len;
		tab->precision -= tab->len;
	}
	if (tab->flag_min)
	{
		write(1, "0x", 2);
		while (tab->precision--  > 0)
			ft_putchar_count(box, '0');;
		if (tab->n || !tab->dot_prec)
			ft_figure_put(box, tab->n, 16, 97);
	}
	while (tab->width-- > 0)
		ft_putchar_count(box, ' ');
	if (!tab->flag_min)
	{
		write(1, "0x", 2);
		while (tab->precision--  > 0)
			ft_putchar_count(box, '0');;
		if (tab->n || !tab->dot_prec)
			ft_figure_put(box, tab->n, 16, 97);
	}
}