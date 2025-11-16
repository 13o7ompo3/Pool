/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:08:50 by obahya            #+#    #+#             */
/*   Updated: 2025/07/23 00:12:37 by obahya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_addr(unsigned long addr)
{
	int	i;
	char		out[17];
	char		*hex;

	i = 15;
	hex = "0123456789abcdef";
	while (0 <= i)
	{
		out[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	i = 0;
	while (i < 16)
	{
		ft_putchar(out[i]);
		i++;
	}
	write(1, ": ", 2);
}

void	put_hex(unsigned char a)
{
	char	*string;

	string = "0123456789abcdef";
	ft_putchar(string[a / 16]);
	ft_putchar(string[a % 16]);
}

void	put_line(unsigned char *addr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			put_hex(addr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
	j = 0;
	while (j < 16 && i + j < size)
	{
		if (!(addr[i + j] > 31 && addr[i + j] < 127))
			ft_putchar('.');
		else
			ft_putchar(addr[i + j]);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*addr0;

	i = 0;
	addr0 = (unsigned char *) addr;
	while (i < size)
	{
		put_addr((unsigned long)(addr0) + i);
		put_line(addr0, i, size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
