#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;
void opener(fstream &file, char *fn,ios_base::openmode mode){
	file.open(fn,mode);
	if(!file){
		cout<<"unable to open the file \n ";
		exit(1);
	}else{
		cout << "Opened";
	}
}
void match(fstream &file1 ,fstream &file2 ,fstream &ofile){
	char s1[25] ,s2[25];
	file1.getline(s1,25,'\n');
	file2.getline(s2,25,'\n');
	while(!file1.eof() && !file2.eof()){
		if(strcmp(s1,s2)== 0){
			ofile<<s1<<"\n";
			cout<<s1<<endl;
			file1.getline(s1,25,'\n');
			file2.getline(s2,25,'\n');
		}
		else if(strcmp(s1,s2)<0)
			file1.getline(s1,25,'\n');
		else
			file2.getline(s2,25,'\n');
	}
}
int main(){
	fstream list1,list2,outlist;
	opener(list1,"name1.txt",ios::in);
	opener(list2,"name2.txt",ios::in);
	opener(outlist,"names.txt",ios::out);
	match(list1,list2,outlist);
	cout<<"name1.txt & name2.txt matching names in names.txt\n";
	list1.close();
	list2.close();
	outlist.close();
	return 0;
}

