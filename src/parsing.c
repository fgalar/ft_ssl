/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:56:32 by fgarault          #+#    #+#             */
/*   Updated: 2024/04/27 16:10:45 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	usage(t_usage error, char *input)
{
	if (error == NO_ARG)
		ft_printf("usage: ft_ssl command [flags] [file/string]\n\n");
	else if (error == INVALID_COMMAND)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", input);
		ft_printf("Commands:\nmd5\nsha256\n\nFlags:\n-p -q -r -s\n");
	}
}

void	get_arguments(char **argv)
{
	t_hash_method	m;

	if (!argv[1])
		return (usage(NO_ARG, NULL));
	m = get_method(argv[1]);
	if (m == UNKNOWN)
		return (usage(INVALID_COMMAND, argv[1]));
	print_method(&m);
}

void	print_method(enum e_hash_method *hash)
{
	const char	*method[] = {"unknown", "MD5", "Sha256"};

	ft_printf("%s", method[*hash]);
}

t_hash_method	get_method(const char *str)
{
	const char	*method[] = {"unknown", "md5", "sha256"};
	int			i;

	i = 1;
	while (i < 3)
	{
		if (!ft_strcmp(str, method[i]))
			return ((t_hash_method)i);
		i++;
	}
	return (UNKNOWN);
}
