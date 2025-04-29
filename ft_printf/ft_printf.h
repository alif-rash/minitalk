/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:44:12 by raalifa           #+#    #+#             */
/*   Updated: 2025/01/03 08:40:37 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int			ft_printf(const char *car, ...);
void		ft_putnbrl(int num, int *len);
void		ft_hexa(unsigned long long num, int *len, int i);
void		ft_pointer(unsigned long long ptr, int *len);
void		ft_unsigned_int(unsigned int unum, int *len);

void		ft_putcharl(int ch, int *len);
void		ft_string(char *str, int *len);

#endif