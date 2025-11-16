/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:22:42 by obahya            #+#    #+#             */
/*   Updated: 2025/07/25 21:22:45 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power == 0 || nb == 1)
		return (1);
	if (power < 0)
		return (0);
	result = nb;
	while (--power)
		result *= nb;
	return (result);
}
