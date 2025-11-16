/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:48:43 by obahya            #+#    #+#             */
/*   Updated: 2025/07/24 19:48:48 by obahya           ###   ########.fr       */
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
	while (pos != -1)
	{
		resulte = (resulte * b) + pos;
		str++;
		pos = char_in_str(*str, base);
	}
	return (resulte * signe);
}

int	ft_atoi_base(char *str, char *base)
{
	int	signe;

	if (!base_check(base) || !*str)
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
