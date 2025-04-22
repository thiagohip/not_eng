#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int to_Eng(double num){
    if(num == 0) return 0;
    return (int)(floor(log10(num) / 3)) * 3;
}


double convertStrDot(char * num){
    char * vir = strchr(num, ',');
    char * dot = strchr(num, '.');
    
    double num_d;
    if(vir == NULL && dot == NULL){
        char aux[(strlen(num) + 2)];
        aux[strlen(num)] = '.';
        aux[strlen(num) + 1] = '0';
        return 0;
    }else{
        if(vir != NULL && *vir == ','){
            *vir = '.';
        }
        num_d = atof(num);
    }
    return num_d;
}

char prefix(int exp){
    switch(exp){
        case 3:
            return 'k';
        case 6:
            return 'M';
        case 9:
            return 'G';
        case 12:
            return 'T';
        case 15:
            return 'P';
        case 18:
            return 'E';
        case 21:
            return 'Z';
        case 24:
            return 'Y';
        case -3:
            return 'm';
        case -6:
            return 'u';
        case -9:
            return 'n';
        case -12:
            return 'p';
        case -15:
            return 'f';
        case -18:
            return 'a';
        case -21:
            return 'z';
        case -24:
            return 'y';
        default:
            return ';';
    }
}



int main(int argc, char *argv[]){

    clock_t start, end;
    double time, num_d;

    start = clock();

    if(argc < 2){
        printf("Write a number: \n%s <your_string>\n", argv[0]);
        return 1;
    }

    int len = (int)(strlen(argv[1]));
    char num[len];
    strcpy(num, argv[1]);

    num_d = convertStrDot(num);

    printf("Number: %f\n", num_d);

    int exp = to_Eng(num_d);
    printf("Exp: %d\n", exp);
    printf("Eng: %.2f %c\n", num_d/pow(10, exp), prefix(exp));

    end = clock();
    time = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("%f segundos\n", time);

    return 0;
}