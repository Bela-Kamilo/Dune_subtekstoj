#include<stdio.h>
#include<stdlib.h>
// ricevas .srt dosieron 
// produktas .srt dosieretojn po 10 subtekstoj kiuj efikas la unuan .srt dosieron .
// la dosieretoj nomigxas 1.srt 2.srt ktp.

// aserto : la dosiero ekzistos
// aserto : la dosiero sekvos la .srt formaton

char read_n_write(FILE* from , FILE* to);
void appropriate_name( char * name , int i);
int copy_to_single_file(FILE* from, FILE* to);

int main(){
	int i=0;
	char c;
	FILE * clean= fopen("pura.srt","r");
	if(!clean){printf("dosiero pura.srt ne ekzistas aux ne legeblas\n");exit(-1);}
	char   current_file_name[8]={"000.srt"};
	FILE * current_file;
	int input_file_finished=0;
	while(!input_file_finished){
		//malfermu arkiveton
		appropriate_name(current_file_name ,i);
		current_file= fopen(current_file_name , "w");
		if(!current_file){printf("ne povas krei dosiereton cxi tie\n");exit(-1);}
		//kopiu al gxi
		input_file_finished=!copy_to_single_file(clean,current_file);		
		fclose(current_file);
		i++;			//sekva arkiveto
	}
	printf("%d dosieretoj kreitaj",i);
	return 0;
}
//kopias 10 subtitolojn el from al to
//return 0 se from finigxis
//return 1 alie
int copy_to_single_file(FILE* from, FILE* to){
	char c;
	for(int j=0;j<10;){
		c=read_n_write(from,to);	
		if(c==EOF) return 0;
		if(c!='\n') continue;	//verki gxis -newline--newline-
					//
		c=read_n_write(from,to);
		if(c=='\n'){	//lasas unu pli malplenan linion
		       	fputc('\n', to);
			fputc('\n', to);
			j++;
		}	
	}
	return 1;
}

char read_n_write(FILE* from , FILE* to){
	char c = fgetc(from);
	if(c==EOF) return c;
	return fputc(c ,to) ;
}

//sangxas la 3 unuaj karakterojn al la numero i.
//supozigxas ke i estu 3cifera nombro
void appropriate_name( char * name , int i){
	int ones =i%10;
	int tens = ( (i%100) -ones  )/10;
	int hundreds = i /100 ;
	
	//printf("%d %d %d \n",hundreds ,tens ,ones);	

	//karakteroj trovigxas en la ascii tablo
	// '0' + x signifas x karakteroj poste la '0' karaktero
	//cxe la tablo :D
	name[2]='0'+ones;
	name[1]='0'+tens;
	name[0]='0'+hundreds;
}

