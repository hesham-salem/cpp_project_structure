#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>
#include <stdexcept>
#include <functional>
#include <fstream>
class storage
{
public:
    void save(int result)
    {
        std::ofstream file("data.txt");

        file << result;
    }
};

class calculator_base
{
public:
    virtual void reset_result() = 0;
    ~calculator_base() = default;
};

template <typename T>
class calculator : public calculator_base
{

public:
    const float pi = 3.14;

    calculator();
    explicit calculator(T);
    calculator(const calculator &);
    calculator &operator=(const calculator &other);
    calculator(calculator &&other);
    calculator &operator=(calculator &&otheer);
    ~calculator();

    T add(T first_no, T second_no);
    T add(std::initializer_list<T> const &list);

    T product(T first_no, T second_no);
    T specify_operation(T first_no, T second_no, std::function<T(T, T)> const &func);
    void save_result();
    inline T get_result() const
    {
        return *result;
    }
    inline T get_last_operation_value() const
    {
        return *last_operation_value;
    }
    inline void reset_result() override
    {
        *result = 0;
    }

private:
    storage _storge;
    std::unique_ptr<T> last_operation_value;
    std::unique_ptr<T> result;
};

#endif