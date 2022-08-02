/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 08:02:30 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/01 16:09:40 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
int	ft_strcmp(char *s1, char *s2)
{
	int	compteur;
	int	resultat;

	compteur = 0;
	resultat = 0;
	while (s1[compteur] != '\0' || s2[compteur] != '\0' )
	{
		resultat = s1[compteur] - s2[compteur];
		if (resultat > 0)
		{
			return (resultat);
		}
		else if (resultat < 0)
		{
			return (resultat);
		}
		compteur++;
	}
	return (resultat);
}
