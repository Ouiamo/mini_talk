/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:20:30 by oaoulad-          #+#    #+#             */
/*   Updated: 2023/12/14 22:47:59 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	handle_str(va_list args)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	len = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str);
		str++;
		len++;
	}
	return (len);
}
