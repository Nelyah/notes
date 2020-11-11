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

    if (mFileTypeInclusions.count(fileType) > 0)
    {
        mFileTypeInclusions.erase(fileType);
    }
}

void DirectoryRunner::addFileTypeInclusions(const std::string& fileType)
{
    mFileTypeInclusions.insert(fileType);

    if (mFileTypeExclusions.count(fileType) > 0)
    {
        mFileTypeExclusions.erase(fileType);
    }
}

void DirectoryRunner::addToFileList(const std::filesystem::directory_entry& currentEntry)
{
    auto currentEntryPath = currentEntry.path();
    auto currentEntryExtension = currentEntryPath.extension();
    if (mFileTypeInclusions.count(currentEntryExtension) > 0 ||
        mFileTypeExclusions.count(currentEntryExtension) == 0)
    {
        mFileList.push_back(currentEntry);
    }
}

void DirectoryRunner::run()
{
    std::filesystem::recursive_directory_iterator it;
    for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(mStartingDirectory))
    {
        const auto entryExt = dirEntry.path().extension();
        if ((mFileTypeInclusions.empty() && mFileTypeExclusions.count(entryExt) == 0) ||
            (mFileTypeInclusions.count(entryExt) > 0))
        {
            this->addToFileList(dirEntry);
        }
    }
}

std::vector<std::filesystem::directory_entry> DirectoryRunner::getlist()
{
    return mFileList;
}
}  // namespace filetools
