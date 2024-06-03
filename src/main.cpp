#include <iostream>
#include "io.hpp"
#include <memory>

int main() {
    std::string path = "/dev/ttyUSB1";
    std::unique_ptr<A7602EPort> port = std::make_unique<A7602EPort>(path);
    port->open_port(O_RDWR | O_NONBLOCK, S_IWOTH | S_IROTH);
    int count = 10;
    while(count){
        std::cout << port->read_port() << std::endl;
        count--;
    }
    port->close_port();
    return 0;
}