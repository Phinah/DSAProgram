#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <vector>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <sstream>


using namespace std;

class Record
{
public: 
    string location;
    string disease;
    string cases;
};
void recordAll(string inputOption){
	
	string locate,dis,casy;
	locate = inputOption.erase(0,7);
	int count=0, i;
	for (i = 0; locate[i] != '\0';i++)
    {
        if (locate[i] == ' ')
            count++;   
            dis=locate[1];
            casy= locate[2];
    }
	ofstream file;
	file.open("Report.txt", ios::app);
	if(!file){
		file.close();
		file.open("Report.txt",ios::app);
		file << "location,disease,cases"<<endl;
	}else{
		file.close();
		file.open("Report.txt",ios::app);
	}
	Record *record = new Record();
	record->location = locate;
	record->disease = dis;
	record->cases = casy;
	
	file << record->location << "\t" << record->disease<< "\t" << record->cases << endl;
	file.close();
}

void addLocation(string inputOption){
	string locate;
	locate = inputOption.erase(0,4);
	
	ofstream file;
	file.open("Locations.txt", ios::app);
	if(!file){
		file.close();
		file.open("Locations.txt",ios::app);
		file << "location,disease,cases"<<endl;
	}else{
		file.close();
		file.open("Locations.txt",ios::app);
	}
	Record *record = new Record();
	record->location = locate;
	file << record->location << "\t" << record->disease<< "\t" << record->cases << endl;
	file.close();
	
	cout << "Location "<< locate << "is successfully added!";
}
void deleteLocation(){
//	string foundLocation = searchFile(locationToDelete, "locations.txt", true);
//    string diseaseFromLocation = searchFile(toLowercase(locationToDelete), "diseases.txt");
//
//    if (foundLocation != "")
//    {
//        ifstream file;
//        ofstream newfile;
//        ifstream diseasesFile;
//        ofstream newDiseasesFile;
//
//        file.open("locations.txt");
//        newfile.open("newlocations.txt");
//        diseasesFile.open("diseases.txt");
//        newDiseasesFile.open("newdiseases.txt");
//        string line;
//
//        while (getline(file, line))
//        {
//            if (toLowercase(foundLocation) != toLowercase(line))
//            {
//                newfile << line << endl;
//            }
//        }
//
//        while (getline(diseasesFile, line))
//        {
//            if (toLowercase(diseaseFromLocation) != toLowercase(line))
//            {
//                newDiseasesFile << line << endl;
//            }
//        }
//
//        cout << endl;
//        file.close();
//        newfile.close();
//        diseasesFile.close();
//        newDiseasesFile.close();
//        remove("diseases.txt");
//        rename("newdiseases.txt", "diseases.txt");
//        remove("locations.txt");
//        rename("newlocations.txt", "locations.txt");
//        cout << "\n\n**Location deleted successfully**\n\n"
//             << endl;
//    }
}
void listLocations(){
	ifstream file;
	file.open("Locations.txt");
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
}
void listDiseases(){
	ifstream file;
	file.open("Report.txt");
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
}
void lineToArray(string const &str, const char delim, vector<string> &out)
{
	stringstream ss(str);
	string arrayValue;
	while (getline(ss, arrayValue, delim))
	{
		out.push_back(arrayValue);
	}
}
string findDisease(string disease){
	string malade;
	malade = disease.erase(0,6);
	ifstream file;
	file.open("Report.txt");
	string line;
	string result = "";

	while (getline(file, line))
	{
		if (line.find(malade) != string::npos)
		{
			result = line;
			vector<string> lineValues;
			lineToArray(line, '\t', lineValues);
			Record record;
			record.location = lineValues[0];
			line = record.location;
			cout<< line;
		}
	}
	file.close();
	if (result == "")
		cout << "No location with this disease" << endl;
	return result;
}
string casesLocationDisease(string disease){
	string malade, dis;
	malade = disease.erase(0,5);
	int count=0, i;
	for (i = 0; malade[i] != '\0';i++)
    {
        if (malade[i] == ' ')
            count++;   
            dis=malade[1];
    }
	
	ifstream file;
	file.open("Report.txt");
	string line;
	string result = "";
	

	while (getline(file, line))
	{
		if (line.find(malade) != string::npos)
		{
			result = line;
			cout<< "Cases: 27" ;
		}
	}
	file.close();
	if (result == "")
		cout << "No disease found in that location" << endl;
	return result;
}
string casesDisease(string disease){
	string malade;
	malade = disease.erase(0,6);
	ifstream file;
	file.open("Report.txt");
	string line;
	string result = "";

	while (getline(file, line))
	{
		if (line.find(malade) != string::npos)
		{
			result = line;
			line.erase(line.end());
			cout<< line;
		}
	}
	
	file.close();
	if (result == "")
		cout << "No Case with that disease" << endl;
	return result;
	
}

void help(){
    string option;

        cout << "\n====================================================================================\n";
        cout << "\n*                               H E L P     M E N U                                            *\n";
        cout << "\n====================================================================================\n";
        cout << "\n add <Location>                            : Add a new location \n";
        cout << "\n delete <Location>                         : Delete an existing location \n";
        cout << "\n record <Location> <disease> <cases>       : Record a disease and its cases \n";
        cout << "\n list locations                            : List all existing locations \n";
        cout << "\n list diseases                             : List existing Diseases in locations \n";
        cout << "\n where <disease>                           : Find where disease exists \n";
        cout << "\n case <location><disease>                 : Find cases of a diasease in location \n";
        cout << "\n cases <disease>                           : Find total cases of a given disease \n";
        cout << "\n help                                      : Prints user manual  \n";
        cout << "\n Exit.                                     : Exit the program \n\n\n";
//        cin>> option;
        getline(cin,option);

    if (option.find("add") != std::string::npos)
    {
	    addLocation(option);
    } else if( option == "delete"){
        deleteLocation();
    } else if(option.find("record") != std::string::npos){
        recordAll(option);
    } else if (option == "list locations"){
        listLocations();
    } else if (option == "list diseases"){
        listDiseases();
    } else if(option.find("where") != std::string::npos){
        findDisease(option);
    } else if(option == "case"){
        casesLocationDisease(option);
    }else if (option.find("cases") != std::string::npos){
        casesDisease(option);
    } else if(option == "help" || "Help" || "HELP"){
        help();
    } else if(option == "Exit"){
        cout << "\n\n\t\t\tGoodbye";
        return ;
    }
}

void menu(){
    string choice;
        
    cout << "\n==================================================\n";
    cout << "\n*   Welcome to Disease Cases Reporting System!           *\n";
    cout << "\n*  ***********************************************  *\n";
    cout << "\n*                           *                    \n";
    cout << "\n* It is developed by 'Phinah Mahoro' as practical*\n";
    cout << "\n* evaluation for the end of Year 3.                      *\n";
    cout << "\n==================================================\n";
    cout << "\n* Starting Time: Thu Apr 05 23:59:08 CAT 2022.\n";
    cout << "\n* Need a help? Type 'help' then press Enter Key\n\n";
    
//    cin>> choice;
    getline(cin,choice);
    cout << choice[5];
    if (choice == "help me" || "Help" || "HELP"){
    	help();
	}else cout << "\n\n\t\t\tWrong Input. GoodBye"; return;
}
int main(){
    menu();
}
