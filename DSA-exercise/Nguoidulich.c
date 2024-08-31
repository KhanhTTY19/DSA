#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int *mat;
int *visited;
int n;
int first;
int min;

void gen(int sum,int from,int count){
    if(count==n){
        if(sum+mat[from*n+first]<min){
             min=sum+mat[from*n+first];
             //printf("%d\n",sum+mat[from*n+first]);
        }
        return;
    }
    if(sum>min) return;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            gen(sum+mat[from*n+i],i,count+1);
            visited[i]=0;
        }
    }
}

void main(){
    scanf("%d",&n);
    mat=malloc(sizeof(int)*n*n);
    for(int i=0;i<n*n;i++){
        scanf("%d",mat+i);
    }
    visited=calloc(n,sizeof(int));
    first=0;
    visited[first]=1;
    min=INT_MAX;
    gen(0,first,1);
    printf("%d",min);
}