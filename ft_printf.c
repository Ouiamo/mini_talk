/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:57:24 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/05/23 17:54:54 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_atoi(char *str)
{
	long long	res;
	int			i;

	res = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 & str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (res > 2147483647)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (res);
}

void	success(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message has been sent successfully :)\n\n");
}

void	protect(int n)
{
	if (n == -1)
		exit(write(1, "there is an error\n", 18));
}

static void	cheak_input(const char *ptr, va_list arg, int *len)
{
	char	a;

	if (*ptr == 'c')
		*len += handle_char(arg);
	else if (*ptr == 's')
		*len += handle_str(arg);
	else if (*ptr == 'd' || *ptr == 'i')
		*len += handle_int(arg);
	else if (*ptr == 'u')
		*len += handle_unsg(arg);
	else if (*ptr == 'x' || *ptr == 'X')
		*len += handle_hexa(arg, *ptr);
	else if (*ptr == 'p')
		*len += handle_ptr(arg);
	else
	{
		a = *ptr;
		*len += write(1, &a, 1);
	}
}

int	ft_printf(const char *p, ...)
{
	va_list	arg;
	int		len;
	char	*ptr;

	ptr = (char *)p;
	va_start(arg, p);
	len = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
				break ;
			cheak_input(ptr, arg, &len);
		}
		else
			len += write(1, ptr, 1);
		ptr++;
	}
	va_end(arg);
	return (len);
}
