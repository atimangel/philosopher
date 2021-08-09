/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:41 by snpark            #+#    #+#             */
/*   Updated: 2021/08/08 15:04:27 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_table(t_condition *condition)
{
	int	i;

	i = 0;
	while (i < condition->number)
		pthread_mutex_destroy(condition->m_fork + i++);
	pthread_mutex_destroy(condition->mic);
	pthread_mutex_destroy(condition->mouth);
	free(condition->fork);
	free(condition->m_fork);
	free(condition->mic);
	free(condition->mouth);
	free(condition->philo);
}
