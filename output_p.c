#include "ft_printf.h"

void    output_p(t_box *box, t_tab *tab)
{
	unsigned long    p;

	p = (unsigned long)va_arg(box->av, unsigned long);
	tab->len = ft_figure_len((long long int)p, 16) + 2;
	if (tab->width > tab->len)
		tab->width -= tab->len;
	else
		tab->width = 0;
	box->res += tab->len;
	if (tab->flag_min)
	{
		write(1, "0x", 2);
		ft_figure_put((long long int)p, 16);
	}
	while (tab->width--)
		ft_putchar_count(box, ' ');
	if (!tab->flag_min)
	{
		write(1, "0x", 2);
		ft_figure_put((long long int)p, 16);
	}
}