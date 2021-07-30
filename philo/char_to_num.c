/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:01:36 by snpark            #+#    #+#             */
/*   Updated: 2021/07/29 09:03:13 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static	int	ft_ispm(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	return (1);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *string)
{
	int	i;
	long	number;
	int	negative;

	i = 0;
	number = 0;
	while (ft_isspace(string[i]))
		i++;
	negative = ft_ispm(string[i]);
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (ft_isdigit(string[i]))
	{
		number *= 10;
		number += string[i] - '0';
		if (negative != -1 && number > 2147483647)
			return (-1);
		if (negative == -1 && number > 2147483648)
			return (0);
		i++;
	}
	if (negative == -1)
		number *= -1;
	return (number);
}

float	ft_atof(const char *string)
{
	float	number;
	float	under_dot;
	int		pm;

	number = 0;
	under_dot = 1;
	while (ft_isspace(*string))
		string++;
	pm = ft_ispm(*string);
	if (pm)
		string++;
	while (ft_isdigit(*string))
		number = number * 10 + *string++ - '0';
	if (*string == '.')
		string++;
	while (ft_isdigit(*string))
	{
		under_dot = under_dot * 0.1;
		number += pm * under_dot * (*string++ - '0');
	}
	return (number);
}
