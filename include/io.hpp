#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class IOPort{
    std::string m_path;
    int m_fd;
public:
    IOPort(std::string & path);
    virtual int open(int flags, mode_t mode) = 0;    
    virtual std::string read() = 0;
    virtual int write() = 0;
    virtual int close() = 0;
};

class A7602EPort : public IOPort{
    public:
    A7602EPort(std::string & path) : IOPort(path) {};
    int open(int flags, mode_t mode) override;
    std::string read() = 0;
};