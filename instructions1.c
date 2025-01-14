/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:04:47 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/09 17:40:41 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_stack *a, t_stack *b, int flag)
{
    if (b->top >= b->size - 1 || a->top == -1)
        return ;
    push_to_stack(b, pop_from_stack(a));
    if (flag)
        ft_printf("pb\n");
}

void pa(t_stack *a, t_stack *b, int flag)
{
    if (a->top >= a->size - 1 || b->top == -1)
        return ;
    push_to_stack(a, pop_from_stack(b));  
    if (flag)
        ft_printf("pa\n"); 
}

void sa(t_stack *a, int flag)
{
    int tmp;

    if (a->top <= 0)
        return ;
    tmp = a->arr[a->top];
    a->arr[a->top] = a->arr[a->top - 1];
    a->arr[a->top - 1] = tmp;
    if (flag)
        ft_printf("sa\n");
}

void rra(t_stack *a, int flag)
{
    int i;
    int tmp;

    if (a->top <= 0)
        return ;
    tmp = a->arr[0];
    i = 0;
    while (i < a->top)
    {
        a->arr[i] = a->arr[i + 1];
        i++;
    }
    a->arr[a->top] = tmp;
    if (flag)
        ft_printf("rra\n");
}

void ra(t_stack *a, int flag)
{
    int i;
    int tmp;

    if (a->top <= 0)
        return;
    tmp = a->arr[a->top];
    for (i = a->top; i > 0; i--)
        a->arr[i] = a->arr[i - 1];
    a->arr[0] = tmp;
    if (flag)
        ft_printf("ra\n");
}

void rrb(t_stack *a, int flag)
{
    int i;
    int tmp;

    if (a->top <= 0)
        return ;
    tmp = a->arr[0];
    i = 0;
    while (i < a->top)
    {
        a->arr[i] = a->arr[i + 1];
        i++;
    }
    a->arr[a->top] = tmp;
    if (flag)
        ft_printf("rrb\n");
}

void rb(t_stack *a, int flag)
{
    int i;
    int tmp;

    if (a->top <= 0)
        return;
    tmp = a->arr[a->top];
    for (i = a->top; i > 0; i--)
        a->arr[i] = a->arr[i - 1];
    a->arr[0] = tmp;
    if (flag)
        ft_printf("rb\n");
}

void sb(t_stack *a, int flag)
{
    int tmp;

    if (a->top <= 0)
        return ;
    tmp = a->arr[a->top];
    a->arr[a->top] = a->arr[a->top - 1];
    a->arr[a->top - 1] = tmp;
    if (flag)
        ft_printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    sa(a, 0);
    sb(b, 0);
    ft_printf("ss\n");
}

void rr(t_stack *a, t_stack *b)
{
    ra(a, 0);
    rb(b, 0);
    ft_printf("rr\n");
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a, 0);
    rrb(b, 0);
    ft_printf("rrr\n");
}

