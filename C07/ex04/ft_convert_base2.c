/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:14:01 by obahya            #+#    #+#             */
/*   Updated: 2025/07/30 19:14:03 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base);

int	char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_number(char *str, char *base, int signe)
{
	int	pos;
	int	b;
	int	resulte;

	b = str_len(base);
	pos = char_in_str(*str, base);
	resulte = 0;
	while (*str && pos != -1)
	{
		resulte = (resulte * b) + (signe * pos);
		str++;
		pos = char_in_str(*str, base);
	}
	return (resulte);
}

int	ft_atoi_base(char *str, char *base)
{
	int	signe;

	if (!base_check(base) || !str || !*str)
		return (0);
	while (*str == ' '
		|| (7 <= *str && *str <= 13))
		str++;
	signe = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	return (ft_number(str, base, signe));
}
