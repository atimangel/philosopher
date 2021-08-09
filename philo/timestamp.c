/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:25:26 by snpark            #+#    #+#             */
/*   Updated: 2021/08/08 13:43:42 by snpark           ###   ########.fr       */
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

int	timestamp(long long start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error: can't get time od day\n");
		return (-1);
	}
	return ((time.tv_sec * 1000000L + time.tv_usec - start) / 1000);
}

void	ft_usleep(int time)
{
	long long	end;

	end = gettime() + time - 1;
	while (end > gettime())
		;
}
