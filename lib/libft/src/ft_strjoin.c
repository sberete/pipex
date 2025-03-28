/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/03/21 18:38:43 by sxrimu           ###   ########.fr       */
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
        j = ft_strlen(s1) + 1 + ft_strlen(s2);  // +1 pour le '/'
    else
    {
        j = ft_strlen(s1) + ft_strlen(s2);
    }
    str = malloc(sizeof(char) * (j + 1));  // +1 pour le caractère '\0'
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