/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:09:51 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/21 20:15:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Creates a new string by repeatedly applying 'f' to each character of 's'.
// The function 'f' use index of string 's' as the first argument.
// Map is a way to store data by pairing a key with a value
// and using the key to access and modify the value.

// === RETURN VALUE ===
// if (s == NULL || f == NULL) → Return NULL.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	buff = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		buff[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

// char	ft_addindex(unsigned int i, char c)
// {
// 	return ((char)i + c);
// }

// int	main(void)
// {
// 	char	str[] = "00000";
// 	// char	*str = NULL;
// 	char	*ptr;

// 	ptr = ft_strmapi(str, ft_addindex);
// 	printf("Before ft_strmapi: %s\n", str);
// 	printf("Before ft_strmapi: %s\n", ptr);
// 	free(ptr);
// 	return (0);
// }
