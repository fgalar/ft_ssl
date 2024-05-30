/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:08:00 by fgarault          #+#    #+#             */
/*   Updated: 2024/05/30 18:37:37 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include<stdio.h>

#define UINT_BITS(x) (x * 8 - 1)

void    print_step_debug(int i, uint32_t *w) {
    uint32_t w0 = w[i-16];
    uint32_t w9 = w[i-7];

// 1. Calculate:
// w16 = w0 + σ0 + w9 + σ1
    printf("\n\nw%d = w%d + σ0 + w%d + σ1\n\n", i, i-16, i-7);
// where
    printf("Expected:\n");
    printf("w0 = 00110100 00110010 00100000 01101001\n");
    printf("w9 = 00000000 00000000 00000000 00000000\n");
    printf("Current:\n");
    printf("w0 = ");
    print_bits(sizeof(uint32_t), &w0);
    printf("w9 = ");
    print_bits(sizeof(uint32_t), &w9);
// σ0 =
    printf("\n\n__ calculation σ0 __\n");
    printf("exp w1 = 01110011 00100000 01101110 01101001\ncur w1 = ");
    print_bits(sizeof(uint32_t), &w[i-15]);
// (w1 rightrotate 7) xor
    printf("\n\nσ0 = (w%d rightrotate 7) xor:\n", i - 15);
    uint32_t r7 = rightrotate(w[i-15], 1);
    printf("exp: 11010010 11100110 01000000 11011100\ncur: ");
    print_bits(sizeof(uint32_t), &r7);
// (w1 rightrotate 18) xor
    printf("σ1 = (w%d rightrotate 18) xor\n", i-15);
    uint32_t r18 = rightrotate(w[i-15], 18);
    printf("exp: 00011011 10011010 01011100 11001000\ncur: ");
    print_bits(sizeof(uint32_t), &r18);
// (w1 rightshift 3)
    printf("right shift 3\n");
    uint32_t v = (w[i-15] >> 3);
    printf("exp: 00001110 01100100 00001101 11001101\ncur: ");
    print_bits(sizeof(uint32_t), &v);
// and
// σ1 =
// (w14 rightrotate 17) xor
// (w14 rightrotate 19) xor
// (w14 rightshift 10)
    // printf("\nw%d: ", i - 15);
    // print_bits(sizeof(uint32_t), &w0);
    // printf("w%d = ", i - 16);
    // print_bits(sizeof(uint32_t), &w[i-16]);
    // printf("\nw%d = ", i - 7);
    // print_bits(sizeof(uint32_t), &w[i-7]);


    // int y = 18/8;
    // printf("σ1 = (right rotate %d)\n", y);
    // uint32_t u = rightrotate(tmp, UINT_BITS(y));
    // print_bits(sizeof(uint32_t), &u);
    // printf("00011011 10011010 01011100 11001000\n");
    
    // printf("right shift 3\n");
    // uint32_t v = (tmp >> 3);
    // print_bits(sizeof(uint32_t), &v);
    // printf("00001110 01100100 00001101 11001101\n");
}