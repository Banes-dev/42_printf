/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:27:25 by ehay              #+#    #+#             */
/*   Updated: 2023/10/30 12:57:26 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>           // printf
# include <unistd.h>          // write
# include <string.h>          // fonction string
# include <stdlib.h>          // malloc()
# include <stddef.h>          // size_t
# include <stdarg.h>          // fonction va_

int		ft_printf(const char *format, ...);

#endif