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

bool compareByAuthor(const TBook& book1, const TBook& book2) {
    return book1.getAuthor() < book2.getAuthor();
}

int main(){
    std::vector<TBook> books;
	 std::ifstream inputFile("books.txt");

    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
	
	std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string name, author;
        int count;

        if (std::getline(ss, name, ';') && std::getline(ss, author, ';') && (ss >> count)) {
            TBook book;
            book.setName(name);
            book.setAuthor(author);
            book.setCount(count);
            books.push_back(book);
        }
        else {
            std::cout << "Invalid data: " << line << std::endl;
        }
    }

    inputFile.close();
}