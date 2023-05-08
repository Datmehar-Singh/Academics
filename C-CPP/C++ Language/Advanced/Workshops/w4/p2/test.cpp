#include<iostream>  
#include<string>

int main(){
    std::string str="    John    ";
    std::string res=str.substr(str.find_first_not_of(' '),str.find_last_not_of(' ')-str.find_first_not_of(' ')+1);

    std::cout<<res<<"||"<<res.length();
        
}