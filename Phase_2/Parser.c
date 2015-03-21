
//Team 9 Group 2
//Piyush Dosi 2012C6PS317P
//Vivek Sahu 2012A7PS058P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char token_types[50][15];
FILE *ptr;
char input[15];
char input_tokens[200][15];
//char terminals[50][15];
int i=0;
int j=-1;

enum token{
	TK_INT,TK_FLOAT,TK_POINT,TK_DISTANCE,TK_WALL,TK_DOOR,TK_WINDOW,TK_RATIO,TK_BUILDING,TK_IDENTIFIER,TK_RETURN,TK_IF,TK_FOR,TK_SEMICOLON,TK_SQUARE_OPEN,TK_SQUARE_CLOSE,TK_ROUND_OPEN,TK_ROUND_CLOSE,TK_EQUALTO,TK_LITERAL,TK_COMMA,TK_COLON,TK_THICKNESS,TK_PLUS,TK_MINUS,TK_MUL,TK_DIVIDE,TK_DOTSTART,TK_DOTEND,TK_AND,TK_FLOOR,TK_LESS_THAN,TK_GREATER_THAN,TK_NOT_EQUAL_TO,TK_CURLY_OPEN,TK_CURLY_CLOSE,TK_EOF 
};


void getallTokens(){

	//fillDict();
	i=0;
	while(fscanf(ptr,"%s",input)!=EOF) {
		strcpy(input_tokens[i],input);


       /* if(!strcmp(input_tokens[i],"TK_SEMICOLON")){ 
            printf("WTF\n");
        printf("%s\n", input_tokens[i]);
        printf("%s\n", input_tokens[i-1]);
        printf("%s\n", input_tokens[i-2]);
    }*/
		i++;
	}
	
}

//RETURNS NEXT TOKEN
enum token getToken(){
    
    if(j<i-1){
        j++;
//printf("%s\n",input_tokens[j] );


        
        if(!strcmp(input_tokens[j],"TK_INT")){ return TK_INT;}
        else if(!strcmp(input_tokens[j],"TK_FLOAT")){ return TK_FLOAT;}
        else if(!strcmp(input_tokens[j],"TK_POINT")){ return TK_POINT;}
        else if(!strcmp(input_tokens[j],"TK_DISTANCE")){ return TK_DISTANCE;}
        else if(!strcmp(input_tokens[j],"TK_WALL")){ return TK_WALL;}
        else if(!strcmp(input_tokens[j],"TK_DOOR")){ return TK_DOOR;}
        else if(!strcmp(input_tokens[j],"TK_WINDOW")){ return TK_WINDOW;}
        else if(!strcmp(input_tokens[j],"TK_RATIO")){ return TK_RATIO;}
        else if(!strcmp(input_tokens[j],"TK_BUILDING")){ return TK_BUILDING;}
        else if(!strcmp(input_tokens[j],"TK_IDENTIFIER")){return TK_IDENTIFIER;}
        else if(!strcmp(input_tokens[j],"TK_RETURN")){ return TK_RETURN;}
        else if(!strcmp(input_tokens[j],"TK_IF")){ return TK_IF;}
        else if(!strcmp(input_tokens[j],"TK_FOR")){ return TK_FOR;}
        else if(!strcmp(input_tokens[j],"TK_SEMICOLON")){ return TK_SEMICOLON;}
        else if(!strcmp(input_tokens[j],"TK_SQUARE_OPEN")){ return TK_SQUARE_OPEN;}
        else if(!strcmp(input_tokens[j],"TK_SQUARE_CLOSE")){ return TK_SQUARE_CLOSE;}
        else if(!strcmp(input_tokens[j],"TK_SQUARE_CLOSETK_SEMICOLON")){ return TK_SQUARE_CLOSE;}
        else if(!strcmp(input_tokens[j],"TK_SQUARE_CLOSETK_EQUALTO")){ return TK_SQUARE_CLOSE;}
        else if(!strcmp(input_tokens[j],"TK_SQUARE_CLOSETK_NOT_EQUAL_TO")){ return TK_SQUARE_CLOSE;}
         else if(!strcmp(input_tokens[j],"TK_SQUARE_CLOSETK_GREATER_THAN")){ return TK_SQUARE_CLOSE;}
        else if(!strcmp(input_tokens[j],"TK_SQUARE_CLOSETK_LESS_THAN")){ return TK_SQUARE_CLOSE;}
       else if(!strcmp(input_tokens[j],"TK_ROUND_OPEN")){ return TK_ROUND_OPEN;}
        else if(!strcmp(input_tokens[j],"TK_ROUND_CLOSE")){ return TK_ROUND_CLOSE;}
        else if(!strcmp(input_tokens[j],"TK_EQUALTO")){ return TK_EQUALTO;}
        else if(!strcmp(input_tokens[j],"TK_LITERAL")){ return TK_LITERAL;}
        else if(!strcmp(input_tokens[j],"TK_COMMA")){ return TK_COMMA;}
        else if(!strcmp(input_tokens[j],"TK_COLON")){ return TK_COLON;}
        else if(!strcmp(input_tokens[j],"TK_THICKNESS")){ return TK_THICKNESS;}
        else if(!strcmp(input_tokens[j],"TK_PLUS")){ return TK_PLUS;}
        else if(!strcmp(input_tokens[j],"TK_MINUS")){ return TK_MINUS;}
        else if(!strcmp(input_tokens[j],"TK_MUL")){ return TK_MUL;}
        else if(!strcmp(input_tokens[j],"TK_DIVIDE")){ return TK_DIVIDE;}
        else if(!strcmp(input_tokens[j],"TK_DOTSTART")){ return TK_DOTSTART;}
        else if(!strcmp(input_tokens[j],"TK_DOTEND")){ return TK_DOTEND;}
        else if(!strcmp(input_tokens[j],"TK_AND")){ return TK_AND;}
        else if(!strcmp(input_tokens[j],"TK_FLOOR")){ return TK_FLOOR;}
        else if(!strcmp(input_tokens[j],"TK_LESS_THAN")){ return TK_LESS_THAN;}
        else if(!strcmp(input_tokens[j],"TK_GREATER_THAN")){ return TK_GREATER_THAN;}
        else if(!strcmp(input_tokens[j],"TK_NOT_EQUAL_TO")){ return TK_NOT_EQUAL_TO;}
        else if(!strcmp(input_tokens[j],"TK_CURLY_OPEN")){ return TK_CURLY_OPEN;}
        else if(!strcmp(input_tokens[j],"TK_CURLY_CLOSE")){ return TK_CURLY_CLOSE;}
        else if(!strcmp(input_tokens[j],"TK_EOF")){ return TK_EOF;}
        //else if(!strcmp(input_tokens[j],"")) return getToken();
        else {
           printf("Lala:%s:Lala\n",input_tokens[j] );
            return -1;
}


    }

}

typedef struct node{
    char s[50];
    //int n; // Number of children...
	
    struct node* child[15];

}node;




struct node * make_nt_node(char nonterminal[20]);

enum token getToken();





struct node * make_nt_node(char nonterminal[20]){
    struct node *m;
    m  =  (struct node *)malloc(sizeof(struct node));
    strcpy(m->s,nonterminal);
    return m;
}



enum token tok;


void pr_error(char *s){
    fprintf(stdout,"%s",s);

}
void advance(){
    tok = getToken();
    }

void eat(enum token t) {
	

    if(tok == t){
    printf("Eating token no. %d\n",tok);
    advance();
    printf("New token no. %d\n",tok );
    if(tok==TK_EOF) printf("Parsing Completed Successfully\n");
}
    else
        pr_error("Cannot eat this token\n");
        printf("%d\n",tok );

    }

struct node * id(){
    //printf("id\n");
    // enter the symbol in symbol table...
    //printf("eating id\n");
	eat(TK_IDENTIFIER);
    //printf("eaten\n");
    //printf("%d\n",tok );

}

struct node * literal(){
	   
 printf("literal\n");
eat(TK_LITERAL);

}

void error(){
    printf("Error\n");

}




struct node * Prog();

struct node * functions();

struct node * _function();

struct node * type();

struct node * params();

struct node * _stats();

struct node * stat();

struct node * forfunction();

struct node * iffunction();

struct node * returnstats();

struct node * funcstats();

struct node * normalstats();

struct node * Zip();

struct node * LF3();

struct node * kim();

struct node * E();

struct node * LF1();

struct node * LF4();

struct node * LF5();

struct node * LF6();

struct node * K();

struct node * LF7();

struct node * LF8();

struct node * LF0();

struct node * buildparams();

struct node * LF9();

struct node * arithmeticoperators();

struct node * building();
struct node * newstats();

struct node * body();

struct node * ifrelatedstuff();

struct node * forrelatedstuff();

struct node * _floor();

struct node * arr();

struct node * _exp();

struct node * conditionaloperator();

struct node * LF10();


void traverse(struct node * tree){


    if(tree->s!=NULL){
if(!strcmp(tree->s,"EPS")) return;
    printf("%s",tree->s);
    printf("->");
}
else return;
    
    struct node *ptr;
    ptr = tree->child[0];

    int i=0;
    int j=0;

    if(ptr->s!=NULL){
    printf("%s\t",ptr->s);
    i++;
}else return;

    while(tree->child[i]!= NULL){
       ptr = tree->child[i];
       if(ptr->s!=NULL) printf("%s\t",ptr->s);
       i++;
    }
    printf("\n");

//////////////////////////

    /*for (j = 0; j < i; ++j)
    {
       if(tree->child[j]!=NULL) traverse(tree->child[j]);
       else return;
    }*/

       printf("%s\n",tree->child[1]->child[0]/*->child[0]->child[0]*/->s );

        printf("\n");


/////////////////
   /*ptr = tree->child[0];
    int j=0;

    for(j=0;j<i;j++){
        if(tree->child[j]!=NULL){
        ptr=tree->child[j];
        traverse(ptr);
    }else return;

    }*/
    

    /*while(ptr!= NULL){
       traverse(ptr);
        printf("\n");
       ptr = ptr->child[j];
       j++;
    }*/
    /*
        ptr=tree->child[j];
    }*/



/*        ptr = tree->child[0];
    while(ptr!= NULL){
int j=0;
    for(j=0;j<i;j++){
       traverse(ptr);
        printf("\n");
       ptr = ptr->child[++j];
}
    }*/

    
    
    return;
}   



main(){

	struct node *pt_ptr;
	pt_ptr = (struct node *)malloc(sizeof(struct node));
	//strcpy(pt_ptr->s ,"PArse Tree");
	//ptr=fopen("output.txt","r");
	ptr=fopen("output.txt","r");
	getallTokens();

        tok=getToken();

	//printf("%d",tok);
    
   // pt_ptr->child[0] = Prog();

        pt_ptr=Prog();

        //traverse(pt_ptr);
  
    //traverse(pt_ptr);
    //tok = getToken();
	//normalstats();
 	//building();
	//normalstats();
	
}





struct node * Prog(){
    	struct node * n;
    	n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"Prog");
    //pr_error("Prog -->");
           
        pr_error("<Prog> ===> <functions><building>\n");
    switch(tok){
        case TK_INT:
           // strcpy(n->s,"Prog");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;

            break;
	case TK_WINDOW:
           // strcpy(n->s,"Prog");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;

            break;

	case TK_DOOR:
           // strcpy(n->s,"Prog");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;

            break;
	case TK_POINT:
           // strcpy(n->s,"Prog");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;

            break;
	case TK_WALL:
           // strcpy(n->s,"Prog");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;

            break;

        case TK_FLOAT:
          // strcpy(n->s = "Prog");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;
            break;

        case TK_DISTANCE:
           // strcpy(n->s,"Prog");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;
            break;

        case TK_RATIO:
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;
            break;

        case TK_BUILDING:
           // n->str = "Prog";
            //printf("yayy\n");
            n->child[0] = functions();
            n ->child[1] = building();
            n->child[2] = NULL;
            break;
        case TK_EOF:   //end of file
            //accept..
		
            printf("Completed\n");
            break;

        default:
            pr_error("Expecting type or building \n");

    }
    return n;
}


struct node * functions(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s,"functions");
    //printf("functions\t");

    switch(tok){
        case TK_INT:
        pr_error("<functions> ===> <function><functions>");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;

        case TK_FLOAT:
pr_error("<functions> ===> <function><functions>\n");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;
	case TK_POINT:
pr_error("<functions> ===> <function><functions>\n");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;
	case TK_WALL:
pr_error("<functions> ===> <function><functions>\n");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;
	case TK_DOOR:
pr_error("<functions> ===> <function><functions>\n");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;
	case TK_WINDOW:
pr_error("<functions> ===> <function><functions>\n");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;

        case TK_DISTANCE:
pr_error("<functions> ===> <function><functions>\n");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;

        case TK_RATIO:
pr_error("<functions> ===> <function><functions>\n");
            n->child[0] = _function();
            n->child[1] = functions();
            n->child[2] = NULL;
            break;
        case TK_BUILDING:
            //   wwrror ...eat(TK_BUILDING);
        //printf("going\n");
        pr_error("<functions> ===> EPS\n");
	    n->child[0] = make_nt_node("EPS");
            break;
        default:
            pr_error("Expecting type or building");

    }
    return n;
}

struct node * _function(){
     struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
     strcpy(n->s,"function");
     //printf("function\t");
     pr_error("<function> ===><type><id>TK_ROUND_OPEN<params>TK_ROUND_CLOSETK_CURLY_OPEN<stats>TK_CURLY_CLOSE\n");

    switch(tok){
        case TK_INT:

            n->child[0] = type();
            n->child[1] = id();

            //n->child[2]->s = "TK_ROUND_OPEN"

            eat(TK_ROUND_OPEN);
            n->child[2] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[2]->s,"(");

             n->child[3]=params();
            eat(TK_ROUND_CLOSE);
	
            n->child[4] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[4]->s,")");

            eat(TK_CURLY_OPEN);
            n->child[5] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[5]->s,"{");
            
	    n->child[6] =_stats();


            eat(TK_CURLY_CLOSE);
            n->child[7] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[7]->s,"}");

            n->child[8] = NULL;

            break;

        case TK_FLOAT:
            n->child[0] = type();
            n->child[1] = id();
            eat(TK_ROUND_OPEN);
            n->child[2] = make_nt_node("(");
            n->child[3] =  params();
            eat(TK_ROUND_CLOSE);
            n->child[4] = make_nt_node(")");

            eat(TK_CURLY_OPEN);
            n->child[5] = make_nt_node("{");
            n->child[6] = _stats();
            eat(TK_CURLY_CLOSE);
            n->child[7] = make_nt_node("}");
		n->child[8] = NULL;
            break;

	case TK_DOOR:
            n->child[0] = type();
            n->child[1] = id();
            eat(TK_ROUND_OPEN);
            n->child[2] = make_nt_node("(");
            n->child[3] =  params();
            eat(TK_ROUND_CLOSE);
            n->child[4] = make_nt_node(")");

            eat(TK_CURLY_OPEN);
            n->child[5] = make_nt_node("{");
            n->child[6] = _stats();
            eat(TK_CURLY_CLOSE);
            n->child[7] = make_nt_node("}");
		n->child[8] = NULL;
            break;
	
	case TK_WINDOW:
            n->child[0] = type();
            n->child[1] = id();
            eat(TK_ROUND_OPEN);
            n->child[2] = make_nt_node("(");
            n->child[3] =  params();
            eat(TK_ROUND_CLOSE);
            n->child[4] = make_nt_node(")");

            eat(TK_CURLY_OPEN);
            n->child[5] = make_nt_node("{");
            n->child[6] = _stats();
            eat(TK_CURLY_CLOSE);
            n->child[7] = make_nt_node("}");
		n->child[8] = NULL;
            break;

	case TK_POINT:
            n->child[0] = type();
            n->child[1] = id();
            eat(TK_ROUND_OPEN);
            n->child[2] = make_nt_node("(");
            n->child[3] =  params();
            eat(TK_ROUND_CLOSE);
            n->child[4] = make_nt_node(")");

            eat(TK_CURLY_OPEN);
            n->child[5] = make_nt_node("{");
            n->child[6] = _stats();
            eat(TK_CURLY_CLOSE);
            n->child[7] = make_nt_node("}");
		n->child[8] = NULL;
            break;

	case TK_WALL:
            n->child[0] = type();
            n->child[1] = id();
            eat(TK_ROUND_OPEN);
            n->child[2] = make_nt_node("(");
            n->child[3] =  params();
            eat(TK_ROUND_CLOSE);
            n->child[4] = make_nt_node(")");

            eat(TK_CURLY_OPEN);
            n->child[5] = make_nt_node("{");
            n->child[6] = _stats();
            eat(TK_CURLY_CLOSE);
            n->child[7] = make_nt_node("}");
		n->child[8] = NULL;
            break;

        case TK_DISTANCE:
            n->child[0] = type();
            n->child[1] = id();
            eat(TK_ROUND_OPEN);
            n->child[2] = make_nt_node("(");
            n->child[3] =  params();
            eat(TK_ROUND_CLOSE);
            n->child[4] = make_nt_node(")");

            eat(TK_CURLY_OPEN);
            n->child[5] = make_nt_node("{");
            n->child[6] = _stats();
            eat(TK_CURLY_CLOSE);
            n->child[7] = make_nt_node("}");
            break;

        case TK_RATIO:
            n->child[0] = type();
            n->child[1] = id();
            eat(TK_ROUND_OPEN);
            n->child[2] = make_nt_node("(");
            n->child[3] =  params();
            eat(TK_ROUND_CLOSE);
            n->child[4] = make_nt_node(")");

            eat(TK_CURLY_OPEN);
            n->child[5] = make_nt_node("{");
            n->child[6] = _stats();
            eat(TK_CURLY_CLOSE);
            n->child[7] = make_nt_node("}");
            break;

        default:
            pr_error("Expecting type\n");
}
    return n;
}

struct node * type(){
     struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
     strcpy(n->s,"type");
     pr_error("<type> ===>TK_INT/TK_FLOAT/TK_DISTANCE/TK_POINT/TK_WALL/TK_DOOR/TK_WINDOW/TK_RATIO\n");
    switch(tok){
        case TK_INT:
            eat(TK_INT);
           //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0] = make_nt_node("int");
            break;

        case TK_FLOAT:
            eat(TK_FLOAT);
           // n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]= make_nt_node("float");
            break;
	
	case TK_DOOR:
            eat(TK_DOOR);
           // n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]= make_nt_node("door");
            break;
	case TK_WINDOW:
            eat(TK_WINDOW);
           // n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]= make_nt_node("window");
            break;
	case TK_POINT:
            eat(TK_POINT);
           // n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]= make_nt_node("point");
            break;
	case TK_WALL:
            eat(TK_WALL);
           // n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]= make_nt_node("wall");
            break;
        case TK_DISTANCE:
           eat(TK_DISTANCE);
           // n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0] = make_nt_node("distance");
            break;

        case TK_RATIO:
            eat(TK_RATIO);
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0] = make_nt_node("ratio");
            break;

        default:
            pr_error("Expecting type\n");
    }
    return n;
}

struct node * params(){
   // Node *ptr;

    //ptr = (Node *)malloc(sizeof(Node));
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s,"params");
    switch(tok){
        case TK_INT:
                pr_error("<params>===> <type><id>TK_COMMA<params>\n");

            n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
            //n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;

        case TK_FLOAT:
                pr_error("<params>===> <type><id>TK_COMMA<params>\n");

            n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
           // n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;

	case TK_WINDOW:
            pr_error("<params>===> <type><id>TK_COMMA<params>\n");

            n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
           // n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;
	case TK_POINT:
            pr_error("<params>===> <type><id>TK_COMMA<params>\n");

            n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
           // n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;
	
	case TK_DOOR:
            pr_error("<params>===> <type><id>TK_COMMA<params>\n");

            n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
           // n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;
	
	case TK_WALL:
            pr_error("<params>===> <type><id>TK_COMMA<params>\n");

            n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
           // n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;
        case TK_DISTANCE:
                pr_error("<params>===> <type><id>TK_COMMA<params>\n");

          n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
           // n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;
        case TK_RATIO:
                pr_error("<params>===> <type><id>TK_COMMA<params>\n");

           n->child[0] = type();
            n->child[1] = id();
            eat(TK_COMMA);
            //n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2] = make_nt_node(",");
            n->child[3] = params();
            break;

        case TK_ROUND_CLOSE:
                pr_error("<params>===> EPS\n");

           // eat(TK_ROUND_CLOSE);
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
           // n->child[0] = make_nt_node(")");
            n->child[0] = make_nt_node("EPS");
            break;


        default:
            pr_error("Expecting ) or type");
    }
    return n;

}
struct node * _stats(){
     
     struct node * n;
     n = (struct node *)malloc(sizeof(struct node));   	
     strcpy(n->s,"stats");
 switch(tok){
    case TK_INT:
    pr_error("<stats>===> <stat> <stats>\n");
            n->child[0] = stat();
            n->child[1] =_stats();
            break;

        case TK_FLOAT:
            pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

        case TK_DISTANCE:
            pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;
        case TK_RATIO:
            pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

	case TK_POINT:
        pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;
	
	case TK_WINDOW:
        pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

	case TK_DOOR:
        pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;
	
	case TK_WALL:
        pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

        case TK_IDENTIFIER:
            pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

        case TK_RETURN:
            pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

            case TK_IF:
                pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

            case TK_FOR:
                pr_error("<stats>===> <stat> <stats>\n");

            n->child[0] = stat();
            n->child[1] =_stats();
            break;

            case TK_CURLY_CLOSE:
                pr_error("<stats>===> EPS\n");

            n->child[0] = make_nt_node("EPS");

            break;

    default:
        pr_error("Expecting if or for or return or type or id\n");
    }
    return n;

}
struct node * stat(){
     struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"stat");
    switch(tok){
    case TK_INT:
    pr_error("<stat>===> <funcstats>\n");
            n->child[0] =funcstats();
            break;

        case TK_FLOAT:
            pr_error("<stat>===> <funcstats>\n");


           n->child[0] = funcstats();
            break;

        case TK_DISTANCE:
            pr_error("<stat>===> <funcstats>\n");

            n->child[0] = funcstats();
            break;
        case TK_RATIO:
            pr_error("<stat>===> <funcstats>\n");

             n->child[0] =funcstats();
            break;
	case TK_POINT:
        pr_error("<stat>===> <funcstats>\n");

             n->child[0] =funcstats();
            break;
	
	case TK_WINDOW:
        pr_error("<stat>===> <funcstats>\n");

             n->child[0] =funcstats();
            break;

	case TK_DOOR:
        pr_error("<stat>===> <funcstats>\n");

             n->child[0] =funcstats();
            break;

	case TK_WALL:
        pr_error("<stat>===> <funcstats>\n");

             n->child[0] =funcstats();
            break;
        case TK_IDENTIFIER:
            pr_error("<stat>===> <funcstats>\n");

            n->child[0] =funcstats();
            break;
        case TK_RETURN:
            pr_error("<stat>===> <returnstats>\n");

            n->child[0] =returnstats();
            break;

        case TK_IF:
            pr_error("<stat>===> <iffunction>\n");

            n->child[0] =iffunction();
            break;

        case TK_FOR:
            pr_error("<stat>===> <forfunction>\n");

            n->child[0] =forfunction();
            break;

        default:
            pr_error("Expecting if or for or return or type or id\n");

    }
    return n;
}

struct node * forfunction(){
     struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"forfunction");
    pr_error("<forfunction>===>TK_FORTK_ROUND_OPEN<exp>TK_SEMICOLON<exp>TK_SEMICOLON<exp>TK_ROUND_CLOSETK_CURLY_OPEN<stats>TK_CURLY_CLOSE\n");
        switch(tok){
        case TK_FOR:
                eat(TK_FOR);
                n->child[0] = make_nt_node("for");
                eat(TK_ROUND_OPEN);
                n->child[1] = make_nt_node("(");
                n->child[2] =_exp();
                eat(TK_SEMICOLON);
                n->child[3] = make_nt_node(";");
                n->child[4] =_exp();
                eat(TK_SEMICOLON);
                n->child[5] = make_nt_node(";");
                n->child[6] =_exp();
                eat(TK_ROUND_CLOSE);
                n->child[7] = make_nt_node(")");
                eat(TK_CURLY_OPEN);
                n->child[8] = make_nt_node("{");
                n->child[9] =_stats();
                eat(TK_CURLY_CLOSE);
                n->child[10] = make_nt_node("}");
                break;

        default:
                pr_error("Expecting for\n");
        }
        return n;

}
struct node * iffunction(){
      struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"iffunction");
    pr_error("<iffunction>===>TK_IFTK_ROUND_OPEN<exp>TK_ROUND_CLOSETK_CURLY_OPEN<stats>TK_CURLY_CLOSE\n");
    switch(tok){
            eat(TK_IF);
            n->child[0] = make_nt_node("if");
            eat(TK_ROUND_OPEN);
            n->child[1] = make_nt_node("(");
            n->child[2] =_exp();
            eat(TK_ROUND_CLOSE);
            n->child[3] = make_nt_node(")");
            eat(TK_CURLY_OPEN);
            n->child[4] = make_nt_node("{");
            n->child[5] =_stats();
            eat(TK_CURLY_CLOSE);
            n->child[6] = make_nt_node("}");
            break;

        default:
                pr_error("Expecting if\n");

    }
    return n;
}

struct node * returnstats(){
      struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"returnstats");
    pr_error("<returnstats>===>TK_RETURN<Kim>TK_SEMICOLON\n");
    switch(tok){
    case TK_RETURN:
            eat(TK_RETURN);
            n->child[0] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[0]->s,"return");
            n->child[1] = kim();
            eat(TK_SEMICOLON);
//            n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[3] = make_nt_node(";");
            break;
	default:
                pr_error("Expecting return\n");
    }

    return n;
}

struct node * funcstats(){
     struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"funcstats");
    switch(tok){
    case TK_INT:
    pr_error("<funcstats>===><normalstats>\n");
           n->child[0] =normalstats();
           break;

        case TK_FLOAT:
            pr_error("<funcstats>===><normalstats>\n");
            n->child[0] =normalstats();
           break;

	case TK_WINDOW:
        pr_error("<funcstats>===><normalstats>\n");

            n->child[0] =normalstats();
           break;
	case TK_DOOR:
        pr_error("<funcstats>===><normalstats>\n");

            n->child[0] =normalstats();
           break;
	case TK_POINT:
        pr_error("<funcstats>===><normalstats>\n");

            n->child[0] =normalstats();
           break;
	case TK_WALL:
        pr_error("<funcstats>===><normalstats>\n");

            n->child[0] =normalstats();
           break;
        case TK_DISTANCE:
            pr_error("<funcstats>===><normalstats>\n");

            n->child[0] =normalstats();
           break;

        case TK_RATIO:
            pr_error("<funcstats>===><normalstats>\n");

            n->child[0] =normalstats();
           break;

        case TK_IDENTIFIER:

        pr_error("<funcstats>===><id><LF3>TK_SEMICOLON\n");
            n->child[0] =id();
            n->child[1] =LF3();
            eat(TK_SEMICOLON);
            n->child[2] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[2]->s,";");
           break;



        default:
            pr_error("Expecting type or id\n");
    }
    return n;
}

struct node * normalstats(){
     struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"normalstats");
    pr_error("<normalstats>===><type><id><Zip>\n");
	//printf(" in normalstats\n");
    switch(tok){
    case TK_INT:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;
	case TK_WALL:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;

    case TK_WINDOW:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;

	case TK_POINT:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;
	case TK_DOOR:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;
	

        case TK_FLOAT:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;

	


        case TK_DISTANCE:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;

        case TK_RATIO:
           n->child[0] =type();
           n->child[1] =id();
           n->child[2] =Zip();
           break;

        default:
		//printf("Goes to error from here");
            pr_error("Expecting type\n");
    }
    return n;
}

struct node * LF3(){
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));	
	strcpy(n->s,"LF3");
    switch(tok){

        case TK_SQUARE_OPEN:
        pr_error("<LF3>===> TK_SQUARE_OPEN<Kim>TK_SQUARE_CLOSE=<E>\n");

        eat(TK_SQUARE_OPEN);
        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[0]->s,"[");
        n->child[1] =kim();
        eat(TK_SQUARE_CLOSE);
        n->child[2] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[2]->s,"]");
        eat(TK_EQUALTO);
        n->child[3] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[3]->s,"=");
        n->child[4] =E();
        break;

    case TK_EQUALTO:
    pr_error("<LF3>===> =<E>");
            eat(TK_EQUALTO);
            n->child[0] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[0]->s,"=");
            n->child[1] =E();
            break;
    default:
        pr_error("Expecting [ or =\n");
    }
    return n;
}


struct node * Zip(){
	struct node * n;
     	n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"Zip");
	//printf("Here in zip\n");
	//printf("Current Tokern: %d",tok);
    switch(tok){

    case TK_SEMICOLON:

    pr_error("<Zip>===>TK_SEMICOLON\n");
	//printf("Zip error");
        eat(TK_SEMICOLON);
	
        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[0]->s,";");
        break;

    case TK_SQUARE_OPEN:
    pr_error("<Zip>===>TK_SQUARE_OPEN<Kim>TK_SQUARE_CLOSETK_SEMICOLON\n");
        eat(TK_SQUARE_OPEN);
        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[0]->s,"[");
        n->child[1] =kim();
        eat(TK_SQUARE_CLOSE);
        n->child[2] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[2]->s ,"]");
        eat(TK_SEMICOLON);
        n->child[3] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[3]->s , ";");
        break;

    case TK_EQUALTO:

    pr_error("=<E>TK_SEMICOLON\n");
            eat(TK_EQUALTO);
            n->child[0] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[0]->s ,"=");
            n->child[1] =E();
            eat(TK_SEMICOLON);
            n->child[2] =  (struct node *)malloc(sizeof(struct node));
            strcpy(n->child[2]->s,";");
            break;
    default:
	//printf("Zi[[[[[");
        pr_error("Expecting = or [ or ;\n");
    }
    return n;
}



struct node * kim(){
	  struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"Kim");
    switch(tok){
    case TK_IDENTIFIER:
    pr_error("<Kim>===><id>\n");
        n->child[0] =id();
        break;

    case TK_LITERAL:
    pr_error("<Kim>===><literal>\n");
        n->child[0] =literal();
        break;

    default:
        pr_error("Expecting literal or id\n");

    }
    return n;

}
struct node * E(){
	  struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"E");
    switch(tok){
    case TK_IDENTIFIER:
    pr_error("<E>===><Kim><K>\n");

        n->child[0] =kim();
        n->child[1] =K();
        break;

    case TK_LITERAL:
        pr_error("<E>===><Kim><K>\n");

        n->child[0] =kim();
        n->child[1] =K();
        break;


     case TK_ROUND_OPEN:
     pr_error("<E>===>TK_ROUND_OPEN<LF1>\n");

         eat(TK_ROUND_OPEN);
         n->child[0] = make_nt_node("(");
         n->child[1] =LF1();
        //n->child[2] =literal();
        break;


    default:
        pr_error("Expecting ( or id or lieral\n");

    }
    return n;

}

struct node * LF1(){
	  struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF1");
    switch(tok){
    case TK_IDENTIFIER:
    pr_error("<LF1>===><id><LF4>\n");
        n->child[0] =id();
        n->child[1] =LF4();
        break;

    case TK_LITERAL:

    pr_error("<LF1>===><literal>TK_COMMA<Kim>TK_ROUND_CLOSE\n");

        n->child[0] =literal();
        eat(TK_COMMA);

        n->child[1] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[1]->s, ",");
        n->child[2] =kim();
        eat(TK_ROUND_CLOSE);
        n->child[3] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[3]->s , ")");
        break;

    default:
        pr_error("Expecting id or literal\n");

    }	
    return n;

}

struct node * LF4(){
	  struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF4");
    pr_error("<LF4>===>TK_COMMA<LF5>\n");
    switch(tok){
    case TK_COMMA:
        eat(TK_COMMA);
        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[0]->s, ",");
        n->child[1] =LF5();
        break;
    default:
        pr_error("Expecting ,\n");


    }
    return n;
}

struct node * LF5(){
	  struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF5");
    switch(tok){
    case TK_IDENTIFIER:
    pr_error("<LF5>===><id><LF6>\n");

        n->child[0] =id();
        n->child[1] =LF6();
        break;

    case TK_LITERAL:
    pr_error("<LF5>===><literal>TK_ROUND_CLOSE");

        n->child[0] =literal();
        eat(TK_ROUND_CLOSE);
        n->child[1] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[1]->s ,")");
    default:
        pr_error("Expecting id or literal\n");

    }
    return n;
}


struct node * LF6(){
	  struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF6");
    switch(tok){
    case TK_ROUND_CLOSE:
    pr_error("<LF6>===>TK_ROUND_CLOSE\n");
        eat(TK_ROUND_CLOSE);
        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[0]->s , ")");
        break;

    case TK_COMMA:
    pr_error("<LF6>===>TK_COMMA<Kim>TK_ROUND_CLOSE\n");

        eat(TK_COMMA);
        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[0]->s , ",");
        n->child[1] = kim();
        eat(TK_ROUND_CLOSE);
        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        strcpy(n->child[0]->s ,")");

        break;
    default:
        pr_error("Expectin , or )\n");

    }
    return n;
}

struct node * K(){
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"K");
    switch(tok){
    case TK_SEMICOLON:
    pr_error("<K>===>EPS\n");

	n->child[0] =  make_nt_node("EPS");
        break;

    case TK_ROUND_OPEN:
        eat(TK_ROUND_OPEN);
        pr_error("<K>===>TK_ROUND_OPEN<LF7>\n");
        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0] =  make_nt_node("(");
        n->child[1] =LF7();
        break;

    case TK_ROUND_CLOSE:
        pr_error("<K>===>EPS\n");

	n->child[0] =  make_nt_node("EPS");
        break;

    case TK_COLON:
        eat(TK_COLON);
        pr_error("<K>===>TK_COLON<Kim>\n");
       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0] = make_nt_node(":");
        n->child[1] =kim();
        break;

    case TK_THICKNESS:
        eat(TK_THICKNESS);
        pr_error("<K>===>TK_THICKNESSTK_ROUND_OPEN<id><LF9>\n");
        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0] = make_nt_node("||");
        eat(TK_ROUND_OPEN);
        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]= make_nt_node("(");
        n->child[1] =id();
        n->child[2] =LF9();
        break;

    case TK_PLUS:
    pr_error("<K>===> <arithmeticoperators><Kim>\n");
        n->child[0] =arithmeticoperators();
        n->child[1] =kim();
        break;
    case TK_MUL:
        pr_error("<K>===> <arithmeticoperators><Kim>\n");

        n->child[0] =arithmeticoperators();
        n->child[1] =kim();
        break;
    case TK_MINUS:
        pr_error("<K>===> <arithmeticoperators><Kim>\n");

        n->child[0] =arithmeticoperators();
        n->child[1] =kim();
        break;
    case TK_DIVIDE:
        pr_error("<K>===> <arithmeticoperators><Kim>\n");

        n->child[0] =arithmeticoperators();
        n->child[1] =kim();
        break;

    case TK_DOTSTART:
        eat(TK_DOTSTART);
    pr_error("<K>===> TK_DOTSTART\n");
        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node( ".start");
        break;

    case TK_DOTEND:
        eat(TK_DOTEND);
            pr_error("<K>===> TK_DOTEND\n");

        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node( ".end");
        break;



    default:
        pr_error("Expecting .end or .start or+or-or/or* or|| or: or) or ( or; \n");
    }

    return n;
}



struct node * LF7(){
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF7");
    switch(tok){

    case TK_IDENTIFIER:
    pr_error("<LF7>===><id>TK_COMMA<LF8>\n");
        n->child[0] =id();
        eat(TK_COMMA);
      //  n->child[1] =  (struct node *)malloc(sizeof(struct node));
        n->child[1]=make_nt_node( ",");
        n->child[2]=LF8();
        break;

    case TK_ROUND_CLOSE:
        eat(TK_ROUND_CLOSE);
        pr_error("<LF7>===>TK_ROUND_CLOSE\n");
        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node(")");
        break;

    case TK_LITERAL:
    pr_error("<LF7>===><literal>TK_COMMA<buildparams>TK_ROUND_CLOSE\n");
        n->child[0] =literal();
        eat(TK_COMMA);
       // n->child[1] =  (struct node *)malloc(sizeof(struct node));
        n->child[1]=make_nt_node(",");
        n->child[2] =buildparams();
        eat(TK_ROUND_CLOSE);
       // n->child[3] =  (struct node *)malloc(sizeof(struct node));
        n->child[3]=make_nt_node(")");
        break;

    default:
        pr_error("Expecting id or literal or )\n");
    }
    return n;

}

struct node * LF8(){
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF8");
    switch(tok){
    case TK_IDENTIFIER:
    pr_error("<LF8>===><id><LF0>\n");
        n->child[0] =id();
        n->child[1] =LF0();
        break;

    case TK_ROUND_CLOSE:
    pr_error("<LF8>===>TK_ROUND_CLOSE\n");
        eat(TK_ROUND_CLOSE);
      //  n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node( ")");
        break;

    case TK_LITERAL:
    pr_error("<LF8>===><literal>TK_COMMA<buildparams>TK_ROUND_CLOSE\n");
        n->child[0] =literal();
        eat(TK_COMMA);
        //n->child[1] =  (struct node *)malloc(sizeof(struct node));
        n->child[1]=make_nt_node(",");
        n->child[2] =buildparams();
        eat(TK_ROUND_CLOSE);
       // n->child[3] =  (struct node *)malloc(sizeof(struct node));
        n->child[3]=make_nt_node(")");
        break;


    default:
        pr_error("Expecting ) or id or literal\n");

    }
    return n;
}

struct node * LF0(){
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF0");
    switch(tok){


    case TK_ROUND_CLOSE:
    pr_error("<LF0>===>TK_ROUND_CLOSE\n");
        eat(TK_ROUND_CLOSE);
        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node(")");
        break;

    case TK_COMMA:

        eat(TK_COMMA);
            pr_error("<LF0>===>TK_COMMA<buildparams>TK_ROUND_CLOSE\n");

       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node(",");
        n->child[1] =buildparams();
        eat(TK_ROUND_CLOSE);
        //n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[2]=make_nt_node(")");
        break;


    default:
        pr_error("Expecting ) or ,\n");

    }
    return n;
}


struct node * buildparams(){
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"buildparams");
    switch(tok){
    case TK_ROUND_CLOSE:
    pr_error("<buildparams>===> EPS\n");
	n->child[0]=make_nt_node("EPS");
        break;

    case TK_IDENTIFIER:
    pr_error("<buildparams>===> <Kim>TK_COMMA<buildparams>\n");
        n->child[0] =kim();
        eat(TK_COMMA);
       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[1]=make_nt_node(",");
         n->child[2] =buildparams();
        //eat(TK_ROUND_CLOSE);
        break;

    case TK_LITERAL:
        pr_error("<buildparams>===> <Kim>TK_COMMA<buildparams>\n");

        n->child[0] =kim();
        eat(TK_COMMA);
       // n->child[1] =  (struct node *)malloc(sizeof(struct node));
        n->child[1]=make_nt_node(",");
        n->child[2] =buildparams();
        //eat(TK_ROUND_CLOSE);
        break;
    default:
        pr_error("Expecting id or literal or )\n");

    }
    return n;
}

struct node * LF9(){
	
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"LF9");
    switch(tok){

    case TK_COMMA:

        eat(TK_COMMA);
        pr_error("<LF9>===>TK_COMMA<id>TK_COMMA<Kim>TK_COMMA<Kim>TK_ROUND_CLOSE\n");
      //  n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node(",");
        n->child[1] =id();
        eat(TK_COMMA);
       // n->child[2] =  (struct node *)malloc(sizeof(struct node));
        n->child[2]=make_nt_node(",");
        n->child[3] =kim();
        eat(TK_COMMA);
       // n->child[4] =  (struct node *)malloc(sizeof(struct node));
        n->child[4]=make_nt_node(",");
        n->child[5] =kim();
        eat(TK_ROUND_CLOSE);
        //n->child[6] =  (struct node *)malloc(sizeof(struct node));
        n->child[6]=make_nt_node(")");
        break;

    case TK_AND:
        eat(TK_AND);
        pr_error("<LF9>===>TK_AND<id>TK_ROUND_CLOSE\n");
       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node("&");
        n->child[1] =id();
        eat(TK_ROUND_CLOSE);
      //  n->child[2] =  (struct node *)malloc(sizeof(struct node));
        n->child[2]=make_nt_node(")");
        break;

    default:
        pr_error("Expecting & or ,\n");

    }
        return n;
}

struct node * arithmeticoperators(){
	struct node * n;
     n = (struct node *)malloc(sizeof(struct node));
	strcpy(n->s,"artihmeticoperators");
    switch(tok){

    case TK_PLUS:
    pr_error("<arithmeticoperators>===>TK_PLUS\n");
        eat(TK_PLUS);
       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node("+");
        break;

    case TK_MINUS:
        pr_error("<arithmeticoperators>===>TK_MINUS\n");

        eat(TK_MINUS);
       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node("-");
        break;
    case TK_DIVIDE:
        pr_error("<arithmeticoperators>===>TK_DIVIDE\n");

        eat(TK_DIVIDE);
       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node( "/");
        break;
    case TK_MUL:
        pr_error("<arithmeticoperators>===>TK_MUL\n");

        eat(TK_MUL);
       // n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node( "*");
        break;

    default:
        pr_error("Expecting + or - or * or /\n");

    }
    return n;
}

struct node * building(){
     struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s,"building_func");
    pr_error("<building> ===> TK_BUILDING<id> TK_CURLY_OPEN<newstats>TK_CURLY_CLOSE\n");

    switch(tok){
	
    case TK_BUILDING:
        eat(TK_BUILDING);
        //printf("eating\n");
        //printf("%d\n",tok );

//        n->child[0] =  (struct node *)malloc(sizeof(struct node));
        n->child[0]=make_nt_node("building_token");

        n->child[1] = id();
        //need to analyze the symbol b here...
        // enter in st in fo corresponding to buuilding id..
        eat(TK_CURLY_OPEN);
        //printf("%d\n",tok );
  //      n->child[2] =  (struct node *)malloc(sizeof(struct node));
        n->child[2]=make_nt_node("{");
        n->child[3] = newstats();
        eat(TK_CURLY_CLOSE);
    //    n->child[4] =  (struct node *)malloc(sizeof(struct node));
        n->child[4]=make_nt_node( "}");
        n->child[5] = NULL;
        break;



    default:
        pr_error("Expecting Building\n");

    }
        return n;
}


struct node * newstats(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s , "newstats");

    switch(tok){
        case TK_INT:
        pr_error("<newstats>===><body><newstats>\n");
            n->child[0] =body();
            n->child[1] =newstats();
            break;

        case TK_FLOAT:
                pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;
        case TK_DISTANCE:
                pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;

        case TK_RATIO:
                pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;
	case TK_WALL:
            pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;
	case TK_POINT:
            pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;
	case TK_DOOR:
            pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;
	case TK_WINDOW:
            pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;
        case TK_IDENTIFIER:
                pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;
            //   wwrror ...eat(TK_BUILDING);

        case TK_FLOOR:
                pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;

        case TK_IF:
                pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;

        case TK_FOR:
                pr_error("<newstats>===><body><newstats>\n");

            n->child[0] =body();
            n->child[1] =newstats();
            break;

        
        case TK_CURLY_CLOSE:
                pr_error("<newstats>===>EPS\n");

		n->child[0]=make_nt_node( "EPS");
        //eat(TK_CURLY_CLOSE);
            break;


        default:
            pr_error("Expecting type or floor or if or for or id or }\n	");

    }
        return n;
}

struct node * body(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
   strcpy( n->s ,"body");
    switch(tok){
        case TK_INT:
        pr_error("<body>===><funcstats>\n");
            n->child[0] =funcstats();
            break;

        case TK_FLOAT:
                pr_error("<body>===><funcstats>\n");

            n->child[0] =funcstats();
            break;

        case TK_DISTANCE:
                pr_error("<body>===><funcstats>\n");

            n->child[0] =funcstats();
            break;

	case TK_WALL:
            pr_error("<body>===><funcstats>\n");

            n->child[0] =funcstats();
            break;
	
	case TK_POINT:
            pr_error("<body>===><funcstats>\n");

            n->child[0] =funcstats();
            break;

	case TK_DOOR:
            pr_error("<body>===><funcstats>\n");

            n->child[0] =funcstats();
            break;

	case TK_WINDOW:
            pr_error("<body>===><funcstats>\n");

            n->child[0] =funcstats();
            break;

        case TK_RATIO:
                pr_error("<body>===><funcstats>\n");

           n->child[0] =funcstats();
            break;

        case TK_IDENTIFIER:
                pr_error("<body>===><funcstats>\n");

            n->child[0] =funcstats();
            break;

            //   wwrror ...eat(TK_BUILDING);

        case TK_FLOOR:
        pr_error("<body>===><floor>\n");
            n->child[0] =_floor();
            break;

        case TK_IF:
        pr_error("<body>===><ifrelatedstuff>\n");
           n->child[0] =ifrelatedstuff();
            break;

        case TK_FOR:
        pr_error("<body>===><forrelatedstuff>\n");
           n->child[0] =forrelatedstuff();
            break;

        default:
            pr_error("Expecting type variable or id or floor or for \n");

    }
        return n;
}


struct node * ifrelatedstuff(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s ,"ifrelatedstuff");
    pr_error("<ifrelatedstuff>===>TK_IFTK_ROUND_OPEN<exp>TK_ROUND_CLOSETK_CURLY_OPEN<funcstats><newstats>TK_CURLY_CLOSE\n");
    switch(tok){
        case TK_IF:
            eat(TK_IF);
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]=make_nt_node( "if");
            eat(TK_ROUND_OPEN);
           // n->child[1] =  (struct node *)malloc(sizeof(struct node));
            n->child[1]=make_nt_node( "(");
            n->child[2] =_exp();
            eat(TK_ROUND_CLOSE);
            //n->child[3] =  (struct node *)malloc(sizeof(struct node));
            n->child[3]=make_nt_node(")");
            eat(TK_CURLY_OPEN);
            //n->child[4] =  (struct node *)malloc(sizeof(struct node));
            n->child[4]=make_nt_node("{");

            n->child[5] =funcstats();
            n->child[6] =newstats();
            eat(TK_CURLY_CLOSE);
           // n->child[7] =  (struct node *)malloc(sizeof(struct node));
            n->child[7]=make_nt_node( "}");
            break;

        default:
            pr_error("Expectting if\n");
    }
        return n;
}

struct node * forrelatedstuff(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s ,"forrelatedstuff");
    pr_error("<forelatedstuff>===>TK_FORTK_ROUND_OPEN<exp>TK_SEMICOLON<exp>TK_SEMICOLON<exp>TK_ROUND_CLOSETK_CURLY_OPEN<funcstats><newstats>TK_CURLY_CLOSE\n");
    switch(tok){
        case TK_FOR:
            eat(TK_FOR);
           // n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]=make_nt_node("for");
            eat(TK_ROUND_OPEN);
            //n->child[1] =  (struct node *)malloc(sizeof(struct node));
            n->child[1]=make_nt_node("(");
            n->child[2] =_exp();
            eat(TK_SEMICOLON);
            //n->child[3] =  (struct node *)malloc(sizeof(struct node));
            n->child[3]=make_nt_node(";");
            n->child[4] =_exp();
            eat(TK_SEMICOLON);
           // n->child[5] =  (struct node *)malloc(sizeof(struct node));
            n->child[5]=make_nt_node(";");
            n->child[6] =_exp();
            eat(TK_ROUND_CLOSE);
           // n->child[7] =  (struct node *)malloc(sizeof(struct node));
            n->child[7]=make_nt_node(")");

            eat(TK_CURLY_OPEN);
            //n->child[8] =  (struct node *)malloc(sizeof(struct node));
            n->child[8]=make_nt_node("{");

            n->child[9] =funcstats();
            n->child[10] =newstats();
            eat(TK_CURLY_CLOSE);
          //  n->child[11] =  (struct node *)malloc(sizeof(struct node));
            n->child[11]=make_nt_node( "}");
            break;

        default:
            pr_error("Expecting for\n");
    }
    return n;
}

struct node * _floor(){
	
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
 strcpy(   n->s,"floor");
    switch(tok){
        case TK_FLOOR:
        pr_error("<floor>===>TK_FLOOR<id><arr>TK_CURLY_OPEN<funcstats><newstats>TK_CURLY_CLOSE\n");
            eat(TK_FLOOR);
		n->child[0]=make_nt_node("floor");
            n->child[1] =id();
            n->child[2] =arr();

            eat(TK_CURLY_OPEN);
            //n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[3]=make_nt_node("{");

            n->child[4] =funcstats();
            n->child[5] =newstats();
            eat(TK_CURLY_CLOSE);
            //n->child[4] =  (struct node *)malloc(sizeof(struct node));
            n->child[6]=make_nt_node("}");
            break;

        default:
            pr_error("Expecting floor\n");
    }
    return n;
}

struct node * arr(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s ,"arr");
    switch(tok){
        case TK_SQUARE_OPEN:
        pr_error("<arr> ===> TK_SQUARE_OPEN <literal> TK_SQUARE_CLOSE\n");
            eat(TK_SQUARE_OPEN);
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]=make_nt_node("[");
            n->child[1] =literal();
            eat(TK_SQUARE_CLOSE);
            //n->child[2] =  (struct node *)malloc(sizeof(struct node));
            n->child[2]=make_nt_node("]");

            break;

        case TK_CURLY_OPEN:
        pr_error("<arr> ===> EPS\n");
		n->child[0]=make_nt_node("EPS");	
            break;


        default:
            pr_error("Expecting { or [ \n");

    }
    return n;
}


struct node * _exp(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));

    strcpy(n->s ,"exp");
    pr_error("<exp>===>id<conditionaloperator><E>\n");
    switch(tok){
        case TK_IDENTIFIER:
            n->child[0] =id();
            n->child[1] =conditionaloperator();
            n->child[2] =E();
            break;

        default:
            pr_error("Expecting id\n");

    }
    return n;
}


struct node * conditionaloperator(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s , "conditionaloperator");
    switch(tok){
        case TK_EQUALTO:
        pr_error("<conditionaloperator>===>TK_EQUALTO<LF10>\n");

            eat(TK_EQUALTO);
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]=make_nt_node( "=");
            n->child[1] =LF10();
            break;

        case TK_GREATER_THAN:
        pr_error("<conditionaloperator>===>TK_GREATER_THAN<LF10>\n");
            eat(TK_GREATER_THAN);
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]=make_nt_node( ">");
            n->child[1] =LF10();
            break;

        case TK_NOT_EQUAL_TO:
        pr_error("<conditionaloperator>===>TK_NOT_EQUAL_TO\n");
            eat(TK_NOT_EQUAL_TO);
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]=make_nt_node("!=");
            break;

        case TK_LESS_THAN:
            eat(TK_LESS_THAN);
            pr_error("<conditionaloperator>===>TK_LESS_THAN<LF10>\n");
            //n->child[0] =  (struct node *)malloc(sizeof(struct node));
            n->child[0]=make_nt_node("<");
            LF10();
            break;

        default:
            pr_error("Expecting a consitional operator (<,>,=,!=)\n");

    }
    return n;
}

struct node * LF10(){
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->s , "LF10");
switch(tok){

case TK_IDENTIFIER:
pr_error("<LF10>===>EPS\n");
	n->child[0]=make_nt_node("EPS");
    break;

case TK_ROUND_OPEN:
pr_error("<LF10>===>EPS\n");

	n->child[0]=make_nt_node("EPS");
    break;

case TK_EQUALTO:
pr_error("<LF10>===>TK_EQUALTO\n");

    eat(TK_EQUALTO);
	//n->child[0] =  (struct node *)malloc(sizeof(struct node));
	n->child[0]=make_nt_node("=");
    break;

case TK_LITERAL:
pr_error("<LF10>===>EPS\n");

	n->child[0]=make_nt_node("EPS");
    break;

	
default:
    pr_error("Expecting id or ( or = or nothing\n");
}
return n;
}

