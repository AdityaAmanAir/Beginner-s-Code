// #include<iostream>
#include<stdio.h>

int main(){

    FILE *f= fopen("output.ppm","wb");
    int w= 1920;
    int h = 1080;

    fprintf(f, "P6\n");
    fprintf(f,"%d %d\n", w,h);
    fprintf(f, "255\n");

    for(int y =0 ; y<h;++y){
        for(int x=0;x<w;x++){
            if((x/60+y/60)%2==0){
            fputc(0xFF,f);
            fputc(0xFF,f);
            fputc(0xFF,f);
        }else{
            fputc(0x69,f);
            fputc(0x92,f);
            fputc(0x3E,f);
        }
        }
    }
fclose(f);
printf("OUTPUT");
return 0;

}