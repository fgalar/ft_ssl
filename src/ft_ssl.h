/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:46:28 by fgarault          #+#    #+#             */
/*   Updated: 2024/04/28 17:06:01 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "../libft/ft_printf/ft_printf.h"

typedef enum e_usage
{
	NO_ARG,
	INVALID_COMMAND,
}	t_usage;

typedef enum e_hash_method
{
	UNKNOWN = 0,
	MD5 = 1,
	SHA256 = 2,
}	t_hash_method;

void			usage(t_usage error, char *input);
void			print_method(enum e_hash_method *hash);
void			get_arguments(char **argv);
t_hash_method	get_method(const char *str);
void			md5(int len);

#endif