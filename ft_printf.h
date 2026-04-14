/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:01:13 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:10 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		handle_char(va_list args);
void	ft_putstr(char *str);
int		handle_str(va_list arg);
int		handle_int(va_list arg);
int		handle_unsg(va_list arg);
int		handle_hexa(va_list arg, char c);
int		handle_ptr(va_list arg);

#endif
