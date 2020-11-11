#include "directoryRunner.h"

#include <filesystem>
#include <iostream>
#include <set>
#include <vector>

int main(int argc, char* argv[])
{
    try
    {
        std::filesystem::recursive_directory_iterator it;
        filetools::DirectoryRunner dirr = filetools::DirectoryRunner("src");

        dirr.addFileTypeInclusions(".cpp");
        dirr.addFileTypeInclusions(".h");
        dirr.addFileTypeExclusions(".cpp");
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
