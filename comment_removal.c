#include<stdio.h>

void remove_comments(FILE *src,FILE *des){
	char ch,ch2,prev;
	while((ch=getc(src))!=-1){
		if(ch=='/'){
			ch2=fgetc(src);
			if(ch2=='/'){
				while((ch=fgetc(src))!='\n'){
					if(ch==-1)
						break;
				}
				if(ch!=EOF)
					fputc(ch,des);
			}
			else if(ch2=='*'){
				while((ch=fgetc(src))!=EOF){
					if(ch=='\n')
						fputc(ch,des);
					if(prev=='*' && ch=='/')
						break;
					prev=ch;
				}
			}
			else{
				fputc(ch,des);
				fputc(ch2,des);
			}
		}
		else
			fputc(ch,des);
	}

}
