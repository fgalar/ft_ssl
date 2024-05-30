/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:46:28 by fgarault          #+#    #+#             */
/*   Updated: 2024/05/30 18:36:29 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "../libft/ft_printf/ft_printf.h"
// # define H0	0x67452301
// # define H1	0xEFCDAB89
// # define H2	0x98BADCFE
// # define H3	0x10325476


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

typedef struct	s_padding
{
	size_t		len;
	size_t		bits;
	size_t		padding;
	size_t		total;
	size_t		offset;
	uint8_t	*msg;
}	t_padding;

typedef struct s_hash
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
}	t_hash;

static const uint32_t	g_r_md5[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 5, 9, 14, 20,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4,
	11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6,
	10, 15, 21
};

// k[i] := floor(abs(sin(i + 1)) × 2^32)
static const uint32_t g_k_md5[64] = {
	0xd76aa478,	0xe8c7b756,	0x242070db,	0xc1bdceee,	0xf57c0faf,
	0x4787c62a,	0xa8304613,	0xfd469501, 0x698098d8,	0x8b44f7af,
	0xffff5bb1,	0x895cd7be,	0x6b901122, 0xfd987193,	0xa679438e,
	0x49b40821, 0xf61e2562,	0xc040b340, 0x265e5a51,	0xe9b6c7aa,
	0xd62f105d, 0x02441453,	0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6,
	0xc33707d6, 0xf4d50d87,	0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
	0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122,
	0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039,
	0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97,
	0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d,
	0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d39
};

// 32 premiers bits de la partie décimale des racines cubiques des 64 premiers nombres premiers
static const uint32_t g_k_sha[64] = {
	0x428a2f98,	0x71374491,	0xb5c0fbcf,	0xe9b5dba5,	0x3956c25b,
	0x59f111f1,	0x923f82a4,	0xab1c5ed5, 0xd807aa98,	0x12835b01,
	0x243185be,	0x550c7dc3,	0x72be5d74, 0x80deb1fe,	0x9bdc06a7,
	0xc19bf174, 0xe49b69c1,	0xefbe4786, 0x0fc19dc6,	0x240ca1cc,
	0x2de92c6f, 0x4a7484aa,	0x5cb0a9dc,	0x76f988da, 0x983e5152,
	0xa831c66d, 0xb00327c8,	0xbf597fc7,	0xc6e00bf3, 0xd5a79147,
	0x06ca6351,	0x14292967, 0x27b70a85,	0x2e1b2138, 0x4d2c6dfc,
	0x53380d13,	0x650a7354, 0x766a0abb,	0x81c2c92e,	0x92722c85,
	0xa2bfe8a1,	0xa81a664b, 0xc24b8b70,	0xc76c51a3,	0xd192e819,
	0xd6990624,	0xf40e3585,	0x106aa070, 0x19a4c116,	0x1e376c08,
	0x2748774c,	0x34b0bcb5,	0x391c0cb3, 0x4ed8aa4a,	0x5b9cca4f,
	0x682e6ff3, 0x748f82ee,	0x78a5636f, 0x84c87814,	0x8cc70208,
	0x90befffa, 0xa4506ceb,	0xbef9a3f7,	0xc67178f2
};

void			usage(t_usage error, char *input);
void			print_method(enum e_hash_method *hash);
void			get_arguments(char **argv);
t_hash_method	get_method(const char *str);

void			print_bits(size_t const size, void const * const ptr);
void			md5(int len);
uint32_t		leftrotate(uint32_t x, uint32_t n);
void			sha_256();
void    		print_step_debug(int i, uint32_t *w);

uint32_t    rightrotate(uint32_t value, uint32_t bits);

#endif