#include "philo.h"

int	set_fork(t_condition *condition)
{
	int i;

	condition->fork = malloc(sizeof(pthread_mutex_t) * condition->number);
	if (!condition->fork)
		return(exit_error("Error: fork is missing\n"));
	i = 0;
	while (i < condition->number)
	{
		pthread_mutex_init(condition->fork + i++, NULL);
		printf("%i fork is set\n", i);
	}
	return (0);
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
		condition->philo[i].rfork = (i + 1) % condition->number;
		condition->philo[i].able_to_think = 1;
		condition->philo[i].condition = condition;
		i++;
		printf("id %i\nspaghetti %i\nlfork %i\nrfork %i\nable to think %i\n", condition->philo[i - 1].id, condition->philo[i - 1].spaghetti, condition->philo[i - 1].lfork, condition->philo[i - 1].rfork, condition->philo[i - 1].able_to_think);
	}
	return (0);
}

int	set_mic(t_condition *condition)
{
	condition->mic = malloc(sizeof(pthread_mutex_t));
	if (!condition->mic)
		return(exit_error("Error: MIC is missing\n"));
	if (pthread_mutex_init(condition->mic, NULL))
		return(exit_error("Error: MIC is missing\n"));
	printf("MIC set\n");
	return (0);
}

void	*who_are_you(void *arg)
{
	t_philo	*philo;
	int a;
	int	i;

	i = 0;

	philo = (t_philo *)arg;
	printf("---------start--------\n%ld\n",philo->thread_info);
	if (a = pthread_mutex_lock(philo->condition->mic))
		printf("Error: %d\n", a);
	while (i < 4)
	{
		printf("%ldms %i philo introduce itself %i\n", timestamp() - philo->condition->start_time, philo->id, i);
		usleep(10000);
		i++;
	}
	//printf("%ldms %i philo introduce itself %i\n", timestamp() - philo->condition->start_time, philo->id, i);
	pthread_mutex_unlock(philo->condition->mic);
	printf("-------end-------\n");
}

void	*eat(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("----\n");
	pthread_mutex_lock(philo->condition->fork + philo->lfork);
	printf("%ldms %d philo hold %i fork\n", timestamp() - philo->condition->start_time, philo->id, philo->lfork);
	pthread_mutex_lock(philo->condition->fork + philo->rfork);
	printf("%ldms %d philo hold %i fork\n", timestamp() - philo->condition->start_time, philo->id, philo->rfork);
	philo->start_eat = timestamp();
	printf("%ldms %d philo start eat\n", timestamp() - philo->condition->start_time, philo->id);
	philo->limit = philo->start_eat + philo->condition->death;
	usleep(philo->condition->death * 1000);
	printf("%ldms %d philo finish eat\n", timestamp() - philo->condition->start_time, philo->id);
	pthread_mutex_unlock(philo->condition->fork + philo->lfork);
	printf("%ldms %d philo drop %i fork\n", timestamp()- philo->condition->start_time , philo->id, philo->lfork);
	pthread_mutex_unlock(philo->condition->fork + philo->rfork);
	printf("%ldms %d philo drop %i fork\n", timestamp() - philo->condition->start_time, philo->id, philo->rfork);
}

int	start_dinner(t_condition *condition)
{
	int	i;
	int	thread_end;

	condition->start_time = timestamp();
	condition->test = 0;
	i = 0;
	while (i  < condition->number)
	{
		pthread_create(&condition->philo[i].thread_info, NULL, eat, condition->philo + i);
		//pthread_detach(condition->philo[i].thread_info);
		usleep(1);
		i++;
	}
	/*i = 1;
	while (i  < condition->number)
	{
		pthread_create(&condition->philo[i].thread_info, NULL, eat, condition->philo + i);
		//pthread_detach(condition->philo[i].thread_info);
		usleep(1);
		i += 2;
	}
*/
	i = 0;
	while (i < condition->number)
	{
		if(pthread_detach(condition->philo[i].thread_info));// (void *)&thread_end))
		printf("%d %ld\n", i, pthread_self());
		i++;
	}
	while(1);
}

int	set_table(t_condition *condition)
{
	if (set_fork(condition))
		return (1);
	if (invite_philo(condition))
		return (1);
	if (set_mic(condition))
		return (1);
	if (start_dinner(condition))
		return (1);
	return (0);
}
