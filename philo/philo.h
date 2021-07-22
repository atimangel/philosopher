/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:57 by snpark            #+#    #+#             */
/*   Updated: 2021/07/22 14:24:40 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
//printf
# include <stdlib.h>
//malloc free
# include <string.h>
//memset
# include <unistd.h>
//write usleep
# include <time.h>
//gettimeofday
# include <pthread.h>

typedef struct s_philo
{
	int	number;
	int	death;
	int	eat;
	int	sleep;
	int	need;
}		t_philo;

int	ft_atoi(const char *string);

#endif
