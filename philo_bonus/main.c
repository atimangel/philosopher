/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:30:39 by snpark            #+#    #+#             */
/*   Updated: 2021/08/09 11:55:32 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse(t_condition *condition, int arg_n, char **arg_s)
{
	if (arg_n < 5)
		printf("Error\nargmuant is not enough\n");
	if (arg_n >= 5)
	{
		condition->number = ft_atoi(arg_s[1]);
		condition->death = ft_atoi(arg_s[2]) * 1000;
		condition->eat = ft_atoi(arg_s[3]) * 1000;
		condition->sleep = ft_atoi(arg_s[4]) * 1000;
		condition->spaghetti = -1;
	}
	if (arg_n == 6)
		condition->spaghetti = ft_atoi(arg_s[5]);
	if (arg_n > 6)
		printf("Error\nargumant is too much\n");
	if (arg_n < 5 || arg_n > 6)
		return (1);
	if (condition->number <= 0 || condition->death <= 0
		|| condition->eat <= 0 || condition->sleep <= 0
		|| (arg_n == 6 && condition->spaghetti <= 0))
	{
		printf("Error\nargumant should over than 0 or number\n");
		return (1);
	}
	return (0);
}

int	main(int arg_n, char **arg_s)
{	
	t_condition	condition;

	if (parse(&condition, arg_n, arg_s))
		return (1);
	printf("%d %d %d %d\n", condition.number, condition.death, condition.eat, condition.sleep);
	if (set_table(&condition))
		return (1);
	return (0);
}
