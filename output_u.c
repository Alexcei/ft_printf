#include "ft_printf.h"

static unsigned long int	get_figure(t_box *box, t_tab *tab)
{
	unsigned long int	n;

	if (tab->modifier_l)
		n  = (unsigned long int)va_arg(box->av, unsigned long int);
	else if (tab->modifier_h)
		n  = (unsigned short)va_arg(box->av, unsigned int);
	else
		n  = (unsigned int)va_arg(box->av, unsigned int);
	if ((tab->len = ft_figure_len((long long int)n, 10)))
		box->res += tab->len;
	if (n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
	return (n);
}

static void    put_secondary(t_box *box, t_tab *tab)
{
	if (tab->flag_null && !tab->dot_prec)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, '0');
	}
	else
	{
		if (!tab->flag_min)
		{
			while (tab->width-- > 0)
				ft_putchar_count(box, ' ');;
		}
	}
	while (tab->precision--  > 0)
		ft_putchar_count(box, '0');;
}

void    output_u(t_box *box, t_tab *tab)
{
	unsigned long int	n;

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
	put_secondary(box, tab);
	if (n || !tab->dot_prec)
		ft_figure_put((long long int)n, 10);
	else
		box->res--;
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}