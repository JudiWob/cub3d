/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:15:31 by jpaselt           #+#    #+#             */
/*   Updated: 2024/12/05 18:53:35 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fi_putnbr(int d, int fd)
{
	long	n;
	int		count;

	count = 0;
	n = d;
	if (d < 0)
	{
		count += fi_putchar('-', fd);
		n = -n;
	}
	if (n / 10)
		count += fi_putnbr((n / 10), fd);
	fi_putchar((n % 10) + 48, fd);
	count++;
	return (count);
}

// int main ()
// {
// 	printf( "%d", fi_putnbr(12345));
// }
