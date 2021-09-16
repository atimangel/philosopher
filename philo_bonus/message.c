/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:14:06 by snpark            #+#    #+#             */
/*   Updated: 2021/08/09 10:55:52 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_message(int id, char flag, int now)
{
	if (flag == 0)
		printf("%d	%d has taken a fork\n",
			now, id);
	else if (flag == 1)
		printf("%d	%d is eating\n",
			now, id);
	else if (flag == 2)
		printf("%d	%d is sleeping\n",
			now, id);
	else if (flag == 3)
		printf("%d	%d is thinking\n",
			now, id);
	else if (flag == 4)
		printf("%d	%d died\n",
			now, id);
}
