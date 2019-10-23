#include "ft_printf.h"

static void		ft_putnbr_u(unsigned long int i)
{
	if (i >= 10)
	{
		ft_putnbr_u(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
}

size_t	ft_intlen_u(unsigned long int n)
{
	if (n >= 10)
		return (ft_intlen_u(n / 10) + 1);
	return (1);
}

static void		ft_putchar_count(t_box *box, char c)
{
	ft_putchar(c);
	box->res++;
}

static void    put_dif(t_box *box, t_tab *tab)
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

	if (tab->modifier_l)
		n  = (unsigned long int)va_arg(box->av, unsigned long int);
	else if (tab->modifier_h)
		n  = (unsigned short)va_arg(box->av, unsigned int);
	else
		n  = (unsigned int)va_arg(box->av, unsigned int);
	if ((tab->len = ft_intlen_u(n)))
		box->res += tab->len;
	if (n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
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
	put_dif(box, tab);
	if (n || !tab->dot_prec)
		ft_putnbr_u(n);
	else
		box->res--;
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}