/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolasig <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:25:20 by hyolasig          #+#    #+#             */
/*   Updated: 2022/07/29 14:23:41 by hyolasig         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	sum;

	sum = 0;
	if (format == 'c')
		sum += ft_printchar(va_arg(args, int));
	else if (format == 's')
		sum += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		sum += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		sum += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		sum += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		sum += ft_printchar_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		sum += ft_printchar('%');
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		sum;
	va_list	args;

	i = 0;
	sum = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			sum += ft_formats(args, str[++i]);
		else
			sum += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (sum);
}

/* #include <stdio.h>
int main()
{
	int a;
	char *str;
	char b;
	unsigned int d;
	d = 1039;
	b = 'h';
	a = 35;
	str = "abc";
	printf("\n%d\n", ft_printf("%%%% %x", "c");
	printf("\n%d\n", printf("%c %s %p %d %u %x %%", b, str, &a, a, d, d));
} */
