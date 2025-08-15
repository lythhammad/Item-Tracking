#include "itemTracking.h"
#include <fstream> 
#include <sstream>

ItemTracker::ItemTracker(const std::string& filePath) { // Constructor
	inputFilePath = filePath;
}

void ItemTracker::load() { // Loads items from file
	std::ifstream inFile(inputFilePath);
	if (!inFile) {
		std::cerr << "Error: Could not open file " << inputFilePath << std::endl;
		return;
	}

	std::string item;
	while (inFile >> item) {
		counts[item]++;
	}

	inFile.close();

	writeBackup(); // Creates a backup file
}

void ItemTracker::writeBackup(const std::string& outputFilePath) { // Writes data to backup file
	std::ofstream outFile(outputFilePath);
	if (!outFile) {
		std::cerr << "Error: Could not create backup file " << outputFilePath << std::endl;
		return;
	}

	for (const auto& pair : counts) {
		outFile << pair.first << " " << pair.second << std::endl;
	}

	outFile.close();
}

int ItemTracker::countOf(const std::string& item) const { // Gets the frequency of an item
	auto it = counts.find(item);
	if (it != counts.end()) {
		return it->second;
	}
	return 0;
}

void ItemTracker::printAllFrequencies() const { // Prints all items and their frequencies
	for (const auto& pair : counts) {
		std::cout << pair.first << " " << pair.second << std::endl;
	}
}

void ItemTracker::printHistogram(char barChar) const { // Prints a histogram
	for (const auto& pair : counts) {
		std::cout << pair.first << " ";
		for (int i = 0; i < pair.second; ++i) {
			std::cout << barChar;
		}
		std::cout << std::endl;
	}
}