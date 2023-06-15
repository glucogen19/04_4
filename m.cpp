#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class TBook {
	private:
    std::string Name;
    std::string Author;
    int Count;
	public:
    std::string getName() const { return Name; }
    std::string getAuthor() const { return Author; }
    int getCount() const { return Count; }

    void setName(const std::string& name) { Name = name; }
    void setAuthor(const std::string& author) { Author = author; }
    void setCount(int count) { Count = count; }
};

int main(){}