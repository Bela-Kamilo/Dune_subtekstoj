
#include<stdio.h>


// ricevas .srt dosieron 
// produktas .srt dosieretojn po 10 subtekstoj kiuj efikas la unuan .srt dosieron .
// la dosieretoj nomigxas 1.srt 2.srt ktp.




// aserto : la dosiero ekzistos
// aserto : la dosiero sekvos la .srt formaton


char read_n_write(FILE* from , FILE* to);
void appropriate_name( char * name , int i);

int main(){


	int i=0;
	char c;
	
	FILE * clean= fopen("pura.srt","r");
	char   current_file_name[8]={"000.srt"};
	FILE * current_file;



	while(i<10){

	
		//malfermu arkiveton
		approriate_name(current_file_name ,i);
		current_file= fopen(current_file_name , "w");
				
		
		//verki gxis -newline--newline-
		for(int j=0;j<10;){
		
			/*	
			while( read_n_write(clean , current_file)!='\n');
			  	
			 			
			c=read_n_write(clean ,current_file );
			
			if(c=='\n'){ fputc('\n');fputc('\n');j++;}	//lasas unu pli malplenan linion
	
			j++;
			*/
		}

		fclose(current_file);
		i++;			//sekva arkiveto


	}




	return 0;
}



char read_n_write(FILE* from , FILE* to){

	return fputc(fgetc (from) ,to) ;

}


//sangxas la 3 unuaj karakterojn al la numero i.
//supozigxas ke i estu 3digita nombro
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

