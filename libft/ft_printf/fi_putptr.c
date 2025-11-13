/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:15:28 by jpaselt           #+#    #+#             */
/*   Updated: 2024/12/09 14:53:45 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fi_putptr(unsigned long address, int fd)
{
	int	count;

	count = 0;
	if (address == 0)
	{
		count += fi_putstr("(nil)", fd);
		return (count);
	}
	count += fi_putstr("0x", fd);
	count += fi_puthex(address, 'x', fd);
	return (count);
}

// int main()
// {
// 	char *p = NULL;

// 	char *s = "Hello";

// 	//p = &s;

// 	ft_printf("Address of ptr    	(%%p, &p): %p\n", &s);
// 	printf("Ori Address of ptr    	(%%p, &p): %p\n", &s);
// 	ft_printf("Address ptr holds 	(%%p,  p): %p\n", s);
// 	printf("Ori:Address ptr holds 	(%%p,  p): %p\n", s);

// }
