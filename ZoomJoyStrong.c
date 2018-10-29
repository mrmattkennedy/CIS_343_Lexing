%{
	#include <stdio.h>
	int total = 1;
%}

%%

POINT[ ][(][0-9]+,[0-9]+[)]  							{ total++; printf("Making %s", yytext); }
LINE[ ][(][0-9]+,[0-9]+,[0-9]+,[0-9]+[)]  					{ total++; printf("Making %s", yytext); }
CIRCLE[ ][(][0-9]+,[0-9]+,[0-9]+[)] 						{ total++; printf("Making %s", yytext); }
RECTANGLE[ ][(][0-9]+,[0-9]+,[0-9]+,[0-9]+,[0-9]+,[0-9]+,[0-9]+,[0-9]+[)]	{ total++; printf("Making %s", yytext); }
SET_COLOR[ ][(][0-9][)] 							{ total++; printf("Color %s", yytext); }
INT[ ][(][0-9]+[)] 								{ total++; printf("INT %s", yytext); }
FLOAT[ ][(][0-9]+.[0-9]+[)] 							{ total++; printf("FLOAT %s", yytext); }
;										{ printf("END_STATEMENT"); }	
[ \t]+  									|
END										{ exit(1); }
.										{ total++; printf("Error on line %d", total); }

%%

int main(int argc, char** argv) {
	yylex();
	return 0;
}
