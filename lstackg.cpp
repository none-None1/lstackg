#include<cstdio>
#include<stack>
#include<fstream>
#include<cstring>
std::stack<char> s;
std::stack<int> p;
char str[1000000];
int num,mat[1000000],ptr;
int main(int argc,char *argv[]){
	if(argc!=2){
		fprintf(stderr,"Usage: lstackg <filename>");
		return 1;
	}
	std::ifstream f(argv[1]);
	if(!f){
		fprintf(stderr,"File does not exist");
		return -1;
	}
	char c;
	while(f.get(c)){
		str[num++]=c;
	}
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='<'){
			p.push(i);
		}
		if(str[i]=='>'){
			if(p.empty()){
				fprintf(stderr,"Unmatched >");
				return 2;
			}
			int t=p.top();
			p.pop();
			mat[t]=i;
			mat[i]=t;
		}
	}
	if(!p.empty()){
		fprintf(stderr,"Unmatched <");
		return 3;
	}
	s.push(0);
	for(;ptr<strlen(str);ptr++){
		switch(str[ptr]){
			case '<':{
				if(!s.top()) ptr=mat[ptr];
				break;
			}
			case 's':{
				s.push(0);
				break;
			}
			case 't':{
				s.push(getchar());
				break;
			}
			case 'a':{
				int t=s.top()+1;
				s.pop();
				s.push(t);
				break;
			}
			case 'c':{
				if(s.size()<2) break;
				putchar(s.top());
				s.pop();
				break;
			}
			case 'k':{
				if(s.size()<2) break;
				s.pop();
				break;
			}
			case '>':{
				if(s.top()) ptr=mat[ptr];
				break;
			}
		}
	}
	return 0;
}

