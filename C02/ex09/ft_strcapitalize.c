/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:47:11 by obahya            #+#    #+#             */
/*   Updated: 2025/07/23 17:43:40 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	first_alpha_in_word(char a, char b)
{
	if (!('0' <= a && a <= '9')
		&& !('a' <= a && a <= 'z')
		&& !('A' <= a && a <= 'Z')
		&& ('a' <= b && b <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	while (str[i])
	{
		if (first_alpha_in_word(str[i - 1], str[i]))
			str[i] -= 32;
		else if ((('a' <= str[i - 1] && str[i - 1] <= 'z')
				|| ('A' <= str[i - 1] && str[i - 1] <= 'Z')
				|| ('0' <= str[i - 1] && str[i - 1] <= '9'))
			&& ('A' <= str[i] && str[i] <= 'Z'))
			str[i] += 32;
		i++;
	}
	return (str);
}
