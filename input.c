#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>


struct Student{
    char id[9];
    char name[20];
    int minor[5];
    int major[5];
}student;

FILE *out;
int count=0;
float total_percentage=0;
float highest=0;
float lowest=100;
int count_O,count_AP,count_A,count_BP,count_B,count_C,count_D,count_F;
char stored_ids[100][9];
int stored_count = 0;

int validation();
int computation();
void output();



int main(){
    FILE *fptr=fopen("inp.txt","r");
    out=fopen("out.txt","w");
    
    while((fscanf(fptr,"%s %s %d %d %d %d %d %d %d %d %d %d",student.id,student.name,&student.minor[0],&student.major[0],&student.minor[1],&student.major[1],&student.minor[2],&student.major[2],&student.minor[3],&student.major[3],&student.minor[4],&student.major[4]))!=EOF){
        if (!validation()) {
        continue;   
        }
        fprintf(out,"%s %s %d %d %d %d %d %d %d %d %d %d\t",student.id,student.name,student.minor[0],student.major[0],student.minor[1],student.major[1],student.minor[2],student.major[2],student.minor[3],student.major[3],student.minor[4],student.major[4]);
        computation();
    }
    output();
    return 0;
}


int validation(){
    int i;
    for(i=0;student.id[i]!='\0';i++){
        if (!isalnum(student.id[i])){
             fprintf(out,"Rejected ID due to invalid format: %s\n", student.id);
            return 0;
        }
    }
     for (i = 0; i < stored_count; i++) {
        if (strcmp(stored_ids[i], student.id) == 0) {
            fprintf(out,"Rejected ID due to duplication : %s\n", student.id);
            return 0;
        }
    }

    for(i=0;student.name[i]!='\0';i++){
        if (!isalpha(student.name[i])){
            fprintf(out,"Rejected name due to invalid format : %s\n", student.name);
            return 0;
        }
    }

    for (int i = 0; i < 5; i++) {
            if (student.minor[i] < 0 || student.minor[i] > 40){
                fprintf(out,"Rejected  due to invalid minor marks: %s\n", student.id);
                return 0;
            }

            if (student.major[i] < 0 || student.major[i] > 60){
                fprintf(out,"Rejected  due to invalid major marks: %s\n", student.id);
                return 0;
            }   
    }
   
   strcpy(stored_ids[stored_count++], student.id);
   return 1;
}




int computation(){

    int total[5],i;
    float grade=0;
    for(i=0;i<5;i++){
        total[i]=student.minor[i]+student.major[i];
    }
    for(i=0;i<5;i++){

        fprintf(out,"%d\t",total[i]);

    if(total[i]>=90 && total[i]<=100){
        fprintf(out,"O\t");
        grade+=10;
        count_O++;
    }
    else if(total[i]>=85 && total[i]<90){
        fprintf(out,"A+\t");
        grade+=9;
        count_AP++;
    }
    else if(total[i]>=75 && total[i]<85){
        fprintf(out,"A\t");
        grade+=8;
        count_A++;
    }
    else if(total[i]>=65 && total[i]<75) {
        fprintf(out,"B+\t");
        grade+=7;
        count_BP++;
    }
    else if(total[i]>=60 && total[i]<65) {
        fprintf(out,"B\t");
        grade+=6;
        count_B++;
    }
    else if(total[i]>=55 && total[i]<60){
        fprintf(out,"C\t");
        grade+=5;
        count_C++;
    }
       
       else if(total[i]>=50 && total[i]<55) {
        fprintf(out,"D\t");
        grade+=4;
        count_D++;
    } 
    
    else {
        fprintf(out,"F\t");
        count_F++;
    }   
    }
    
    float cgpa=grade/5;
    fprintf(out,"%f",cgpa);
    count++;
    int percentage=cgpa*10;
    total_percentage+=percentage;

    if(highest<percentage){
        highest=percentage;
    }

    if(lowest>percentage){
        lowest=percentage;
    }

    fprintf(out,"\n");
    return 0;
}

 void output(){
    fprintf(out,"Class Average Percentage: %f\n",total_percentage/count);
    fprintf(out,"Highest percentage = %f\n",highest);
    fprintf(out,"Lowest percentage=%f\n",lowest);
    fprintf(out,"No. of student in O grade: %d\n",count_O);
    fprintf(out,"No. of student in A+ grade: %d\n",count_AP);
    fprintf(out,"No. of student in A grade: %d\n",count_A);
    fprintf(out,"No. of student in B+ grade: %d\n",count_BP);
    fprintf(out,"No. of student in B grade: %d\n",count_B);
    fprintf(out,"No. of student in C grade: %d\n",count_C);
    fprintf(out,"No. of student in D grade: %d\n",count_D);
    fprintf(out,"No. of student in F grade: %d\n",count_F);

 }
