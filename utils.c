/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:14:04 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/14 14:43:02 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_array(int *arr, int size) {
    int i;
    int j;

    i = 0;
    while (i < size - 1) {
        j = 0;
        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }

        i++;
    }
}

int *clone_array(int *arr, int size)
{
    int *new_arr;
    int i;

    new_arr = (int *)malloc(size * sizeof(int));
    if (!new_arr)
        return NULL;
    i = 0;
    while (i < size)
    {
        new_arr[i] = arr[i];
        i++;
    }
    return new_arr;
}

int index_of(int *arr, int size, int item)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == item)
            return i;
        i++;
    }
    return -1;
}

int ft_min(int *a, int size)
{
    int i;
    int min;

    if (!a)
        return -1;
    if (size == 1)
        return a[0];
    min = a[0];
    i = 1;
    while (i < size)
    {
        if (a[i] < min)
            min = a[i];
        i++;
    }
    return min;
}

int ft_max(int *a, int size)
{
    int i;
    int max;

    if (!a)
        return -1;
    if (size == 1)
        return a[0];
    max = a[0];
    i = 1;
    while (i < size)
    {
        if (a[i] > max)
            max = a[i];
        i++;
    }
    return max;    
}

int ft_abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}