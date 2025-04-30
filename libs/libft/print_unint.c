/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:18 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/29 19:54:27 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unint(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += print_unint(nbr / 10);
	count += print_char((nbr % 10) + '0');
	return (count);
}
