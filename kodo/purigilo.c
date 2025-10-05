// ricevas .srt dosieron
// produktas puran.srt dosieron havante la tempopunktoj  sen la teksto


// aserto : la dosiero ekzistos
// aserto : la dosiero sekvos la .srt formaton

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DIRTY_FILE_USES_WIN_NEWLINES 1

char fgetc2(FILE* file);

int main(int argc, char **argv){
	char sourcefile[100]={};
	char c;
	int i=0;

	enum two_newline_finder_fsm {none, one,two};
	enum two_newline_finder_fsm fsm ;
	if(argc <2){
		printf("Nomu la dosieron purigotan\n");
		scanf("%s",sourcefile);
	}
	else
		strcpy(sourcefile ,argv[1]);

	FILE* dirty =fopen(sourcefile , "r");
	FILE* clean = fopen("pura.srt" ,"w");

	if(!dirty) {printf("dosiero \"%s\" ne troveblas\n",sourcefile);exit(-1);}
	if(!clean) {printf("ne povas krei dosieron\n");exit(-1);}

	//la formato estas	
	//subtekstonumero -newline 1-
	//temposignoj     -newline 2-
	// teksto	-newline3--newline4-
	while(1){
		//legi numeron
		//verki numeron
		do{
			c=fgetc2(dirty);
			fputc(c,clean);
		}while(c!='\n');
	
		//legi temposignojn
		//verki temposignojn
		do{
			c=fgetc2(dirty);
			fputc(c,clean);
		}while(c!='\n');
		
		//legi tekston 
		//ignori tekston
		//verki -newline-on
		fsm=none;
		while(fsm!=two){
			c=fgetc2(dirty);
			if(c=='\n')
				fsm++;
			else if(c==EOF)
				break;
			else
			       	fsm=none;
		}
		fputc('\n',clean);
		
		c=fgetc2(dirty);
		if (c==EOF) break;
		ungetc(c,dirty);
	}
	fclose(clean);
	fclose(dirty);
	printf("dosiero pura.srt estas kreita\n");
	return 0;
}

//legu la vindozan newline-on (\r\n) kiel \n
char fgetc2(FILE* file){
	char c = fgetc(file);
	if(c!= '\r' || !DIRTY_FILE_USES_WIN_NEWLINES) return c;
	char nextc= fgetc(file);
	if(nextc == '\n') return '\n';
	ungetc(nextc,file);
	return c;

}
