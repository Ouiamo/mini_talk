/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:12:24 by oaoulad-          #+#    #+#             */
/*   Updated: 2023/12/12 12:16:21 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, int *len, char c)
{
	char	*hexa;

	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar(hexa[n % 16]);
		(*len)++;
	}
	else
	{
		ft_puthexa(n / 16, len, c);
		ft_puthexa(n % 16, len, c);
	}
}

int	handle_hexa(va_list arg, char c)
{
	int				len;
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	len = 0;
	ft_puthexa(n, &len, c);
	return (len);
}
