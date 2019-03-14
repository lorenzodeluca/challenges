#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
using namespace std;


using namespace std;

void readFile(const char* filename, vector<string>& lines)
{
    lines.clear();
    ifstream file(filename);
    string s;
    while (getline(file, s))
        lines.push_back(s);
}

void writeFile(const char* filename,string line){
    ofstream myfile;
    myfile.open (filename,ios::app);
    myfile << line;
    myfile.close();
}
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
void cleanFileContent(const char* filename){
    ofstream file(filename); //cancella contenuto file
    file << "";
    file.close();
}

int main()
{
    vector<string> v;
    readFile("input.txt",v);
    for(int i=0;i<v.size();i++){
        //cout<<v[i]<<endl;
    }
    cleanFileContent("output.txt");
    //elaborazione file
    int sum,num=0;
    for(int i=0;i<v.size()-1;i++){
            while(split(v[i]," ").size()<2)i++;
            sum=0;
            vector<string> toSum=split(v[i]," ");
            for(int k=0;k<toSum.size();k++){
                if(stoi(toSum[k])>0)sum+=stoi(toSum[k]);
            }
            num++;
            writeFile("output.txt","Case #"+to_string(num)+": "+to_string(sum)+"\n");
    }
    return 0;
}
