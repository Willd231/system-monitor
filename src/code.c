#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>




float *  getTemps(){


	char * path = "/sys/class/thermal/thermal_zone";
	
	char * temp = "/temp";
	char ** string = malloc(sizeof(char*) * 9);
	float * temps = malloc(sizeof(int) * 9); 
	
	//char * final = malloc(sizeof(char) * strlen(path) + strlen(temp) + 2);
	for(int i = 0; i < 9; i++){
				
		char buffer[10];
		snprintf(buffer,sizeof(buffer), "%d", i);
		//printf("%s\n", buffer);
		string[i] = (char*)malloc(sizeof(char) * (strlen(path) + strlen(temp) + strlen(buffer) + 1));
		strcpy(string[i], path);
		strcat(string[i], buffer);
		strcat(string[i], temp);
		//printf("%s\n", string[i]);
																
	 //the segfault is due to trying to use fread on a NULL or nonexistant path aka : path

	
	FILE * fp;
	if((fp = fopen(string[i], "r")) == NULL){
		printf("File not found\n");
		return NULL;
	}
	else{
		fp = fopen(string[i], "r");
	} 
	
	//fread(path, 4, 1, fp); 
	fscanf(fp, "%f", &temps[i]);
			
	for(int i = 0; i < 9; i++){
		if(temps[i]!= 0){
			temps[i] = temps[i];
		}
	}

		
		}
		return temps;
}


int get_Meminfo(){

	FILE * fp;
	if((fp = fopen("/proc/meminfo", "r")) == NULL){
		printf("memfile not found \n"); 
		return -2;
	};
	
		int value;
		char line[100];
		int line_num = 0;
		fp = fopen("/proc/meminfo", "r");
		//while(fgets(line, sizeof(line), fp)){
		//	line_num++;
		//	if(line_num == 2){
		//		sscanf(line, "%d", &value);
		fscanf(fp, "%s", line);
				printf("%s", line);
				//break;
			//}
		//}
	return value;
	
}



int main(){
	
	while(1==1){
		if(getTemps() == NULL){
			perror("Error getting temperatures\n");
			return -2;
		}
		float * temps = malloc(sizeof(float) * 9);
		temps = getTemps();
		int mem = get_Meminfo(); 

	
		
		printf("\rCPU TEMP: %.1lf°C \t\t\tWIFI CHIP TEMP: %.1lf°C\tMemory Usage: %d", temps[7]/1000, temps[8]/1000, mem);
		fflush(stdout);
		//printf("\rWIFI Chip: %f°C", temps[8]);
				
		
		sleep(1);
		}
		
		
	
	
	return 0;
}
\
