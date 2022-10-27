#include <iostream>
#include <fstream>
#include <algorithm>
#include <string_view>

class Employee{
    private:    
        std::string m_Name, m_Status;
        int m_Age;
    public:
        Employee() : m_Name(""), m_Status(""), m_Age(0) {}
        void setName(std::string_view name) { m_Name = name; }
        void setStatus(std::string_view status) { m_Status = status; }
        void setAge(int age) { m_Age = age; }
        void printData()
        {
            std::cout<< "Name: \t\t" << m_Name << std::endl;
            std::cout<< "Status: \t" << m_Status << std::endl;
            std::cout<< "Age: \t\t" << m_Age << std::endl;
            std::cout<< "------------------" << std::endl;
        }
};

int readData(std::string_view _file_name, Employee* Employees, size_t size);

int main()
{
    const size_t size = 10;
    Employee Employees[size];
    int totalLines = readData("tt.txt", Employees, size);

    for (int i = 0; i < totalLines; i++)
        Employees[i].printData();

}


int readData(std::string_view _file_name, Employee* Employees, size_t size)
{
    std::fstream file(static_cast<std::string>(_file_name).c_str());

    short totalLinesRead = 0;
    while (totalLinesRead < size and !file.eof())
    {
        std::string each_line;
        getline(file, each_line);
        if (std::all_of(each_line.begin(), each_line.end(), isspace)) continue;

        std::string temp_str[3];
        uint16_t count = 0;

        for (int i = 0; i < each_line.length(); i++)
        {
            if (each_line[i] == ',')
            {
                count++;
                continue;
            }

            temp_str[count] += each_line[i];
        }
        
        Employees[totalLinesRead].setName(temp_str[0]);
        Employees[totalLinesRead].setStatus(temp_str[1]);
        Employees[totalLinesRead].setAge(std::stoi(temp_str[2]));
        totalLinesRead++;
    }
    
    file.close();
    return totalLinesRead;
}