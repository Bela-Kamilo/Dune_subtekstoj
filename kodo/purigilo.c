

// ricevas .srt dosieron
// produktas puran.srt dosieron havante la tempopunktoj  sen la teksto



// aserto : la dosiero ekzistos
// aserto : la dosiero sekvos la .srt formaton


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv){


	char sourcefile[100]={};
	char c;
	int i=0;

	enum two_newline_finder_fsm {none, one,two};
	
	enum two_newline_finder_fsm fsm ;

	if(argc <1) {
		printf("Nomu la dosieron purigotan\n");
		scanf("%s",sourcefile);
	}
	else
		strcpy(sourcefile ,argv[1]);



	FILE* dirty =fopen(sourcefile , "r");
	FILE* clean = fopen("pura.srt" ,"w");


	if(!dirty) {printf("dosiero \"%s\" ne trovebla\n",sourcefile);exit(-1);}

	//la formato estas
	
	//subtekstonumero -newline 1-
	//temposignoj     -newline 2-
	// teksto	-newline3--newline4-
	
	
	while(1){
		
		
		//legi numeron
		//verki numeron
		do{
			
			c=fgetc(dirty);
			fputc(c,clean);
		
		}while(c!='\n');
		
		
	
		//legi temposignojn
		//verki temposignojn
		
		do{
			c=fgetc(dirty);
			fputc(c,clean);
			
		}while(c!='\n');
		

		//legi tekston 
		//ignori tekston
		//verki -newline-on
		
		fsm=none;
		
		while(fsm!=two){
		
			
			c=fgetc(dirty);
			
			if(c=='\n')fsm++;
			else fsm=none;
		
		}
		
		fputc('\n',clean);
		
		
		//feof fukcias poste kiamn la EOF legigxas ...
		c=fgetc(dirty);
		if (c==EOF) break;
		ungetc(c,dirty);
		
		
	}




	return 0;


}





