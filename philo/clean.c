/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:41 by snpark            #+#    #+#             */
/*   Updated: 2021/08/09 10:57:22 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_table(t_condition *condition)
{
	int	i;

	i = 0;
	while (i < condition->number)
	{
		if (pthread_mutex_destroy(condition->m_fork + i++))
			return (exit_error("Error: mutex destroy fail fork\n"));
	}
	if (pthread_mutex_destroy(condition->mic))
		return (exit_error("Error: mutex destroy fail mic\n"));
	if (pthread_mutex_destroy(condition->mouth))
		return (exit_error("Error: mutex destroy fail mouth\n"));
	free(condition->fork);
	free(condition->m_fork);
	free(condition->mic);
	free(condition->mouth);
	free(condition->philo);
	return (0);
}
