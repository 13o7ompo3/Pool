/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:15:41 by obahya            #+#    #+#             */
/*   Updated: 2025/08/03 22:15:43 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	unsigned int	div;
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	div = 1;
	while ((nb / div) >= 10)
		div *= 10;
	while (div != 0)
	{
		ft_putchar(((nb / div) % 10) + '0');
		div /= 10;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putnbr(par->size);
		ft_putstr(par->copy);
		par++;
	}
}
