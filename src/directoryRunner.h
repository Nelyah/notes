#pragma

#include <filesystem>
#include <set>
#include <string>
#include <vector>

namespace filetools
{
using namespace std::filesystem;

class DirectoryRunner
{
  private:
    std::vector<directory_entry> mFileList;
    std::set<std::string> mFileTypeExclusions;
    std::set<std::string> mFileTypeInclusions;
    directory_entry mStartingDirectory;

  public:
    DirectoryRunner(){};
    DirectoryRunner(const path& startingDirectory) :
        mStartingDirectory(directory_entry(startingDirectory))
    {
        if (!mStartingDirectory.is_directory())
        {
            throw std::string(
                "Error: Specified starting point is not a directory!");
        }
    }

    void addFileTypeExclusions(const std::string& fileType);
    void addFileTypeInclusions(const std::string& fileType);
    void addToFileList(const directory_entry& currentEntry);
    void run();
    std::vector<directory_entry> getlist();
};
}  // namespace filetools
