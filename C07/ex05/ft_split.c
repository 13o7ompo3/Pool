/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:12:28 by obahya            #+#    #+#             */
/*   Updated: 2025/08/02 20:12:30 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_in_set(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	word_count(char *str, char *sep)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 1;
	while (str[i])
	{
		if (!char_in_set(str[i], sep))
		{
			if (word == 1)
				count++;
			word = 0;
		}
		else
			word = 1;
		i++;
	}
	return (count);
}

int	g_strlen;

char	*ft_strdup(char *str, int *index, char *charset)
{
	char	*word;
	int		i;

	g_strlen = 0;
	i = *index;
	while (char_in_set(str[i], charset))
		i++;
	*index = i;
	while (str[i] && !char_in_set(str[i], charset))
	{
		i++;
		g_strlen++;
	}
	word = malloc(sizeof(char) * (g_strlen + 1));
	if (!word)
		return (NULL);
	word[g_strlen] = '\0';
	i = 0;
	while (str[*index] && !char_in_set(str[*index], charset))
	{
		word[i] = str[*index];
		i++;
		(*index)++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr;
	int		j;
	int		len;
	int		i;

	i = 0;
	j = 0;
	len = word_count(str, charset);
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	while (i < len)
	{
		ptr[i] = ft_strdup(str, &j, charset);
		i++;
	}
	return (ptr);
}
