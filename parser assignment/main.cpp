/* 
 * File:   main.cpp
 * Author: Prashant Singh
 *
 * Created on 17 July, 2014, 10:40 AM
 
 this file has following classes in it
 	Identify_language
 	PRINT
 	PHP
 	JAVA
 	RUBY
 	BusinessLogic:
 		this is the invoking class
 
 
 
 */

#include <iostream>;
#include <fstream>;
#include <string>;
#include <stack>;
using namespace std;

class Identify_language{
            
public:
    
    /*
     this function tells what type of language the file has
     */
    string typeOfFile(string filename){
        
        string token;
        ifstream infile;
        infile.open(filename.c_str());
        string t="unknown";
        
        infile >> token;
        
        if(token=="<?php"){
            t= "php";
            infile.close();
            return t;
	}
	
	else{
            ifstream infile;
            infile.open(filename.c_str());
            while(getline(infile,token)){
                if(token.find("end")!=std::string::npos){
                    infile.close();
                    t= "ruby";
                    infile.close();
                    return t;
	        }
            }
            if(t=="unknown"){
                t= "java";
                return t;
            }
        }
    }
};

/*
 this class does only the printing purpose
 */
class PRINT{
public:
    static void printClass(string className){
        cout<<"class --- "+className<<"\n";
    }
    static void printFunction(string functionName){
        cout<<"function --- "+functionName<<"\n";
    }
    static void printVariable(string variableName){
        cout<<"variable --- "+variableName<<"\n";
    }
};


/*
 parses php files
 */
class PHP{
    
public:
    ifstream infile;
    string token;
    string accesstype;
    
    void SCAN(string filename){
        
        
        infile.open(filename.c_str());
        
        while(infile >> token){
            
            if(token.find("//")!=std::string::npos || token.find("#")!=std::string::npos){
                getline(infile,token);
                continue;
            }
            
            if(token.find("/*")!=std::string::npos){
                while(token.find("*/")==std::string::npos)
                    infile>>token;
                continue;
            }
            
            if(token=="var" ){
                infile >> token;
                PRINT::printVariable(token);
            }
            
            if(token=="class")
                    parseClass();
            
            if(token=="function"){
                parseFunction();
                cout<<"access type ---"<<"default"<<endl;
            }
            
            if(token=="public"){
                Express();
            }
            
            if(token=="private"){
                Express();
            }
            
            if(token=="protected"){
                Express();
            }
        }
    }
    
    
    void Express(){
        accesstype=token;
        infile >> token;
        
        if(token=="class"){
            parseClass();
            cout<<"access type ---"<<accesstype<<endl;
        }
        
        else{
            if(token=="function"){
                parseFunction();
                cout<<"access type ---"<<accesstype<<endl;
            }
            
            if(token.find("$")==0 ){
                PRINT::printVariable(token);
                infile >> token;       	                
            }
        }
    }
    
    void parseClass(){
        infile >> token;
        if(token.find("{")!=string::npos){
            token=token.substr(0,token.find("{"));
        }
        
        PRINT::printClass(token);
        infile >> token;
    }
    
    void parseFunction(){
        infile>>token;
        PRINT::printFunction(token.substr(0,token.find("(")));
    }
    
};

/*
 parses java file
 */
class JAVA{
    
public:
    
    ifstream infile;
    string token;
    string accesstype,returntype;
    
    
    void SCAN(string filename){
        
        infile.open(filename.c_str());
        
        while(infile >> token){
            
            if(token.find("//")!=std::string::npos){
                getline(infile,token);
                continue;
            }
            
            if(token.find("/*")!=std::string::npos){
                while(token.find("*/")==std::string::npos)
                    infile>>token;
                continue;
            }
                        
            if(token=="class"){
                parseClass();
                cout<<"access type ---"<<accesstype<<endl;
            }
            
            if(token=="function"){
                parseFunction();
                cout<<"access type ---"<<accesstype<<endl;
            }
            
            if(token=="public"){
                Express();
            }
            
            if(token=="private"){
                Express();
            }
            
            if(token=="protected"){
                Express();
            }
        }
    }
    
    void Express(){
        
        accesstype=token;
        infile >> token;
        
        if(token=="class"){
            parseClass();
        }
        
        else{
            returntype=token;
            infile >> token; 
            
            
            if(token.find(";")!=string::npos){
                PRINT::printVariable(token);
                cout<<" access type--- "<<accesstype<<endl;
            }
            
            else{
                function_or_variable();
            }
        }
    }
    
    void function_or_variable(){
        string next;
        infile>>next;
        
        if(token.find("(")!=string::npos){
            string function_name=token;
            int t=token.find("(");
            
            function_name=token.substr(0,t);
            PRINT::printFunction(function_name);
            cout<< "access type--- "<<accesstype<<endl;
        }
        
        else {
            if(next.find("(")!=std::string::npos){
                PRINT::printFunction(token);
                cout<< "access type--- "<<accesstype<<endl;
            }
            else{
                PRINT::printVariable(next);
                cout<< "access type--- "<<accesstype<<endl;
            }
        }
        
    }
    
    
    void parseClass(){
        infile >> token;
        if(token.find("{")!=string::npos){
            token=token.substr(0,token.find("{"));
        }
        
        PRINT::printClass(token);
        infile >> token;
    }
    
    void parseFunction(){
        infile>>token;
        PRINT::printFunction(token.substr(0,token.find("(")));
    }
    
};


/*
 parses ruby file
 */

class RUBY{
    
public:
    ifstream infile;
    string token;
    
    void SCAN(string filename){
        
        infile.open(filename.c_str());
        
         while(infile >> token){
             
             if(token.find("#")!=std::string::npos){
                 getline(infile,token);
                 continue;
             }
             
             if(token=="class"){
                 infile >> token;
                 PRINT::printClass(token);
             }
             
             if(token=="def"){
                 infile >> token;
                 parseFunction();
             }
             
             if(token=="public"){
                 parseFunctionWithAcceccSpecifier();
             }
             
             if(token=="protected"){
                 parseFunctionWithAcceccSpecifier();
             }
             
             if(token=="private"){
                 parseFunctionWithAcceccSpecifier();
             }
             
             
             if(token.find("@")!=std::string::npos){
                 PRINT::printVariable(token);
             }
         }
    }
    
    void parseFunctionWithAcceccSpecifier(){
        infile>> token;
        
        if(token=="def"){
            parseFunction();
        }
    }
    
    void parseFunction(){
        
        if(token.find("(")!=string::npos){
            token=token.substr(0,token.find("("));
        }
        
        PRINT::printFunction(token);
    }
};


class BusinessLogic{
    
public:
    void check_file(string type_of_file, string filename){
        
        if(type_of_file=="ruby"){
            cout<<"ruby file\n";
            RUBY rb;
            rb.SCAN(filename);
        }
        
        if(type_of_file=="java"){
            cout<<"java file\n";
            JAVA java;
            java.SCAN(filename);
        }
        
        if(type_of_file=="php"){
            cout<<"php file\n";
            PHP php;
            php.SCAN(filename);
        }
    }
    
};


int main(int argc, char** argv) {

    string file_name;
    cout<<"enter file name\n";
    cin>>file_name;
    
    Identify_language the_file;
    
    string lang_of_file=the_file.typeOfFile(file_name);
    
    BusinessLogic parse;
    
    parse.check_file(lang_of_file,file_name);
    
    return 0;
}
