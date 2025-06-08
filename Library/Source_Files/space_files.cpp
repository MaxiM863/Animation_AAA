#include <iostream>
#include <string>
#include <filesystem>  //std::filesystem::path, std::filesystem::recursive_directory_iterator
#include <algorithm>
#include <fstream>

using namespace std;

std::string changeFileName(const std::string& currentFileName, const std::string& extension, int number)
{
   std::cout << "Current file name: " << currentFileName << "\n";

   // ....other logics regarding current filename
   
   std::string str = "";

   for(int i = 0; i < currentFileName.length(); i++) {
   
   	if(currentFileName[i] == ' ') str += '_';
   	else str += currentFileName[i];
   }
   
   const std::string newFileName{ str };    
   std::cout << "File name after renaming: " << newFileName << "\n";
   return newFileName; // new file name
}

int main()
{
   const std::filesystem::path myPath = ".";
   
   // iterate through all the files in the directory
   for (const auto& dirEntry : std::filesystem::directory_iterator(myPath))
   {
      // if the file is meant for changing name!
      if (std::filesystem::is_regular_file(dirEntry))
      {
         std::string ffile = "";
         
         ifstream in(dirEntry.path().filename().string());
         
         std::string line;
	while (std::getline(in, line))
	{
	   if(line.length() > 3 && line.substr(0, 4) == "#inc") {
	   
	   	std::cout << "F";
	      bool start = false;
	      
	      for(int i = 0; i < line.length(); i++) {
	      
	         if(line[i] == '"') start = true;
	         
	         if(start) {
	         
	            if(line[i] == ' ') ffile += '_';
	            else ffile += line[i];
	         }
	         else ffile += line[i];	  
	      }
	      
	      ffile += '\n';
	   }
	   else ffile += line + '\n';
	}
	
	in.close();
	
	ofstream out(dirEntry.path().filename().string());
	out << ffile;
	out.close();
      }

   }
}
