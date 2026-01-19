#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdio>

void add_task() {
    std::string name, deadline;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "--------------------" << std::endl;
    std::cout << "Adding task..." << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Enter task's name: " << std::endl;
    std::getline(std::cin, name);
    std::cout << "Enter task's deadline: " << std::endl;
    std::getline(std::cin, deadline);
    
    std::ofstream tasks("tasks.txt", std::ios::app);
    tasks << name << std::endl;
    tasks << deadline << std::endl;

    tasks.close();
}

void delete_task() {
    std::string name, deadline;
    int num_to_delete;
    int current_num = 1;

    std::cout << "--------------------" << std::endl;
    std::cout << "Deleting task..." << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Enter task's number: " << std::endl;
    std::cin >> num_to_delete;

    std::ifstream tasks_main("tasks.txt");
    std::ofstream tasks_main_new("tasks_new.txt");

    while (std::getline(tasks_main, name)) {
        if (!std::getline(tasks_main, deadline)) {
            break;
        }

        if (current_num != num_to_delete) {
            tasks_main_new << name << std::endl;
            tasks_main_new << deadline << std::endl;
        }

        current_num++;
    }

    tasks_main.close();
    tasks_main_new.close();

    std::remove("tasks.txt");
    std::rename("tasks_new.txt", "tasks.txt");
}

void see_tasks() {
    std::string line;
    int task_num = 1;

    std::ifstream tasks_main("tasks.txt");

    std::cout << "--------------------" << std::endl;
    std::cout << "Listing tasks..." << std::endl;
    std::cout << "--------------------" << std::endl;

    while (std::getline(tasks_main, line)) {
        std::cout << task_num << ". Name: " << line << std::endl;
        std::getline(tasks_main, line);
        std::cout << "Deadline: " << line << std::endl;
        task_num++;
    }

    tasks_main.close();
}

int main() {
    short int choice;

    while (true) {
        std::cout << "--------------------" << std::endl;
        std::cout << "To-Do List" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Delete Task" << std::endl;
        std::cout << "3. See Tasks" << std::endl;

        std::cout << "Choice: ";
        std::cin >> choice;

        switch(choice) {
            case(1):
                add_task();
                break;
            case(2):
                delete_task();
                break;
            case(3):
                see_tasks();
                break;
            case(0):
                return 0;
        }
    }

    return 0;
}