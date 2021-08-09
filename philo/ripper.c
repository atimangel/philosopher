/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:00 by snpark            #+#    #+#             */
/*   Updated: 2021/08/09 11:54:30 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ripper(t_condition *condition, t_philo *philo)
{
	int			i;

	while (!condition->stop)
	{
		i = 0;
		while (i < condition->number)
		{
			pthread_mutex_lock(condition->mouth);
			if (is_dead(condition->philo + i++) < 0)
			{
				condition->stop++;
				pthread_mutex_unlock(condition->mouth);
				break ;
			}
			pthread_mutex_unlock(condition->mouth);
			usleep(9000 / condition->number);
		}
		i = 0;
		while (condition->need > 0 && i < condition->number
			&& philo[i].spaghetti >= condition->need)
			i++;
		if (i && i == condition->number)
			condition->stop++;
	}
}
