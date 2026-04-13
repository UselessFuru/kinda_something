#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h> 

int main() {
	char message[] = "please enter the 'password': ";
	int status = 0; 
	char buffer[10];
	char fortune_cmd[] = "/usr/games/fortune";
	
	/* Switch to root to check password database*/
	uid_t uid = getuid();
	setuid(0);
	
	if(strncmp(buffer, "password", 8) == 0) {
	
	printf("Congratulations, you found the 'password'!\n");
	return(0);
	
	} else { 
	printf("\nThat is not the password! Please have a fortune instead:\n\n");
	
	status = system(fortune_cmd);
	if(status == -1) 
		printf("Error executing fortune commans %s", fortune_cmd);
	}
	
	/* restore original uid */ 
	setuid(uid);
	return(-1);
}
