/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:30:16 by obahya            #+#    #+#             */
/*   Updated: 2025/07/26 15:30:19 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
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
