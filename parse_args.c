/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:38:11 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/09 16:53:00 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_int(char *str)
{
    int i;
    long    result;
    
    i = 0;
    if (!str || !str[0] || ft_strlen(str) > INT_MAX_LENGTH)
        return (0);
    if ((str[0] == '-' || str[0] == '+') && ft_strlen(str) == 1)
        return (0);
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i])
        if (!ft_isdigit(str[i++]))
            return (0);
    result = ft_atol(str);
    if (result > INT_MAX || result < INT_MIN)
        return (0);
    return (1);
}

int check_valid_args(char **av)
{
    int i;

    i = 0;
    while (av[i])
        if (!is_int(av[i++]))
            return (0);
    return (i); 
}


int check_duplicate(t_stack *stack)
{
    int i; 
    int j;
    int tmp;

    i = 0;  
    while (i < stack->size - 1)
    {
        j = i + 1;
        tmp = stack->arr[i];
        while (j < stack->size)
            if (tmp == stack->arr[j++])
                return (0);
        i++;
    }
    return (1);
}

void initialize_stack_a(t_stack *stack, int size, char **str)
{
    int i;

    i = size - 1;
    while (i >= 0)
        push_to_stack(stack, ft_atol(str[i--]));
}

char **parse_args(int ac, char **av)
{
    char *s;
    int i;
    char **splited;
    char *tmp;

    i = 1;
    s = ft_strdup("");
    while (i < ac)
    {
        s = ft_strjoin(s, av[i]);
        if (!s)
            return (NULL);
        s = ft_strjoin(s, " ");
        if (!s)
            return (NULL);
        i++;
    }
    splited = ft_split(s, ' ');
    free(s);
    return splited;
}
