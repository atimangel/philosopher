#include "philo.h"

int	is_dead(t_philo *philo)
{
	int	arg;

	arg = philo->condition->death -
		(gettime() - philo->start_eat) / 1000;
	if (arg < 0)
	{
		printf("%dms	%d philo die	%d\n",
			timestamp(philo->condition->start_time), philo->id, arg);
	}
	return(arg);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*fork;
	long long	start;

	fork = philo->condition->fork;
	start = philo->condition->start_time;
	pthread_mutex_lock(fork + philo->lfork);
	printf("%dms	%d has taken a fork\n", timestamp(start), philo->id);
	pthread_mutex_lock(fork + philo->rfork);
	printf("%dms	%d has taken a fork\n", timestamp(start), philo->id);
	printf("%dms	%d is eating\n", timestamp(start), philo->id);
	philo->start_eat = gettime();
	ft_usleep(philo->condition->eat * 1000);
	pthread_mutex_unlock(fork + philo->lfork);
	pthread_mutex_unlock(fork + philo->rfork);
}

void	philo_sleep(t_philo *philo)
{
	printf("%dms	%d is sleeping\n",
		timestamp(philo->condition->start_time), philo->id);
	ft_usleep(philo->condition->sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	printf("%dms	%d is thinking\n",
		timestamp(philo->condition->start_time), philo->id);
}
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->start_eat =
		philo->condition->start_time;
	while(is_dead(philo) > 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
