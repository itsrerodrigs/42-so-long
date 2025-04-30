/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:12:17 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/28 22:28:46 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	int	count;

	if (str == NULL)
		return (print_str("(null)"));
	count = 0;
	while (str[count] != '\0')
	{
		print_char(str[count]);
		count++;
	}
	return (count);
}
