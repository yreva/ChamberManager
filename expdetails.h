#ifndef EXPDETAILS_H
#define EXPDETAILS_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <filesystem>
#include <map>


class Experiment {
private:
    int experiment_started[1];
    std::chrono::time_point<std::chrono::system_clock> exp_start_time;
    std::string experiment_directory;

public:
    std::string start_experiment(std::string username, std::string experiment_title) {
        experiment_started[0] = 1;
        exp_start_time = std::chrono::system_clock::now();
        // Assuming equivalent of QDateTime::currentDateTime() is not available, you can use std::chrono::system_clock::now()
        std::time_t current_time = std::chrono::system_clock::to_time_t(exp_start_time);

        // Convert the time_t object to a tm structure
        std::tm *timeInfo = std::localtime(&current_time);

        // Format the date as YYYYMMDD
        char buffer[9]; // Buffer to hold the formatted date
        std::strftime(buffer, sizeof(buffer), "%Y%m%d", timeInfo);

        std::string current_date_str = std::string(buffer);

        experiment_directory = "C:/ChIMS/" + username + "/" + current_date_str + "_" + experiment_title + "/";

        try {
            if (!std::filesystem::create_directories(experiment_directory)) {
                std::cerr << "Folder '" << experiment_directory << "' creation failed." << std::endl;
            } else {
                std::cout << "Folder '" << experiment_directory << "' created successfully." << std::endl;
            }
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << e.what() << std::endl;
        } catch (...) {
            std::cerr << "An error occurred while creating folder." << std::endl;
        }
        return experiment_directory;
    }
};

#endif // EXPDETAILS_H
