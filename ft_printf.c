/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:31:22 by ehay              #+#    #+#             */
/*   Updated: 2023/10/30 15:28:59 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// fonction si % alors appelle fonction ft_putstr, ft_putnbr, etc...
int	jaj(char form, va_list args)
{
	if (form == 'c')
		return (write(1, &form, 1));
	else if (form == 's')
		return (ft_putstr(form));
	else if (form == 'p')
		return ();
	else if (form == 'd')
		return (ft_putnbr(form));
	else if (form == 'i')
		return ();
	else if (form == 'u')
		return ();
	else if (form == 'x')
		return ();
	else if (form == 'X')
		return ();
	else if (form == '%')
		return (write(1, '%', 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	if (!format)
	{
		return (0);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			jaj(format[i + 1], args);
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	// return (nbcharnice);
	return (-1);
}

// int	main()
// {
// 	printf("test V\n");
// 	ft_printf("test F\n");
// 	return (0);
// }
