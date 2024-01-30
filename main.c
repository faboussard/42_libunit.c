/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguillon <dguillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:57:51 by dguillon          #+#    #+#             */
/*   Updated: 2024/01/28 20:20:43 by dguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libunit.h"
#include "header/tests.h"
#include "libft/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	result(int res, int b)
{
	if (b)
		ft_printf("\033[32m");
	else
		ft_printf("\033[31m");
	if (res == 0)
		ft_printf("[OK]\033[0m\n");
	else if (res == 33)
		ft_printf("[KO]\033[0m\n");
	else if (res == 7)
		ft_printf("[SIGBUS]\033[0m\n");
	else if (res == 11)
		ft_printf("[SIGSEGV]\033[0m\n");
	else if (res == 6)
		ft_printf("[SIGABRT]\033[0m\n");
	else if (res == 8)
		ft_printf("[SIGFPE]\033[0m\n");
	else if (res == 4)
		ft_printf("[SIGILL]\033[0m\n");
	else if (res == 13)
		ft_printf("[SIGPIPE]\033[0m\n");
}

int	to_launch(const int action, char flags)
{
	int	i;

	i = 0;
	if (action == STRLEN_LAUNCH)
		i += strlen_launcher(flags);
	if (action == LSTSIZE_LAUNCH)
		i += lstsize_launcher(flags);
	if (action == ITOA_LAUNCH)
		i += itoa_launcher(flags);
	if (action == ATOI_LAUNCH)
		i += atoi_launcher(flags);
	if (action == IS_ALPHA_LAUNCH)
		i += isalpha_launcher(flags);
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	flags;
	int		j;
	t_bool	b;
	int		passed;

	i = 1;
	flags = 0;
	b = FALSE;
	j = 1;
	passed = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (b == FALSE && ft_strcmp(argv[i], BASIC) == 0)
			{
				flags |= 0x01;
				b = TRUE;
			}
			if (b == FALSE && ft_strcmp(argv[i], NILL) == 0)
			{
				flags |= 0x02;
				b = TRUE;
			}
			if (b == FALSE && ft_strcmp(argv[i], BIG) == 0)
			{
				flags |= 0x04;
				b = TRUE;
			}
			b = FALSE;
			i++;
		}
	}
	if (flags == 0)
		flags = 7;
	i = 0;
	while (j < argc)
	{
		if (b == FALSE && ft_strcmp(argv[j], "strlen") == 0)
		{
			if (flags == 1 || flags == 2 || flags == 4)
				i += 1;
			else if (flags == 3 || flags == 5 || flags == 6)
				i += 2;
			else if (flags == 7)
				i += 3;
			passed += to_launch(STRLEN_LAUNCH, flags);
			b = TRUE;
		}
		else if (b == FALSE && ft_strcmp(argv[j], "lstsize") == 0)
		{
			if (flags == 1 || flags == 2 || flags == 4)
				i += 1;
			else if (flags == 3 || flags == 5 || flags == 6)
				i += 2;
			else if (flags == 7)
				i += 3;
			passed += to_launch(LSTSIZE_LAUNCH, flags);
			b = TRUE;
		}
		else if (b == FALSE && ft_strcmp(argv[j], "itoa") == 0)
		{
			if (flags == 1 || flags == 2 || flags == 4)
				i += 1;
			else if (flags == 3 || flags == 5 || flags == 6)
				i += 2;
			else if (flags == 7)
				i += 3;
			passed += to_launch(ITOA_LAUNCH, flags);
			b = TRUE;
		}
		else if (b == FALSE && ft_strcmp(argv[j], "atoi") == 0)
		{
			if (flags == 1 || flags == 2 || flags == 4)
				i += 1;
			else if (flags == 3 || flags == 5 || flags == 6)
				i += 2;
			else if (flags == 7)
				i += 3;
			passed += to_launch(ATOI_LAUNCH, flags);
			b = TRUE;
		}
		else if (b == FALSE && ft_strcmp(argv[j], "isalpha") == 0)
		{
			if (flags == 1 || flags == 2 || flags == 4)
				i += 1;
			else if (flags == 3 || flags == 5 || flags == 6)
				i += 2;
			else if (flags == 7)
				i += 3;
			passed += to_launch(IS_ALPHA_LAUNCH, flags);
			b = TRUE;
		}
		else if (b == FALSE)
		{
			ft_printf("\n\t\t\033[33m%s function/test unavailable\033[0m\n",
				argv[j]);
			return (0);
		}
		b = FALSE;
		j++;
	}
	if (i == 0)
	{
		i = 15;
		passed += to_launch(STRLEN_LAUNCH, flags);
		passed += to_launch(LSTSIZE_LAUNCH, flags);
		passed += to_launch(ITOA_LAUNCH, flags);
		passed += to_launch(ATOI_LAUNCH, flags);
		passed += to_launch(IS_ALPHA_LAUNCH, flags);
	}
	ft_printf("\n\n%d/%d test passed\n", passed, i);
	if (passed == i)
	{
		ft_printf("\t\t\033[4m\033[32mGREAT WORK\033[0m\033[0m\n");
		return (0);
	}
	else
	{
		ft_printf("\t\t\033[4m\033[33m");
		ft_printf("NEED SOME CORRECTIONS\033[0m\033[0m\n");
		return (-1);
	}
}
