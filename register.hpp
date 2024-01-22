#ifndef REGISTER_HPP
#define REGISTER_HPP

#include<string>

class Register {
  private:
    std::string name;
    bool free;

  public:
    Register(std::string& name);
    bool isFree() { return free; }
    void lock();
    void unlock();
};

#endif;