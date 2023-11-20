/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:22:56 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/20 11:51:25 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns a copy of ’s1’ 
// with the characters specified in ’set’ removed
// from the beginning and the end of the string

// setがempty stringの時どうする？

#include "libft.h"

static size_t	ft_isset(const char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	// char	*buff;
	size_t	start;
	size_t	end;

	start = 0;
	while (ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[end], set))
		end--;
	printf("%zu\n", end);
	return (NULL);
}

int	main(void)
{
	ft_strtrim("abcxyz", "z");
	return (0);
}

























// static int	ft_findchar(const char *s, const int c)
// {
// 	char	ch;

// 	ch = (char)c;
// 	while (1)
// 	{
// 		if (*s == ch)
// 			return (1);
// 		if (*s == '\0')
// 			return (0);
// 		s++;
// 	}
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	const char	*start;
// 	const char	*end;
// 	char		*buff;

// 	if (s1 == NULL)
// 		return (NULL);
// 	if (set == NULL)
// 		return (ft_strdup(s1));
// 	start = s1;
// 	end = s1 + ft_strlen(s1) - 1;
// 	while (*start != '\0' && ft_findchar(set, *start))
// 		start++;
// 	while (start < end && ft_findchar(set, *end))
// 		end--;
// 	buff = malloc(end - start + 2);
// 	if (buff == NULL)
// 		return (NULL);
// 	ft_memcpy(buff, start, end - start + 1);
// 	buff[end - start + 1] = '\0';
// 	return (buff);
// }

// int	main(void)
// {
// 	char	str[] = "  \t \t \n   \n\n\n\t";
// 	// char	set[] = " \n\t";
// 	char	*set = NULL;
// 	char	*ptr;

// 	ptr = ft_strtrim(str, set);
// 	printf("%s\n", ptr);
// 	return (0);
// }
