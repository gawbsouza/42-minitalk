/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charbuilder_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:38:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 00:54:00 by gasouza          ###   ########.fr       */
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
	t_charbuild	*cb = new_charbuild();

	result("create", cb != NULL);
	build_char(cb, BIT_ONE);
	/* printf("B: %08b N: %d\n", cb->buffer, cb->next_bit); */
	build_char(cb, BIT_ONE);
	build_char(cb, BIT_ONE);
	build_char(cb, BIT_ZERO);
	build_char(cb, BIT_ZERO);
	build_char(cb, BIT_ZERO);
	build_char(cb, BIT_ONE);
	build_char(cb, BIT_ZERO);
	result("valid char created #1 : value", cb->buffer == 'G');
	result("valid char created #1 : status", cb->done == 1 && cb->next_bit == 0);
	build_char(cb, BIT_ZERO);
	result("Inaltered value / status when done", 
			cb->buffer == 'G' && cb->done == 1 && cb->next_bit == 0);
	cb->done = 0;
	build_char(cb, BIT_ZERO);
	build_char(cb, BIT_ONE);
	build_char(cb, BIT_ZERO);
	build_char(cb, BIT_ZERO);
	build_char(cb, BIT_ONE);
	build_char(cb, BIT_ZERO);
	build_char(cb, BIT_ONE);
	build_char(cb, BIT_ZERO);
	result("valid char created #2", cb->buffer == 'R');
}

int main (void)
{
	printf("\n%s\n", __FILE_NAME__);
	
	test();

	return (0);
}
