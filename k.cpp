#include <iostream>
#include <ctime>
#include <vector>

struct Node {
    std::string start_time;
    std::string end_time;
    std::vector<int> available_days;
};

bool isAvailable(const Node& node, const std::string& datetime) {
    // Convert datetime to a time_t object
    struct tm dt = {};
    strptime(datetime.c_str(), "%Y-%m-%dT%H:%M:%S", &dt);
    time_t dtTimestamp = mktime(&dt);

    // Check if the day of the week is in the available_days vector
    int dayOfWeek = dt.tm_wday;
    if (std::find(node.available_days.begin(), node.available_days.end(), dayOfWeek) == node.available_days.end()) {
        return false;
    }

    // Extract the hours and minutes from the datetime
    int hours = dt.tm_hour;
    int minutes = dt.tm_min;

    struct tm startTime = {};
    struct tm endTime = {};
    strptime(node.start_time.c_str(), "%H:%M", &startTime);
    strptime(node.end_time.c_str(), "%H:%M", &endTime);
    time_t startTimeTimestamp = mktime(&startTime);
    time_t endTimeTimestamp = mktime(&endTime);

 
    if (dtTimestamp >= startTimeTimestamp && dtTimestamp <= endTimeTimestamp) {
        return true;
    }

    return false;
}

int main() {
    Node node = {
        .start_time = "08:00",
        .end_time = "17:00",
        .available_days = {1, 2, 3, 4, 5}, // Monday to Friday
    };

    std::string datetimeToCheck = "2023-07-24T10:30:00"; 

    if (isAvailable(node, datetimeToCheck)) {
        std::cout << "The datetime is available." << std::endl;
    } else {
        std::cout << "The datetime is not available." << std::endl;
    }

    return 0;
}
