#ifndef __H_PREFERENCES_STORAGE_MEDIUM__
#define __H_PREFERENCES_STORAGE_MEDIUM__
#include <config-handler-core.h>
#include <Preferences.h>

class PreferencesStorageMedium : public StorageMedium
{
public:
    PreferencesStorageMedium()
        : preferences() {}

protected:
    bool openFile(const String &fileName, const FileMode fileMode) override;

    void closeFile() override;

    bool existsImpl(const String &fileName) override;

    bool isCompleteImpl(const String &fileName, const std::vector<ParameterInfo> &parameters) override;

    bool deleteImpl(const String &fileName) override;

    int8_t readChar(const String &key, const int8_t defaultValue) override
    {
        return preferences.getChar(key.c_str(), defaultValue);
    }
    uint8_t readUChar(const String &key, const uint8_t defaultValue) override
    {
        return preferences.getUChar(key.c_str(), defaultValue);
    }
    int16_t readShort(const String &key, const int16_t defaultValue) override
    {
        return preferences.getShort(key.c_str(), defaultValue);
    }
    uint16_t readUShort(const String &key, const uint16_t defaultValue) override
    {
        return preferences.getUShort(key.c_str(), defaultValue);
    }
    int32_t readInt(const String &key, const int32_t defaultValue) override
    {
        return preferences.getInt(key.c_str(), defaultValue);
    }
    uint32_t readUInt(const String &key, const uint32_t defaultValue) override
    {
        return preferences.getUInt(key.c_str(), defaultValue);
    }
    int64_t readLong(const String &key, const int64_t defaultValue) override
    {
        return preferences.getLong64(key.c_str(), defaultValue);
    }
    uint64_t readULong(const String &key, const uint64_t defaultValue) override
    {
        return preferences.getULong64(key.c_str(), defaultValue);
    }
    float readFloat(const String &key, const float defaultValue) override
    {
        return preferences.getFloat(key.c_str(), defaultValue);
    }
    double readDouble(const String &key, const double defaultValue) override
    {
        return preferences.getDouble(key.c_str(), defaultValue);
    }
    bool readBool(const String &key, const bool defaultValue) override
    {
        return preferences.getBool(key.c_str(), defaultValue);
    }
    String readString(const String &key, const String defaultValue) override
    {
        return String(preferences.getString(key.c_str(), String(defaultValue.c_str())).c_str());
    }

    void writeChar(const String &key, const int8_t value) override
    {
        preferences.putChar(key.c_str(), value);
    }
    void writeUChar(const String &key, const uint8_t value) override
    {
        preferences.putUChar(key.c_str(), value);
    }
    void writeShort(const String &key, const int16_t value) override
    {
        preferences.putShort(key.c_str(), value);
    }
    void writeUShort(const String &key, const uint16_t value) override
    {
        preferences.putUShort(key.c_str(), value);
    }
    void writeInt(const String &key, const int32_t value) override
    {
        preferences.putInt(key.c_str(), value);
    }
    void writeUInt(const String &key, const uint32_t value) override
    {
        preferences.putUInt(key.c_str(), value);
    }
    void writeLong(const String &key, const int64_t value) override
    {
        preferences.putLong(key.c_str(), value);
    }
    void writeULong(const String &key, const uint64_t value) override
    {
        preferences.putULong(key.c_str(), value);
    }
    void writeFloat(const String &key, const float value) override
    {
        preferences.putFloat(key.c_str(), value);
    }
    void writeDouble(const String &key, const double value) override
    {
        preferences.putDouble(key.c_str(), value);
    }
    void writeBool(const String &key, const bool value) override
    {
        preferences.putBool(key.c_str(), value);
    }
    void writeString(const String &key, const String value) override
    {
        preferences.putString(key.c_str(), value.c_str());
    }

private:
    Preferences preferences;
};

#endif // __H_PREFERENCES_STORAGE_MEDIUM__
