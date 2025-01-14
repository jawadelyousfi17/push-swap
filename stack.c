/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:19:31 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/14 14:10:41 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_stack *stack, int size)
{
    if (size <= 0)
    {
        stack->arr = NULL;
        return;
    }
    stack->arr = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    stack->length = 0;
}

void push_to_stack(t_stack *stack, int element)
{
    if (stack->top >= stack->size - 1)
        return;
    stack->arr[++stack->top] = element;
    stack->length++;
}

int pop_from_stack(t_stack *stack)
{
    if (stack->top == -1)
        return (-1);
    stack->length--;
    return (stack->arr[stack->top--]);
}

int get_top_from_stack(t_stack *stack)
{
    if (stack->top == -1)
        return (-1);
    return (stack->arr[stack->top]);
}