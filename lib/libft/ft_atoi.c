/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:24:40 by demre             #+#    #+#             */
/*   Updated: 2023/11/30 19:47:46 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power_of_10(int n)
{
	int	num;
	int	count;

	num = 1;
	count = 0;
	while (count < n)
	{
		num = num * 10;
		count++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;
	int	start;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	res = 0;
	while (start < i)
	{
		res += (str[start] - '0') * ft_power_of_10(i - start - 1);
		start++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *numbers = "123";
	char *minus = "-123";
	char *plus = "+123";
	char *spaces = "  	\n 	123";
	char *letters = "12k3";
	char *minuses = "--123";
	char *pluses = "++123";
	char *empty = "";
	char *other = "gg";
	printf("%d | %d\n", atoi(numbers), ft_atoi(numbers));
	printf("%d | %d\n", atoi(minus), ft_atoi(minus));
	printf("%d | %d\n", atoi(plus), ft_atoi(plus));
	printf("%d | %d\n", atoi(spaces), ft_atoi(spaces));
	printf("%d | %d\n", atoi(letters), ft_atoi(letters));
	printf("%d | %d\n", atoi(minuses), ft_atoi(minuses));
	printf("%d | %d\n", atoi(pluses), ft_atoi(pluses));
	printf("%d | %d\n", atoi(empty), ft_atoi(empty));
	printf("%d | %d\n", atoi(other), ft_atoi(other));
	return 0;
}
*/