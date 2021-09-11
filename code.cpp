#include<iostream>
#include<unistd.h>
#include<bits/stdc++.h>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string mainTags[4] {
    "html", "body", "head", "script" 
};

string extraTags[5] {
   "a", "img", "p", "b", "center"
};

class main_function {
  public: 
	  string mainTag,endTag;
	  stack <string> s;
	  
	  void start_page() {
	    cout<<"<!-- Welcome to the editor. Type Exit to Quit -->"<<endl;
	    sleep(2);
	    system("clear");
	  }

	  int checkTagStatus(string mainTag) {
	 	if(mainTag[0]=='<' && mainTag[mainTag.length()-1]=='>') {
		    return 1;
		}
		return 0;
	  }

	  int checkTagExitStatus(string mainTag) {
		if(mainTag=="Exit" || mainTag=="exit" || mainTag=="EXIT") {
		return 0;
		}
		return 1;
	  }

	  int checkTagType(string mainTag) {
		string str= mainTag.substr(1,mainTag.length()-2);
		for(int i=0;i<3;i++) {
		   if(str==mainTags[i]) {
		       return 1;
		   }
		}
		for(int i=0;i<4;i++) {
		   if(str==extraTags[i]) {
		   	return 2;
		   }
		}
	  }

	  void start_code() {
	     int DoWhileRunner=1, tagStatus=0, tagType=0;
	     do {
	        getline(cin,mainTag);
		DoWhileRunner=checkTagExitStatus(mainTag);
		if(DoWhileRunner==0) {
		  break;
		}
		tagStatus=checkTagStatus(mainTag);
		tagType=checkTagType(mainTag);
		switch(tagType) {
		 	case 1: endTag=mainTag.insert(1,"/");
				s.push(endTag);
				break;

			case 2: endTag=mainTag.insert(1,"/");
				cout<<endTag<<endl;
				break;
		}
		while(!s.empty()) {
		   cout<<s.top()<<endl;
		   s.pop();
		}
	   }while(DoWhileRunner!=0);
	}
};

int main(void) {
  main_function m;
  m.start_page();
  m.start_code();
  return 0;
}


