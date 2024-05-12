/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:01:27 by fgarault          #+#    #+#             */
/*   Updated: 2024/05/02 11:38:58 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

static void padding(int len, char *str)
{
    // trouver la taille du padding
    // +1 car on soit ajouter un 1 a la fin de la chaine de caractere
    int initial_bits_size = (len * 8) + 1;
    int padding = ((448 - initial_bits_size)) % 512;
    int new_size = initial_bits_size + padding + 64;

    ft_printf("initial bits size = %d\n", initial_bits_size);
    ft_printf("total size %d (check error:", new_size);
    if (new_size % 512 == 0)
        ft_printf("ok)\n");
    else
        ft_printf("NoK)\n");
    // Allouer string avec cette size

    char *buffer;
    // on ajoute une séquence de '0' (le nombre de zéros dépend de la longueur du remplissage nécessaire) ;
    if (!(buffer = (char *)ft_memalloc(sizeof(char) * (new_size / 8))))
        return (-1);
    buffer = ft_strcpy(buffer, str);
    // on ajoute un 1 à la fin du message ;
    buffer = 1 << 7;
    // on écrit la taille du message, un entier codé sur 64 bits.
    
}

void md5(int len)
{
    char *str = "bonjour";
    // 1 - Padding
    padding(str, ft_strlen(str));


}