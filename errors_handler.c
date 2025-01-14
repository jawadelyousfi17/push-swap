#include "push_swap.h"

void custom_exit(char *s)
{
    ft_putstr_fd(s, STDERR_FILENO);
    exit(EXIT_FAILURE);
}

void custom_exit_clean(char *s)
{
    ft_putstr_fd(s, STDERR_FILENO);
    exit(EXIT_FAILURE);   
}