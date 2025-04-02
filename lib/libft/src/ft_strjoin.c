/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/02 13:37:47 by sxrimu           ###   ########.fr       */
=======
/*   Updated: 2025/03/22 00:24:57 by sberete          ###   ########.fr       */
>>>>>>> 88b3781224d77094250275f3ff5ccf771b41c143
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i, j;
    char *str;

    if (!s1 || !s2)
        return (NULL);
    if (s1[ft_strlen(s1) - 1] != '/')
        j = ft_strlen(s1) + 1 + ft_strlen(s2);
    else
        j = ft_strlen(s1) + ft_strlen(s2);
<<<<<<< HEAD
    str = malloc(sizeof(char) * (j + 1));  // +1 pour le caractère '\0'
=======
    str = malloc(sizeof(char) * (j + 1));
>>>>>>> 88b3781224d77094250275f3ff5ccf771b41c143
    if (!str)
        return (NULL);
    i = 0;
    while (*s1)
        str[i++] = *s1++;
    if (s1[-1] != '/')
        str[i++] = '/';
    while (*s2)
        str[i++] = *s2++;
    str[i] = '\0';
    return (str);
}
/*
int main()
{
	char s1[] = "Je suis venu";
	char s2[] = " a l'ecole";

	char *x = ft_strjoin(s1, s2);
	printf(""%s", x);
}
*/