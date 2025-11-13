/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:11:22 by jpaselt           #+#    #+#             */
/*   Updated: 2024/12/09 14:53:34 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fi_puthex(unsigned long hex, char c, int fd)
{
	int				temp;
	int				count;

	count = 0;
	if (hex / 16)
		count += fi_puthex((hex / 16), c, fd);
	temp = hex % 16;
	if (temp > 9)
	{
		if (c == 'X')
			fi_putchar(temp + 55, fd);
		else
			fi_putchar(temp + 87, fd);
	}
	else
		fi_putchar(temp + 48, fd);
	count++;
	return (count);
}

// int main()
// {	
// 	int num = 188234;
// 	//int num2 = &num;

// 	//puthex(num, 'X');
// 	//printf("\n%p", num2);

// 	printf("\n%d", puthex(num, 'X'));
// }
//cc puthex.c fi_putchar.c && ./a.out