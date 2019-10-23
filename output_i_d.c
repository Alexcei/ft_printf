#include "ft_printf.h"

static long long int	get_figure(t_box *box, t_tab *tab)
{
	long long int	n;

	if (tab->modifier_h == 1)
		n  = (short)va_arg(box->av, int);
	else if (tab->modifier_h > 1)
		n  = (signed char)va_arg(box->av, int);
	else if (tab->modifier_l == 1)
		n  = (long)va_arg(box->av, long int);
	else if (tab->modifier_l > 1)
		n  = (long long)va_arg(box->av, long long int);
	else
		n  = (int)va_arg(box->av, int);
	if (n < 0 && ++tab->sign)
		n *= -1;                      // not like that
	if ((tab->len = ft_figure_len(n, 10)))
		box->res += tab->len;
	if (n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
	return (n);
}

static void    put_sign(t_box *box, t_tab *tab)
{
	if (tab->flag_plus && !tab->sign)
		ft_putchar_count(box, '+');
	if (tab->sign)
		ft_putchar_count(box, '-');
	else if (tab->flag_space && !tab->flag_plus)
		ft_putchar_count(box, ' ');
}

static void    put_secondary(t_box *box, t_tab *tab)
{
	if (tab->flag_space || tab->flag_plus || tab->sign)
		tab->width--;
	if (tab->flag_null && !tab->dot_prec)
	{
		put_sign(box, tab);
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
		put_sign(box, tab);
	}
	while (tab->precision--  > 0)
		ft_putchar_count(box, '0');;
}

void    output_d(t_box *box, t_tab *tab)
{
	long long int	n;

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
		ft_figure_put(n, 10);
	else
		box->res--;
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}