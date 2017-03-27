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

//Learning rate
float n = 0.1;

point prototype;
int pos;
float var[M];
int count[M];
char map[28][28];

center centers[M];
center oldCenters[M];

void setOld(){
	int i,j;
	int x,y;
	for(i=0; i<M; i++){
		oldCenters[i].cx = centers[i].cx;
		oldCenters[i].cy = centers[i].cy;
		x = (oldCenters[i].cx + 1.4)*10;
		y = (oldCenters[i].cy + 1.4)*10;
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
		if(((oldCenters[i].cx) != (centers[i].cx)) || ((oldCenters[i].cy) != (centers[i].cy)) ){
			return  0;
		}
	}
	return 1;
}


void initExamples(){
    srand(time(NULL));
	int i;
	int x,y;
	for(i=0; i<100; i++){
		sq0[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4; 
		sq0[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4;
		x = (sq0[i].x + 1.4)*10;
		y = (sq0[i].y + 1.4) *10;
		map[x][y] = '.';

		sq1[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4; 
		sq1[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6;
		x = (sq1[i].x + 1.4)*10;
		y = (sq1[i].y + 1.4) *10;
		map[x][y] = '.';	

		sq2[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4; 
		sq2[i].y = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6);
		x = (sq2[i].x + 1.4)*10;
		y = (sq2[i].y + 1.4) *10;
		map[x][y] = '.';	

		sq3[i].x = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6); 
		sq3[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4;
		x = (sq3[i].x + 1.4)*10;
		y = (sq3[i].y + 1.4) *10;
		map[x][y] = '.';	

		sq4[i].x = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6); 
		sq4[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6;
		x = (sq4[i].x + 1.4)*10;
		y = (sq4[i].y + 1.4) *10;
		map[x][y] = '.';	

		sq5[i].x = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6); 
		sq5[i].y = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6);
		x = (sq5[i].x + 1.4)*10;
		y = (sq5[i].y + 1.4) *10;
		map[x][y] = '.';	

		sq6[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6; 
		sq6[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 - 0.4;
		x = (sq6[i].x + 1.4)*10;
		y = (sq6[i].y + 1.4) *10;
		map[x][y] = '.';	

		sq7[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6; 
		sq7[i].y = -(((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6);
		x = (sq7[i].x + 1.4)*10;
		y = (sq7[i].y + 1.4) *10;
		map[x][y] = '.';	

		sq8[i].x = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6; 
		sq8[i].y = ((float)rand()/(float)(RAND_MAX)) * 0.8 + 0.6;
		x = (sq8[i].x + 1.4)*10;
		y = (sq8[i].y + 1.4) *10;
		map[x][y] = '.';	

	}
	return ;
}

void initCenters(){
	int i;
	int x,y;
	for(i=0;i<M;i++){
		int arr = rand()%9;
		int pos1 = rand()%100;
		if(arr == 0){
			centers[i].cx = sq0[pos1].x;
			centers[i].cy = sq0[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 1){
			centers[i].cx = sq1[pos1].x;
			centers[i].cy = sq1[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 2){
			centers[i].cx = sq2[pos1].x;
			centers[i].cy = sq2[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 3){
			centers[i].cx = sq3[pos1].x;
			centers[i].cy = sq3[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 4){
			centers[i].cx = sq4[pos1].x;
			centers[i].cy = sq4[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 5){
			centers[i].cx = sq5[pos1].x;
			centers[i].cy = sq5[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 6){
			centers[i].cx = sq6[pos1].x;
			centers[i].cy = sq6[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else if(arr == 7){
			centers[i].cx = sq7[pos1].x;
			centers[i].cy = sq7[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}else{
			centers[i].cx = sq8[pos1].x;
			centers[i].cy = sq8[pos1].y;
			x = (centers[i].cx + 1.4)*10;
			y = (centers[i].cy + 1.4)*10;
			map[x][y] = 'O';
		}
	}
	return;
}

void getPrototype(){
		int arr = rand()%9;
		int position = rand()%100;
		if(arr == 0){
			prototype.x = sq0[position].x;
			prototype.y = sq0[position].y;
		}else if(arr == 1){
			prototype.x = sq1[position].x;
			prototype.y = sq1[position].y;
		}else if(arr == 2){
			prototype.x = sq2[position].x;
			prototype.y = sq2[position].y;
		}else if(arr == 3){
			prototype.x = sq3[position].x;
			prototype.y = sq3[position].y;
		}else if(arr == 4){
			prototype.x = sq4[position].x;
			prototype.y = sq4[position].y;
		}else if(arr == 5){
			prototype.x = sq5[position].x;
			prototype.y = sq5[position].y;
		}else if(arr == 6){
			prototype.x = sq6[position].x;
			prototype.y = sq6[position].y;
		}else if(arr == 7){
			prototype.x = sq7[position].x;
			prototype.y = sq7[position].y;
		}else{
			prototype.x = sq8[position].x;
			prototype.y = sq8[position].y;
		}
		printf("prototype %lf , %lf\n",prototype.x,prototype.y);
		return;
}

float distance(point p,center c){
	float dis;
	dis = sqrt((float)((p.x-c.cx)*(p.x-c.cx)) + (float)((p.y-c.cy)*(p.y-c.cy)));
	return dis;
}

void moveCenter(){
	int i,x,y;
	centers[pos].cx =oldCenters[pos].cx + n*(prototype.x - oldCenters[pos].cx);
	centers[pos].cy =oldCenters[pos].cy + n*(prototype.y - oldCenters[pos].cy);
	x = (oldCenters[pos].cx + 1.4)*10;
	y = (oldCenters[pos].cy + 1.4)*10;
	map[x][y] = '_';
	x = (centers[pos].cx + 1.4)*10;
	y = (centers[pos].cy + 1.4)*10;
	map[x][y] = 'O';
}



void getWinner(){
	int i;
	float temp=999.99;
	pos=0;
	
	for(i=0; i<M; i++){
		float dis = distance(prototype,centers[i]); 
		if(dis < temp){
			temp = dis;
			pos = i;
		}
	}
	moveCenter();
	return;
}

void calculateVar(){
	int i,j;
	for(i=0;i<100;i++){
		for(j = 0;j<M;j++){
			if(sq0[i].team == j){
				var[j] +=  distance(sq0[i],centers[j]); 
				count[j]++;
			}else if(sq1[i].team == j){
				var[j] +=  distance(sq1[i],centers[j]);
				count[j]++;
			}else if(sq2[i].team == j){
				var[j] +=  distance(sq2[i],centers[j]);	
				count[j]++;
			}else if(sq3[i].team == j){
				var[j] +=  distance(sq3[i],centers[j]);	
				count[j]++;
			}else if(sq4[i].team == j){
				var[j] +=  distance(sq4[i],centers[j]);
				count[j]++;
			}else if(sq5[i].team == j){
				var[j] +=  distance(sq5[i],centers[j]);	
				count[j]++;
			}else if(sq6[i].team == j){
				var[j] +=  distance(sq6[i],centers[j]);	
				count[j]++;
			}else if(sq7[i].team == j){
				var[j] +=  distance(sq7[i],centers[j]);		
				count[j]++;
			}else{
				var[j] +=  distance(sq8[i],centers[j]);	
				count[j]++;
			}
		}
	}	
	for(i=0;i<M;i++){
		var[i] = var[i]/count[i];
		printf("var[%d] =  %lf\n",i,var[i]);
	}
	return;
}

int main()
{
	srand(time(NULL));
	int c = 0;
	int i,j;
	int x,y;
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			map[i][j] = '_';
		}
	}
	initExamples();
	initCenters();
	for(i = 0;i<M;i++){
		printf("Centers[%d] (%lf,%lf)\n",i,centers[i].cx,centers[i].cy);
	}
	printf("\n\n");
	while(c<1000 && (checkCenter()!=1)){
		getPrototype();
		setOld();
		getWinner();
		n = 0.95*n;
		c++;
		for(i = 0;i<M;i++){
			printf("Centers[%d] (%lf,%lf)\n",i,centers[i].cx,centers[i].cy);
		}
		printf("\n\n");
	}
	for(i=0; i<M; i++){
		x = (centers[i].cx + 1.4)*10;
		y = (centers[i].cy + 1.4)*10;
		map[x][y] = 'O';
	}
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			printf("%c  ",map[i][j]);
		}
		printf("\n");
	}
	printf("count %d\n",c);
	calculateVar();
	return 0;
}




