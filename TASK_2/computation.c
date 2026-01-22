#include "computation.h"
#include "input.h"


 int computation(){

    int total[5],i;
    float grade=0;
    for(i=0;i<5;i++){
        total[i]=student.minor[i]+student.major[i];
    }
    for(i=0;i<5;i++){

        fprintf(out," %3d %3d %3d\t",student.minor[i],student.major[i],total[i]);

    if(total[i]>=90 && total[i]<=100){
        fprintf(out,"O");
        grade+=10;
        count_O++;
    }
    else if(total[i]>=85 && total[i]<90){
        fprintf(out,"A+");
        grade+=9;
        count_AP++;
    }
    else if(total[i]>=75 && total[i]<85){
        fprintf(out,"A");
        grade+=8;
        count_A++;
    }
    else if(total[i]>=65 && total[i]<75) {
        fprintf(out,"B+");
        grade+=7;
        count_BP++;
    }
    else if(total[i]>=60 && total[i]<65) {
        fprintf(out,"B");
        grade+=6;
        count_B++;
    }
    else if(total[i]>=55 && total[i]<60){
        fprintf(out,"C");
        grade+=5;
        count_C++;
    }
       
       else if(total[i]>=50 && total[i]<55) {
        fprintf(out,"D");
        grade+=4;
        count_D++;
    } 
    
    else {
        fprintf(out,"F");
        count_F++;
    }   
    }
    
    float cgpa=grade/5;
    fprintf(out,"\t%f",cgpa);
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