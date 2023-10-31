/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:28:02 by ehay              #+#    #+#             */
/*   Updated: 2023/10/31 13:26:57 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_putnbr(int n)
{
    int count = 0;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return 11;
    }
    if (n < 0)
    {
        count += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        count += ft_putnbr(n / 10);
    }
    count += ft_putchar(n % 10 + '0');
    return count;
}

int	printadress(const unsigned long n)
{
	if (n / 16)
		return (printadress(n / 16) + printadress(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char) n - 10 + 'a');
	return (1);
}

int	ft_putpointer(void *adress)
{
	if (!adress)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + printadress((unsigned long) adress));
}