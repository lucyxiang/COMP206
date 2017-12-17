#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

struct Member
{
	char user_name[30];
	char password[30];
	char group_name[30];
};


struct System_op
{
	char user_name[30];
	char password[30];
	int security_level;
};

union User
{
	struct Member member;
	struct System_op system_op;
	
} u1, u2;

int forkSearch(union User *array, char search_term[], int start, int end)
{
	union User *one_user;
	int comp;

	if(start == end)
	{
		one_user = array+end;
		comp = strcmp(one_user->member.user_name, search_term);
		if(!(comp))
		{
			
			return end;
    	}

    	exit(0);    	

	}
	else
	{
		
		pid_t child = fork();
		if(child == 0) return forkSearch(array, search_term, start, (start+end)/2);
		else return forkSearch(array, search_term, (start + end)/2 + 1, end);
	}
}


int main()
{

	union User *user_array, *one_user;
	int no_user, loop, index;
	char buff[255];
	FILE *fp;
	char *sep_s;

	fp = fopen( "user_file.csv", "r" );

	printf("Please enter no of total users \n");
	scanf("%d", &no_user);

	user_array = (union User *)calloc(no_user, sizeof(union User));
	if (user_array == NULL) exit(1);


	for(loop = 0; loop < no_user; loop++)
	{
		one_user = user_array+loop;

		fscanf(fp, "%s", buff);
		sep_s = strtok(buff,",");

		// printf("%s\n", sep_s);
		
		if (!(strcmp(sep_s, "M")))
		{
			printf("%s\n","M condition true" );
			
			sep_s = strtok(NULL, ",");
			strncpy(one_user->member.user_name, sep_s, sizeof(one_user->member.user_name));
			sep_s = strtok(NULL, ",");
			strncpy(one_user->member.password, sep_s, sizeof(one_user->member.password));
			sep_s = strtok(NULL, ",");
			strncpy(one_user->member.group_name, sep_s, sizeof(one_user->member.group_name));

			printf("%s\n", one_user->member.user_name);
			printf("%s\n", one_user->member.password);
			printf("%s\n", one_user->member.group_name);
				
		}

		else if (!(strcmp(sep_s, "S")))
		{
			printf("%s\n","S condition true" );
			
			sep_s = strtok(NULL, ",");
			strncpy(one_user->system_op.user_name, sep_s, sizeof(one_user->system_op.user_name));
			sep_s = strtok(NULL, ",");
			strncpy(one_user->system_op.password, sep_s, sizeof(one_user->system_op.password));
			sep_s = strtok(NULL, ",");
			one_user->system_op.security_level = atoi(sep_s);

			printf("%s\n", one_user->system_op.user_name);
			printf("%s\n", one_user->system_op.password);
			printf("%d\n", one_user->system_op.security_level);
    		
		}

		else
		{
			printf("Invalid User\n");
		}

	}

	index = forkSearch(user_array, "Anna", 0, 2);

	printf("User is at Index: %d\n", index);

}
