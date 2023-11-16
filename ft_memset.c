/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:00:53 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/16 11:39:32 by akyoshid         ###   ########.fr       */
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
	size_t			i;

	ptr = (unsigned char *)b;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	unsigned char	str1[11] = "0123456789";
// 	unsigned char	str2[11] = "0123456789";

// 	ft_memset(str1, 256 + 'a', 5);
// 	memset(str2, 256 + 'a', 5);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }
