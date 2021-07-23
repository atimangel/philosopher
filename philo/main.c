/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:30:39 by snpark            #+#    #+#             */
/*   Updated: 2021/07/23 20:21:58 by snpark           ###   ########.fr       */
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

void	*who_are_you(void *data)
{
	t_philo	philo;
	t_condition condition;

	philo = *(t_philo *)data;
	condition = *(t_condition *)philo.condition;
	printf("I AM %d PHILOSOPHER dath time%d\n", philo.id, condition.death);
}

int	dinner_time(t_condition condition)
{
	int	i;
	int	stat;
	pthread_t	*philosopher;
	t_philo	*status;

	i = 0;
	stat = 0;
	philosopher = malloc(sizeof(pthread_t) * condition.number);
	if (!philosopher)
		return (0);
	status = malloc(sizeof(t_philo) * condition.number);
	if (!status)
		return (0);
	while (i < condition.number)
	{
		status[i].id = i + 1;
		status[i].condition = &condition;
		stat = pthread_create(philosopher + i, NULL, who_are_you, (void *)(status + i));
		i++;
	}
	i = 0;
	while (i < condition.number)
	{
		pthread_join(philosopher[i], NULL);
		i++;
	}
	free(philosopher);
	free(status);
}

int	main(int arg_n, char **arg_s)
{	
	t_condition	condition;

	if (!parse(&condition, arg_n, arg_s))
		return (0);
	dinner_time(condition);
}
