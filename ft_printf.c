/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:31:22 by ehay              #+#    #+#             */
/*   Updated: 2023/10/31 13:46:59 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conv(char form, va_list args)
{
	if (form == 'c')
		return (ft_putchar((char) va_arg(args, int)));
	if (form == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (form == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (form == 'd')
		return (ft_putnbr(va_arg(args, int)));
	// else if (form == 'i')
	// 	return ();
	// else if (form == 'u')
	// 	return ();
	// else if (form == 'x')
	// 	return ();
	// else if (form == 'X')
	// 	return ();
	else if (form == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int 	nb;

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
			nb = conv(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (nb);
}

int	main()
{
	char chara = 'a';
	char string[] = "lalala";
	int apoint = 412;
	void *point = &apoint;
	int decimal = 42;
	char pourcent = '%';


	printf("test base\n");
	int jaj = ft_printf("test base ft\n");
	printf("%i \n\n",jaj);
	
	printf("char %c\n", chara);
	int jaj2 = ft_printf("char %c\n", chara);
	printf("%i \n\n",jaj2);

	int jajtest = printf("string %s\n", string);
	int jaj3 = ft_printf("string %s\n", string);
	printf("%i \n",jajtest);
	printf("%i \n\n",jaj3);

	printf("void pointer %p\n", (void *)point);
	int jaj4 = ft_printf("void pointer %p\n", (void *)point);
	printf("%i \n\n",jaj4);

	printf("decimal %d\n", decimal);
	int jaj5 = ft_printf("decimal %d\n", decimal);
	printf("%i \n\n",jaj5);

	int jaj10 = ft_printf("pourcent %%\n", pourcent);
	printf("%i \n\n",jaj10);
}
