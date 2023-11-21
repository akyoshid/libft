/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:09:51 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/21 19:34:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Applies the function ’f’ to each character of the string ’s’,
// and passing its index as first argument
// to create a new string resulting from successive applications of ’f’

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	buff = malloc((s_len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		buff[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	return (buff);
}

char	ft_addindex(unsigned int i, char c)
{
	return ((char)i + c);
}

int	main(void)
{
	printf("%s\n", ft_strmapi("00000", *ft_addindex));
	return (0);
}
