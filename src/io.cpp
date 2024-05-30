#include "io.hpp"

IOPort::IOPort(std::string &path)
{
    m_path = path;
}

int A7602EPort::open(int flags, mode_t mode)
{
    m_fd = open(m_path, flags, mode);
    if (m_fd){
        std::cout << "cant open port" << std::endl;
    } else {

    }
}

std::string A7602EPort::read()
{
    std::string result;
    result.resize(200);
    int ret = read(m_fd, result.data(), 200);
    if (ret > 0){
        result.resize(ret);
    } else {
        std::cout << "[A7602EPort::read] can't read from device " << std::endl;
    }    
    return result;
}
