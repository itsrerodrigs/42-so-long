/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/28 22:27:15 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned int nbr, char *str, int index, int hash_check)
{
	int	count;

	count = 0;
	if (nbr != 0 && str[index - 1] == '#' && hash_check == 1)
	{
		if (str[index] == 'x')
			count += print_str("0x");
		else
			count += print_str("0X");
	}
	hash_check = 0;
	if (str[index] == 'X')
	{
		if (nbr > 15)
			count += print_hex(nbr / 16, str, index, hash_check);
		count += print_char(UPPER_HEX[nbr % 16]);
	}
	else
	{
		if (nbr > 15)
			count += print_hex(nbr / 16, str, index, hash_check);
		count += print_char(LOWER_HEX[nbr % 16]);
	}
	return (count);
}
