/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:52:56 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/28 20:03:46 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libunit.h"
#include "../../header/tests.h"

int	itoa_launcher(char flags)
{
	pid_t	pid;
	int		passed_test;
	int		status;
	int		good;
	int		res;

	passed_test = 0;
	res = 0;
	good = 0;
	if (flags & 0x01)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_printf("error_fork\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			status = basic_test_itoa(&ft_itoa, &ft_itoa_ko);
			if (status == 0)
				exit(EXIT_SUCCESS);
			else
				exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			good = 0;
			wait(&status);
			if (WIFEXITED(status))
			{
				res = WEXITSTATUS(status);
				if (res == good)
					passed_test++;
				else if (res == 1)
					res = 33;
			}
			else if (WIFSIGNALED(status))
				res = WTERMSIG(status);
		}
		ft_printf("ITOA : basic_tests : ");
		if (res == good)
			result(res, 1);
		else
			result(res, 0);
	}
	if (flags & 0x02)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_printf("error_fork\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			status = null_test_itoa(&ft_itoa, &ft_itoa_ko);
			if (status == 0)
				exit(EXIT_SUCCESS);
			else
				exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			good = 0;
			wait(&status);
			if (WIFEXITED(status))
			{
				res = WEXITSTATUS(status);
				if (res == good)
					passed_test++;
				else if (res == 1)
					res = 33;
			}
			else if (WIFSIGNALED(status))
				res = WTERMSIG(status);
		}
		ft_printf("ITOA : null_tests : ");
		if (res == good)
			result(res, 1);
		else
			result(res, 0);
	}
	if (flags & 0x04)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_printf("error_fork\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			status = int_min_itoa(&ft_itoa, &ft_itoa_ko);
			if (status == 0)
				exit(EXIT_SUCCESS);
			else
				exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			good = 0;
			wait(&status);
			if (WIFEXITED(status))
			{
				res = WEXITSTATUS(status);
				if (res == good)
					passed_test++;
				else if (res == 1)
					res = 33;
			}
			else if (WIFSIGNALED(status))
				res = WTERMSIG(status);
		}
		ft_printf("ITOA : int_min_test : ");
		if (res == good)
			result(res, 1);
		else
			result(res, 0);
	}
	return (passed_test);
}
