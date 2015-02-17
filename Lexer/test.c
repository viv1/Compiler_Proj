#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
char ch;

char file_name[10]="inp.txt";

FILE *fp;

char *str=(char *)malloc(sizeof(char)*20);

/*If you do want to be able to change the actual string content, the you have to do something like

char a[2][14];
strcpy(a[0], "blah");
strcpy(a[1], "hmm");*/


const char *TOKENS[2];
TOKENS[0]="building";
TOKENS[1]="floor";

//int size=sizeof(TOKENS)/sizeof(TOKENS[0]);
fp=fopen(file_name,"r");

while((ch=fgetc(fp))!='\n') str[strlen(str)]=ch;

printf("%s\n",str);

char temp;

int i,j,k,m;
char *curr_token=(char *)malloc(sizeof(char)*20);

for(i=0;i<strlen(str);i++){									//pointer 1
	
	memset(curr_token, '\0', sizeof(curr_token));			//clear the curr_token string

	for(j=i;j<strlen(str);j++){								//pointer 2
		
		curr_token[strlen(curr_token)]=str[j];				
		for(k=0;k<2;k++){
			
			if(strcmp(curr_token,TOKENS[k])==0){
				printf("SUCCESS\n");
			}
		} 
		
	}
	printf("\n");
}
//printf("%s\n",curr_token);

fclose(fp);
return 0;

}
