#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    t_box   box;
    t_tab   tab;

    ft_bzero(&box, sizeof(t_box));
    box.format = format;
    va_start(box.av, format);
    parser(&box, &tab);
    va_end(box.av);
    return (box.res);
}

void		ft_put_nbr(long long int i)
{
	if (i >= 10)
	{
		ft_put_nbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
}

int			ft_int_len(long long int n, int m)
{
	if (n >= m)
		return (ft_int_len(n / m, m) + 1);
	return (1);
}

void		ft_putchar_count(t_box *box, char c)
{
	ft_putchar(c);
	box->res++;
}