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

void     ft_figure_put_f(t_box *box, long n, int rank, char c)
{
	if (n >= rank)
		ft_figure_put_f(box, n / rank, rank, c);
	n = n % rank;
	n += n < 10 ? '0' : c - 10;
	ft_putchar_count(box, (char)n);
}
/*
void     ft_figure_put(long long int n, int rank, char c)
{
	if (n >= rank)
		ft_figure_put(n / rank, rank, c);
	n = n % rank;
	n += n < 10 ? '0' : c - 10;
	write(1, &n, 1);
}*/

int			ft_figure_len(long long int n, int m)
{
	if (n >= m)
		return (ft_figure_len(n / m, m) + 1);
	return (1);
}

void		ft_putstr_count(t_box *box, char *s)
{
	int		len;
	len = ft_strlen(s);
	write(1, &*s, len);
	box->res += len;
}

void		ft_putchar_count(t_box *box, char c)
{
	write(1, &c, 1);;
	box->res++;
}