/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:04:44 by obahya            #+#    #+#             */
/*   Updated: 2025/08/03 20:04:45 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			strlen;
	t_stock_str	*ptr;
	t_stock_str	*ptr0;

	ptr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ptr)
		return (NULL);
	ptr0 = ptr;
	i = 0;
	while (i < ac)
	{
		strlen = ft_strlen(av[i]);
		ptr->size = strlen;
		ptr->str = av[i];
		ptr->copy = (char *)malloc(sizeof(char) * (strlen + 1));
		if (!ptr->copy)
			ptr->copy = NULL;
		ft_strcpy(ptr->copy, av[i]);
		i++;
		ptr++;
	}
	ptr->str = 0;
	return (ptr0);
}
