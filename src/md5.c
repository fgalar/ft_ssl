/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:01:27 by fgarault          #+#    #+#             */
/*   Updated: 2024/05/12 20:37:43 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = 0; i < (int)size; i++) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
        printf(" ");
    }
    puts("");
}

uint32_t	leftrotate(uint32_t x, uint32_t n)
{
	return (x << n) | (x >> (32 - n));
}

static void padding(t_padding *data, char *msg, size_t len)
{
    data->offset = 0;
    data->len = len;
    data->bits = len * 8;
    data->padding = (448 - (data->bits+1)) % 512;
    data->total = (data->bits + data->padding + 64 + 1 ) / 8;

    if (!(data->msg = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (data->total))))
        return ;
    ft_memcpy(data->msg, msg, len);
    data->msg[len] |= 1 << 7;
    ft_memcpy(data->msg + data->total - 1, &data->bits, 8);

    print_bits(data->total, data->msg);
}

static void    calc_md5(t_padding *data, t_md5 *hash)
{
    int i;
    uint32_t f;
    uint32_t g;
    uint32_t tmp;
    uint32_t *w;

    i = 0;
    w = (uint32_t*)(data->msg + data->offset);
    while (i < 64)
    {
        if (i >= 0 && i <= 15)
        {
            f = (hash->b & hash->c) |  ((~hash->b) & hash->d);
            g = i;
        } else if (i >= 16 && i <= 31)
        {
            f = (hash->d & hash->b) | ((~hash->d) & hash->c);
            g = (5 * i + 1) % 16;
        } else if (i >= 32 && i <= 47)
        {
            f = hash->b ^ hash->c ^ hash->d;
            g = (3 * i + 5) % 16;
        } else if (i >= 48 && i <= 63)
        {
            f = hash->c ^ (hash->b | (~hash->d));
            g = (7 * i) % 16;
        }
        tmp = hash->d;
        hash->d = hash->c;
        hash->c = hash->b;
        hash->b  += leftrotate((hash->a + f + g_k_md5[i] + w[g]), g_r_md5[i]);
        hash->a = tmp;
        i++;
    }
}


void md5(int len)
{
    t_padding   data;
    t_md5       hash;
    uint32_t h0, h1, h2, h3; 

    h0 = H0;
    h1 = H1;
    h2 = H2;
    h3 = H3;

    (void)len;
    char *str = "They are deterministic";
    padding(&data, str, ft_strlen(str));
    hash = (t_md5){.a = H0, .b = H1, .c = H2, .d = H3};
    while (data.offset < data.len)
    {
        hash.a = h0;
        hash.b = h1;
        hash.c = h2;
        hash.d = h3;
        calc_md5(&data, &hash);
        h0 += hash.a;
        h1 += hash.b;
        h2 += hash.c;
        h3 += hash.d;
        data.offset += 64;
    }
        printf("hash a: %x\n", h0);
        printf("hash b: %x\n", h1);
        printf("hash c: %x\n", h2);
        printf("hash d: %x\n", h3);
}