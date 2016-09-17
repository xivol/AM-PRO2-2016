#pragma once

template <typename T>
T read_binary(std::ifstream &fin)
{
    T t;
    fin.read(reinterpret_cast<char*> (&t), sizeof(t));
    return t;
}

template <typename T>
void write_binary(std::ofstream &fout, T &t)
{
    fout.write(reinterpret_cast<char*> (&t), sizeof(t));
}

template <typename T>
size_t number_of(const char *filename)
{
    assert(filename);

    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open())
        throw std::exception("���������� ������� ����!");

    size_t count = 0;
    while (!fin.eof()) {
        // ������� ��������� ������� �� �����
        read_binary<T>(fin);
        if (fin)   // ���� ������ ������ �������
            count++;
    }

    fin.close();
    return count;
}

