/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 09:55:33 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/15 15:27:32 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

// functions prototypes
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_lowercase(char *str);
int	ft_str_is_uppercase(char *str);
int	ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str):
char	*ft_capitalize(char *str);


int	main()
{
	// ex00
	char dest00[50] = "Salut";
	char src00[50] = "Hello";
	printf("%s --" "%s \n", dest00, src00);
	ft_strcpy(dest00, src00);
	printf("after ft: %s --" "%s \n", dest00, src00);
	char dest00bis[50] = "Salut";
	char src00bis[50] = "Hello";
	printf("%s --" "%s \n", dest00bis, src00bis);
	strcpy(dest00bis, src00bis);
	printf("after real ft: %s --" "%s", dest00bis, src00bis);
	
	// ex01
	char dest01[50] = "Salut";
	char src01[50] = "Maman";
	unsigned int n01 = 10;
	printf("%s --" "%s \n", dest01, src01);
	ft_strncpy(dest01, src01, n01);
	printf("after ft and n = %d: %s --" "%s \n", n01, dest01, src01);
	char dest01bis[50] = "Salut";
	char src01bis[50] = "Maman";
	unsigned int n01bis = 10;
	printf("%s --" "%s \n", dest01bis, src01bis);
	strncpy(dest01bis, src01bis, n01bis);
	printf("after real ft and n = %d: %s --" "%s", n01bis, dest01bis, src01bis);

	// ex02
	char dest02[] = "ijediQskf++Dj";
	printf("return value is: %d \n", ft_str_is_alpha(dest02));
	if (ft_str_is_alpha(dest02) == 1 && dest02[0] == '\0')
		printf("dest is empty");
	else if (ft_str_is_alpha(dest02) == 1)
		printf("dest is indeed alpha");
	else
		printf("dest is not alpha");	

	// ex03
	char dest03[] = "38593jd8374";
	printf("return value is: %d \n", ft_str_is_numeric(dest03));
	if (ft_str_is_numeric(dest03) == 1 && dest03[0] == '\0')
		printf("dest is empty");
	else if (ft_str_is_numeric(dest03) == 1)
		printf("dest is indeed numeric only");
	else
		printf("dest is not numeric only");

	// ex04
	char dest04[] = "";
	printf("return value is: %d \n", ft_str_is_lowercase(dest04));
	if (ft_str_is_lowercase(dest04) == 1 && dest04[0] == '\0')
		printf("dest is empty");
	else if (ft_str_is_lowercase(dest04) == 1)
		printf("dest is indeed lowercase only");
	else
		printf("dest is not lowercase only");

	// ex05
	char dest05[] = "KDJFKSK";
	printf("return value is: %d \n", ft_str_is_uppercase(dest05));
	if (ft_str_is_uppercase(dest05) == 1 && dest05[0] == '\0')
		printf("dest is empty");
	else if (ft_str_is_uppercase(dest05) == 1)
		printf("dest is indeed uppercase only");
	else
		printf("dest is not uppercase only");

	// ex06
	char dest06[] = "";
	printf("return value is: %d \n", ft_str_is_printable(dest06));
	if (ft_str_is_printable(dest06) == 1 && dest06[0] == '\0')
		printf("dest is empty");
	else if (ft_str_is_printable(dest06) == 1)
		printf("dest is indeed printables only");
	else
		printf("dest is not printables only");

	// ex07
	char dest07[] = "Salut c'est moi, im noo++b";
	printf("before ft: %s \n", dest07);
	printf("ater ft: %s \n", ft_strupcase(dest07));

	// ex08
	char dest08[] = "SaLUT c'ESt mOi, IM NOo++b";
	printf("before ft: %s \n", dest08);
	printf("ater ft: %s \n", ft_strlowcase(dest08));

	// ex09
	char dest09[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s", ft_capitalize(dest09));

	// ex10
	char		d1[] = "oooo";
	char		s1[] = "kkkk";
	char		d2[] = "oooo";
	const char	s2[] = "kkkk";

	printf("10 : %s | ", d1);
	if (ft_strlcpy(d1, s1, 3) == strlcpy(d2, s2, 3) && strcmp(d1, d2) == 0)
		printf("OK | ");
	else
		printf("KO | ");
	printf("%s", d1);

	char		d12[] = "oooo";
	char		s12[] = "kkkk";
	char		d22[] = "oooo";
	const char	s22[] = "kkkk";

	printf("  -|-  %s | ", d12);
	if (ft_strlcpy(d12, s12, 0) == strlcpy(d22, s22, 0) && strcmp(d12, d22) == 0)
		printf("OK | ");
	else
		printf("KO | ");
	printf("%s", d12);

	char		d13[] = "oo";
	char		s13[] = "kkkk";
	char		d23[] = "oo";
	const char	s23[] = "kkkk";

	printf("  -|-  %s | ", d13);
	if (ft_strlcpy(d13, s13, 3) == strlcpy(d23, s23, 3) && strcmp(d13, d23) == 0)
		printf("OK | ");
	else
		printf("KO | ");
	printf("%s\n", d13);

	// ex11
	char str[]="Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	printf("\n");

	ft_putstr_non_printable("11 : Test : Cou\tcou\ntu\vvas\fbien\r ?");
	printf("\n  Reponse : Cou\\09cou\\0atu\\0bvas\\0cbien\\0d ?\n");	
}
