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



int k, d, size, heapsize;

//costruisce min heap
void min_heapify(struct vertex_from0 vert[], int n){
int dx, sx, min;
struct vertex_from0 v;
   sx = 2 * n;
   dx = (2 * n) + 1;
   if((sx < heapsize)&&(vert[sx].dist < vert[n].dist)){
   		  min = sx;
	}else{
		min = n;
	}
	if((dx < heapsize) && (vert[dx].dist < vert[n].dist)){
		min = dx;
	}
	if(min != n){
	v = vert[min];
	vert[min] = vert[n];
	vert[n] = v;
	min_heapify(vert, min);	     	  	  
	}

}

//restituisce il minimo e sistema lo heap
struct vertex_from0 get_min(struct vertex_from0 vert[]){
	struct vertex_from0 min = vert[0];
	
	vert[0] = vert[heapsize - 1];
	heapsize--;
	min_heapify(vert,0);
	vert[heapsize] = min;
	return min;
}

long int djkstra(int graph[]){
 struct vertex_from0 vertex[d], u;
 int start, i, j;
 heapsize = d;
 int dist;
 long int sum_dis;
 
 vertex[0].dist = 0;
 vertex[0].num = 0;
	for(i = 1; i < d; i++){
		vertex[i].dist = INT_MAX;
		vertex[i].num = i;
	}
	 
 for(i = d/2 - 1; i >= 0; i--){
 	min_heapify(vertex, i);
 }
 
 while(heapsize > 0){
	u = get_min(vertex);
	start = d * u.num;
	for(i = start + 1; i < start + d; i++){
		if((graph[i] != 0)){
		 dist = u.dist + graph[i];
		for(j = 0; j < heapsize; j++){
		  if((vertex[j].num == i % d)&&(vertex[j].dist > dist)){
		  	vertex[j].dist = dist;
		  	min_heapify(vertex, 0);
		  }	
  		}
  	  }
	}
 }
 sum_dis = 0;
for(i = 0; i < d; i++){
	sum_dis = sum_dis + vertex[i].dist;
}
return sum_dis;	 
}


int main(){
char str[11], c;
int *graph;
int i, j;
long int sum;
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

graph = malloc(sizeof(int)*size);
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
  			  printf("%d ", graph[j]);
		  }
    sum = djkstra(graph);
    printf("\n%ld", sum);
	  }
    else{
    	
		 }
		 c = fgetc(stdin);

  
}
return 0;
}


