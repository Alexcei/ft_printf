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
	unsigned long    p_copy;

	p = (unsigned long)va_arg(box->av, unsigned long);
	p_copy = p;
	tab->len += 3;
	while (p_copy /= 16)
		tab->len++;
	if (tab->width > tab->len)
		tab->dif = tab->width - tab->len;
	box->res += tab->len + tab->dif;
	if (tab->flag_min)
	{
		write(1, "0x", 2);
		print_hex(p);
		while (tab->dif--)
			ft_putchar(' ');
	}
	else
	{
		while (tab->dif--)
			ft_putchar(' ');
		write(1, "0x", 2);
		print_hex(p);
	}
}