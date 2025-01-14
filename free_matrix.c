/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:29 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/09 15:50:43 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

char	**free_matrix(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return (NULL);
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (NULL);
}