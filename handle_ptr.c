/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:19:13 by oaoulad-          #+#    #+#             */
/*   Updated: 2023/12/12 12:19:39 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long nbr, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 16)
	{
		ft_putchar(hexa[nbr % 16]);
		(*len)++;
	}
	else
	{
		ft_putptr(nbr / 16, len);
		ft_putptr(nbr % 16, len);
	}
}

int	handle_ptr(va_list arg)
{
	int				len;
	unsigned long	ptr ;

	ptr = (unsigned long)va_arg(arg, void *);
	len = 0;
	ft_putstr("0x");
	len += 2;
	ft_putptr(ptr, &len);
	return (len);
}
