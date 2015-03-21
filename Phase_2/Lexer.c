//Team 9 Group 2
//Piyush Dosi 2012C6PS317P
//Vivek Sahu 2012A7PS058P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//To get single token in each line, replace ' ");' with '\n");'

int main(){

	char filename[20];

	printf("Enter file name\n");
	scanf("%s",filename);
	FILE *fp=fopen(filename,"r");			//open input file
	FILE *fp_write=fopen("output.txt","w");		//output for parser
	FILE *fp_sym=fopen("symbol_table.txt","w");		//for symble table...id/lit and type, line no
	fprintf(fp_sym,"NAME\t\t\t\tTOKEN_TYPE\t\t\t\tLINE_NO \n\n");


	int next_char;
	int state=0;								//initialize state to 0
	int line_no=1;
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
				else if(next_char==':') state=95;
				else if(next_char=='.') state=1;
				else if(next_char==32||next_char=='\n'||next_char=='\t'){
						if(next_char=='\n') line_no++;				
						state=0;
						next_char=fgetc(fp);
					}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A') state=92;
				else if(next_char<='9' && next_char>='0') state=93;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;

			
			case 1:{
				
				next_char=fgetc(fp);
				if(next_char=='s') state=2;
				else if(next_char=='e') state=7;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 2:{
				next_char=fgetc(fp);
				if(next_char=='t') state=3;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 3:{
				next_char=fgetc(fp);
				if(next_char=='a') state=4;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 4:{
				next_char=fgetc(fp);
				if(next_char=='r') state=5;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 5:{
				next_char=fgetc(fp);
				if(next_char=='t') state=6;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 6:{
				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){

				if(next_char=='\n') line_no++;
				//fprintf(fp_write,".start ");
				fprintf(fp_write,"TK_DOTSTART ");
				//fprintf(fp_sym,"TK_DOTSTART", );
				state=0;
				next_char=fgetc(fp);
			}
			else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 7:{
				
				next_char=fgetc(fp);
				if(next_char=='n') state=8;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 8:{
				next_char=fgetc(fp);
				if(next_char=='d') state=9;
				else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
				}
				break;
			}

			case 9:{
				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
				//fprintf(fp_write,".end ");
				fprintf(fp_write,"TK_DOTEND ");

				state=0;
				next_char=fgetc(fp);
			}
			else {
					printf("Error:Illegal character found \n");
					next_char=EOF;
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 14:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"point ");
				fprintf(fp_write,"TK_POINT ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_POINT ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				
				//else fprintf(fp_write,"Error:Illegal character found \n");
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				
				break;
			}

			case 18:{
				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"wall ");
				fprintf(fp_write,"TK_WALL ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_WALL ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 23:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"window ");
				fprintf(fp_write,"TK_WINDOW ");
				state=0;
				next_char=fgetc(fp);
			}
			else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
			else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_WINDOW ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				//else fprintf(fp_write,"Error:Illegal character found \n");
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 27:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"door ");
				fprintf(fp_write,"TK_DOOR ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
			else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_DOOR ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 34:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"distance ");
				fprintf(fp_write,"TK_DISTANCE ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_DISTANCE ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				//else fprintf(fp_write,"Error:Illegal character found \n");
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 40:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"return ");
				fprintf(fp_write,"TK_RETURN ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_RETURN ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 44:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"ratio ");
				fprintf(fp_write,"TK_RATIO ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_RATIO ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				//else fprintf(fp_write,"Error:Illegal character found \n");
				break;
			}

			case 46:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"if ");
				fprintf(fp_write,"TK_IF ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IF ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
		}

			case 47:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='t') state=48;
				//fprintf(fp_write,"int ");
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 48:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"int ");
				fprintf(fp_write,"TK_INT ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_INT ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				//else fprintf(fp_write,"Error:Illegal character found \n");
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				//else fprintf(fp_write,"Error:Illegal character found \n");
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 53:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"float ");
				fprintf(fp_write,"TK_FLOAT ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_FLOAT ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 55:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"floor ");
				fprintf(fp_write,"TK_FLOOR ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_FLOOR ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}

			case 57:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"for ");
				fprintf(fp_write,"TK_FOR ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_FOR ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
		}

			case 58:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char=='u') state=59;
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
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
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
			}


			case 65:{

				//add to string id
				len=strlen(id);
				id[len]=next_char;
				id[len+1]='\0';

				next_char=fgetc(fp);
				if(next_char==32||next_char=='\n'||next_char=='\t'){
					if(next_char=='\n') line_no++;
				//fprintf(fp_write,"building ");
				fprintf(fp_write,"TK_BUILDING ");
				state=0;
				next_char=fgetc(fp);
			}
				else if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_BUILDING ");
					id[0]='\0';
				//next_char=fgetc(fp);	
				}
				break;
		}

			case 66	:{
				//fprintf(fp_write,"+ ");
				fprintf(fp_write,"TK_PLUS ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 67	:{
				//fprintf(fp_write,"- ");
				fprintf(fp_write,"TK_MINUS ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 68	:{
				//fprintf(fp_write,"/ ");
				fprintf(fp_write,"TK_DIVIDE ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 69	:{
				//fprintf(fp_write,"* ");
				fprintf(fp_write,"TK_MUL ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 70	:{
				//fprintf(fp_write,"( ");
				fprintf(fp_write,"TK_ROUND_OPEN ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 71	:{
				//fprintf(fp_write,") ");
				fprintf(fp_write,"TK_ROUND_CLOSE ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 72	:{
				//fprintf(fp_write,"{ ");
				fprintf(fp_write,"TK_CURLY_OPEN ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 73	:{
				//fprintf(fp_write,"} ");
				fprintf(fp_write,"TK_CURLY_CLOSE ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 74	:{
				//fprintf(fp_write,"[ ");
				fprintf(fp_write,"TK_SQUARE_OPEN ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 75	:{
				//fprintf(fp_write,"] ");
				fprintf(fp_write,"TK_SQUARE_CLOSE ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 76	:{
				//fprintf(fp_write,"; ");
				fprintf(fp_write,"TK_SEMICOLON ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 77	:{
				//fprintf(fp_write,", ");
				fprintf(fp_write,"TK_COMMA ");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 95 :{
				//fprintf(fp_write,"; ");
				fprintf(fp_write,"TK_COLON ");
				state=0;
				next_char=fgetc(fp);
				break;
			}

			case 78	:{
				//fprintf(fp_write,"& ");
				fprintf(fp_write,"TK_AND ");
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
				//fprintf(fp_write,"|| ");
				fprintf(fp_write,"TK_THICKNESS ");
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
				//fprintf(fp_write,"!= ");
				fprintf(fp_write,"TK_NOT_EQUAL_TO ");
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

			case 84 :{     //fprintf(fp_write,">= ");
			fprintf(fp_write,"TK_GREATER_EQUAL ");     state=0;
			next_char=fgetc(fp);     break; }

			case 85	:{
				//fprintf(fp_write,"> ");
				fprintf(fp_write,"TK_GREATER_THAN ");
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
				//fprintf(fp_write,"<= ");
				fprintf(fp_write,"TK_LESS_EQUAL ");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 88	:{
				//fprintf(fp_write,"< ");
				fprintf(fp_write,"TK_LESS_THAN ");
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
				//fprintf(fp_write,"== ");
				fprintf(fp_write,"TK_EQUALTO ");
				state=0;
				next_char=fgetc(fp);
				break;
			}	

			case 91	:{
				//fprintf(fp_write,"= ");
				fprintf(fp_write,"TK_EQUALTO ");
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
				//fprintf(fp_write,"%c ",next_char );
				if(next_char=='_'|| next_char<='z' && next_char>='a' || next_char <='Z' && next_char >='A'|| next_char<='9' && next_char>='0') state=92;
				else {
					state=0;
					//fprintf(fp_write,"%s ", id);
					fprintf(fp_write,"TK_IDENTIFIER ");fprintf(fp_sym,"%12s\t\tTK_IDENTIFIER%12d\n",id,line_no);
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
					//fprintf(fp_write,"%s ", num);
					fprintf(fp_write,"TK_LITERAL ");
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
					//fprintf(fp_write,"%s ", num);
					fprintf(fp_write,"TK_LITERAL ");
					num[0]='\0';
				
				}
				break;

			}






	}
}


fprintf(fp_write,"TK_EOF");


fclose(fp);
fclose(fp_write);


}