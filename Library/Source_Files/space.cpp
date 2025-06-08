#include <iostream>
#include <string>
#include <filesystem>  //std::filesystem::path, std::filesystem::recursive_directory_iterator
#include <algorithm>

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
         const std::string currentFileName{ dirEntry.path().filename().string() };
         // following function is meant for the logic to provide the new file names in the directory
         // in your case it cout have been simply: "August - " + std::to_string(number++) + "extension"
         const std::string newFileName{ changeFileName(currentFileName, ".*", 0) };
         try
         {
            std::filesystem::rename(myPath / currentFileName, myPath / newFileName);
         }
         catch (std::filesystem::filesystem_error const& error)  // catch the errors(if any)!
         {
            std::cout << error.code() << "\n" << error.what() << "\n";
         }
      }

   }
}
