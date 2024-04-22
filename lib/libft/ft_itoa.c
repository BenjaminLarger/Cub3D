/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:55:10 by demre             #+#    #+#             */
/*   Updated: 2023/12/03 13:25:06 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num >= 1)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static long	check_neg(long num, int *is_neg)
{
	if (num < 0)
	{
		*is_neg = 1;
		return (-num);
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		n_length;
	int		is_neg;
	long	num;

	num = n;
	n_length = get_digits(num);
	string = (char *)malloc((n_length + 1) * sizeof(char));
	if (!string)
		return (NULL);
	is_neg = 0;
	num = check_neg(num, &is_neg);
	string[n_length] = '\0';
	n_length--;
	while (n_length >= 0)
	{
		if (n_length == 0 && is_neg == 1)
			string[0] = '-';
		else
			string[n_length] = (num % 10) + '0';
		num = num / 10;
		n_length--;
	}
	return (string);
}

/*
#include <stdio.h>
int main()
{
	printf("(-15): %s\n", ft_itoa(-15));
	printf("(-623): %s\n", ft_itoa(-623));
	printf("(156): %s\n", ft_itoa(156));
	printf("(2147483647): %s\n", ft_itoa(2147483647));
	printf("(-2147483648): %s\n", ft_itoa(-2147483648));
	printf("(0): %s\n", ft_itoa(0));
	printf("(-0): %s\n", ft_itoa(-0));
 	return 0;
}
*/