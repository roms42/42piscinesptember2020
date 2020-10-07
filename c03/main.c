/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:13:36 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/17 12:00:29 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{	
/*---------------------------EX 00 ------------------------------------*/
	
	char *s1 = "Patate";
	char *s2 = "ZZZZZZZZZ";
	printf("\n EX 00 :Result = %i \n", (ft_strcmp(s1, s2)));
	printf("Expected Result = %i \n\n", (strcmp(s1, s2)));


/*---------------------------EX 01---------------------------------------*/

	char *s3 = "Patate";
	char *s4i = "Patates";
	unsigned char n1 = 2;
	printf("\n EX 01 :Result = %i \n", (ft_strncmp(s3, s4i, n1)));
	printf("Expected Result = %i \n\n", (strncmp(s3, s4i, n1)));

	char *s4 = "\0";
	char *s5 = "Patates";
	unsigned char n2 = 6;
	printf("\n EX 01 :Result = %i \n", (ft_strncmp(s4, s5, n2)));
	printf("Expected Result = %i \n\n", (strncmp(s4, s5, n2)));

	char *s6 = "Patate";
	char *s7 = "\0";
	unsigned char n3 = 0;
	printf("\n EX 01 :Result = %i \n", (ft_strncmp(s6, s7, n3)));
	printf("Expected Result = %i \n\n", (strncmp(s6, s7, n3)));
	
	char *s8 = " ";
	char *s9 = "\0";
	unsigned char n4 = 1;
	printf("\n EX 01 :Result = %i \n", (ft_strncmp(s8, s9, n4)));
	printf("Expected Result = %i \n\n", (strncmp(s8, s9, n4)));

	char *s10 = "012356";
	char *s11 = "012356";
	unsigned char n5 = 5;
	printf("\n EX 01 :Result = %i \n", (ft_strncmp(s10, s11, n5)));
	printf("Expected Result = %i \n\n", (strncmp(s10, s11, n5)));

	char *s12 = "Patate";
	char *s13 = "\0";
	unsigned char n6 = 2;
	printf("\n EX 01 :Result = %i \n", (ft_strncmp(s12, s13, n6)));
	printf("Expected Result = %i \n\n", (strncmp(s12, s13, n6)));



/*---------------------------EX 02---------------------------------------*/

	char dest[50] = "0";
	char src[50] = "1";
	char destbis[50] = "0";
	printf("\n EX 02 :Result = %s \n", (ft_strcat(dest, src)));
	printf("Expected Result = %s \n\n", (strcat(destbis, src)));

	char dest2[50] = "Patate";
	char dest2bis[50] = "Patate";
	char src2[50] = " chaude !";

	printf("\n EX 02 :Result = %s \n", (ft_strcat(dest2, src2)));
	printf("Expected Result = %s \n\n", (strcat(dest2bis, src2)));

	char dest3[50] = "Jean";
	char dest3bis[50] = "Jean";
	char src3[50] = "-Luc";
	printf("\n EX 02 :Result = %s \n", (ft_strcat(dest3, src3)));
	printf("Expected Result = %s \n\n", (strcat(dest3bis, src3)));


/*---------------------------EX 03---------------------------------------*/

char dest4[50] = "0";
	char dest4b[50] = "0";
	char src4[50] = "1";
	int n7 = 5;
	printf("\n EX 03 :Result = %s \n", (ft_strncat(dest4, src4, n7)));
	printf("Expected Result = %s \n\n", (strncat(dest4b, src4, n7)));

	char dest5[50] = "Patate";
	char dest5b[50] = "Patate";
	char src5[50] = " chaude !";
	int n8 = 8;
	printf("\n EX 03 :Result = %s \n", (ft_strncat(dest5, src5, n8)));
	printf("Expected Result = %s \n\n", (strncat(dest5b, src5, n8)));

	char dest6[50] = "Jean";
	char dest6b[50] = "Jean";
	char src6[50] = "-Luc";
	int n9 = 10;
	printf("\n EX 03 :Result = %s \n", (ft_strncat(dest6, src6, n9)));
	printf("Expected Result = %s \n\n", (strncat(dest6b, src6, n9)));

/*---------------------------EX 04---------------------------------------*/

	char to_find[50] = "0";
	char str[50] = "01111110000";
	printf("\n EX 04 :Result = %s \n", (ft_strstr(str, to_find)));
	printf("Expected Result = %s \n\n", (strstr(str, to_find)));

	char to_find2[50] = "Patate";
	char str2[50] = "Patate chaude !";
	printf("\n EX 04 :Result = %s \n", (ft_strstr(str2, to_find2)));
	printf("Expected Result = %s \n\n", (strstr(str2, to_find2)));

	char to_find3[50] = "Luc";
	char str3[50] = "Jean-Luc";
	printf("\n EX 04 :Result = %s \n", (ft_strstr(str3, to_find3)));
	printf("Expected Result = %s \n\n", (strstr(str3, to_find3)));

	char to_find4[50] = "Luc";
	char str4[50] = "Jean-Luc";
	printf("\n EX 04 :Result = %s \n", (ft_strstr(str4,to_find4)));
	printf("Expected Result = %s \n\n", (strstr(str4, to_find4)));


/*---------------------------EX 05---------------------------------------*/

	char desti[50] = "0";
	char srci[50] = "01";
	int na = 5;
	char desat[50] = "0";
	char sarc[50] = "01";
	printf("\n EX 05 :Result = %u \n", (ft_strlcat(desti, srci, na)));
	printf("Expected Result = %lu \n\n", (strlcat(desat, sarc, na)));
	printf(" String After cc : %s \n", desti);

	char desta[50] = "Patate";
	char srca[50] = " chaude !";
	int nb = 7;
	char destab[50] = "Patate";
	char srcab[50] = " chaude !";
	printf("\n EX 05 :Result = %u \n", (ft_strlcat(desta, srca, nb)));
	printf("Expected Result = %lu \n\n", (strlcat(destab, srcab, nb)));
	printf(" String After cc : %s \n", desta);

	char destac[50] = "Jean";
	char srcac[50] = "Jean-Luc";
	int nc = 0;
	char destb[50] = "Jean";
	char srcb[50] = "Jean-Luc";
	printf("\n EX 05 :Result = %u \n", (ft_strlcat(destac, srcac, nc)));
	printf("Expected Result = %lu \n\n", (strlcat(destb, srcb, nc)));



	char dest[50] = "Hello";
	char src[50] = "World";
	unsigned int size = 5;
	printf("retour = %u | size = %d\n", ft_strlcat(dest, src, size), size);
	printf("resultat = %s\n\n", dest);
	char dest2[50] = "Hello";
	char src2[50] = "World";
	printf("retour = %lu | size = %d\n", strlcat(dest2, src2, size), size);
	printf("resultat = %s", dest2);
	return(0);
}
