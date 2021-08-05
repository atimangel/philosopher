/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:14:06 by snpark            #+#    #+#             */
/*   Updated: 2021/08/05 12:26:23 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_message(t_philo *philo, char flag)
{
	int		id;
	long long	start;

	id = philo->id;
	start = philo->condition->start_time;
	if (flag == 0)
		printf("%d	%d philo has taken a fork\n",
			timestamp(start), id);
	else if (flag == 1)
		printf("%d	%d philo is eating\n",
			timestamp(start), id);
	else if (flag == 2)
		printf("%d	%d philo is sleeping\n",
			timestamp(start), id);
	else if (flag == 3)
		printf("%d	%d philo is thinking\n",
			timestamp(start), id);
}
