/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charbuilder_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:38:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/22 19:01:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <string.h>

static void	result(const char *test, int result)
{
	if (result)
		printf("- %s: ", "\033[0;32mPASS\033[;0m");
	if (!result)
		printf("- %s: ", "\033[0;31mFAIL\033[;0m");
	printf("%s\n", test);
}

static void	test(void)
{
	char		build = 0;
	t_charbuild	*cb = new_charbuild();

	result("create", cb != NULL);
	result("null charbuild", build_char(NULL, BIT_ZERO) == -1);
	result("invalid bit value", build_char(NULL, 2) == -1);
	build_char(cb, BIT_ONE);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	build_char(cb, BIT_ONE);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	build_char(cb, BIT_ONE);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	build_char(cb, BIT_ZERO);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	build_char(cb, BIT_ZERO);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	build_char(cb, BIT_ZERO);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	build_char(cb, BIT_ONE);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	build = build_char(cb, BIT_ZERO);
	printf("B: %08b N: %d\n", cb->buffer, cb->next_bit);
	result("valid char created", build == 'G');
	result("charbuild reseted", build_char(cb, BIT_ZERO) == -1 && cb->next_bit == 1);
}

int main (void)
{
	printf("\n%s\n", __FILE_NAME__);
	
	test();

	return (0);
}
