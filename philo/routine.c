#include "philo.h"

int	routine()
{
	long start;

	start = gettime();
	while (1)
	{
		printf("%dms eat\n", timestamp(start));
		usleep(200 * 1000);
		printf("%dms sleep\n", timestamp(start));
		usleep(200 * 1000);
		printf("%dms think\n", timestamp(start));
		usleep(200 * 1000);
	}
}
