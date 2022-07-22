/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strbuilder_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:34:32 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/22 18:35:57 by gasouza          ###   ########.fr       */
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

static void	test_bs1(void)
{
	size_t buffer_size = 1;
	t_strbuild *sb = new_strbuild(buffer_size);

	result("buffer size 1 : created", sb!= NULL);
	build_str(sb, 'a', buffer_size);
	result("buffer size 1 : add char #1", strcmp(sb->buffer, "a") == 0);
	build_str(sb, 'g', buffer_size);
	result("buffer size 1 : add char #2", strcmp(sb->buffer, "ag") == 0);
	build_str(sb, 't', buffer_size);
	result("buffer size 1 : add char #2", strcmp(sb->buffer, "agt") == 0);
	printf("%s\n", sb->buffer);
	free(sb->buffer);
	free(sb);
}

static void	test_bs100(void)
{
	size_t buffer_size = 100;
	t_strbuild *sb = new_strbuild(buffer_size);

	result("buffer size 100 : created", sb!= NULL);
	build_str(sb, 'a', buffer_size);
	result("buffer size 100 : add char #1", strcmp(sb->buffer, "a") == 0);
	build_str(sb, 'g', buffer_size);
	result("buffer size 100 : add char #2", strcmp(sb->buffer, "ag") == 0);
	build_str(sb, 't', buffer_size);
	result("buffer size 100 : add char #2", strcmp(sb->buffer, "agt") == 0);
	printf("%s\n", sb->buffer);
	free(sb->buffer);
	free(sb);
}

int main (void)
{
	printf("\n%s\n", __FILE_NAME__);
	
	test_bs1();
	test_bs100();

	return (0);
}
