#include "ft_printf.h"

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
	if ((tab->len = ft_int_len(n)))
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
		ft_put_nbr((long long int)n);
	else
		box->res--;
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}