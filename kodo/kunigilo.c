#include<stdlib.h>
#include<stdio.h>
	//bezonatas dosieretoj 000.srt gxis N.srt  
//aserto : cxiuj tiuj dosieretoj troveblos
//aserto : cxiuj tiuj dosieretoj sekvos la .srt formaton
int file_count=100;	//<- sangxu la nombron por agordi la nombron de dosieretoj  [0 ĝis file_count]
char* out_file="Dune_EO.srt";
int main(int argc, char **argv){
	char filename[8]="000.srt";
	char c=':',prev='D';
	FILE* file;	//tio estos unu post la alia la dosieretoj
	FILE * final_file = fopen(out_file,"w");		//fina dosierooo!!!
	int flag=1;
	for(int i =0; i <file_count +1 ;i++){
		//sekva dosiereto
		filename[2] ='0'+ i % 10;		//unua cifero de la dosiereto
		filename[1]= '0' +(i % 100)/10 ;	// dua
		filename[0] = '0'+ (i % 1000)/100;	//kaj tria
		
		file = fopen(filename,"r");
		if(!file){
			printf("! Ne kapablis malfermi dosieron %s !\n",filename);
			exit(-1);
		}
		//printf(filename);
		printf("malfermis dosiereton %s\n",filename);
	
		//legu
		//kaj tuj skribu cxion al la fina dosiero
		while(flag){
			while(!(prev=='\n' && c=='\n')){		//unu subtitolo
				prev=c;
				fscanf(file,"%c",&c);
				if(feof(file)){flag=0;break;}	//fino de la dosiereto
				fprintf(final_file,"%c",c);
			}
			//post unu subtitolo , ignoru cxiun '\n'		
			while(c=='\n'){
	
			fscanf(file ,"%c",&c);
			if(feof(file))flag=0;break;}	//fino de la dosiereto
			//post la supra 'while', c havos singlan karakteron ankaux skribendan
			fprintf(final_file ,"%c",c);
		}
		flag=1;
		fclose(file);	
	}
	fclose(final_file);	//GG
}

