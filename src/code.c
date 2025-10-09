#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


char ** get_temps(){
	char line[1024];
	int capacity = 8;
	char ** array = malloc(sizeof(char*) * capacity);
	int index = 0;
	FILE * fp = popen("cat /sys/class/thermal/thermal_zone*/temp", "r"); 
	while(fgets(line, sizeof(line), fp)){
		line[strcspn(line, "\n")] = 0;
		if(index >= capacity){
			capacity *=2;
			array = realloc(array, capacity * sizeof(char*));
		}
		array[index] = strdup(line);	
		index++;
	}
	array[index+1] = NULL;
fclose(fp);
return array;
	
}

char ** get_types(){
	char line[1024];
	int capacity = 8;
	char ** array = malloc(sizeof(char*) * capacity);
	int index = 0;
	FILE * fp = popen("cat /sys/class/thermal/thermal_zone*/type", "r"); 
	while(fgets(line, sizeof(line), fp)){
		line[strcspn(line, "\n")] = 0;
		if(index >= capacity){
			capacity *=2;
			array = realloc(array, capacity * sizeof(char*));
		}
		array[index] = strdup(line);	
		index++;
	}
	array[index+1] = NULL;
fclose(fp);
return array;
	
}
char ** get_mem(){
	char line[1024];
	int capacity = 8;
	char ** array = malloc(sizeof(char*) * capacity);
	int index = 0;
	FILE * fp = popen("cat /proc/meminfo", "r"); 
	while(fgets(line, sizeof(line), fp)){
		line[strcspn(line, "\n")] = 0;
		if(index >= capacity){
			capacity *=2;
			array = realloc(array, capacity * sizeof(char*));
		}
		if( (strstr(line,"MemTotal"))||
				 (strstr(line,"MemTotal"))||
				(strstr(line,"MemTotal"))||
				(strstr(line,"MemTotal"))){
				array[index] = strdup(line);	
				
		}array[index] = strdup(line);	
		index++;
	}
	array[index+1] = NULL;
fclose(fp);
return array;
	
}


int main(){
	
	/*while(1==1){
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
		
*/
char ** array = get_types();
for(int i =0; array[i]!=NULL; i++){
	printf("%s\n", array[i]);
}	
char ** array1 = get_temps();
for(int i =0; array1[i]!=NULL; i++){
	printf("%s\n", array1[i]);
}	
char ** array2 = get_mem();
for(int i =0; array1[i]!=NULL; i++){
	printf("%s\n", array2[i]);
}	

	
	return 0;
}

