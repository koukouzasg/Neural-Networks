#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define  M 5

typedef struct Point{

        float x;
        float y;
		int team;

}point;

typedef struct Center{

        float cx;
        float cy;
		int num;

}center;

//Declare groups
	point sq0[100];
	point sq1[100];
	point sq2[100];
	point sq3[100];
	point sq4[100];
	point sq5[100];
	point sq6[100];
	point sq7[100];
	point sq8[100];	


	float sumX[M];
	float sumY[M];
	int count[M];
	float var[M];
	char map[28][28];
float distance(point p,center c){
	float dis;
	 dis = sqrt((float)((p.x-c.cx)*(p.x-c.cx)) + (float)((p.y-c.cy)*(p.y-c.cy)));
	return dis;
}

void initExamples(){
	int i;
	int x,y;
	for(i=0; i<100; i++){
		sq0[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4; 
		sq0[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4;
		x = (sq0[i].x + 1.4)*10;
		y = (sq0[i].y + 1.4) *10;
		map[x][y] = '+';

		sq1[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4; 
		sq1[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6;
		x = (sq1[i].x + 1.4)*10;
		y = (sq1[i].y + 1.4) *10;
		map[x][y] = '+';	

		sq2[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4; 
		sq2[i].y = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6);
		x = (sq2[i].x + 1.4)*10;
		y = (sq2[i].y + 1.4) *10;
		map[x][y] = '+';	

		sq3[i].x = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6); 
		sq3[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4;
		x = (sq3[i].x + 1.4)*10;
		y = (sq3[i].y + 1.4) *10;
		map[x][y] = '+';	

		sq4[i].x = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6); 
		sq4[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6;
		x = (sq4[i].x + 1.4)*10;
		y = (sq4[i].y + 1.4) *10;
		map[x][y] = '+';	

		sq5[i].x = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6); 
		sq5[i].y = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6);
		x = (sq5[i].x + 1.4)*10;
		y = (sq5[i].y + 1.4) *10;
		map[x][y] = '+';	

		sq6[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6; 
		sq6[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4;
		x = (sq6[i].x + 1.4)*10;
		y = (sq6[i].y + 1.4) *10;
		map[x][y] = '+';	

		sq7[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6; 
		sq7[i].y = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6);
		x = (sq7[i].x + 1.4)*10;
		y = (sq7[i].y + 1.4) *10;
		map[x][y] = '+';	

		sq8[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6; 
		sq8[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6;
		x = (sq8[i].x + 1.4)*10;
		y = (sq8[i].y + 1.4) *10;
		map[x][y] = '+';	

	}	
	return ;
}

center means[M];
center oldMeans[M];

void setOld(){
	int i,j;
	int x,y;
	for(i=0; i<M; i++){
		oldMeans[i].cx = means[i].cx;
		oldMeans[i].cy = means[i].cy;
		x = (means[i].cx + 1.4)*10;
		y = (means[i].cy + 1.4)*10;
		map[x][y] = 'O';
	}
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			printf("%c  ",map[i][j]);
		}
		printf("\n");
	}
	return;
}

int checkCenter(){
	int i;

	for(i=0; i<M; i++){
		if(((oldMeans[i].cx) != (means[i].cx)) || ((oldMeans[i].cy) != (means[i].cy)) ){
			return  0;
		}
	}
	return 1;
}

void initCenters(){
	int i;
	int x,y;
	for(i=0;i<M;i++){
		int arr = rand()%9;
		int pos = rand()%100;
		if(arr == 0){
			means[i].cx = sq0[pos].x;
			means[i].cy = sq0[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 1){
			means[i].cx = sq1[pos].x;
			means[i].cy = sq1[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 2){
			means[i].cx = sq2[pos].x;
			means[i].cy = sq2[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 3){
			means[i].cx = sq3[pos].x;
			means[i].cy = sq3[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 4){
			means[i].cx = sq4[pos].x;
			means[i].cy = sq4[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 5){
			means[i].cx = sq5[pos].x;
			means[i].cy = sq5[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 6){
			means[i].cx = sq6[pos].x;
			means[i].cy = sq6[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 7){
			means[i].cx = sq7[pos].x;
			means[i].cy = sq7[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else{
			means[i].cx = sq8[pos].x;
			means[i].cy = sq8[pos].y;
			x = (means[i].cx + 1.4)*10;
			y = (means[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}
	}
	return;
}

void computeTeams(){
	
	int i,j;
	float tmp0[100];
	float tmp1[100];
	float tmp2[100];
	float tmp3[100];
	float tmp4[100];
	float tmp5[100];
	float tmp6[100];
	float tmp7[100];
	float tmp8[100];
	for(i=0;i<100;i++){
		tmp0[i] = 100.0;
		tmp1[i] = 100.0;
		tmp2[i] = 100.0;
		tmp3[i] = 100.0;
		tmp4[i] = 100.0;
		tmp5[i] = 100.0;
		tmp6[i] = 100.0;
		tmp7[i] = 100.0;
		tmp8[i] = 100.0;
	}
	for(i = 0;i<100;i++){
		float d;
		for(j=0;j<M;j++){
			d = distance(sq0[i],means[j]);
			if(d!=0){			
				if(d<tmp0[i]){
					tmp0[i] = d;
					sq0[i].team = j;
				}
			}
			d = distance(sq1[i],means[j]);
			if(d!=0){			
				if(d<tmp1[i]){
					tmp1[i] = d;
					sq1[i].team = j;
				}
			}
			d = distance(sq2[i],means[j]);
			if(d!=0){			
				if(d<tmp2[i]){
					tmp2[i] = d;
					sq2[i].team = j;
				}
			}
			d = distance(sq3[i],means[j]);
			if(d!=0){			
				if(d<tmp3[i]){
					tmp3[i] = d;
					sq3[i].team = j;
				}
			}
			d = distance(sq4[i],means[j]);
			if(d!=0){			
				if(d<tmp4[i]){
					tmp4[i] = d;
					sq4[i].team = j;
				}
			}
			d = distance(sq5[i],means[j]);
			if(d!=0){			
				if(d<tmp5[i]){
					tmp5[i] = d;
					sq5[i].team = j;
				}
			}
			d = distance(sq6[i],means[j]);
			if(d!=0){			
				if(d<tmp6[i]){
					tmp6[i] = d;
					sq6[i].team = j;
				}
			}
			d = distance(sq7[i],means[j]);
			if(d!=0){			
				if(d<tmp7[i]){
					tmp7[i] = d;
					sq7[i].team = j;
				}
			}
			d = distance(sq8[i],means[j]);
			if(d!=0){			
				if(d<tmp8[i]){
					tmp8[i] = d;
					sq8[i].team = j;
				}
			}
		}
	}
	return;
}		

void computeCenters(){

	int i,j;
	int x,y;
	for(i=0;i<100;i++){
		for(j = 0;j<M;j++){
			if(sq0[i].team == j){
				sumX[j] += sq0[i].x;
				sumY[j] += sq0[i].y;
				count[j]++;
			}else if(sq1[i].team == j){
				sumX[j] += sq1[i].x;
				sumY[j] += sq1[i].y;
				count[j]++;		
			}else if(sq2[i].team == j){
				sumX[j] += sq2[i].x;
				sumY[j] += sq2[i].y;
				count[j]++;		
			}else if(sq3[i].team == j){
				sumX[j] += sq3[i].x;
				sumY[j] += sq3[i].y;
				count[j]++;		
			}else if(sq4[i].team == j){
				sumX[j] += sq4[i].x;
				sumY[j] += sq4[i].y;
				count[j]++;		
			}else if(sq5[i].team == j){
				sumX[j] += sq5[i].x;
				sumY[j] += sq5[i].y;
				count[j]++;		
			}else if(sq6[i].team == j){
				sumX[j] += sq6[i].x;
				sumY[j] += sq6[i].y;
				count[j]++;		
			}else if(sq7[i].team == j){
				sumX[j] += sq7[i].x;
				sumY[j] += sq7[i].y;
				count[j]++;		
			}else{
				sumX[j] += sq8[i].x;
				sumY[j] += sq8[i].y;
				count[j]++;		
			}
		}
	}
	for(i=0;i<M;i++){
		x = (oldMeans[i].cx + 1.4)*10;
		y = (oldMeans[i].cy + 1.4)*10;
		map[x][y] = '_';
		means[i].cx = sumX[i]/count[i];
		means[i].cy = sumY[i]/count[i];
		x = ((means[i].cx + 1.4)*10);
		y = (means[i].cy + 1.4)*10;
		map[x][y] = 'O';
	}
	return;
}

void calculateVar(){
	int i,j;
	for(i=0;i<100;i++){
		for(j = 0;j<M;j++){
			if(sq0[i].team == j){
				var[j] +=  distance(sq0[i],means[j]); 
			}else if(sq1[i].team == j){
				var[j] +=  distance(sq1[i],means[j]);
			}else if(sq2[i].team == j){
				var[j] +=  distance(sq2[i],means[j]);	
			}else if(sq3[i].team == j){
				var[j] +=  distance(sq3[i],means[j]);	
			}else if(sq4[i].team == j){
				var[j] +=  distance(sq4[i],means[j]);
			}else if(sq5[i].team == j){
				var[j] +=  distance(sq5[i],means[j]);	
			}else if(sq6[i].team == j){
				var[j] +=  distance(sq6[i],means[j]);	
			}else if(sq7[i].team == j){
				var[j] +=  distance(sq7[i],means[j]);		
			}else{
				var[j] +=  distance(sq8[i],means[j]);	
			}
		}
	}	
	for(i=0;i<M;i++){
		var[i] = var[i]/count[i];
		printf("var[%d] =  %lf\n",i,var[i]);
	}
	return;
}



void resetParams(){
	
	int i;
	for(i=0;i<M;i++){
		sumX[i] = 0.0;
		sumY[i] = 0.0;
		count[i] = 0;
	}
	return;
}

int main(){
	
	int i,j;
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			map[i][j] = '_';
		}
	}
    srand(time(NULL));
	initExamples();
	initCenters();
	int x,y;
	int c = 0;
	for(i = 0;i<M;i++){
		printf("Means[%d] (%lf,%lf)\n",i,means[i].cx,means[i].cy);
		x=(means[i].cx + 1.4)*10;
		y=(means[i].cy + 1.4)*10;
		map[x][y] = 'O';
	}
	printf("\n\n");
	while((c<10) && (checkCenter()!=1)){
		setOld();
		resetParams();
		computeTeams();
		computeCenters();
		for(i = 0;i<M;i++){
			printf("Means[%d] (%lf,%lf)\n",i,means[i].cx,means[i].cy);
		}
		printf("\n\n");
		c++;
	}
	for(i=0; i<M; i++){
		x = (means[i].cx + 1.4)*10;
		y = (means[i].cy + 1.4)*10;
		map[x][y] = 'O';
	}
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			printf("%c  ",map[i][j]);
		}
		printf("\n");
	}
	calculateVar();
	
	return 0;
}
	




