#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>


union Parameter
{
	char group_name[30];
	int security_level;
};

struct User
{
	char user_name[30];
	char password[30];
	union Parameter parameter; 
	
};

int linear_search(struct User *array, char search_term[], int start, int end)
{
	int i, comp;
	struct User *one_user;

	for(i=start; i < end; i++)
	{
		one_user = array+i;
		comp = strcmp(one_user->user_name, search_term);
		if(!(comp))
		{
			return i;
    	}

    	exit(0);   

	}
}

int forkSearch(struct User *array, char search_term[], int start, int end)
{
	struct User *one_user;
	int comp;

	if(start == end)
	{
		one_user = array+end;
		comp = strcmp(one_user->user_name, search_term);
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

	struct User *user_array, *one_user;
	int no_user, loop, index_b, index_l;
	char buff[255];
	FILE *fp;
	char *sep_s;

	fp = fopen( "user_file.csv", "r" );

	printf("Please enter no of total users \n");
	scanf("%d", &no_user);

	user_array = (struct User *)calloc(no_user, sizeof(struct User));
	if (user_array == NULL) exit(1);


	for(loop = 0; loop < no_user; loop++)
	{
		one_user = user_array+loop;

		fscanf(fp, "%s", buff);
		sep_s = strtok(buff,",");

		// printf("%s\n", sep_s);
		
		if (!(strcmp(sep_s, "M")))
		{
			// You can also set username password outside this block and just set Group name here
			printf("%s\n","M condition true" );
			
			sep_s = strtok(NULL, ",");
			strncpy(one_user->user_name, sep_s, sizeof(one_user->user_name));
			sep_s = strtok(NULL, ",");
			strncpy(one_user->password, sep_s, sizeof(one_user->password));
			sep_s = strtok(NULL, ",");
			strncpy(one_user->parameter.group_name, sep_s, sizeof(one_user->parameter.group_name));

			printf("%s\n", one_user->user_name);
			printf("%s\n", one_user->password);
			printf("%s\n", one_user->parameter.group_name);
				
		}

		else if (!(strcmp(sep_s, "S")))
		{
			printf("%s\n","S condition true" );
			
			// You can also set username password outside this block and just set security level here
			sep_s = strtok(NULL, ",");
			strncpy(one_user->user_name, sep_s, sizeof(one_user->user_name));
			sep_s = strtok(NULL, ",");
			strncpy(one_user->password, sep_s, sizeof(one_user->password));
			sep_s = strtok(NULL, ",");
			one_user->parameter.security_level = atoi(sep_s);

			printf("%s\n", one_user->user_name);
			printf("%s\n", one_user->password);
			printf("%d\n", one_user->parameter.security_level);
    		
		}

		else
		{
			printf("Invalid User\n");
		}

	}

	//Binary search using Fork
	index_b = forkSearch(user_array, "Anna", 0, no_user);
	printf("User is at Index using binary search: %d\n", index_b);

	//Linear search using Fork
	// Please note here start and end indexing is different than binary try to study them carefully
	pid_t child = fork();
	if(child == 0) 
		index_l = linear_search(user_array, "Anna", 0, no_user/2);
	else
		index_l = linear_search(user_array, "Anna", no_user/2, no_user);
	printf("User is at index using linear_search %d\n", index_l);
}
