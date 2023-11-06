/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:31:22 by ehay              #+#    #+#             */
/*   Updated: 2023/11/06 16:04:13 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv(char form, va_list args)
{
	int	result;

	result = 0;
	if (form == 'c')
		result = ft_putchar((char) va_arg(args, int));
	else if (form == 's')
		result = ft_putstr(va_arg(args, char *));
	else if (form == 'p')
		result = ft_putpointer(va_arg(args, void *));
	else if (form == 'd')
		result = ft_putnbr(va_arg(args, int));
	else if (form == 'i')
		result = ft_putnbr(va_arg(args, int));
	else if (form == 'u')
		result = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (form == 'x')
		result = ft_puthexalower(va_arg(args, unsigned int));
	else if (form == 'X')
		result = ft_puthexaupper(va_arg(args, unsigned ));
	else if (form == '%')
		result = ft_putchar('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		nb;

	va_start(args, format);
	i = 0;
	nb = 0;
	if (!format)
	{
		return (0);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			nb = nb + conv(format[i + 1], args);
			i++;
		}
		else
			nb = nb + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (nb);
}

// int	main()
// {
// 	char chara = 'a';
// 	char string[] = "lalala";
// 	int apoint = 412;
// 	void *point = &apoint;
// 	int decimal = 42;
// 	int hexadecimal = 255;
// 	char pourcent = '%';

// 	int jajtest = printf("test base\n");
// 	int jaj = ft_printf("test base ft\n");
// 	printf("%i \n",jajtest);
// 	printf("%i \n\n",jaj);

// 	int jajtest2 = printf("char %c\n", chara);
// 	int jaj2 = ft_printf("char %c\n", chara);
// 	printf("%i \n",jajtest2);
// 	printf("%i \n\n",jaj2);

// 	int jajtest3 = printf("string %s\n", string);
// 	int jaj3 = ft_printf("string %s\n", string);
// 	printf("%i \n",jajtest3);
// 	printf("%i \n\n",jaj3);

// 	int jajtest4 = printf("void pointer %p\n", (void *)point);
// 	int jaj4 = ft_printf("void pointer %p\n", (void *)point);
// 	printf("%i \n",jajtest4);
// 	printf("%i \n\n",jaj4);

// 	int jajtest5 = printf("decimal %d\n", decimal);
// 	int jaj5 = ft_printf("decimal %d\n", decimal);
// 	printf("%i \n",jajtest5);
// 	printf("%i \n\n",jaj5);

// 	int jajtest6 = printf("integer %i\n", decimal);
// 	int jaj6 = ft_printf("integer %i\n", decimal);
// 	printf("%i \n",jajtest6);
// 	printf("%i \n\n",jaj6);

// 	int jajtest7 = printf("decimal unsi %u\n", decimal);
// 	int jaj7 = ft_printf("decimal unsi %u\n", decimal);
// 	printf("%i \n",jajtest7);
// 	printf("%i \n\n",jaj7);

// 	int jajtest8 = printf("lower %x\n", hexadecimal);
// 	int jaj8 = ft_printf("lower %x\n", hexadecimal);
// 	printf("%i \n",jajtest8);
// 	printf("%i \n\n",jaj8);

// 	int jajtest9 = printf("upper %X\n", hexadecimal);
// 	int jaj9 = ft_printf("upper %X\n", hexadecimal);
// 	printf("%i \n",jajtest9);
// 	printf("%i \n\n",jaj9);

// 	int jaj10 = ft_printf("pourcent %%\n", pourcent);
// 	printf("%i \n\n",jaj10);
// }
