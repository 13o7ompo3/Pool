/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:13:48 by obahya            #+#    #+#             */
/*   Updated: 2025/07/30 19:13:52 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str);

int	base_check(char *base)
{
	int	i;
	int	j;

	if (!base || !*base || str_len(base) < 2)
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

int	ft_atoi_base(char *str, char *base);

char	*ft_number_base(long nb, char *base_to, int s, long b)
{
	long	div;
	int		i;
	char	*ptr;

	div = 1;
	i = 0;
	while ((nb / div) >= b)
	{
		div *= b;
		i++;
	}
	ptr = (char *)malloc(sizeof(char) * (i + s + 1));
	if (!ptr)
		return (NULL);
	ptr[i + s] = '\0';
	i = 0;
	if (s == 1)
		ptr[i++] = '-';
	while (div != 0)
	{
		ptr[i++] = base_to[(nb / div) % b];
		div /= b;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	int		b;
	int		s;

	if (!base_check(base_from) || !base_check(base_to)
		|| !nbr)
		return (0);
	b = str_len(base_to);
	nb = (long)ft_atoi_base(nbr, base_from);
	s = 0;
	if (nb < 0)
	{
		s = 1;
		nb *= -1;
	}
	return (ft_number_base(nb, base_to, s, (long)b));
}
