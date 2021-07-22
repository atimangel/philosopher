/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:01:36 by snpark            #+#    #+#             */
/*   Updated: 2021/07/22 13:55:56 by snpark           ###   ########.fr       */
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
	return (0);
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
	int	number;
	int	negative;

	i = 0;
	number = 0;
	while (ft_isspace(string[i]))
		i++;
	negative = ft_ispm(string[i]);
	if (negative != 0)
		i++;
	while (ft_isdigit(string[i]))
	{
		number *= 10;
		number += string[i] - '0';
		if (negative != -1 && (unsigned int)number > 2147483647)
			return (-1);
		if (negative == -1 && (unsigned int)number > 2147483648)
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

	number = ft_atoi(string);
	under_dot = 0;
	while (ft_isspace(*string))
		string++;
	pm = ft_ispm(*string);
	if (pm)
		string++;
	while (ft_isdigit(*string))
		string++;
	if (*string == '.' && ft_isdigit(string[1]))
		under_dot = ft_atoi(++string);
	while (under_dot >= 1.0)
		under_dot /= 10;
	while (*(string++) == '0')
		under_dot /= 10;
	if (pm == -1)
		number -= under_dot;
	else
		number += under_dot;
	return (number);
}
