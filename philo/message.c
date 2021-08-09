/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:14:06 by snpark            #+#    #+#             */
/*   Updated: 2021/08/07 16:43:00 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_message(t_philo *philo, char flag)
{
	int			id;
	long long	start;

	id = philo->id;
	start = philo->condition->start_time;
	pthread_mutex_lock(philo->condition->mic);
	if (flag == 0)
		printf("%d	%d has taken a fork\n",
			timestamp(start), id);
	else if (flag == 1)
		printf("%d	%d is eating\n",
			timestamp(start), id);
	else if (flag == 2)
		printf("%d	%d is sleeping\n",
			timestamp(start), id);
	else if (flag == 3)
		printf("%d	%d is thinking\n",
			timestamp(start), id);
	else if (flag == 4)
		printf("%d	%d died\n",
			timestamp(start), id);
	pthread_mutex_unlock(philo->condition->mic);
}
