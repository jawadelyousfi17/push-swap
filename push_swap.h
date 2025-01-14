/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:46:14 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/14 19:09:08 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
#include <limits.h>

#define SA 1
#define SB 2
#define RA 3
#define RB 4
#define RRA 5
#define RRB 6
#define RR 7
#define RRR 8
#define SS 9
#define PA 10
#define PB 11

#define UP 1
#define DOWN -1

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	top;
	int length;
} t_stack;

#define INT_MAX_LENGTH 11

void	init_stack(t_stack *stack, int size);
void	push_to_stack(t_stack *stack, int element);
int		pop_from_stack(t_stack *stack);
int		get_top_from_stack(t_stack *stack);

int		check_valid_args(char **av);
void	initialize_stack_a(t_stack *stack, int ac, char **av);
int		check_duplicate(t_stack *stack);

char	**parse_args(int ac, char **av);

void	custom_exit(char *s);
void	custom_exit_clean(char *s);

char	**free_matrix(char **grid);

void	pb(t_stack *a, t_stack *b, int flag);
void	pa(t_stack *a, t_stack *b, int flag);
void	sa(t_stack *a, int flag);
void	rra(t_stack *a, int flag);
void	ra(t_stack *a, int flag);
void	rrb(t_stack *a, int flag);
void	rb(t_stack *a, int flag);
void	sb(t_stack *a, int flag);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void sort_array(int *arr, int size);
int *clone_array(int *arr, int size);
int index_of(int *arr, int size, int item);
int ft_min(int *a, int size);
int ft_max(int *a, int size);
int ft_abs(int a);

#endif