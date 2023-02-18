/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:31:22 by ofadhel           #+#    #+#             */
/*   Updated: 2023/02/18 14:11:29 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(const char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg(arg, unsigned long));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_hexlower(va_arg(arg, unsigned int)))
	else if (c == 'X')
		return (ft_hexupper(va_arg(arg, unsigned int)));
	else (c == '%')
		return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int	i;
	int	count;
	
	va_start(arg, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_convert(format[++i], arg);
		else 
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
