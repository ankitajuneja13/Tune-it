#include <iostream>
#include<windows.h>
#include<mmsystem.h>
#include <cstdlib>


#include <bits/stdc++.h>
using namespace std;
const int alphabets  =26;
vector<string> lyrics;
struct Node{

    struct Node* children [alphabets]={};
    int occurences;
    bool flag;

};
void insert_trie(struct Node * trietree,char * word){
struct Node * current=trietree;// current
while(*word!='\0'){

    if(current->children[*word-'a']==NULL){
        current->children[*word-'a']= (struct Node *) calloc(1, sizeof(struct Node));
    }
    current=current->children[*word-'a'];
  ++word;
}
current->flag=true;
}
struct Node* search_trie(struct Node* current,char* word){

while(*word!='\0'){
if(current->children[*word-'a']!=NULL){
    current=current->children[*word-'a'];
    ++word;
}
else
    break;
}
if(*word=='\0'){
    return current;
}
else
    return NULL;


}
void autocomplete(struct Node* trietree, vector <char> word,char* prefix){
    bool nochild=true;
if(trietree->flag==true && word.size()!=0){
    cout<<prefix;
    string s=prefix;
    for(int i=0;i<word.size();i++){
        cout<<word[i];
        s=s+word[i];
    }
    lyrics.push_back(s);
    cout<<endl;

}
for(int i=0;i<alphabets;i++){
if(trietree->children[i]!=NULL){
       
    word.push_back(i+'a');
    autocomplete(trietree->children[i],word,prefix);
    word.pop_back();
}
}
word.pop_back();
}


string main1()
{

 struct Node * trietree = new Node();
 char filename[100];
	ifstream bad;
	cin.getline(filename,100);
	bad.open(filename);
if(!bad.is_open()){
	exit(EXIT_FAILURE);
}

char word[50];

bad>>word;


while(bad.good()){
	cout<<"word insert"<<word<<" "<<endl;
	
	 insert_trie(trietree,word);
	bad>>word;

}


vector <char > ch;
cout<<"enter  ur word to search"<<endl;
cin>>word;
Node* temp=search_trie(trietree,word);


if(temp==NULL)
   {
   		
	 cout<<"NO word with this prefix in dictionary "<<endl;
     exit(1);

   }   
else
   {
   	   autocomplete(temp,ch,word);
   }



  
cout<<endl;
int n;
cout<<"Select your buzz";
cin>>n;
string m=lyrics[n-1];

string s2=".wav";
 
 for(int i=0;i<s2.size();i++)
 {
 	m=m+s2[i];
 }

return m;

}






