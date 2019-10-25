#include "ft_printf.h"

static double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

static void		ft_putchar_count_f(t_box *box, char c)
{
	write(1, &c, 1);;
	box->res++;
}

static int			ft_figure_len_f(long long int n, int rank)
{
	if (n >= rank)
		return (ft_figure_len_f(n / rank, rank) + 1);
	return (1);
}

static void     ft_figure_put_f(t_box *box, long n, int rank, char c)
{
	if (n >= rank)
		ft_figure_put_f(box, n / rank, rank, c);
	n = n % rank;
	n += n < 10 ? '0' : c - 10;
	ft_putchar_count_f(box, (char)n);
}

static void     ft_put_decimal(t_box *box, t_tab *tab, long decimal)
{
	if (decimal)
	{
		if (decimal >= 10)
			ft_put_decimal(box, tab, decimal / 10);
		decimal %= 10;
		ft_putchar_count_f(box, (char)(decimal + '0'));
	}
	else
	{
		while (tab->precision--  > 0)
			ft_putchar_count_f(box, '0');
	}
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
	if (tab->flag_null && !tab->flag_min)
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
	ft_figure_put_f(box, tab->n, 10, 97);
	if (tab->flag_grid || tab->precision)
		ft_putchar_count_f(box, '.');
	ft_put_decimal(box, tab, tab->decimal);

	while (tab->width-- > 0)
		ft_putchar_count_f(box, ' ');
}

void		output_f(t_box *box, t_tab *tab)
{
	double long 	n;
	double long		decimal;

	if (tab->modifier_L)
		n = (long double)va_arg(box->av, double);
	else
		n = (double)va_arg(box->av, double);
	if (n < 0 && ++tab->sign)
		n *= -1;
	if (!tab->dot_prec)
		tab->precision = 6;
	decimal = (n - (long)n) * ft_pow(10, tab->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;

	//printf("");

	tab->n = (long)n + (long)(decimal / ft_pow(10, tab->precision));
 	tab->decimal = (long)decimal % (long)ft_pow(10, tab->precision);
	tab->len = ft_figure_len_f(tab->n, 10);
	tab->width -= tab->len + tab->precision;
	if (tab->flag_grid || tab->precision)
		tab->width--;
	if (tab->flag_space || tab->flag_plus || tab->sign)
		tab->width--;
	put_secondary(box, tab);
}