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
    virtual int open_port(int flags, mode_t mode) = 0;    
    virtual std::string read_port() = 0;
    virtual int write_port(std::string & to_write) = 0;
    virtual int close_port() = 0;
    int get_fd();
    void set_fd(int fd);
    const std::string& get_my_path();
};

class A7602EPort : public IOPort{
    public:
    A7602EPort(std::string & path) : IOPort(path) {};
    int open_port(int flags, mode_t mode) override;
    std::string read_port() override;
    int write_port(std::string & to_write) override;
    int close_port() override;
};