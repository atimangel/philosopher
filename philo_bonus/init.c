/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:29:10 by snpark            #+#    #+#             */
/*   Updated: 2021/09/16 14:04:25 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_fork(t_condition *condition)
{
	int	n;

	n = condition->number;
	if (n != 1)
		n >>= 1;
	sem_unlink("left_fork");
	condition->l_fork = sem_open("left_fork", O_CREAT, 0644, n);
	if (condition->l_fork == SEM_FAILED)
		return (1);
	if (condition->number == 1)
		--n;
	else if (condition->number & 1)
		++n;
	sem_unlink("right_fork");
	condition->r_fork = sem_open("right_fork", O_CREAT, 0644, n);
	if (condition->r_fork == SEM_FAILED)
		return (1);
	sem_unlink("stop");
	condition->stop = sem_open("stop", O_CREAT, 0644, 1);
	if (condition->stop == SEM_FAILED)
		return (1);
	return (0);
}

int	start_dinner(t_condition *condition)
{
	condition->id = 0;
	condition->start_time = gettime();
	condition->start_eat = condition->start_time;
	while (++condition->id <= condition->number)
	{
		condition->philos[condition->id - 1] = fork();
		if (condition->philos[condition->id - 1] < 0)
			exit(0);
		else if (condition->philos[condition->id - 1] == 0)
		{
			routine(condition);
			exit(1);
		}
	}
	return (0);
}

void	clean_table(t_condition *condition)
{
	int	check;
	int	number_philos;

	number_philos = 0;
	while (++number_philos <= condition->number)
	{
		waitpid(-1, &check, 0);
		if (check != 0)
		{
			condition->id = -1;
			while (++condition->id < condition->number)
				kill(condition->philos[condition->id], SIGKILL);
		}
	}
}

int	set_table(t_condition *condition)
{
	if (set_fork(condition))
		return (1);
	condition->philos = malloc(sizeof(pid_t *) * condition->number);
	if (condition->philos == NULL)
		return (1);
	if (start_dinner(condition))
		return (1);
	clean_table(condition);
	return (0);
}
