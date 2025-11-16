/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:08:47 by obahya            #+#    #+#             */
/*   Updated: 2025/07/26 17:08:50 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	k;

	k = 1;
	while (k * k < nb)
		k++;
	return (k);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb == 0 || nb == 1
		|| nb == -1 || nb == -2147483648)
		return (0);
	if (nb < 0)
		nb *= -1;
	if (nb == 2)
		return (1);
	sqrt = ft_sqrt(nb);
	i = 2;
	while (i <= sqrt)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
