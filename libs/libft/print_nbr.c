/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:11:56 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/28 22:27:58 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_nbr(int nbr, char *str, int index, int flag_check)
{
	int	count;

	count = 0;
	if (nbr >= 0 && flag_check == 1 && (str[index - 1] == ' '
			|| str[index - 1] == '+'))
		count += print_char(str[index - 1]);
	flag_check = 0;
	if (nbr == -2147483648)
	{
		count += print_char('-');
		count += print_char('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		count += print_char('-');
		nbr *= -1;
	}
	if (nbr > 9)
		count += print_nbr(nbr / 10, str, index, flag_check);
	count += print_char((nbr % 10) + '0');
	return (count);
}
