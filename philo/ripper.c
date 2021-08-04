/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:00 by snpark            #+#    #+#             */
/*   Updated: 2021/08/04 21:49:03 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ripper(void *arg)
{
	t_philo	*philo;
	t_condition	*condition;
	int	i;

	condition = (t_condition *)arg;
	philo = condition->philo;
	i = 0;
	while(!condition->stop)
	{
		if (i == condition->number)
			i = 0;
		if (is_dead(philo + i) < 0)
			condition->stop++;
			//mutex가 있으면 좋겠다.
		i++;
	}
}
