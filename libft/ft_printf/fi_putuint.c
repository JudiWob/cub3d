/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:41:48 by jpaselt           #+#    #+#             */
/*   Updated: 2024/12/09 14:53:29 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fi_putuint(unsigned int num, int fd)
{
	int	count;

	count = 0;
	if (num / 10)
		count += fi_putuint((num / 10), fd);
	fi_putchar((num % 10) + 48, fd);
	count++;
	return (count);
}

// int main()
// {
// 	int num = -87857;
// 	putuint(num);
// 	printf("\n%u", num);
// }