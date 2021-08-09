/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:00 by snpark            #+#    #+#             */
/*   Updated: 2021/08/09 09:51:33 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ripper(void *arg)
{
	t_philo		*philo;
	t_condition	*condition;
	int			i;

	condition = (t_condition *)arg;
	philo = condition->philo;
	while (!condition->stop)
	{
		i = 0;
		while (i < condition->number)
		{
			pthread_mutex_lock(condition->mouth);
			if (is_dead(philo + i++) < 0)
				break ;
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
	condition->stop++;
}
