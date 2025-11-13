/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:34:07 by jpaselt           #+#    #+#             */
/*   Updated: 2024/12/09 15:29:14 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//cc printf.c fti_putstr.c putnbr.c fti_putchar.c && ./a.out

static int	print_this(va_list args, char c, int fd)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += fi_putchar(va_arg(args, int), fd);
	if (c == 's')
		count += fi_putstr(va_arg(args, char *), fd);
	if (c == 'p')
		count += fi_putptr(va_arg(args, unsigned long), fd);
	if (c == 'd' || c == 'i')
		count += fi_putnbr(va_arg(args, int), fd);
	if (c == 'u')
		count += fi_putuint(va_arg(args, unsigned int), fd);
	if (c == 'x')
		count += fi_puthex(va_arg(args, unsigned int), 'x', fd);
	if (c == 'X')
		count += fi_puthex(va_arg(args, unsigned int), 'X', fd);
	if (c == '%')
		count += fi_putchar('%', fd);
	return (count);
}

int	ft_printf(int fd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i])
				count += print_this(args, s[i], fd);
			i++;
		}
		else
		{
			count += fi_putchar(s[i], fd);
			i++;
		}
	}
	va_end(args);
	return (count);
}
//cc putptr.c fi_putstr.c fi_putchar.c ft_printf.c puthex.c && ./a.out
// int ft_printf(const char *s, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		count;

// 	count = 0;
// 	i = 0;
// 	va_start(args, s);
// 	while (s[i])
// 	{
// 		while(s[i] == '%')
// 		{
// 			i++;
// 			count += print_this(args, s[i]);
// 			i++;
// 		}
// 		if (s[i])
// 			count += fi_putchar(s[i]);
// 		i++;
// 	}
// 	va_end(args);
// 	return(count);
// }

/* int main()
{
	ft_printf("%c", 'A');
	//write(1, "\n", 1);
	//printf("\n%d", ft_printf("%c", 'A'));
	return(0);
} */