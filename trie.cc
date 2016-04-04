#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#define ALPHABETS 26

struct node{

     bool isEnd;
     struct node *child[ALPHABETS];
}*head;


void Init(){

     head = new node();
     head->isEnd = false;
}

void Insert(std::string word){
     if(word.empty())
          return;
     node *current = head;
     for(int i =0; i < word.length(); i++){
          if(current->child[word[i] - 'a'] == NULL)
               current->child[word[i]-'a'] = new node();

          current = current->child[word[i]-'a'];
     }
     current->isEnd = true;           
}

bool Search(std::string word){

     node *current = head;
     for(int i=0; i < word.length(); i++){
          if(current->child[word[i]-'a'] == NULL)
               return false;
          else
               current = current->child[word[i]-'a'];
     }
     return current->isEnd;
}

void PrintAll(node *tmp,std::vector<char> word){
     if(tmp == NULL)
          return; 
     if(tmp->isEnd){
          std::vector<char>::iterator it = word.begin();
          while(it != word.end()){
               std::cout << *it;
               ++it;
          }
          std::cout << "\n";         
     }
     for(int i=0; i<26; i++){
          if(tmp->child[i] != NULL){         
              word.push_back((char)i+'a');
              PrintAll(tmp->child[i],word);
              word.pop_back();
          }
     }
}

void AutoComplete(std::string prefix){ 

     std::vector<char> word;
     std::cout << __FUNCTION__ << " called" << "with prefix: " << prefix << "\n";
     if(prefix.length() == 0){
          std::cout << "please enter valid prefix " << "\n";  
          return;
     }   
     node *current = head;
     for(int i=0; i < prefix.length(); i++){
          if(current->child[prefix[i]-'a'] == NULL){
               std::cout << "prefix does not exist in word:" << "\n";
               return;
          }
          word.push_back(prefix[i]);
          current = current->child[prefix[i]-'a'];
     }
     std::cout << "All the words with give prefix are as follows:" << "\n";    
     PrintAll(current,word);
}


int main(){

     Init();
     std::ifstream fin("./wordlist.txt");
     if(!fin){
          std::cout << "could not open a file: " << "\n";
          return -1;
     }
     std::string word;
     while(fin >> word){
          Insert(word);
     }
     fin.close();
     AutoComplete("youthful");
     return 0;
}
