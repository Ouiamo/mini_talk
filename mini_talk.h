/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:26:09 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/05/22 15:27:05 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "ft_printf.h"
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		my_atoi(char *str);
void	protect(int n);
void	success(int sig);
void	protect(int n);
#endif
