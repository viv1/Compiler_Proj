#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE *fp=fopen("input.txt","r");			//open input file
	FILE *fp_write=fopen("output.txt","w");
	int next_char;
	int state=0;								//initialize state to 0
	next_char=fgetc(fp);	
	char id[20];	
	char num[20];
	int len;
	

//imp..there is no reading a char in state 0

while(next_char != EOF){


	
	switch(state){

		case 0:
				id[0]='\0';
				num[0]='\0';

				if(next_char=='p') state=10;
				else if(next_char=='w') state=15;
				else if(next_char=='d') state=24;
				else if(next_char=='r') state=35;
				else if(next_char=='i') state=45;
				else if(next_char=='f') state=49;
				else if(next_char=='b') state=58;

				else if(next_char=='+') state=66;
				else if(next_char=='-') state=67;
				else if(next_char=='/') state=68;
				else if(next_char=='*') state=69;
				else if(next_char=='(') state=70;
				else if(next_char==')') state=71;
				else if(next_char=='{') state=72;
				else if(next_char=='}') state=73;
				else if(next_char=='[') state=74;
				else if(next_char==']') state=75;
				else if(next_char==';') state=76;
				else if(next_char==',') state=77;
				else if(next_char=='&') state=78;
				else if(next_char=='|') state=79;
				else if(next_char=='!') state=81;
				else if(next_char=='>') state=83;
				else if(next_char=='<') state=86;
				else if(next_char=='=') state=89;
				else if(next_char=='.') state=1;
				else if(next_char==32||next_char=='\n'||next_char=='\t'){				
						state=0;
						next_char=fgetc(fp);
					}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A') state=92;
				else if(next_char<='9' && next_char>='0') state=93;
				else fprintf(fp_write,"error\n");
				break;

			
			case 1:{
				
				next_char=fgetc(fp);
				if(next_char=='s') state=2;
				else if(next_char=='e') state=7;
				else fprintf(fp_write,"error1\n");
				break;
			}

			case 2:{
				next_char=fgetc(fp);
				if(next_char=='t') state=3;
				break;
			}

			case 3:{
				next_char=fgetc(fp);
				if(next_char=='a') state=4;
				break;
			}

			case 4:{
				next_char=fgetc(fp);
				if(next_char=='r') state=5;
				break;
			}

			case 5:{
				next_char=fgetc(fp);
				if(next_char=='t') state=6;
				break;
			}

			case 6:{
				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){

				fprintf(fp_write,".start\n");
				state=0;
				next_char=fgetc(fp);
			}
				break;
			}

			case 7:{
				
				next_char=fgetc(fp);
				if(next_char=='n') state=8;
				break;
			}

			case 8:{
				next_char=fgetc(fp);
				if(next_char=='d') state=9;
				break;
			}

			case 9:{
				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,".end\n");
				state=0;
				next_char=fgetc(fp);
			}

				break;
			}

			case 10:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='o') state=11;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 11:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='i') state=12;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 12:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='n') state=13;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 13:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='t') state=14;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 14:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"point\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 15:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';
				
				next_char=fgetc(fp);
				if(next_char=='a') state=16;
				else if(next_char=='i') state=19;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;

				else fprintf(fp_write,"error1\n");
				break;
			}

			case 16:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='l') state=17;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;

				break;
			}

			case 17:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='l') state=18;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;

				break;
			}

			case 18:{
				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"wall\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;

			break;
		}

			case 19:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='n') state=20;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;

				break;
			}

			case 20:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='d') state=21;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 21:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='o') state=22;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 22:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='w') state=23;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 23:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"window\n");
				state=0;
				next_char=fgetc(fp);
			}
			else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
			break;
		}


			case 24:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';
				
				next_char=fgetc(fp);
				if(next_char=='o') state=25;
				else if(next_char=='i') state=28;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else fprintf(fp_write,"error1\n");
				break;
			}

			case 25:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='o') state=26;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 26:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';


				next_char=fgetc(fp);
				if(next_char=='r') state=27;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 27:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"door\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
			break;
		}

			case 28:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='s') state=29;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 29:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='t') state=30;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 30:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='a') state=31;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 31:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='n') state=32;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 32:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='c') state=33;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 33:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='e') state=34;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 34:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"distance\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 35:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';
				
				next_char=fgetc(fp);
				if(next_char=='e') state=36;
				else if(next_char=='a') state=41;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else fprintf(fp_write,"error1\n");
				break;
			}


			case 36:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='t') state=37;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 37:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='u') state=38;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 38:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='r') state=39;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}


			case 39:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='n') state=40;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 40:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"return\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 41:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='t') state=42;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 42:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='i') state=43;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 43:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='o') state=44;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 44:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"ratio\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 45:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';
				
				next_char=fgetc(fp);
				if(next_char=='f') state=46;
				else if(next_char=='n') state=47;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else fprintf(fp_write,"error1\n");
				break;
			}

			case 46:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"if\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 47:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='t') state=48;
				//fprintf(fp_write,"int\n");
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 48:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"int\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 49:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';
				
				next_char=fgetc(fp);
				if(next_char=='l') state=50;
				else if(next_char=='o') state=56;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else fprintf(fp_write,"error1\n");
				break;
			}

			case 50:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='o') state=51;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 51:{
				
				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='a') state=52;
				else if(next_char=='o') state=54;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else fprintf(fp_write,"error1\n");
				break;
			}

			case 52:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='t') state=53;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 53:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"float\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 54:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='r') state=55;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 55:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"floor\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 56:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='r') state=57;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 57:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"for\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 58:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='u') state=59;
				break;
			}

			case 59:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='i') state=60;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 60:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='l') state=61;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 61:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='d') state=62;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 62:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='i') state=63;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 63:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='n') state=64;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}

			case 64:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='g') state=65;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
			}


			case 65:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				fprintf(fp_write,"building\n");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				break;
		}

			case 66	:{
				fprintf(fp_write,"+\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 67	:{
				fprintf(fp_write,"-\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 68	:{
				fprintf(fp_write,"/\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 69	:{
				fprintf(fp_write,"*\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 70	:{
				fprintf(fp_write,"(\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 71	:{
				fprintf(fp_write,")\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 72	:{
				fprintf(fp_write,"{\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 73	:{
				fprintf(fp_write,"}\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 74	:{
				fprintf(fp_write,"[\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 75	:{
				fprintf(fp_write,"]\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 76	:{
				fprintf(fp_write,";\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 77	:{
				fprintf(fp_write,",\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 78	:{
				fprintf(fp_write,"&\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}		

			case 79	:{
				next_char=fgetc(fp);
				if(next_char=='|') state=80;
				
				break;
			}

			case 80	:{
				fprintf(fp_write,"||\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 81	:{
				next_char=fgetc(fp);
				if(next_char=='=') state=82;
				
				break;
			}

			case 82	:{
				fprintf(fp_write,"!=\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 83	:{
				next_char=fgetc(fp);
				if(next_char=='=') state=84;
				else state=85;
				
				break;
			}

			case 84	:{
				fprintf(fp_write,">=\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 85	:{
				fprintf(fp_write,">\n");
				state=0;
				//next_char=fgetc(fp);			//NOTE....next character already read in state 83
				break;
			}	

			case 86	:{
				next_char=fgetc(fp);
				if(next_char=='=') state=87;
				else state=88;
				
				break;
			}

			case 87	:{
				fprintf(fp_write,"<=\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 88	:{
				fprintf(fp_write,"<\n");
				state=0;
				//next_char=fgetc(fp);				//NOTE....next character already read in state 86
				break;
			}	

			case 89	:{
				next_char=fgetc(fp);
				if(next_char=='=') state=90;
				else state=91;
				
				break;
			}

			case 90	:{
				fprintf(fp_write,"==\n");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 91	:{
				fprintf(fp_write,"=\n");
				state=0;
				//next_char=fgetc(fp);				//NOTE....next character already read in state 89
				break;
			}	

			case 92 :{							//identifier
				

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				//fprintf(fp_write,"%c\n",next_char );
				if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					fprintf(fp_write,"%s\n", id);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}


			case 93 :{

				len=strlen(num);
				num[len]=next_char;
				num[len+1]='\0';

				next_char=fgetc(fp);	
				if(next_char<='9' && next_char>='0') state=93;
				else if(next_char=='.') state=94;
				else {
					state=0;
					fprintf(fp_write,"%s\n", num);
					num[0]='\0';
				
				}
				break;

			}

			case 94 :{

				len=strlen(num);
				num[len]=next_char;
				num[len+1]='\0';

				next_char=fgetc(fp);	
				if(next_char<='9' && next_char>='0') state=94;
				
				else {
					state=0;
					fprintf(fp_write,"%s\n", num);
					num[0]='\0';
				
				}
				break;

			}






	}
}


fclose(fp);
fclose(fp_write);


}