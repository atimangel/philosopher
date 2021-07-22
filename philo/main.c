/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:30:39 by snpark            #+#    #+#             */
/*   Updated: 2021/07/22 16:54:17 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse(t_philo *condition, int arg_n, char **arg_s)
{
	if (arg_n < 5)
		printf("Error\nargmuant is not enough\n");
	if (arg_n >= 5)
	{
		condition->number = ft_atoi(arg_s[1]);
		condition->death = ft_atoi(arg_s[2]);
		condition->eat = ft_atoi(arg_s[3]);
		condition->sleep = ft_atoi(arg_s[4]);
		condition->need = -1;
	}
	if (arg_n == 6)
		condition->need = ft_atoi(arg_s[5]);
	if (arg_n > 6)
		printf("Error\nargumant is too much\n");
	if (arg_n < 5 || arg_n > 6)
		return (0);
	if (condition->number <= 0 || condition->death <= 0 ||
		condition->eat <= 0 || condition->sleep <= 0 ||
		(arg_n == 6 && condition->need <= 0))
	{
		printf("Error\nargumant should over than 0 or num\n");
		return (0);
	}
	return (1);
}

int	main(int arg_n, char **arg_s)
{	
	t_philo	condition;

	if (!parse(&condition, arg_n, arg_s))
		return (0);

}
