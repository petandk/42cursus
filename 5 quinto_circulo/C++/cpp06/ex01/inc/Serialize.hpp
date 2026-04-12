#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <stdint.h>
# include "Data.hpp"

class Serialize
{
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
        
    private:
        Serialize(void);
        Serialize(const Serialize &other);
        Serialize &operator=(const Serialize &other);
        ~Serialize(void);
};

#endif