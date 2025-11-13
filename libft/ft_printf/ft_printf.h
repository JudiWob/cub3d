/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:24:33 by jpaselt           #+#    #+#             */
/*   Updated: 2024/12/09 15:12:55 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(int fd, const char *s, ...);
int	fi_putchar(int c, int fd);
int	fi_putstr(char *s, int f);
int	fi_putnbr(int num, int f);
int	fi_puthex(unsigned long num, char c, int f);
int	fi_putptr(unsigned long address, int f);
int	fi_putuint(unsigned int num, int f);

#endif