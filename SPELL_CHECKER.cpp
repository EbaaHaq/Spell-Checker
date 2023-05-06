#include <iostream>
#include <fstream>
using namespace std;

const int N = 200; 
long int key;
long int k;

// Node struct for linked list
struct Node {
    string data;
    Node* next;
    Node(string d){
	data=d; 
	next=NULL; 
	}
};


// Function to add a node to the beginning of the linked list
void addNode(Node* &head, string data) { 
     
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}


// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}


// Function to find key
int findkey(int element){
		key = element%N;
		return key;
}


// hash function
int hash(string s) {
    int hash_value = 0;
    int a = s.length();
    for (int i = 0;i<a;i++) {
        hash_value = (hash_value+int(s[i]));
    }
    hash_value = hash_value/2;
    return hash_value;
}


// searching element
bool search(Node* &head,string element){
    while(head!=NULL){
    	if(head->data==element){
    		cout<<element<<" exists."<<endl;
    		return true;
		}
		head = head->next;
	}
	cout<<element<<" does not exist."<<endl;
	return false;
}


//to convert lowercase
string LowerCase(string s){
	string Lstring;
	for(int i=0;i<s.length();i++){
		char ch = tolower(s[i]);
		Lstring = Lstring + ch;
	    }
	cout<<"Word \""<<s<<"\" in lower case is: "<<Lstring<<endl;
	return Lstring;
}

string conversion(string s){
	string Cstring;
	int l = s.length();
	if (s.length() > 2 && s.substr(s.length() - 3) == "ing") {
        s = s.substr(0, s.length() - 3);
	}
	else if (s.length() > 3 && s.substr(s.length()-3) == "ies") {
        s = s.substr(0, s.length()-3) + "y";
	}
	else if (s.length() > 1 && s[s.length()-1] == 's') {
        s = s.substr(0, s.length()-1);
    }
    else if (s.length() > 1 && s.substr(s.length()-2) == "es") {
        s = s.substr(0, s.length()-2); 
	}
	else if (s.length() > 1 && s.substr(s.length()-2) == "ly") {
        s = s.substr(0, s.length()-2); 
	}
	else if (s.length() > 1 && s.substr(s.length()-2) == "ed") {
        s = s.substr(0, s.length()-2) + "e"; 
	}
//		cout<<s;
		return s;
}





int main() {
   // initialize array of linked lists to NULL
   Node* arr[N] = {NULL};   
   float l, load; 
   char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	//Inserting elements using hash function
   cout<<"Inserting elements using hash function.";
   fstream newfile;
   newfile.open("words.txt",ios::in); 
   if (newfile.is_open()){ 
        string s;
        string Lstring = LowerCase(s);
      while(getline(newfile, Lstring)){ 
          k = hash(Lstring);
          key = findkey(k);
          addNode(arr[key], Lstring);
		}
    }
    newfile.close();
     // Print the linked lists
    cout<<endl<<"After nserting elements using hash2 function"<<endl;
    for (int i = 0; i < N; i++) {
      cout << "Linked list at index " << i << ": ";
      printList(arr[i]);
	}
	
	// loadfactor
	l = 0;
	for (int i = 0; i < N; i++) {
			if(arr[i]!=NULL){
        	l++;
			}
	}
	cout<<l<<" elements were inserted without any collisions."<<endl;
    load = (l/N)*100;
	cout<<"loadfactor is: "<<load;  //loadfactor is: 40%
    
    
 /* 70 elements were inserted without any collisions.
loadfactor is: 14
apple does not exist.
a does not exist. */


//    searching
    int num;
    cout<<"How many words you want to search: ";
    cin>>num;
    if((num>=1)){
        for(int i = 1;i<=num;i++){
            string current_string;
            cout<<"Enter "<<num<<" string: ";
            cin>>current_string;
            string Lstring = LowerCase(current_string);
            Lstring = conversion(Lstring);
            k = hash(Lstring);
            key = findkey(k);
            bool exist = search(arr[key],Lstring);
            if(exist == true){
               cout << "Your Word is in the table." << endl;
               cout << "The Spelling for the word you entered is correct." << endl;
               cout << endl;
	        }
			else{
			    cout<<"Your word is either not in the table or spelled incorrectly. " <<endl;
			    cout<<"Suggestions are: "<<endl;
			        int l = Lstring.length();
			        newfile.open("words.txt",ios::in); 
                    if (newfile.is_open()){ 
                        string s;
                        while(getline(newfile, s)){ 
                            if(s.length()==l){
                            	int d = 0;
                             	for (int i = 0;i<s.length();i++){
                        	    	if(s[i] == Lstring[i]){
                        		    	d++;
								    }
								    if(d==(l-1)){
								       cout<<s<<endl;
									}
							    }
						    }
						}
				    }
                newfile.close();
			}       
		}
	}else{
		cout<<"Invalid no";
	}
    return 0;
}

