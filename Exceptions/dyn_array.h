#pragma once
#include <iostream>

class dyn_array
{
public:
    typedef int datatype;
    dyn_array();
    dyn_array(int size);
    dyn_array(const char *filename, bool is_text = true);
    ~dyn_array();

    dyn_array(const dyn_array& d);    
    dyn_array &operator=(const dyn_array& d);

    datatype operator[](int index) const;
    datatype &operator[](int index);
    int count() const;
    void resize(int new_size);
    void append(const datatype &x);
private:
    datatype *data;
    int size;
    void copy(const datatype *from, datatype* to, int size);
    void file_init(const char *filename);
    void text_init(const char *filename);
};

