#include "PreferencesStorageMedium.h"

bool PreferencesStorageMedium::openFile(const String &fileName, const FileMode fileMode)
{
    return preferences.begin(fileName.c_str(), fileMode == FileMode::READ);
}

void PreferencesStorageMedium::closeFile()
{
    preferences.end();
}

bool PreferencesStorageMedium::existsImpl(const String &fileName)
{
    // If we can open the namespace in readonly mode it means it exists
    bool opened = openFile(fileName, FileMode::READ);
    closeFile();
    return opened;
}

bool PreferencesStorageMedium::isCompleteImpl(const String &fileName, const std::vector<ParameterInfo> &parameters)
{
    if (!openFile(fileName, FileMode::READ))
    {
        closeFile();
        return false;
    }
    bool result = true;
    for (auto parameter : parameters)
    {
        if (!preferences.isKey(parameter.name.c_str()))
        {
            result = false;
            break;
        }
    }
    closeFile();
    return result;
}

bool PreferencesStorageMedium::deleteImpl(const String &fileName)
{
    if (!openFile(fileName, FileMode::WRITE))
    {
        closeFile();
        return false;
    }

    bool result = preferences.clear();
    closeFile();
    return result;
}
