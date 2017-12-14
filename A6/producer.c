#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

#define PRODUCER_TURN '0'
#define CONSUMER_TURN '1'
#define COMPLETED_TURN '9'

void producer() {
	FILE *data = fopen("mydata.txt", "rt");
	if (data == NULL) {
		printf("ERROR: Failed to read the data file.\n");
		exit(EXIT_FAILURE);
	}

	char status;
	char currentChar = getc(data);
	FILE *shell_turn, *shell_data;
	while (!feof(data)) {
		do {
			shell_turn = fopen("TURN.txt", "rt");
			status = getc(shell_turn);
			fclose(shell_turn);
		} while (status != PRODUCER_TURN);

		shell_data = fopen("DATA.txt", "wt");
		putc(currentChar, shell_data);
		fclose(shell_data);

		status = CONSUMER_TURN;
		shell_turn = fopen("TURN.txt", "wt");
		putc(status, shell_turn);
		fclose(shell_turn);

		currentChar = getc(data);
	}

	while (status != PRODUCER_TURN) {
		shell_turn = fopen("TURN.txt", "rt");
		status = getc(shell_turn);
		fclose(shell_turn);
	}

	status = COMPLETED_TURN;
	shell_turn = fopen("TURN.txt", "wt");
	putc(status, shell_turn);
	fclose(shell_turn);

	exit(1);
}
