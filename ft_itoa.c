/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:33:49 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/21 18:36:11 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates & returns a string representing the integer.
// Negative numbers must be handled.

#include "libft.h"

static int	ft_countdigit(int n)
{
	int	digit;

	digit = 0;
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

static char	*ft_storenum(char *dst, int n, int sign, int digit)
{
	dst[digit] = '\0';
	digit--;
	while (n > 0)
	{
		dst[digit] = '0' + (n % 10);
		n /= 10;
		digit--;
	}
	if (sign == -1)
		dst[0] = '-';
	return (dst);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		digit;
	char	*buff;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		sign = -1;
		n *= -1;
		digit = ft_countdigit(n) + 1;
	}
	else
	{
		sign = 1;
		digit = ft_countdigit(n);
	}
	buff = malloc((digit + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	return (ft_storenum(buff, n, sign, digit));
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(INT_MAX));
// 	return (0);
// }
