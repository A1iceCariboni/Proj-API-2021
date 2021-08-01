#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_DIST -1


struct vertex_from0 {
int num;
long long dist;
bool visited;
};

struct topK{
	int graph;
	long long weight;
};
//riga = j/d;
//colonna = j%d


// j = d * riga + colonna



int k, d, size, graphcount = 0, ranksize = 0;



//costruisce max heap
void max_heapify(struct topK rank[], int n){
int dx, sx, max;
struct topK r;
   sx = 2 * n;
   dx = (2 * n) + 1;
   if((sx < ranksize)&&(rank[sx].weight > rank[n].weight)){
   		  max = sx;
	}else{
		max = n;
	}
	if((dx < ranksize) && (rank[dx].weight > rank[n].weight)){
		max = dx;
	}
	if(max != n){
	r = rank[max];
	rank[max] = rank[n];
	rank[n] = r;
	max_heapify(rank, max);	     	  	  
	}
}

void place_in_rank(struct topK rank[], long long sum){
	struct topK r;
	int i;
	r.graph = graphcount;
	r.weight = sum;
	
	if(ranksize < k){
		rank[ranksize] = r;
		ranksize ++;
	 	i = ranksize - 1;
		 while((i > 0)	&& (rank[i/2].weight < rank[i].weight)){
		 	r = rank[i/2];
		 	rank[i/2] = rank[i];
		 	rank[i] = r;
		 	i = i/2;
		 }
	}else{
		if(sum < rank[0].weight){
			rank[0] = rank[ranksize - 1];
			ranksize --;
			max_heapify(rank, 0);
			rank[ranksize] = r;
			ranksize ++;
		 	i = ranksize - 1;
			 while((i > 0)	&& (rank[i/2].weight < rank[i].weight)){
			 	r = rank[i/2];
			 	rank[i/2] = rank[i];
			 	rank[i] = r;
			 	i = i/2;
			 }
		}
	}
}

void print_rank(struct topK rank[]){
	int i;
	for(i = 0; i < ranksize - 1; i++){
		printf("%d ", rank[i].graph);
	}
        printf("%d\n", rank[ranksize - 1].graph);

}


//restituisce il minimo e sistema lo heap
struct vertex_from0 get_min(struct vertex_from0 vert[]){
	struct vertex_from0 min;
	int i;
	
	min.dist = 9223372036854775807;
	min.num = -1;
	
	for(i = 0; i < d; i++){
		if((!vert[i].visited) && (vert[i].dist < min.dist) && (vert[i].dist != -1)){
			min = vert[i];
		}
	}
	
	return min;
}

long long djkstra(long long graph[]){
	 struct vertex_from0 vertex[d], u;
	 int start, i;
	 long long dist;
	 long long sum_dis;
	 
	 vertex[0].dist = 0;
	 vertex[0].num = 0;
	 vertex[0].visited = false;
		for(i = 1; i < d; i++){
			vertex[i].dist = MAX_DIST;
			vertex[i].num = i;
			vertex[i].visited = false;
		}
		 
	 
	 	
	 sum_dis = 0; 	
	 u = get_min(vertex);  
	 while(u.num != -1){
		vertex[u.num].visited = true;
	    sum_dis = sum_dis + vertex[u.num].dist;
	
		start = d * u.num;
		for(i = start; i < start + d; i++){
			if(graph[i] != 0){
				dist = u.dist + graph[i];
			if((!vertex[i%d].visited)&&((vertex[i % d].dist > dist)||(vertex[i % d].dist == -1))){
				  	vertex[i%d].dist = dist;
				  }	
		  		}
	    }
  	    u = get_min(vertex);
   }
	 
	return sum_dis;	 
}


int main(){
char str[11], c;
long long *graph;
struct topK *rank;
int i, j;
long long sum;
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

graph = malloc(sizeof(long long)*size);
rank = malloc(sizeof(struct topK)*k);

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
    	sum = djkstra(graph);
    	place_in_rank(rank, sum);
    	printf("GraphCount = %d\n Sum = %lld\n",graphcount, sum);
    	print_rank(rank);
 		graphcount++;

    }else{
    	while(c != '\n') c = fgetc(stdin);
    	print_rank(rank);
        }
		 c = fgetc(stdin);

  
}
return 0;
}


