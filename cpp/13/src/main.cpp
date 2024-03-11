#include <iostream>

enum Example : char
{
    A = 4,
    B,
    C
};

class Log
{
public:
    enum Level : char
    {
        ERROR = 0,
        WARNING,
        INFO
    };

private:
    int m_LogLevel = INFO;

public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void Info(const char *msg)
    {
        if (m_LogLevel >= INFO)
            std::cout << "[INFO]:" << msg << std::endl;
    }

    void Warn(const char *msg)
    {
        if (m_LogLevel >= WARNING)
            std::cout << "[WARNING]:" << msg << std::endl;
    }

    void Error(const char *msg)
    {
        if (m_LogLevel >= ERROR)
            std::cout << "[ERROR]:" << msg << std::endl;
    }
};

int main()
{
    Log log;
    log.SetLevel(Log::ERROR);
    log.Warn("hello");
    log.Error("hello");
    log.Info("hello");

    Example val = B;
    std::cout << val << std::endl;
    std::cout << sizeof(val) << std::endl;
    if (val == 1)
    {
        // do sth
    }
    return 0;
}