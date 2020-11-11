#include "directoryRunner.h"

#include <filesystem>
#include <set>
#include <string>
#include <vector>

namespace filetools
{
void DirectoryRunner::addFileTypeExclusions(const std::string& fileType)
{
    mFileTypeExclusions.insert(fileType);
}

void DirectoryRunner::addFileTypeInclusions(const std::string& fileType)
{
    mFileTypeInclusions.insert(fileType);
}

void DirectoryRunner::addToFileList(const std::filesystem::directory_entry& currentEntry)
{
    auto currentEntryPath = currentEntry.path();
    const auto entryExt = currentEntry.path().extension();
    if (!mFileTypeInclusions.empty())
    {
        if (mFileTypeInclusions.count(entryExt) > 0)
        {
            mFileList.push_back(currentEntry);
        }
    }
    else if (mFileTypeExclusions.count(entryExt) == 0)
    {
        mFileList.push_back(currentEntry);
    }
}

void DirectoryRunner::run()
{
    std::filesystem::recursive_directory_iterator it;
    for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(mStartingDirectory))
    {
        this->addToFileList(dirEntry);
    }
}

std::vector<std::filesystem::directory_entry> DirectoryRunner::getlist()
{
    return mFileList;
}
}  // namespace filetools
