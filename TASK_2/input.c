#include<stdio.h>
#include<stdlib.h>
#include "input.h"
#include "validation.h"
#include "computation.h"


struct Student student;
FILE *out;
int count=0;
float total_percentage=0;
float highest=0;
float lowest=100;
int count_O,count_AP,count_A,count_BP,count_B,count_C,count_D,count_F;
char stored_ids[100][9];
int stored_count = 0;





int main(){
    FILE *fptr=fopen("inp.txt","r");
    out=fopen("out.txt","w");

   
    
    while((fscanf(fptr,"%s %s %d %d %d %d %d %d %d %d %d %d",student.id,student.name,&student.minor[0],&student.major[0],&student.minor[1],&student.major[1],&student.minor[2],&student.major[2],&student.minor[3],&student.major[3],&student.minor[4],&student.major[4]))!=EOF){
        if (!validation()) {
        continue;   
        }
        fprintf(out,"%8s %8s",student.id,student.name);

        //fprintf(out,"%s %s %d %d %d %d %d %d %d %d %d %d\t",student.id,student.name,student.minor[0],student.major[0],student.minor[1],student.major[1],student.minor[2],student.major[2],student.minor[3],student.major[3],student.minor[4],student.major[4]);
        computation();
    }
    output();
    return 0;
}

