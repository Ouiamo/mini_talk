/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:17:32 by oaoulad-          #+#    #+#             */
/*   Updated: 2023/12/12 12:17:53 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		(*len)++;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
		(*len)++;
	}
	else
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
}

int	handle_int(va_list arg)
{
	int	len;
	int	n;

	len = 0;
	n = va_arg(arg, int);
	ft_putnbr(n, &len);
	return (len);
}
