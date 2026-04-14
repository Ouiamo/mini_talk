/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_unsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:21:14 by oaoulad-          #+#    #+#             */
/*   Updated: 2023/12/12 12:22:05 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsg(unsigned int n, int *len)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		(*len)++;
	}
	else
	{
		ft_putnbr_unsg(n / 10, len);
		ft_putnbr_unsg(n % 10, len);
	}
}

int	handle_unsg(va_list arg)
{
	int	len;
	int	n;

	len = 0;
	n = va_arg(arg, int);
	ft_putnbr_unsg(n, &len);
	return (len);
}
