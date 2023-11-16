/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:34:31 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/16 12:33:29 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ## DESCRIPTION
// The memcpy() function copies n bytes from memory area src to memory area dst.
// If dst and src overlap, behavior is undefined.
// Applications in which dst and src might overlap should use memmove instead.
// ## RETURN VALUES
// The memcpy() function returns the original value of dst.

// ## Overlap Problem in `memcpy`
// ```sql
// - Initial Memory State:
//   [a, b, c, d, e, f, g, h, i, j]
//    |  |  |  |  |  |  |  |  |  |
//    0  1  2  3  4  5  6  7  8  9  (Indices)

// - Intention is to `memcpy` from index 1 to index 4.

// 1. First step of `memcpy` (copying b, c, d):
//   [a, b, c, d, b, c, d, h, i, j]
//    |  |  |  |  |  |  |  |  |  |
//    0  1  2  3  4  5  6  7  8  9  (Indices)
// 			   |  |  |
// 			   b  c  d   (Copied over e, f, and g)

// - Original values of 'e', 'f' and 'g' at indices 4, 5 and 6 are lost.

// 2. Continuing `memcpy` (attempting to copy e, f, g):
//   [a, b, c, d, b, c, d, b, c, d]
//    |  |  |  |  |  |  |  |  |  |
//    0  1  2  3  4  5  6  7  8  9  (Indices)
// 						   |  |  |
// 						   b  c  d (Copied over h, i, and j)

// 3. Final Corrupted Memory State:
//   [a, b, c, d, b, c, d, b, c, d]
//    |  |  |  |  |  |  |  |  |  |
//    0  1  2  3  4  5  6  7  8  9  (Indices)

// 4. Intended Memory State:
//   [a, b, c, d, b, c, d, e, f, g]
//    |  |  |  |  |  |  |  |  |  |
//    0  1  2  3  4  5  6  7  8  9  (Indices)
// ```

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str1[22] = "abcdefghijklmnopqrstu";
// 	char	str2[22] = "abcdefghijklmnopqrstu";
// 	// char	*str1 = NULL;
// 	// char	*str2 = NULL;

// 	memcpy(str1 + 4, str1, 10);
// 	ft_memcpy(str2 + 4, str2, 10);
// 	// memcpy(str1, str2, 10);
// 	// ft_memcpy(str1, str2, 10);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }