/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:02:00 by obahya            #+#    #+#             */
/*   Updated: 2025/07/17 09:27:36 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	nb0;
	int	div;

	nb0 = nb;
	div = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while ((nb0 / 10) != 0)
	{
		nb0 /= 10;
		div *= 10;
	}
	while (div != 0)
	{
		ft_putchar(((nb / div) % 10) + 48);
		div /= 10;
	}
}
