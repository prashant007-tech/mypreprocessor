#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct macro{
	char name[100];
	char body[100];
	char parameter[5];
};
int k=0;
void macro_inclusion(FILE *src){	
	FILE *des=fopen("macro_extended.c","w");
	struct macro m[100];
	while(1){
		char line[100],ch;
		int i,j,flag=0;
		if(fgets(line,100,src)==0)
			break;
		if(strncmp(line,"#define",7)==0){
			j=7,i=0;
			while(line[j]==' ')
				j++;
			while(line[j]){
				if(line[j]==' ' || line[j]=='('){
					break;
				}
				m[k].name[i++]=line[j++];
			}
			m[k].name[i]=0;

			if(line[j]=='('){
				j++;
				i=0;
				while(line[j]!=')')
					m[k].parameter[i++]=line[j++];
			}
			m[k].parameter[i]=0;
			j++;

			i=0;
			while(line[j]==' ')
				j++;
			while(line[j]){
				if(line[j]=='\n')
					break;
				m[k].body[i++]=line[j++];
			}
			m[k].body[i]=0;
			k++;
		}
		else{
			char c[20],par[20];
			j=0;
			int flag;
			while(line[j]!=0){
				i=0;
				while(isalnum(line[j]) || line[j]=='_')
					c[i++]=line[j++];
				c[i]=0;
				if(line[j]=='(' && line[j] != 0){
					i=0;
					j++;
					while(line[j]!=')' && line[j]!=0)
						par[i++]=line[j++];
					par[i]=0;
					j++;
				}

				for(i=0,flag=0;i<k;i++){
					if(strcmp(c,m[i].name)==0){
						flag=1;
						int x=0,y=0;
						char word[100];
						while(m[i].body[x] != 0){
							if(isalnum((unsigned char)m[i].body[x]) || m[i].body[x]=='_'){
								y=0;
								while(m[i].body[x] !=0 && isalnum((unsigned char)m[i].body[x]) || m[i].body[x]=='_'){
									word[y++]=m[i].body[x++];
								}
								word[y]=0;
								if(strcmp(word,m[i].parameter)==0)
									fputs(par,des);
									else
										fputs(word,des);

							}
							else{
								fputc(m[i].body[x],des);
								x++;
							}
						}
					}
				}
				if(flag!=1)
					fputs(c,des);
				if(line[j] !=0)
				fputc(line[j++],des);
			}

		}
	}
	fclose(des);
}
