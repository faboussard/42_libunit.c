/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:57:51 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/27 18:43:47 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <tests.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*int strlen_luncher(int i)
{
	if (i == 0)
		return (0);
	else if(i == 1)
		return (1);
	if (i == 2)
	{
		kill(getpid(), SIGSEGV);
		return (-1);
	}
	else if (i == 3)
	{
		kill(getpid(), SIGBUS);
		return (-1);
	}
	else 
		return (-1);
}*/


int check_args(char *str, char *flags)
{

}

int	main(int argc, char *argv[])
{
	int		i;
	char	flags;

	i = 0;
	flags = 0;
	if (argc < 2)
	{
		ft_printf("need function in first argument");
		return (0);
	}
	if (argc < 2)
	{
		while (i < argc)
		{
			if (check_args(argv[i], &flags) == -1)
			{
					ft_printf("invalid argument");
					return (0);
			}
			i++;
		}
	}
	to
}








int	main(void)
{
	int			i;
	pid_t		pid;
	int			passed_test;
	int			nb_tests;
	int			status;
	int			res;
//	int 		flags;

//	test = NULL;
	i = 0;
	passed_test = 0;
	nb_tests = 0;
	while(i < 2)
	{
		pid = fork();
		if (pid == -1)
		{
			printf("error_fork\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			return (strlen_launcher(i));
		else if (pid > 0)
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				res = WEXITSTATUS(status);
				if (!res)
					passed_test++;
			}
			else if(WIFSIGNALED(status))
			 	res = WTERMSIG(status);
			nb_tests++;
		}
		printf ("STRLEN : test %d : ", i);
		RESULT(res);
		i++;
	}
	printf("\n\n%d/%d test passed\n", passed_test, nb_tests);
	return (0);
}
