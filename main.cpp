#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Student {
private:
    int id;
    std::string name;
    int age;
    std::string grade;

public:
    Student(int id, const std::string& name, int age, const std::string& grade)
        : id(id), name(name), age(age), grade(grade) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    std::string getGrade() const {
        return grade;
    }
};

std::vector<Student> loadStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if (tokens.size() == 4) {
                int id = std::stoi(tokens[0]);
                std::string name = tokens[1];
                int age = std::stoi(tokens[2]);
                std::string grade = tokens[3];
                students.emplace_back(id, name, age, grade);
            }
        }
        file.close();
        std::cout << "Students loaded from file successfully.\n";
    } else {
        std::cout << "Failed to open the file for reading.\n";
    }
    return students;
}

void addStudentsToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.getId() << ',' << student.getName() << ',' << student.getAge() << ',' << student.getGrade() << '\n';
        }
        file.close();
        std::cout << "Students added to file successfully.\n";
    } else {
        std::cout << "Failed to open the file for writing.\n";
    }
}

void updateStudentsFromFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.getId() << ',' << student.getName() << ',' << student.getAge() << ',' << student.getGrade() << '\n';
        }
        file.close();
        std::cout << "Students updated in file successfully.\n";
    } else {
        std::cout << "Failed to open the file for writing.\n";
    }
}

void deleteStudentsFromFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.getId() << ',' << student.getName() << ',' << student.getAge() << ',' << student.getGrade() << '\n';
        }
        file.close();
        std::cout << "Students deleted from file successfully.\n";
    } else {
        std::cout << "Failed to open the file for writing.\n";
    }
}

void displayMenu() {
    std::cout << "\nWelcome to the School Management System!\n";
    std::cout << "Please select an option:\n";
    std::cout << "1. Add a student\n";
    std::cout << "2. View all students\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice = 0;
    std::vector<Student> students = loadStudentsFromFile("students.txt");

    while (choice != 3) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string name, grade;
                int age;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                std::cout << "Enter student name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter student age: ";
                std::cin >> age;
                std::cout << "Enter student grade: ";
                std::cin.ignore();
                std::getline(std::cin, grade);

                students.emplace_back(id, name, age, grade);
                std::cout << "Student added successfully!\n";
                break;
            }
            case 2: {
                std::cout << "\nAll Students:\n";
                for (const auto& student : students) {
                    std::cout << "ID: " << student.getId() << "\n";
                    std::cout << "Name: " << student.getName() << "\n";
                    std::cout << "Age: " << student.getAge() << "\n";
                    std::cout << "Grade: " << student.getGrade() << "\n\n";
                }
                break;
            }
            case 3:
                updateStudentsFromFile(students, "students.txt");
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
