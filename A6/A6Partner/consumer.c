#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

#define PRODUCER_TURN '0'
#define CONSUMER_TURN '1'
#define COMPLETED_TURN '9'

void consumer() {
	FILE *shell_turn, *shell_data;
	while (1) {
		char status;
		do {
			shell_turn = fopen("TURN.txt", "rt");
			status = getc(shell_turn);
			if (status == COMPLETED_TURN)
				exit(EXIT_SUCCESS);
			fclose(shell_turn);
		} while (status != CONSUMER_TURN);

		shell_data = fopen("DATA.txt", "rt");
		putchar(getc(shell_data));
		fclose(shell_data);

		status = PRODUCER_TURN;
		shell_turn = fopen("TURN.txt", "wt");
		putc(status, shell_turn);
		fclose(shell_turn);
	}
	printf("done in c \n");
}
