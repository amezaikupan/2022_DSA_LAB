#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Examinee.h"

using namespace std;
 
Examinee readExaminee(string line){
    //Examinee to be read to
    Examinee e;

    //To store fields in a line
    string temp = "";

    //To store list of fields in a line (of an Examinee) 
    vector <string> res (15, "0");
 
    int i = 0;
    int cnt = 0;
    while (i < line.length()){
        if(line[i] != ','){
            temp += line[i];
        }
        else{

            if(temp != "") res[cnt] = temp;
            cnt++;
            temp = "";
        }
        i++;
    }

    res[cnt] = temp;


    e.id = res[0];
    e.maths = stof(res[2]);
    e.literature = stof(res[3]);
    e.physics = stof(res[4]);
    e.chemistry = stof(res[5]);
    e.biology = stof(res[6]);
    e.history = stof(res[7]);
    e.geography = stof(res[8]);
    e.civic_education = stof(res[9]);
    e.natural_science = stof(res[10]);
    e.social_science = stof(res[11]);
    e.foreign_language = stof(res[12]);

    res.clear();
    
    return e;
}
 
vector<Examinee> readFile(string fileName){
    //get data from file
    ifstream ifs (fileName);
 
    //temp string file to get examinee data
    string line;
 
    //get and empty header data
    getline(ifs, line);
    line = "";
 
    //Examinee data list
    vector <Examinee> eList;

    Examinee e;
 
 
    while(getline(ifs, line)){
        e = readExaminee(line);
        eList.push_back(e);
    }

    ifs.close();

    return eList;
}
 
void writeScores(vector <Examinee> examinee_list, string out_file_name){
    //file to write to 
    ofstream ofs (out_file_name);

    //To read file into
    string temp = "";

    //Write first line to file
    ofs << "SDB BB KHTN KHXH\n";

    // ofs.close();
    cout << "SDB BB KHTN KHXH" << endl;

    //To calculate Nature Science Score and Social Science Score
    string nsc = "", ssc = "", cps = "";


    for (int i = 0; i < examinee_list.size(); i++){
        nsc = to_string(examinee_list[i].physics 
            + examinee_list[i].chemistry
            + examinee_list[i].biology);

        ssc = to_string(examinee_list[i].history 
            + examinee_list[i].geography
            + examinee_list[i].civic_education);

        cps = to_string(examinee_list[i].maths 
            + examinee_list[i].literature 
            + examinee_list[i].foreign_language);

        temp = examinee_list[i].id 
            + " " + cps + " " + nsc + " " + ssc + "\n";
        
        ofs << temp;
        cout << temp;
    }

    cout << "finish write file" << endl;
    ofs.close();
}

int main() {
	// your code goes here
    vector <Examinee> eList = readFile("data.txt");
    writeScores(eList, "score_data.txt");
	return 0;
}
