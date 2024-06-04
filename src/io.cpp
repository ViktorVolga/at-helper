#include "io.hpp"

IOPort::IOPort(std::string &path)
{
    m_path = path;
}

int IOPort::get_fd()
{
    if(m_fd)
        return m_fd;
    else
        std::cout << "[IOPort::get_fd] [error] m_fd <= 0" << std::endl;
    return -1;
}

void IOPort::set_fd(int fd)
{
    m_fd = fd;
}

const std::string &IOPort::get_my_path()
{
    return m_path;
}

int A7602EPort::open_port(int flags, mode_t mode)
{
    int fd = open(get_my_path().data(), flags);
    if (fd <= 0){
        std::cout << "cant open port" << std::endl;        
        return -1;
    } else {
        std::cout << "open port succesfull" << std::endl;
        set_fd(fd);
        return 0;
    }
    std::cout << "fd [" << fd << "]" << std::endl;
}

std::string A7602EPort::read_port()
{
    std::string result;
    result.resize(200);
    int ret = read(get_fd(), (void*)result.data(), 200);
    if (ret > 0){
        result.resize(ret);
    } else {
        std::cout << "[A7602EPort::read] can't read from device " << std::endl;
    }
    std::cout << "readed " << ret << " byte" << std::endl;    
    return result;
}

int A7602EPort::write_port(std::string & to_write)
{
    if(get_fd())
        ssize_t ret = write(get_fd(), to_write.data(), to_write.size());
    else
        std::cout << "[A7602EPort::write_port] can't write in port" << std::endl;
}

int A7602EPort::close_port()
{    
    return close(get_fd());;
}
