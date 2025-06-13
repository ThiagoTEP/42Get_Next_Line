#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*get_next_line(int fd);

void swap_nl_for_dots(char *line)
{
	int i;
	if (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
				line[i] = '.';
			i++;
		}
	}
}

int test_gnl(int fd, char *expected, int test_nbr, char *testing)
{
	char *s;
	int errors;

	errors = 0;
	if (testing)
		printf("Testing: %s\n", testing);
	printf("Test %i. -> ", test_nbr);
	s = get_next_line(fd);
	if (s && expected)
	{
		swap_nl_for_dots(s);
		if (strcmp(s, expected) == 0)
			printf("\033[0;32mOK!\033[0m ");
		else
		{
			printf("\033[0;31mKO!\033[0m ");
			errors++;
		}
	}
	else
	{
		if (expected == NULL)
			printf("\033[0;32mOK!\033[0m ");
		else
		{
			printf("\033[0;31mKO!\033[0m ");
			errors++;
		}
	}
	printf("\n-> Expected: %s\n-> Output:   %s\n\n", expected, s);
	free(s);
	return (errors);
}

int main()
{
	int errors = 0;

	printf("Testing BUFFER_SIZE=%i\n\n", BUFFER_SIZE);

	int fd0 = open("files/invalid_file.txt", O_RDONLY);
	int fd1 = open("files/onechar.txt", O_RDONLY);
	int fd2 = open("files/onlyline.txt", O_RDONLY);
	int fd3 = open("files/bigline.txt", O_RDONLY);
	int fd4 = open("files/onlyNL.txt", O_RDONLY);
	int fd5 = open("files/multipleNL.txt", O_RDONLY);
	int fd6 = open("files/bigNL.txt", O_RDONLY);
	int fd7 = open("files/randomNL.txt", O_RDONLY);
	int fd8 = open("files/giantline.txt", O_RDONLY);

	printf("============ Reading invalid_file.txt ============\n");
	errors += test_gnl(fd0, NULL, 1, "Invalid file.");
	//close(fd0);

	printf("============ Reading onechar.txt ============\n");
	errors += test_gnl(fd1, "a", 1, "One char no line.");

	printf("============ Reading onlyline.txt ============\n");
	errors += test_gnl(fd2, "aaaaaaaaaaaaaa", 1, "One line.");

	printf("============ Reading bigline.txt ============\n");
	errors += test_gnl(fd3, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1, "One big line.");

	printf("============ Reading onlyNL.txt ============\n");
	errors += test_gnl(fd4, ".", 1, "One new line.");

	printf("============ Reading multipleNL.txt ============\n");
	printf("============ \\n\\ = '.' ============\n");
	errors += test_gnl(fd5, ".", 1, "New line.");
	errors += test_gnl(fd5, ".", 2, "Other new line.");
	errors += test_gnl(fd5, ".", 3, "Other new line.");
	errors += test_gnl(fd5, ".", 4, "Other new line.");
	errors += test_gnl(fd5, ".", 5, "Other new line.");
	errors += test_gnl(fd5, ".", 6, "Other new line.");
	errors += test_gnl(fd5, ".", 7, "Other new line.");

	printf("============ Reading bigNL.txt ============\n");
	printf("============ \\n\\ = '.' ============\n");
	errors += test_gnl(fd6, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.", 1, "One big new line.");

	printf("============ Reading randomNL.txt ============\n");
	printf("============ \\n\\ = '.' ============\n");
	errors += test_gnl(fd7, "0123456789.", 1, "First random new line.");
	errors += test_gnl(fd7, "012345678.", 2, "Other random new line.");
	errors += test_gnl(fd7, "01234567.", 3, "Other random new line.");
	errors += test_gnl(fd7, "0123456.", 4, "Other random new line.");
	errors += test_gnl(fd7, "012345.", 5, "Other random new line.");
	errors += test_gnl(fd7, "01234.", 6, "Other random new line.");
	errors += test_gnl(fd7, "0123.", 7, "Other random new line.");
	errors += test_gnl(fd7, "012.", 8, "Other random new line.");
	errors += test_gnl(fd7, "01.", 9, "Other random new line.");
	errors += test_gnl(fd7, "0.", 10, "Other random new line.");

	// Read file to expected
	int read_to_copy = open("files/giantline.txt", O_RDONLY);
	char expected[20000 + 1] = {0};
	read(read_to_copy, expected, 20000);
	expected[20000] = '\0';
	close(read_to_copy);

	printf("============ Reading giantline.txt ============\n");
	errors += test_gnl(fd8, expected, 1, "Giant line.");

	// Close files.

	/*
	int fd1 = open("onechar.txt", O_RDONLY);
	int fd2 = open("onlyline.txt", O_RDONLY);
	int fd3 = open("bigline.txt", O_RDONLY);
	int fd4 = open("onlyNL.txt", O_RDONLY);
	int fd5 = open("multipleNL.txt", O_RDONLY);
	int fd6 = open("bigNL.txt", O_RDONLY);
	int fd7 = open("randomNL.txt", O_RDONLY);
	*/
	errors += test_gnl(fd1, NULL, 2, "End of file. -> onechar.txt");
	errors += test_gnl(fd2, NULL, 2, "End of file. -> onlyline.txt");
	errors += test_gnl(fd3, NULL, 2, "End of file. -> bigline.txt");
	errors += test_gnl(fd4, NULL, 2, "End of file. -> onlyNL.txt");
	errors += test_gnl(fd5, NULL, 8, "End of file. -> multipleNL.txt");
	errors += test_gnl(fd6, NULL, 2, "End of file. -> bigNL.txt");
	errors += test_gnl(fd7, NULL, 11, "End of file. -> randomNL.txt");
	errors += test_gnl(fd8, NULL, 2, "End of file. -> randomNL.txt");
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	close(fd7);
	close(fd8);

	if (errors)
		printf("\033[0;31mSomething is wrong! Check test!\033[0m\n");
	else
		printf("\033[0;32mAll correct! Congratulations!\033[0m\n\n");
}
