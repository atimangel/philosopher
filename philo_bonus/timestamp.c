/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:25:26 by snpark            #+#    #+#             */
/*   Updated: 2021/09/16 13:50:17 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error: can't get time of day\n");
		return (-1);
	}
	return (time.tv_sec * 1000000L + time.tv_usec);
}

int	timestamp(const long long start)
{
	return ((gettime() - start) / 1000);
}

void	ft_usleep(const long long deadline)
{
	while (gettime() <= deadline)
		usleep(32);
}
