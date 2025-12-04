/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:02:03 by mjabalqu          #+#    #+#             */
/*   Updated: 2025/12/04 15:28:45 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(unsigned int num);
int	ft_putnbr_base(unsigned long num);

#endif
