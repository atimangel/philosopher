#include "philo.h"

int	routine()
{
	long start;

	start = timestamp();
	while (1)
	{
		printf("%ldms eat\n", timestamp() - start);
		usleep(200 * 1000);
		printf("%ldms sleep\n", timestamp() - start);
		usleep(200 * 1000);
		printf("%ldms think\n", timestamp() - start);
		usleep(200 * 1000);
	}
}
