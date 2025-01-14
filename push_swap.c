/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:49:12 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/14 22:29:23 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_stack(t_stack stack)
{
    int i = stack.top;
    if (stack.top == -1)
        ft_printf("Stack is empty \n");
    while (i >= 0)
    {
        ft_printf("%d\n", stack.arr[i]);
        i--;
    }
    ft_printf("\n");
}

void init_stacks_a_b(t_stack *a, t_stack *b, char **str, int size)
{
    init_stack(a, size);
    if (!a->arr)
    {
        free_matrix(str);
        custom_exit("ERROR\n");
    }
    initialize_stack_a(a, size, str);
    if (!check_duplicate(a))
    {
        free(a->arr);
        free_matrix(str);
        custom_exit("ERROR DIPLUCATION\n");
    }
    init_stack(b, size);
    if (!b->arr)
    {
        free_matrix(str);
        free(a->arr);
        custom_exit("ERROR\n");
    }
}

int get_move_index(t_stack *stack, int index)
{
    if (index <= stack->length / 2)
        return index + 1;
    return stack->length - index - 1;
}

int is_sorted(t_stack *a)
{
    int i = 0;

    return 1;
    // if (a->top == -1)
    //     return 0;
    // while (/* condition */)
    // {
    //     /* code */
    // }
}

void sort(t_stack *a, t_stack *b)
{
    int i = 0;
    int i_hold;

    i_hold = 0;
    while (i <= a->top)
    {
        if (a->arr[i_hold] > a->arr[i])
            i_hold = i;
        i++;
    }
    i = 0;
    while (i < a->top - i_hold)
    {
        ra(a, 1);
        i++;
    }
    if (i_hold > a->top / 2)
        while (i < a->top - i_hold)
        {
            ra(a, 1);
            i++;
        }
    else
        while (i < a->top - i_hold)
        {
            rra(a, 1);
            i++;
        }

    pb(a, b, 1);

    // ft_printf("\n%d\n", a->arr[i_hold]);
}

void duplicate_and_sort(t_stack *stack)
{
    int *duplicate;
    int i;
    int size;

    size = stack->size;
    duplicate = clone_array(stack->arr, stack->size);
    if (!duplicate)
    {
        free(stack->arr);
        return;
    }
    sort_array(duplicate, stack->size);
    i = 0;
    while (i < size)
    {
        stack->arr[i] = index_of(duplicate, size, stack->arr[i]);
        i++;
    }
    free(duplicate);
}

int get_terget_index(t_stack *b, int item)
{
    int max;
    int i;
    int closetNumber;

    i = 0;
    closetNumber = -1;
    max = ft_max(b->arr, b->length);
    if (item < ft_min(b->arr, b->length) || item > max)
        return index_of(b->arr, b->length, max);
    while (i < b->length && closetNumber == -1)
    {
        if (b->arr[i] < item)
            closetNumber = b->arr[i];
        i++;
    }
    while (i < b->length)
    {
        int e = b->arr[i];
        if (e < item && ft_abs(e - item) < ft_abs(closetNumber - item))
            closetNumber = e;
        i++;
    }
    return index_of(b->arr, b->length, closetNumber);
}

int get_terget_index_inverted(t_stack *b, int item)
{
    int max;
    int i;
    int closetNumber;

    i = 0;
    closetNumber = -1;
    max = ft_max(b->arr, b->length);
    if (item > ft_max(b->arr, b->length) || item > max)
        return index_of(b->arr, b->length, max);
    while (i < b->length && closetNumber == -1)
    {
        if (b->arr[i] > item)
            closetNumber = b->arr[i];
        i++;
    }
    while (i < b->length)
    {
        int e = b->arr[i];
        if (e > item && ft_abs(e - item) < ft_abs(closetNumber - item))
            closetNumber = e;
        i++;
    }
    return index_of(b->arr, b->length, closetNumber);
}
void bring_top_top_b(t_stack *stack, int target_index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(stack, target_index);
    if (target_index <= stack->length / 2)
        instruction = RRB;
    else
        instruction = RB;
    i = 0;
    while (i < moves_count)
    {
        if (instruction == RB)
            rb(stack, 1);
        if (instruction == RRB)
            rrb(stack, 1);
        i++;
    }
}

void bring_top_top_a(t_stack *stack, int target_index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(stack, target_index);
    if (target_index <= stack->length / 2)
        instruction = RRA;
    else
        instruction = RA;
    i = 0;
    while (i < moves_count)
    {
        if (instruction == RA)
            ra(stack, 1);
        if (instruction == RRA)
            rra(stack, 1);
        i++;
    }
}
int get_move_direction(t_stack *stack, int index)
{
    if (index <= stack->length / 2)
        return UP;
    return DOWN;
}
int calcul_cost(t_stack *a, t_stack *b, int a_index)
{
    int a_cost;
    int b_cost;
    int a_move_direction;
    int b_move_direction;

    a_move_direction = get_move_direction(a, a_index);
    b_move_direction = get_move_direction(b, get_terget_index(b, a->arr[a_index]));
    a_cost = get_move_index(a, a_index);
    b_cost = get_move_index(b, get_terget_index(b, a->arr[a_index]));
    if (a_move_direction == b_move_direction)
        return a_cost > b_cost ? a_cost : b_cost;
    return a_cost + b_cost;
}

int get_cheapest_index(t_stack *a, t_stack *b)
{
    int cheapest_move_index;
    int cost;
    int temp_cost;
    int i;

    i = 1;
    cheapest_move_index = 0;
    cost = calcul_cost(a, b, 0);
    while (i < a->length)
    {
        temp_cost = calcul_cost(a, b, i);
        if (temp_cost < cost)
        {
            cost = temp_cost;
            cheapest_move_index = i;
        }
        i++;
    }
    return cheapest_move_index;
}

void push_b_if_smaller(t_stack *a, t_stack *b)
{
    int i;

    i = 0;
    while (i < a->length && b->length < 2)
    {
        if (a->arr[i] < a->size - 3)
        {
            bring_top_top_a(a, i);
            pb(a, b, 1);
        }
        i++;
    }
}

void init_instructions_stack(t_stack *inst, int size)
{
    inst->arr = malloc(size * sizeof(int));
    inst->size = size;
    inst->top = -1;
    inst->length = 0;
}

void how_to_top_a(t_stack *a, t_stack *inst, int index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(a, index);
    if (index <= a->length / 2)
        instruction = DOWN;
    else
        instruction = UP;
    i = 0;
    while (i < moves_count)
    {
        push_to_stack(inst, instruction);
        i++;
    }
}

void how_to_top_b(t_stack *a, t_stack *inst, int index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(a, index);
    if (index <= a->length / 2)
        instruction = DOWN;
    else
        instruction = UP;
    i = 0;
    while (i < moves_count)
    {
        push_to_stack(inst, instruction);
        i++;
    }
}

void display_array(t_stack *a)
{
    int i = 0;
    while (i < a->length)
    {
        ft_printf("%d ", a->arr[i++]);
    }
    ft_printf("\n");
}
void sort_stack_of_3(t_stack *stack)
{
    if (stack->length != 3)
        return;

    int a = stack->arr[2];
    int b = stack->arr[1];
    int c = stack->arr[0];

    if (a == ft_min(stack->arr, 3))
    {
        if (b > c)
        {
            rra(stack, 1);
            sa(stack, 1);
        }
        return ;
    }

    if (a == ft_max(stack->arr, 3))
    {
        ra(stack, 1);
        if (b > c)
            sa(stack, 1);
        return ;
    }
    if (b < c)
    {
        sa(stack, 1);
        return ;
    }
    rra(stack, 1);
}

void push_from_b_to_a(t_stack *a, t_stack *b)
{
}

int is_stack_sorted(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->length - 1)
    {
        if (a->arr[i] < a->arr[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char **av)
{
    int size;
    t_stack stack_a;
    t_stack stack_b;
    char **str;

    t_stack a_inst;
    t_stack b_inst;

    if (ac < 2)
        return (EXIT_FAILURE);
    str = parse_args(ac, av);
    if (!str)
        custom_exit("ERROR\n");
    size = check_valid_args(str);
    if (!size)
    {
        free_matrix(str);
        custom_exit("ERROR\n");
    }

    init_instructions_stack(&a_inst, size);
    init_instructions_stack(&b_inst, size);

    init_stacks_a_b(&stack_a, &stack_b, str, size);
    free_matrix(str);
    duplicate_and_sort(&stack_a);

    pb(&stack_a, &stack_b, 1);
    pb(&stack_a, &stack_b, 1);

    int jj = 0;
    while (stack_a.length > 3)
    {
        int cheapest_index = get_cheapest_index(&stack_a, &stack_b);
        int target_index = get_terget_index(&stack_b, stack_a.arr[cheapest_index]);
        a_inst.top = -1;
        a_inst.length = 0;
        b_inst.top = -1;
        b_inst.length = 0;

        how_to_top_a(&stack_a, &a_inst, cheapest_index);
        how_to_top_a(&stack_b, &b_inst, target_index);

        // display_array(&b_inst);
        // display_array(&a_inst);

        int i = 0;
        while (i < a_inst.length && i < b_inst.length)
        {
            if (a_inst.arr[i] == b_inst.arr[i])
            {
                if (a_inst.arr[i] == -1)
                    rrr(&stack_a, &stack_b);
                else if (a_inst.arr[i] == 1)
                    rr(&stack_a, &stack_b);
            }
            else
            {
                if (a_inst.arr[i] == -1)
                    rra(&stack_a, 1);
                else
                    ra(&stack_a, 1);
                if (b_inst.arr[i] == -1)
                    rrb(&stack_b, 1);
                else
                    rb(&stack_b, 1);
            }
            i++;
        }
        while (i < a_inst.length)
        {
            if (a_inst.arr[i] == -1)
                rra(&stack_a, 1);
            else
                ra(&stack_a, 1);
            i++;
        }
        while (i < b_inst.length)
        {
            if (b_inst.arr[i] == -1)
                rrb(&stack_b, 1);
            else
                rb(&stack_b, 1);
            i++;
        }
        pb(&stack_a, &stack_b, 1);
    }
    int max_index = index_of(stack_b.arr, stack_b.length, ft_max(stack_b.arr, stack_b.length));
    bring_top_top_b(&stack_b, max_index);
    int i = 0;
    size = stack_b.length;
    sort_stack_of_3(&stack_a);
    while (i < size)
    {
        if (stack_b.arr[stack_b.top] > ft_max(stack_a.arr, stack_a.length))
            pa(&stack_a, &stack_b, 1);
        else if (stack_a.arr[stack_a.top] == stack_b.arr[stack_b.top] + 1)
           { pa(&stack_a, &stack_b, 1);}
        else
        {
            int a = index_of(stack_a.arr, stack_a.size, stack_b.arr[stack_b.top] + 1);
            int k = 0;
            while (k < a + 1)
            {
                rra(&stack_a, 1);
                k++;
            }
            pa(&stack_a, &stack_b, 1);
        }
        i++;
    }
    
    while (!is_stack_sorted(&stack_a))
    {
        rra(&stack_a, 1);
    }
    
    // pa(&stack_a, &stack_b, 1);

    // display_stack(stack_a);
    // display_stack(stack_b);
}
