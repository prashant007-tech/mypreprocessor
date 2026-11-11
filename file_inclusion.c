#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void file_inclusion(FILE *src){
	FILE *fd=fopen("expanded.c","w");
	while(1){
		char arr[100],hl[100],ch;
		int i,j,flag=0;
		if(fgets(hl,100,src)==0)
			break;
		if(strncmp(hl,"#include",8)==0){
			j=8,i=0;
			while(hl[j]==' ')
				j++;
			if(hl[j]=='"')
				j++;
			while(hl[j]){
				if(hl[j]=='"'){
					j++;
					break;
				}
				arr[i++]=hl[j++];
			}
			arr[i]=0;
			FILE *fh=fopen(arr,"r");
			if(fh==NULL){
				flag=1;
				fputs(hl,fd);
				}

			else{
				while((ch=fgetc(fh))!=-1)
					fputc(ch,fd);
				fclose(fh);

			}
		}
		else{
		if(flag!=1)
		fputs(hl,fd);
		}
	}

	fclose(fd);
}
