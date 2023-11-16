/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:00:53 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/16 11:18:55 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ## Description
// The memset() function writes len bytes of value c
// (converted to an unsigned char) to the string b.
// ## Return Value
// The memset() function returns its first argument.
// ## Why we use unsigned char
// Because unsigned char is a binary safe data type.
// 1. No padding bits
// 2. Not violating the "aliasing rules".
// 3. No sign

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)b;
	ch = (unsigned char)c;
	while (len > 0)
	{
		*ptr = c;
		ptr++;
		len--;
	}
	return (b);
}
