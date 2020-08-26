int main(int argc, char ** argv)
{
	if (argc<2)
	{
		fprintf(stderr,"Call: etapa1 FileName\n");
		exit(1);
	}
	
	yyin = fopen(argv[1],"r");
	if (yyin == 0)
		{
		fprintf(stderr,"Cannot open file %s\n",argv[1]);
		exit(2);
		}
	
	int tok;
	while(Running)
	{
	tok = yylex();
	switch(tok)
	{
		case KW_INT: printf("Achei palavra reservada int\n"); break;
		case LIT_INTEGER: printf("Achei o literal inteiro %s\n",yytext); break;
		case TK_IDENTIFIER: printf("Achei o identificador %s na linha %d\n",yytext,lineNumber); break;
		case TOKEN_ERROR: printf("ERRO\n"); break;
		default: printf("Achei o simbolo %c\n",tok); break;
	}
	}
}
