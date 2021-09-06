#include<stdio.h>
#define PI 3.14159

void exerciceA(){
    int r; double p, s;
    printf("donnez le rayon entier d’un cercle:");
    scanf("%d",&r);
    p=2*PI*r;
    s=PI*r*r;
    printf("le cercle de rayon %d ",r);
    printf("a un perimetre de %f et une surface de %f\n",p,s);
}

int main() {
    exerciceA();
    return 0;
}
