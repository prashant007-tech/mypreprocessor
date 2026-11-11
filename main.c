#include<stdio.h>
#include "comment_removal.h"
int main(){
	FILE *src,*des,*fi,*fm;
	src=fopen("input.c","r");
	des=fopen("output.c","w");

	if(src==0){
		printf("file is not present\n");
		return 1;
	}
	file_inclusion(src);
	fi=fopen("expanded.c","r");
	macro_inclusion(fi);
	fm=fopen("macro_extended.c","r");
	remove_comments(fm,des);
	fclose(fi);
	fclose(fm);
	fclose(src);
	fclose(des);

	return 0;
}
