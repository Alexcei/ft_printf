#include "ft_printf.h"

static void     print_hex(unsigned long n)
{
	if (n >= 16)
		print_hex(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}

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
		print_hex(p);
	}
	while (tab->width--)
		ft_putchar_count(box, ' ');
	if (!tab->flag_min)
	{
		write(1, "0x", 2);
		print_hex(p);
	}
}