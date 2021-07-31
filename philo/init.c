#include "philo.h"

int	set_fork(t_condition *condition)
{
	int i;

	condition->fork = malloc(sizeof(pthread_mutex_t) * condition->number);
	if (!condition->fork)
		return(exit_error("Error: fork malloc\n"));
	i = 0;
	while (i < condition->number)
		pthread_mutex_init(condition->fork + i++, NULL);
}

int	invite_philo(t_condition *condition)
{
	int	i;

	condition->philo = malloc(sizeof(t_philo) * condition->number);
	if (!condition->philo)
		return(exit_error("Error: philosofer refuse invitation\n"));
	i = 0;
	while (i < condition->number)
	{
		condition->philo[i].id = i + 1;
		condition->philo[i].spaghetti = 0;
		condition->philo[i].lfork = i;
		condition->philo[i].rfork = i + 1 % condition->number;
		condition->philo[i].able_to_think = 1;
		i++;
	}
}

int	set_table(t_condition *condition)
{
	set_fork(condition);
	invite_philo(condition);
}
