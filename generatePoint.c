#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL));
	FILE *fp,*fp1;
	fp = fopen("training.txt","w+");
	fp1 = fopen("testing.txt","w+");
	int i;
	float x,y;	

	for(i = 0; i<1500; i++){
		x = ((float)rand()/(float)(RAND_MAX))* 2 - 1;
		y = ((float)rand()/(float)(RAND_MAX))* 2 - 1;
		if((x*x)+(y*y) < 0.09 || (x*x)+(y*y) > 0.81){
			fprintf(fp,"%lf %lf %d \n",x,y,1);
		}else if((x*x)+(y*y) > 0.09 || (x*x)+(y*y) < 0.49){
			fprintf(fp,"%lf %lf %d \n",x,y,2);
		}else{
			fprintf(fp,"%lf %lf %d \n",x,y,3);
		}
	}

	for(i = 0; i<1500; i++){
		x = ((float)rand()/(float)(RAND_MAX))* 2 - 1;
		y = ((float)rand()/(float)(RAND_MAX))* 2 - 1;
		if((x*x)+(y*y) < 0.09 || (x*x)+(y*y) > 0.81){
			fprintf(fp1,"%lf %lf %d \n",x,y,1);
		}else if((x*x)+(y*y) > 0.09 || (x*x)+(y*y) < 0.49){
			fprintf(fp1,"%lf %lf %d \n",x,y,2);
		}else{
			fprintf(fp1,"%lf %lf %d \n",x,y,3);
		}
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
