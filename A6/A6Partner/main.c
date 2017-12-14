#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "main.h"

int main(void) {
	FILE *shell_turn = fopen("TURN.txt", "wt");
	putc('0', shell_turn);
	fclose(shell_turn);

	pid_t pid = fork();
	if (pid < 0) {
		printf("ERROR: Failed to fork the producer and consumer.\n");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
		producer();
	else
		consumer();
	
	return EXIT_SUCCESS;
}
