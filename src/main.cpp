#include <iostream>
#include <filesystem>
#include <vector>
#include <set>

#include "directoryRunner.h"

int main(int argc, char *argv[])
{
    try
    {
    std::filesystem::recursive_directory_iterator it;
    DirectoryRunner dirr = DirectoryRunner();

    dirr.run();

    for (auto& el : dirr.getlist())
    {
        std::cout << el << std::endl;
    }
    }
    catch (const std::string& error) 
    {                                
      std::cerr << error << std::endl;    
      return -1;
    }                                

    return 0;

}
