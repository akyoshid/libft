/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:56:20 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/16 09:37:29 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strlen function does not handle null pointers.
// If you pass a null pointer to strlen,
// it will result in undefined behavior, mostly SEGFAULT.

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
