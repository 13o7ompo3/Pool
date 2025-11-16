/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:00:38 by obahya            #+#    #+#             */
/*   Updated: 2025/11/16 21:36:38 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	if (str_len(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;
	int	div;

	if (!base_check(base))
		return ;
	b = str_len(base);
//	if (nbr == -2147483648) i have no idea what i was doing
//	{
//		write(1, "-2147483648", 11);
//		return ;
//	}
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	div = 1;
	while ((nbr / div) >= b)
		div *= b;
	while (div > 0)
	{
		ft_putchar(base[(nbr / div) % b]);
		div /= b;
	}
}
