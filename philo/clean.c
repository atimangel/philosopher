/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:41 by snpark            #+#    #+#             */
/*   Updated: 2021/08/04 21:49:43 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		clean_table(t_condition *condition)
{
	int	i;

	i = 0;
	while (i < condition->number)
	{
		pthread_mutex_destroy(condition->fork + i++);
		printf("wash %i fork\n", i);
	}
	pthread_mutex_destroy(condition->mic);
	printf("turn off MIC\n");
	free(condition->fork);
	free(condition->mic);
	free(condition->philo);
}
