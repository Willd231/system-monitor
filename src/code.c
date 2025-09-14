#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>




int *  getTemps(){

	char * buffer = malloc(sizeof(int) * 10);

	static int temps[100]; 

	for(int i = 0; i < 9; i++){
	snprintf(buffer, sizeof(buffer), "sys/class/thermal/thermal_zones%d/temp", i);
	FILE * fp = fopen(buffer, "r");
	fread(&buffer, 4, 1, fp); 
		}	
	for(int i = 0; i < 9; i++){
		if(temps[i]!= 0){
			temps[i] = temps[i] / 1000;
		}
	}
		free(buffer);
		return temps;
		
	}



int get_Meminfo(){

	FILE * fp = fopen("/proc/meminfo", "r");
	
		int value  = 0;
		char line[100];
		int line_num = 0;
		fp = fopen("/proc/meminfo", "r");
		while(fgets(line, sizeof(line), fp)){
			line_num++;
			if(line_num == 2){
				sscanf(line, "%d", &value);
				break;
			}
		}
	return value;
	
}



int main(){
	
	while(1==1){

		int * temps = getTemps();
		int mem = get_Meminfo(); 

		printf("\r%d\n", mem);

		
		
		printf("\rCPU TEMP: %d°C \n", temps[7]);
		printf("\rWIFI Chip: %d°C\n", temps[8]);
				
		fflush(stdout);
		sleep(1);
		
	}
	
	return 0;
}
