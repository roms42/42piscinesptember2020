/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:29:56 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/28 16:38:18 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char	*ft_strdup(char *src);
//int		*ft_range(int min, int max);
int	ft_ultimate_range(int **range, int min, int max);

int main(int argc, char **argv)
{
	(void)(argc);

	//ex00
	//printf("ex 00:    ma fonction: %s\n", ft_strdup(argv[1]));
	//printf("ex 00: vraie fonction: %s\n\n", strdup(argv[1]));

	//ex01	
	/*int i = 0;
	int *tab;
	tab = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (tab[i])
	{
		printf("%d ", tab[i]);
		i++;
	}*/
	
	//ex02
	/*int i = 0;
	int j = 0;
	int **range;
	ft_ultimate_range(range, atoi(argv[1]), atoi(argv[2]));
	while (range[0])
	{
		j = 0;
		while (range[0][j])
		{
			printf("%d", range[0][j]);
			j++;
		}
		i++;
	}*/

	//ex03
	char **strs;
	strs = NULL;
	int i = 0;
	strs = (char**)malloc(sizeof(char*) * 5);
	while (i < 5)
	{
		strs[i] = (char*)malloc(sizeof(char) * 30);
		i++;
	}
	strs[0] = "bonjour";
	strs[1] = "je";
	strs[2] = "mappelle";
	strs[3] = "romain";
	strs[4] = 0;
	i = 0;
	while (i < 4)
	{
		printf("%s\n", strs[i]);
		i++;
	}
	printf("dest = %s\n", ft_strjoin( 4, strs, " "));

	//ex03
	char *dest;
	char *strs[3];

	strs[0] = "1";
	strs[1] = "2";
	strs[2] = "3";
	dest = ft_strjoin(3, strs, "");
	printf("dest finale =%s\n", dest);

	//ex05
	#include <stdio.h>
int		main()
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split("boooonjour les copains holakkk", "oa");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

}
