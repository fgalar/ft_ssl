/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:27:06 by fgarault          #+#    #+#             */
/*   Updated: 2024/05/30 18:36:36 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>
# define H0 0x6A09E667
# define H1 0xBB67AE85
# define H2 0x3C6EF372
# define H3 0xA54FF53A
# define H4 0x510E527F
# define H5 0x9B05688C
# define H6 0x1F83D9AB
# define H7 0x5BE0CD19

// #define U32_SIZE sizeof(uint32_t)
#define UINT_BITS(x) (x * 8 - 1)

// uint32_t    rightrotate(uint32_t value, uint32_t bits)
// {
//     return ((value >> bits) | (value << (32 - bits)));
// }

unsigned int rightrotate(uint32_t x, uint32_t n) {

    return (x >> n % 32) | (x << (32-n) % 32);
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
    for (int i = 0; i < 8; i++) // as big-endian
		data->msg[data->total - 8 + i] = ((uint8_t*)&(data->bits))[7 - i];
    print_bits(data->total, data->msg);
    // printf("Expected :\n\
// 00110100 00110010 00100000 01101001 \
// 01110011 00100000 01101110 01101001 \
// 01100011 01100101 10000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 00000000 \
// 00000000 00000000 00000000 01010000");
}

uint32_t	swap_uint32t(uint32_t nb)
{
	return ((nb >> 24 & 0xff) | (nb >> 8 & 0xff00) | (nb << 8 & 0xff0000)
			| (nb << 24 & 0xff000000));
}

uint32_t    *prepare_w(t_padding *data)
{
    uint32_t sum0;
    uint32_t sum1;
    uint32_t *w;

    if (!(w = (uint32_t*)ft_memalloc(sizeof(uint32_t) * 64)))
        exit(-1);
    ft_memcpy(w, &data->msg[data->offset], 64);

    for (uint32_t i = 16; i < 64; i++)
    {
        print_step_debug(i, w);
        uint32_t tmp = w[i-15];
        
        sum0 = rightrotate(tmp, UINT_BITS(7)) ^ rightrotate(tmp, UINT_BITS(18)) ^ (tmp >> 3);
        sum1 = rightrotate(w[i - 2], 17) ^ rightrotate(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + sum0 + w[i - 7] + sum1;
        
        exit(0);
    }
    return (w);
}

void calc_sha256(t_padding *data, t_hash *h)
{
    uint32_t t1;
    uint32_t t2;
    uint32_t ch;
    uint32_t maj;
    uint32_t sum0;
    uint32_t sum1;

    int i = 0;
    uint32_t *w = prepare_w(data);
    while (i++ < 64)
    {
        sum1 = rightrotate(h->e, 6) ^ rightrotate(h->e, 11) ^ rightrotate(h->e, 25);
        ch = ((h->e & h->f) ^ (~(h->e) & h->g));
        t1 = h->e + sum1 + ch + g_k_sha[i] + w[i];
        
        sum0 = rightrotate(h->a, 2) ^ rightrotate(h->a, 13) ^ rightrotate(h->a, 22);
        maj = (h->a & h->b) ^(h->a & h->c) ^ (h->b & h->c);
        t2 = sum0 + maj;

        h->h = h->g;
        h->g = h->f;
        h->f = h->e;
        h->e = h->d + t1;
        h->d = h->c;
        h->c = h->b;
        h->b = h->a;
        h->a = t1 + t2;
    }
    free(w);
}

void sha_256() {
    t_padding   data;
    t_hash      hash;
    uint32_t    h0, h1, h2, h3, h4, h5, h6, h7;

    h0 = H0;
    h1 = H1;
    h2 = H2;
    h3 = H3;
    h4 = H4;
    h5 = H5;
    h6 = H6;
    h7 = H7;

    char *str = "42 is nice";
    padding(&data, str, ft_strlen(str));
    while (data.offset < data.len)
    {
        hash.a = h0;
        hash.b = h1;
        hash.c = h2;
        hash.d = h3;
        hash.e = h4;
        hash.f = h5;
        hash.g = h6;
        hash.h = h7;
        calc_sha256(&data, &hash);
        h0 += hash.a;
        h1 += hash.b;
        h2 += hash.c;
        h3 += hash.d;
        h4 += hash.e;
        h5 += hash.f;
        h6 += hash.g;
        h7 += hash.h;
        data.offset += 64;
    }
    // printf("hash a: %x\n", h0);
	// printf("hash b: %x\n", h1);
	// printf("hash c: %x\n", h2);
	// printf("hash d: %x\n", h3);
	// printf("hash e: %x\n", h4);
	// printf("hash f: %x\n", h5);
	// printf("hash g: %x\n", h6);
	// printf("hash h: %x\n", h7);

}