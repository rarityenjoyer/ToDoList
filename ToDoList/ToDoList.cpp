#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Task
{
	std::string name;
	std::string description;
	bool completed;

	Task(std::string n = "Task", std::string d = "Default Task", bool c = 0) : name(n), description(d), completed(c) {}
};

bool operator==(const Task& lhs, const Task& rhs)
{
	return lhs.name == rhs.name && lhs.description == rhs.description && lhs.completed == rhs.completed;
}

const void showTasks(std::vector<Task>& tasks)
{
	for (int count = 0; count < tasks.size(); ++count)
	{
		std::cout << "Task #" << count + 1 << std::endl;
		std::cout << "Name: " << tasks[count].name << std::endl;
		std::cout << "Description: " << tasks[count].description << std::endl;
		std::cout << "Status: " << ((tasks[count].completed == true) ? "Completed\n" : "Uncompleted\n") << std::endl;
	}
}

void deleteTask(std::vector<Task>& tasks)		// doesn't work properly yet.
{
	showTasks(tasks);
	std::cout << "Choose the number of the task that you want to delete: ";
	int taskNumber = 0;
	std::cin >> taskNumber;
	tasks.erase(tasks.begin() + taskNumber - 1);
	std::cout << "You succesfully deleted task #" << taskNumber << ".\n";
}

void statusUpdate(std::vector<Task>& tasks)		// doesn't work properly yet.				
{
	showTasks(tasks);
	std::cout << "Choose the number of the task that you want to change the status of: ";
	int taskNumber = 0;
	std::cin >> taskNumber;
	tasks[taskNumber-1].completed = true;
	std::cout << "Good work! Congratulations on completing the '" << tasks[taskNumber].name << "' task.\n";
}

void addTask(std::vector<Task>& tasks)
{
	std::string name;
	std::string description;
	bool completed = 0;
	std::cout << "Give a short name for a task: \n";
	std::cout << "Example: 'wash dishes', 'clean up my room', 'go to the gym'\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, name);
	std::cout << "Good! Now give it a more detailed description if it's needed.\n";
	std::cout << "(If you want to skip this part - just press <ENTER> button.)\n";
	std::getline(std::cin, description);
	std::cout << "Done! Your task is created.\n";
	Task task(name, description, completed);
	tasks.push_back(task);
}


void interfaceFunction(std::vector<Task> tasks, std::string name)
{
	std::cout << "Hey, " << name << "! " << ((tasks.size() == 0) ? "Looks like you don't have any tasks yet ;(\n" : "Hope you completed all your tasks for today!\n");
	int workStatus = 1;
	while(workStatus)
	{ 
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
			workStatus = 0;
			break;
		}
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

