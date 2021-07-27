#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int k, d, size;
int manageGraph(){
	return 0;
}


int main(){
char str[11], c;
long  *graph;
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

graph = malloc(sizeof(long)*size);
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
  			  printf("%ld\n", graph[j]);
		  }

	  }
    else{
    	
		 }
		 c = fgetc(stdin);

  
}
}


