/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:53:42 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/08 15:52:12 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	long	holder;

	holder = 0;
	result = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		if (result * 10 + *nptr - 48 < holder)
			return (-(sign + 1) / 2);
		result = result * 10 + *nptr - 48;
		holder = result;
		nptr++;
	}
	return ((int)(result * sign));
}
