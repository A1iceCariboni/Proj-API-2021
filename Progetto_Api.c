#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX_DIST -1

struct vertex_from0{
int num, dist;
};
//riga = j/d;
//colonna = j%d

// j = d * riga + colonna



int k, d, size;

//costruisce min heap
void min_heapify(struct vertex_from0 vert[], int n, heapsize){
int i, dx, sx, min;
struct vertex_from0 v;
   sx = 2 * i;
   dx = (2 * i) + 1;
   if((sx < heapsize)&&(vert.dist[l] < vert.dist[i]){
   		  min = l;
	}else{
		min = i;
	}
	if((dx < heapsize) && (vert.dist[r] < vert.dist[i]){
		min = r;
	}
	if(min != i){
	v = vert[min];
	vert[min] = vert[i];
	vert[i] = v;
	min_heapify(vert, min);	     	  	  
	}

}

//restituisce il minimo e sistema lo heap
struct vertex get_min(struct vertex vert[], int *heapsize){
	struct vertex min = vert[0];
	
	vert[0] = vert[heapsize - 1];
	heapsize--;
	min_heapify(vert,0,heapsize);
	vert[heapsize] = min;
	return min;
}

int djkstra(long long graph[]){
 struct vertex_from0 vertex[d], v, u, *nodes;
 int row;
 int heapsize = d;
 long long dis, sumdis;
 
 vertex[0].dist = 0;
 vertex[0].num = 0;
 nodes[0] -> vertex[0];
	for(i = 1; i < d; i++){
		vertex[i].dist = MAX_DIST;
		vertex[i].num = i;
		nodes[i] -> vertex[i];
	}
	 
 for(i = d/2 - 1; i >= 0; i--){
 	min_heapify(vert, i);
 }
 
 while(heapsize > 0){
	u = get_min(vertex, &heapsize);
	row = d * v.num;
	for(i = row + 1; i < row + d; i++){
		dist = u.dist + graph[row][row + i];
	  if((&nodes[d%i].dist > dist) || (&nodes[d%i] == MAX_DIST)){
	  	&nodes[d%i].dist = dist;
	  	min_heapify(vertex, heapsize, heapsize);
	  }	
	}
 }
 sum_dis = 0;
for(i = 0; i < d; i++){
	sum_dis = sum_dis + &nodes[i].dist;
}
return sum_dis;	 
}


int main(){
char str[11], c;
long long *graph;
int i, j;
i = 0;
c = fgetc(stdin);
while(c != ' '){
	str[i] = c;
	c = fgetc(stdin);
	i++;
}
d = atoi(str);
size = d * d;
c = fgetc(stdin);
i = 0;

while(c != '\n'){
	str[i] = c;
	c = fgetc(stdin);
	i++;
}
str[i] = '\0';
k = atoi(str);

graph = malloc(sizeof(struct edge)*size);
c = fgetc(stdin);
while(c != EOF){
  	if(c == 'A'){
  		while(c != '\n') c = fgetc(stdin);
  		
  		for(j = 0; j < size; j++){
		   	c = fgetc(stdin);
			i = 0;
  			while((c != ',') && (c != '\n')){
  				str[i] = c;
  				c = fgetc(stdin);
  				i++;
			  }
			  str[i] = '\0';
			  graph[j] = atol(str);
	    }
 		printf("%d\n", k);
  		printf("%d\n", d);
  		for(j = 0; j < size; j ++){
  			  printf("%ld ", graph[j]);
		  }

	  }
    else{
    	
		 }
		 c = fgetc(stdin);

  
}
}


