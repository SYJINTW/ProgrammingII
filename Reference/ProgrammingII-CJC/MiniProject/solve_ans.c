#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLEN 256
typedef enum {UNKNOWN, END, INT, ID, ADDSUB,AND,OR,XOR, MULDIV, ASSIGN, LPAREN, RPAREN} TokenSet;
typedef enum {MISPAREN, NOTNUMID, NOTFOUND, RUNOUT, NAN} ErrorType;
void error(ErrorType errorNum);
extern bool match (TokenSet token);
extern void advance(void);
extern char* getLexeme(void);

static TokenSet getToken(void);
static TokenSet lookahead = UNKNOWN;
static char lexeme[MAXLEN];
int valid;
int right=0;

TokenSet getToken(void)
{
    int i;
    char c;
	c = fgetc(stdin);
    while ( c == ' ' || c== '\t' ){
		c = fgetc(stdin);
	}
	if (isdigit(c)) {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isdigit(c) && i<MAXLEN) {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        if(i==MAXLEN){
        	error(0);
		}
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return INT;
    } else if (c == '+' || c == '-') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return ADDSUB;
    } else if (c == '*' || c == '/') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return MULDIV;
    } else if (c == '&'){
    	lexeme[0] = c;
    	lexeme[1] = '\0';
    	return AND;
	} else if (c == '|'){
    	lexeme[0] = c;
    	lexeme[1] = '\0';
    	return OR;
	}  else if (c == '^'){
    	lexeme[0] = c;
    	lexeme[1] = '\0';
    	return XOR;
	} else if (c == '\n') {
        lexeme[0] = '\0';
        return END;
    } else if (c == '=') {
        strcpy(lexeme, "=");
        right = 1;
        return ASSIGN;
    } else if (c == '(') {
        strcpy(lexeme, "(");
        return LPAREN;
    } else if (c == ')') {
        strcpy(lexeme, ")");
        return RPAREN;
    } else if (isalpha(c) || c == '_') {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isalpha(c) || isdigit(c) || c == '_') {
            lexeme[i] = c;
            i += 1;
            c = fgetc(stdin);
            if(i>MAXLEN) {
            	error(0);
			}
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return ID;
    } else {
        return UNKNOWN;
    }
}

void advance(void)
{
    lookahead = getToken();
}

bool match(TokenSet token)
{
    if (lookahead == UNKNOWN) advance();
    return token == lookahead;
}

char* getLexeme(void)
{
    return lexeme;
}

#define TBLSIZE 65535

typedef struct {
	char name[MAXLEN];
	int val, n;
	// int rn ,r;
} Symbol;


Symbol table[TBLSIZE];

int sbcount = 0;

typedef struct _Node {
	char lexeme[MAXLEN];
	TokenSet token;
	int val;
	struct _Node *left, *right;
} BTNode;

void statement(void);
BTNode* expr(void);
BTNode* term(void);
BTNode* factor(void);
int getval(void);
int setval(char*, int);


BTNode* makeNode(TokenSet tok, const char *lexe)
{
	BTNode *node = (BTNode*) malloc(sizeof(BTNode));
	strcpy(node->lexeme, lexe);
	node->token= tok;
	node->val = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void freeTree(BTNode *root)
{
	if (root!=NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

void printPrefix(BTNode *root)
{
	if (root != NULL) {
		printf("%s ", root->lexeme);
		printPrefix(root->left);
		printPrefix(root->right);
	}
}

int find(char str[MAXLEN]){
	int i;
	for(i=0;i<sbcount;i++){
		if(!strcmp(str,table[i].name)){
			if(i>=0&&i<=2){}
			else if(table[i].n&&right){
				printf("EXIT 1\n");
				exit(0);
			}
			return i;
		}
	}
	return -1;
}
// int validv=1;
int printop(BTNode* root,int n){
	int i1,l,r;
	if (root != NULL) {
		switch (root->token) {
			case ID:
				i1 = find(root->lexeme);
				if(table[i1].n){
					if(i1>=0&&i1<=2){
						printf("MOV r%d [%d]\n",n,i1*4);
						printf("MOV r%d r%d\n",i1,n);
						table[i1].n = 0;
					}
				}
				else {
					if(i1>=0&&i1<=2){
						printf("MOV r%d r%d\n",n,i1);
					}
					else {
						printf("MOV r%d [%d]\n",n,i1*4);
					}
				}
				// if(!table[i1].rn) validv = 0;
				return table[i1].val;
			case INT:
				printf("MOV r%d %d\n",n,root->val);
				return root->val;
			case ASSIGN:
				i1 = find(root->left->lexeme);
				r = printop(root->right,n);
				if(table[i1].n){
					table[i1].n = 0;
				}
				if(i1>=0&&i1<=2){
					printf("MOV r%d r%d\n",i1,n);
				}
				else {
					printf("MOV [%d] r%d\n",i1*4,n);
				}
				// if(validv) {
				// 	table[i1].val = r;
				// 	table[i1].rn = 1;
				// }
				return 0;
			case AND:
				l=printop(root->left,n);
				r=printop(root->right,n+1);
				printf("AND r%d r%d\n",n,n+1);
				return l&r;
			case OR:
				l=printop(root->left,n);
				r=printop(root->right,n+1);
				printf("OR r%d r%d\n",n,n+1);
				return l|r;
			case XOR:
				l=printop(root->left,n);
				r=printop(root->right,n+1);
				printf("XOR r%d r%d\n",n,n+1);
				return l^r;
			case ADDSUB:
				l=printop(root->left,n);
				r=printop(root->right,n+1);
				if (root->lexeme[0]=='+'){
					printf("ADD r%d r%d\n",n,n+1);
					return l+r;
				}
				else if (root->lexeme[0]=='-'){
					printf("SUB r%d r%d\n",n,n+1);
					return l-r;
				}
			case MULDIV:
				l=printop(root->left,n);
				r=printop(root->right,n+1);
				if (root->lexeme[0]=='*'){
					printf("MUL r%d r%d\n",n,n+1);
					return l*r;
				}
				else if (root->lexeme[0]=='/') {
					// if(r==0){
					// 	if(validv||(root->right->token==INT)) error(NAN);
					// }
					printf("DIV r%d r%d\n",n,n+1);
					if(r!=0) return l/r;
					else return 1;
				}
			default:
				return 0;
		}
	}
	error(NAN);
}

int getval(void)
{
	int i, retval, found;

	if (match(INT)) {
		retval = atoi(getLexeme());
	} else if (match(ID)) {
		i = 0;
		found = 0;
		retval = 0;
		while (i<sbcount && !found) {
			if (!strcmp(getLexeme(), table[i].name)) {
				retval = table[i].val;
				found = 1;
				break;
			}
			i++;
		}
		if (!found) {
			if(right){
				valid = 0;
				printf("EXIT 1\n");
				exit(0);
			}
			else{
				if (sbcount < TBLSIZE) {
					strcpy(table[sbcount].name, getLexeme());
					// table[sbcount].rn = 0;
					table[sbcount].n = 1;
					// table[sbcount].r = sbcount;
					sbcount++;
				} else {
					error(RUNOUT);
				}
			}
			
		}
	}
	return retval;
}

BTNode* And();
BTNode* Xor();
BTNode* Or();

BTNode* expr(void)
{
	BTNode *retp, *left;
	retp = left = term();
	while (match(ADDSUB)) {
		retp = makeNode(ADDSUB, getLexeme());
		advance();
		retp->right = term();
		retp->left = left;
		left = retp;
	}
	return retp;
}

BTNode* term(void)
{
	BTNode *retp, *left;
	retp = left = factor();
	while (match(MULDIV)) {
		retp = makeNode(MULDIV, getLexeme());
		advance();
		retp->right = factor();
		retp->left = left;
		left = retp;
	}
	return retp;
}

BTNode* And(void)
{
	BTNode *retp, *left;
	retp = left = expr();
	while (match(AND)) {
		retp = makeNode(AND, getLexeme());
		advance();
		retp->right = expr();
		retp->left = left;
		left = retp;
	}
	return retp;
}
BTNode* Xor(){
	BTNode *retp, *left;
	retp = left = And();
	while (match(XOR)) {
		retp = makeNode(XOR, getLexeme());
		advance();
		retp->right = And();
		retp->left = left;
		left = retp;
	}
	return retp;
}
BTNode* Or(){
	BTNode *retp, *left;
	retp = left = Xor();
	while (match(OR)) {
		retp = makeNode(OR, getLexeme());
		advance();
		retp->right = Xor();
		retp->left = left;
		left = retp;
	}
	return retp;
}

BTNode* factor(void)
{
	BTNode* retp = NULL;
	char tmpstr[MAXLEN];

	if (match(INT)) {
		retp =  makeNode(INT, getLexeme());
		retp->val = getval();
		advance();
	} else if (match(ID)) {
		BTNode* left = makeNode(ID, getLexeme());
		left->val = getval();
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ASSIGN)) {
			retp = makeNode(ASSIGN, getLexeme());
			advance();
			retp->right = Or();
			retp->left = left;
		} else {
			retp = left;
		}
	}
	else if (match(ADDSUB)) {
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ID) || match(INT)) {
			retp = makeNode(ADDSUB, tmpstr);
			if (match(ID))
				retp->right = makeNode(ID, getLexeme());
			else
				retp->right = makeNode(INT, getLexeme());
			retp->right->val = getval();
			retp->left = makeNode(INT, "0");
			retp->left->val = 0;
			advance();
		} else {
			error(NOTNUMID);
		}
	} else if (match(LPAREN)) {
		advance();
		retp = Or();
		if (match(RPAREN)) {
			advance();
		} else {
			error(MISPAREN);
		}
	} else {
		error(NOTNUMID);
	}
	return retp;
}

void error(ErrorType errorNum)
{
	valid = 0;
	printf("EXIT 1\n");
	exit(0);
}
int test2(BTNode *root){
	if(root == NULL) return 0;
	if(root->token==INT||root->token==ID) {
		if(root->token==ID){
			int x;
			x = find(root->lexeme);
			if(x==-1) return 0;
		}
		return root->left==NULL&&root->right==NULL;
	}
	else if(root->token==ASSIGN){
		printf("EXIT 1\n");
		exit(0);
	}
	else {
		return test2(root->left)&&test2(root->right);
	}
	return 0;
}
int test(BTNode *root){
	if(root->token==ASSIGN){
		if(root->left->token==ID){
			if(test2(root->right)) return 1;
		}
	}
	return 0;
}
void sett(BTNode *root,BTNode *left,const char* name,BTNode *right,TokenSet token,int val){
	root->left = left;
	if(name!=NULL)strcpy(root->lexeme,name);
	root->right = right;
	root->token = token;
	root->val = val;
}
void fresh(BTNode* root){
	if(root!=NULL){
		if(root->left!=NULL){
			fresh(root->left);
		}
		if(root->right!=NULL){
			fresh(root->right);
		}
		switch(root->token){
			case AND:
				if(root->right->token==INT&&root->left->token==INT){
					sett(root,NULL,NULL,NULL,INT,(root->right->val)&(root->left->val));
				}
				break;
			case OR:
				if(root->right->token==INT&&root->left->token==INT){
					sett(root,NULL,NULL,NULL,INT,(root->right->val)|(root->left->val));
				}
				break;
			case XOR:
				if(root->right->token==INT&&root->left->token==INT){
					sett(root,NULL,NULL,NULL,INT,(root->right->val)^(root->left->val));
				}
				break;
			case ADDSUB:
				if(root->right->token==INT&&root->left->token==INT){
					int i;
					if(root->lexeme[0]=='+')i = (root->right->val)+(root->left->val);
					else if(root->lexeme[0]=='-')i = (root->left->val)-(root->right->val);
					sett(root,NULL,NULL,NULL,INT,i);
				}
				break;
			case MULDIV:
				if(root->right->token==INT&&root->left->token==INT){
					int i;
					if(root->lexeme[0]=='*')i = (root->right->val)*(root->left->val);
					else if(root->lexeme[0]=='/'){
						if(root->right->val!=0)i =(root->left->val)/(root->right->val);
						else error(NAN);
					} 
					sett(root,NULL,NULL,NULL,INT,i);
				}
				break;
		}
	}
}
void statement(void)
{
	BTNode* retp;

	if (match(END)) {
		advance();
	} else {
		retp = Or();
		valid = test(retp)&valid;
		fresh(retp);
		if(valid){
			right = 0;
			printop(retp,3);
		}
		else {
			printf("EXIT 1\n");
			exit(0);
			return;	
		}
		freeTree(retp);
		advance();
	}
}
int main()
{
	valid = 1;
	char c;
	int i;
	table[0].name[0] = 'x';
	// table[0].r = 0;
	table[0].n = 1;
	// table[0].rn = 0;
	//printf("%d\n",table[0].val);
	table[1].name[0] = 'y';
	// table[1].r = 1;
	table[1].n = 1;
	// table[0].rn = 0;
	table[2].name[0] = 'z';
	// table[2].r = 2;
	table[2].n = 1;
	// table[0].rn = 0;
	sbcount = 3;
	while ((c=fgetc(stdin))!=EOF&&valid) {
		right = 0;
		// validv = 1;
		ungetc(c,stdin);
		statement();
	}
	if(valid) {
		if(table[0].n) printf("MOV r0 [0]\n");
		if(table[1].n) printf("MOV r1 [4]\n");
		if(table[2].n) printf("MOV r2 [8]\n");
		printf("EXIT 0\n");
	}
	return 0;
}
