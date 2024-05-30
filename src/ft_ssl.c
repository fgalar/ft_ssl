/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:49:37 by fgarault          #+#    #+#             */
/*   Updated: 2024/05/18 16:03:26 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
// void ft_gets(char *buffer, int max_len, int *stream)
// {
//     int ret = read(STDIN_FILENO, buffer, max_len - 1);

//     if (ret > 0)
//     {
//         buffer[ret] = '\0';
//         ft_printf("IN: %s\n", buffer);
//     }
// }

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    // get_arguments(av);
    // md5(ft_atoi(av[1]));
    sha_256();

    // printf("%d", ft_atoi("45"));

    // while (*++av)
    // {
    //     ft_printf("av : %s\n", *av);
    // }

    // // --- get stdin
    // char buffer[100];

    // ft_gets(buffer, sizeof(buffer), stdin);

    return (0);
}