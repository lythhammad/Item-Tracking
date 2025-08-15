#include <iostream>
#include <string>
#include "itemTracking.h"

int main() {
	ItemTracker tracker("CS210_Project_Three_Input_File.txt"); // Create an ItemTracker object
	tracker.load(); // Load data from file

	int choice;
	std::string item;

	do {
		std::cout << "\n===== Corner Grocer Menu =====\n";
		std::cout << "1. Search for item frequency\n";
		std::cout << "2. Print all item frequencies\n";
		std::cout << "3. Print histogram\n";
		std::cout << "4. Exit\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "Enter item name: ";
			std::cin >> item;
			std::cout << item << " purchased "
				<< tracker.countOf(item) << " times.\n"; // Search and print item frequency
			break;
		case 2:
			tracker.printAllFrequencies(); // Print all frequencies
			break;
		case 3:
			tracker.printHistogram(); // Print histogram
			break;
		case 4:
			std::cout << "Exiting program...\n"; // To exit the program
			break;
		default:
			std::cout << "Invalid choice. Try again.\n";
		}
	} while (choice != 4);

	return 0;
}