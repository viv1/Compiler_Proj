#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
char ch;

char file_name[10]="inp.txt";

FILE *fp;

char *str=(char *)malloc(sizeof(char)*50);		//to store the line of code

char *var=(char *)malloc(sizeof(char)*50);		//to store variable name

int prev_var=0;							//1 means previous part of string completely identified
/*If you do want to be able to change the actual string content, the you have to do something like

char a[2][14];
strcpy(a[0], "blah");
strcpy(a[1], "hmm");*/

////////////////////////////////////////////////////
const char *delim[8];		//delimiters
delim[0]=";";
delim[1]="(";
delim[2]=")";
delim[3]="{";
delim[4]="}";
delim[5]=",";
delim[6]="[";
delim[7]="]";

const char *oper[6];		//operators
oper[0]=":";
oper[1]="&";
oper[2]="*";
oper[3]="-";
oper[4]="+";
oper[5]="/";

const char *op[2];			//operators
op[0]="||";
op[1]="!=";

const char *types[8];		//types
types[0]="int";
types[1]="float";
types[2]="distance";
types[3]="point";
types[4]="wall";
types[5]="door";
types[6]="window";
types[7]="ratio";



///////////////////////////////////////////////////
	
const char *TOKENS[7];		//keywords
TOKENS[0]="building";
TOKENS[1]="floor";
TOKENS[2]="for";
TOKENS[3]="if";
TOKENS[4]="return";
TOKENS[5]=".start";
TOKENS[6]=".end";



const char *cond[3];		//operators
cond[0]=">";
cond[1]="<";
cond[2]="=";
////////////////////////////////////////////////////////

//TO DO

//1.Variable identify
//2.Appropriate Variable identify(eg:9fl is incorrect)
//3.Literal Identify




////////////////////////////////////////////////////////
//int size=sizeof(TOKENS)/sizeof(TOKENS[0]); //won't work since variable sized array values

fp=fopen(file_name,"r");

while((ch=fgetc(fp))!='\n') str[strlen(str)]=ch;	//Read the file and store the character in the String
//printf("%d\n", ch);								//NOTE:	ch is int type
printf("%s\n",str);

char temp;

int i,j,k,m;
int i_start=-1;
//int first_loop=1;
char *curr_token=(char *)malloc(sizeof(char)*20);


//////////////////DO NOT TOUCH ABOVE THIS////////////////////////

for(i=0;i<strlen(str);i++){									//pointer 1

	
	if((i<i_start && i!=0)|| isspace(str[i])){ 									//To jump the 1st pointer to the appropriate location
							//BEWARE..not checked if isspace() works			//when keyword found previously or when the current character is space
		//printf("%d\n",i );
		continue;
	}
	
	memset(curr_token, '\0', sizeof(curr_token));			//clear the curr_token string


//////////////////DO NOT TOUCH ABOVE THIS////////////////////////


	for(j=i;j<strlen(str);j++){								//pointer 2
		
		//printf("%s\n",&str[j] );
		curr_token[strlen(curr_token)]= str[j];				//adding next character		
		//printf("%s\n",curr_token);	
		

		//printf("%s\n",curr_token );
///////////////////////////////////////////////////////////////////////

	for(k=0;k<8;k++){
		if(strcmp(curr_token,delim[k])==0){					//To check if character is delim
			printf("%s :delim\n",curr_token);
			i_start=j+1;
			break;
		}
	}
	if(i_start==j+1) break;
///////////////////////////////////////////////////////////////////////

		for(k=0;k<6;k++){
			if(strcmp(curr_token,oper[k])==0){					//To check if character is oper
				printf("%s :oper\n",curr_token);
				i_start=j+1;
				break;
			}
		}
		if(i_start==j+1) break;

////////////////////////////////////////////////////////////////////

		for(k=0;k<3;k++){
			if(strcmp(curr_token,cond[k])==0){					//To check if character is cond oper
				//printf("%s\n", &str[j+1]);
				if(strcmp(&(str[j+1]),"=")==0){
					printf("%s= :oper\n",curr_token);
					i_start=j+2;	
				}else{
					printf("%s :oper\n",curr_token);
					i_start=j+1;
				}
				printf("%s:variable\n",var );
				break;
			}
		}
		if(i_start==j+1 || i_start==j+2) break;

////////////////////////////////////////////////////////////////////		

		for(k=0;k<2;k++){									//to check for || or !=
			
			if(strcmp(curr_token,op[k])==0){
				printf("%s:oper\n",curr_token);
				i_start=j+1;
				break;

			}
		} 

		if(i_start==j+1) break;


		for(k=0;k<7;k++){									//loop to compare all the tokens with curr_string
			
			if(strcmp(curr_token,TOKENS[k])==0){
				printf("%s:token\n",curr_token);
				i_start=j+1;
				break;

			}
		} 

		if(i_start==j+1) break;

		for(k=0;k<8;k++){									//loop to compare all the types with curr_string
			
			if(strcmp(curr_token,types[k])==0){
				printf("%s:type\n",curr_token);
				i_start=j+1;
				prev_var=1;
				break;

			}
		} 

		if(i_start==j+1) break;


	strcpy(var,&str[j]);
	prev_var=0;
	}
	//printf("%s\n",var );
	//printf("%s\n",curr_token );
	printf("\n");
}
//printf("%s\n",curr_token);
fclose(fp);
return 0;

}
