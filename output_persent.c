#include "ft_printf.h"

void    output_persent(t_box *box, t_tab *tab)
{
	tab->len = 1;
	if (tab->width > 1)
		tab->dif = tab->width - 1;
	box->res += 1 + tab->dif;
	if (tab->flag_min)
	{
		ft_putchar('%');
		while (tab->dif--)
			ft_putchar(' ');
	}
	else
	{
		while (tab->dif--)
		{
			if (tab->flag_null)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar('%');
	}
}