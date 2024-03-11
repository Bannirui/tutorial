#include <iostream>

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void Info(const char *msg)
    {
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[INFO]:" << msg << std::endl;
    }

    void Warn(const char *msg)
    {
        if (m_LogLevel >= LogLevelWarning)
            std::cout << "[WARNING]:" << msg << std::endl;
    }

    void Error(const char *msg)
    {
        if (m_LogLevel >= LogLevelError)
            std::cout << "[ERROR]:" << msg << std::endl;
    }
};

int main()
{
    Log log;
    log.SetLevel(log.LogLevelError);
    log.Warn("hello");
    log.Error("hello");
    log.Info("hello");

    return 0;
}