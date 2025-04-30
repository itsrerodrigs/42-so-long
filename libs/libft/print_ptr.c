/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:12:17 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/28 22:28:25 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_hexlong(unsigned long nbr, char *base);

int	print_ptr(unsigned long nbr, char *base)
{
	int	count;

	if (nbr == 0)
		return (print_str("(nil)"));
	count = 0;
	count += print_str("0x");
	count += print_hexlong(nbr, base);
	return (count);
}

static int	print_hexlong(unsigned long nbr, char *base)
{
	int				count;

	count = 0;
	if (nbr > 15)
		count += print_hexlong(nbr / 16, base);
	count += print_char(base[nbr % 16]);
	return (count);
}
