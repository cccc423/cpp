#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

struct Task {
    std::string name;
    std::string deadline;
    std::string priority;
};

void load_tasks_from_file(std::vector<Task>& tasks) {
    std::string line, name, deadline, priority;

    std::ifstream read_main_file("tasks.txt");

    while (std::getline(read_main_file, name)) {
        if (std::getline(read_main_file, deadline)) {
            if (std::getline(read_main_file, priority)) {
                tasks.push_back({name, deadline, priority});
            }
        }  
    }

    read_main_file.close();

    std::cout << "Loaded tasks: " << tasks.size() << "\n";
    std::cout << "-------------------------\n";
}

int get_priority_value(const std::string& priority) {
    if (priority == "3") return 3;
    if (priority == "2") return 2;
    if (priority == "1") return 1;
    return 0;
}

void priority_sort(std::vector<Task>& tasks) {
    for (int i = 0; i < tasks.size(); i++) {
        for (int j = 0; j < tasks.size() - 1; j++) {
            if (get_priority_value(tasks[j].priority) > get_priority_value(tasks[j + 1].priority)) {
                std::swap(tasks[j], tasks[j + 1]);
            }
        }
    }

    std::ofstream main_file("tasks.txt", std::ios::trunc);

    for (int i = 0; i < tasks.size(); i++) {
        main_file << tasks[i].name << "\n" << tasks[i].deadline << "\n" << tasks[i].priority << "\n";
    }

    main_file.close();
}

void create_task(std::vector<Task>& tasks) {
    std::cout << "\nCreating a task...\n";
    std::cout << "-------------------------\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;
    std::string deadline;
    std::string priority;

    std::cout << "Enter a name: ";
    std::getline(std::cin, name);
    std::cout << "Enter a deadline: ";
    std::getline(std::cin, deadline);
    std::cout << "Enter priority: ";
    std::getline(std::cin, priority);

    tasks.push_back({name, deadline, priority});

    std::ofstream main_file("tasks.txt", std::ios::app);
    main_file << tasks.back().name << "\n" << tasks.back().deadline << "\n" << tasks.back().priority << "\n";

    main_file.close();
}

void delete_task(std::vector<Task>& tasks) {
    std::cout << "\nDeleting a task...\n";
    std::cout << "-------------------------\n";

    auto index_to_delete = tasks.cbegin();
    int p;

    std::cout << "Delete: ";
    std::cin >> p;

    if (p < 0 || p > tasks.size()) {
        std::cout << "Error! (choice out of range)\n";
        return;
    } else {
        tasks.erase(index_to_delete + p - 1);

        std::ofstream main_file("tasks.txt", std::ios::trunc);
    
        for (int i = 0; i < tasks.size(); i++) {
            main_file << tasks[i].name << "\n";
            main_file << tasks[i].deadline << "\n";
            main_file << tasks[i].priority << "\n";
        }

        main_file.close();
    }
}

void show_tasks(std::vector<Task>& tasks) {
    std::cout << "\nShowing tasks...\n";
    std::cout << "-------------------------\n";
    
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". Name: " << tasks[i].name << "\nDeadline: " << tasks[i].deadline << "\nPriority: " << tasks[i].priority << "\n";
    }
}

int main() {
    short int choice; 
    std::vector<Task> tasks;

    load_tasks_from_file(tasks);

    std::cout << "TDL v2\n";

    while(true) {
        priority_sort(tasks);
        
        std::cout << "-------------------------\n";
        std::cout << "1 - Create a task\n";
        std::cout << "2 - Delete a task\n";
        std::cout << "3 - Show tasks\n";
        std::cout << "0 - Exit\n";
        std::cout << "-------------------------\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch(choice) {
            case(1):
                create_task(tasks);
                priority_sort(tasks);
                break;
            case(2):
                delete_task(tasks);
                break;
            case(3):
                show_tasks(tasks);
                break;
            case(0):
                return 0;
            default:
                std::cout << "Error! (wrong choice)\n";
                continue;
        }
    }

    system("pause");
    return 0;
}