#include "ft_printf.h"

static unsigned long long int	get_figure(t_box *box, t_tab *tab)
{
	unsigned long long int	n;

	if (tab->modifier_h == 1)
		n  = (unsigned short)va_arg(box->av, unsigned int);
	else if (tab->modifier_h > 1)
		n  = (unsigned char)va_arg(box->av, unsigned int);
	else if (tab->modifier_l == 1)
		n  = (unsigned long)va_arg(box->av, unsigned long int);
	else if (tab->modifier_l > 1)
		n  = (unsigned long long)va_arg(box->av, unsigned long long int);
	else
		n  = (unsigned int)va_arg(box->av, unsigned int);
	tab->len = ft_figure_len((long long int)n, 8);
	if (n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
	return (n);
}

static void    put_secondary(t_box *box, t_tab *tab)
{
	if (tab->flag_grid && tab->precision < 1)
		tab->width--;
	if (tab->flag_null && !tab->dot_prec)
	{
		if (tab->flag_grid && tab->precision < 1)
			ft_putchar_count(box, '0');
		while (tab->width-- > 0)
			ft_putchar_count(box, '0');
	}
	else
	{
		if (!tab->flag_min)
		{
			while (tab->width-- > 0)
				ft_putchar_count(box, ' ');
		}
		if (tab->flag_grid && tab->precision < 1)
			ft_putchar_count(box, '0');
	}
	while (tab->precision--  > 0)
		ft_putchar_count(box, '0');;
}

void    output_o(t_box *box, t_tab *tab)
{
	unsigned long long int	n;

	n = get_figure(box, tab);
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
		tab->flag_null = 0;
	if (n == 0 && !tab->dot_prec)
		tab->flag_grid = 0;
	put_secondary(box, tab);
	if (n || !tab->dot_prec)
		ft_figure_put(box, (long long int)n, 8, 97);
	//else
	//	box->res--;
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}