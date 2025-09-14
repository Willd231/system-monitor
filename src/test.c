#include <stdio.h>
#include <unistd.h>

int main(){

printf("Cpu Temp: ");
	while(1==1){
	int temp;
	FILE *fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
	fscanf(fp, "%d", &temp);
	printf("\rCpu Temp: %d", temp);
	fflush(stdout);
	sleep(1);
	}
}
