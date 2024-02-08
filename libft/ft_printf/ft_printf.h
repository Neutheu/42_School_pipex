/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:43 by nsouchal          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:27 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	printf_c(int c);
int	printf_s(char *str);
int	printf_d_i(int nb);
int	printf_u(unsigned int nb);
int	printf_xlow_xupp(long unsigned int nb, int c);
int	printf_p(long unsigned int ptr);

#endif
