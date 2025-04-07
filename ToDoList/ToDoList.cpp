#include <iostream>
#include <vector>
#include <algorithm>

struct Task
{
	std::string name;
	std::string description;
	bool completed;

	Task(std::string n, std::string d, bool c = 0) : name(n), description(d), completed(c) {}
};

bool operator==(const Task& lhs, const Task& rhs)
{
	return lhs.name == rhs.name && lhs.description == rhs.description && lhs.completed == rhs.completed;
}

void addTask(std::vector<Task>& tasks)
{
	std::string name;
	std::string description;
	bool completed;
	std::cout << "Give a short name for a task: \n";
	std::cout << "Example: 'wash dishes', 'clean up my room', 'go to the gym'\n";
	std::cin >> name;
	std::cout << "Good! Now give it a more detailed description if it's needed.\n";
	std::cout << "(If you want to skip this part - just press <ENTER> button.)\n";
	std::cin >> description;
	std::cout << "Done! Your task is created.\n";
	Task task(name, description, completed);
	tasks.push_back(task);
}

void deleteTask(std::vector<Task>& tasks, Task task)						// doesn't works properly yet.
{
	auto it = std::find(tasks.begin(), tasks.end(), task);
	if (it != tasks.end()) 
	{
		tasks.erase(it);
	}
	else 
	{
		std::cout << "Task not found" << std::endl;
	}
}

const void showTasks(std::vector<Task>& tasks)
{
	for (int count = 0; count < tasks.size(); ++count)
	{
		std::cout << "Task #" << count << std::endl;
		std::cout << "Name: " << tasks[count].name << std::endl;
		std::cout << "Description: " << tasks[count].description << std::endl;
		std::cout << "Status: " << ((tasks[count].completed == true) ? "Completed\n" : "Uncompleted\n") << std::endl;
	}
}

void statusUpdate(std::vector<Task>& tasks)						
{
	showTasks(tasks);
	std::cout << "Choose the number of the task that you want to change the status of: ";
	int taskNumber = 0;
	std::cin >> taskNumber;
	tasks[taskNumber].completed = true;
	std::cout << "Good work! Congratulations on completing the '" << tasks[taskNumber].name << "' task.\n";
}

void interfaceFunction(std::vector<Task> tasks, std::string name)
{
	std::cout << "Hi there, " << name << "! " << ((tasks.size() == 0) ? "You haven't any tasks yet ;(\n" : "Hope you completed all your tasks for today!\n");
	std::cout << "Use 1-5 for navigation through the interface <3\n";
	std::cout << "1) View all of my tasks.\n";
	std::cout << "2) Add a new task.\n";
	std::cout << "3) Delete task.\n";
	std::cout << "4) Update a status of your task.\n";
	std::cout << "5) Exit.\n";
	int usersChoice = 0;
	while (usersChoice < 1 || usersChoice > 5)
	{ 
		std::cin >> usersChoice;
	}
	switch (usersChoice)
	{
		case 1:
			showTasks(tasks);
			break;
		case 2:
			addTask(tasks);
			break;
		case 3:
			deleteTask(tasks);
			break;
		case 4:
			statusUpdate(tasks);
			break;
		case 5:
			break;
	}
}

int main()
{
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	std::vector<Task> tasks;
	interfaceFunction(tasks, name);



}

