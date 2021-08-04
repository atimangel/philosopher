/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:25:26 by snpark            #+#    #+#             */
/*   Updated: 2021/08/04 20:26:09 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error: can't get time of day\n");
		return (-1);
	}
	return(time.tv_sec * 1000000L + time.tv_usec);
}

int		timestamp(long long start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error: can't get time od day\n");
		return (-1);
	}
	return((time.tv_sec * 1000000L + time.tv_usec - start) / 1000);
}

void	ft_usleep(int time)
{
	struct timeval time_buf;
	long	start;
	long	check;

	time--;
	gettimeofday(&time_buf, NULL);
	start = time_buf.tv_sec * 1000000 + time_buf.tv_usec;
	check = start;
	while (time >= check - start)
	{
		gettimeofday(&time_buf, NULL);
		check = time_buf.tv_sec * 1000000 + time_buf.tv_usec;
	}
}
