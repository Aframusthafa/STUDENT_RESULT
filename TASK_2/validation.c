#include "validation.h"
#include "input.h"

int validation(){
    int i;
    for(i=0;student.id[i]!='\0';i++){
        if (!isalnum(student.id[i])){
            printf("Rejected ID due to invalid format: %s\n", student.id);
            return 0;
        }
    }
     for (i = 0; i < stored_count; i++) {
        if (strcmp(stored_ids[i], student.id) == 0) {
            printf("Rejected ID due to duplication : %s\n", student.id);
            return 0;
        }
    }

    for(i=0;student.name[i]!='\0';i++){
        if (!isalpha(student.name[i])){
            printf("Rejected name due to invalid format : %s\n", student.name);
            return 0;
        }
    }

    for (int i = 0; i < 5; i++) {
            if (student.minor[i] < 0 || student.minor[i] > 40){
                printf("Rejected  due to invalid minor marks: %s\n", student.id);
                return 0;
            }

            if (student.major[i] < 0 || student.major[i] > 60){
                printf("Rejected  due to invalid major marks: %s\n", student.id);
                return 0;
            }   
    }
   
   strcpy(stored_ids[stored_count++], student.id);
   return 1;
}
