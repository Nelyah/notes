#pragma

#include <filesystem>
#include <vector>
#include <set>
#include <string>


class DirectoryRunner
{
    private:
        std::vector<std::filesystem::directory_entry> mFileList;
        std::set<std::string> mFileTypeExclusions;
        std::set<std::string> mFileTypeInclusions;

    public:
        DirectoryRunner () {};

        void addFileTypeExclusions(const std::string& exclusion)
        {
            mFileTypeExclusions.insert(exclusion);

            if (mFileTypeInclusions.count(exclusion) > 0)
            {
                mFileTypeInclusions.erase(exclusion);
            }
        }

        void addFileTypeInclusions(const std::string& exclusion)
        {
            mFileTypeInclusions.insert(exclusion);

            if (mFileTypeExclusions.count(exclusion) > 0)
            {
                mFileTypeExclusions.erase(exclusion);
            }
        }

        void addToFileList(const std::filesystem::directory_entry& currentEntry)
        {
            auto currentEntryPath = currentEntry.path();
            auto currentEntryExtension = currentEntryPath.extension();
            if (mFileTypeInclusions.count(currentEntryExtension) > 0 ||
                mFileTypeExclusions.count(currentEntryExtension) == 0)
            {
                mFileList.push_back(currentEntry);
            }
        }

        void run()
        {
            std::filesystem::recursive_directory_iterator it;
            for (const auto& dirEntry : std::filesystem::recursive_directory_iterator("."))
            {
                this->addToFileList(dirEntry);
                throw std::string ("You must " + dirEntry.path().string());
            }
        }

        std::vector<std::filesystem::directory_entry> getlist()
        {
            return mFileList;
        }
};

