#include "ft_printf.h"

static double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

static long double	get_figure(t_box *box, t_tab *tab)
{
	double		n;
	double			decimal;
	long			value;

	if (tab->modifier_L)
		n = (long double)va_arg(box->av, double);
	else
		n = (double)va_arg(box->av, double);
	if (n < 0 && ++tab->sign)
		n *= -1;
	if (!tab->dot_prec)
		tab->precision = 6;

	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long)(((n < 0.0f) ? -n : n))) *
			  ft_pow(10, tab->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;

	if (!tab->precision)
		n - (long)n < 0.5 ? n : n++;

	tab->len = ft_figure_len(n, 10);
	printf("<%ld %d %ld>\n", (long)n, tab->len, value);
	return ((long)n);
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

void    output_f(t_box *box, t_tab *tab)
{
	long double	n;

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
		ft_figure_put(n, 10, 97);
	else
		box->res--;
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}