#include <vector>
#include <iostream>

void show_vec(std::vector<int> line) {
    for (std::vector<int>::const_iterator iter = line.cbegin(); iter != line.cend(); iter++) {
        std::cout << (*iter);
    }
    std::cout << std::endl;
}

void back_track(int *arr, std::vector<int> track, int len) {
    if (track.size() == len) {
        show_vec(track);
    }
    for (int i = 0; i < len; i++) {
        // 选择路径，如果已经排列过，不处理
        if (std::find(track.begin(), track.end(), arr[i]) != track.end()) {
            continue;
        }
        track.push_back(arr[i]);
        back_track(arr, track, len);
        track.pop_back();
    }
}

int main() {
    std::vector<int> track;
    int arr[] = {1, 2, 3};
    back_track(arr, track, sizeof(arr) / sizeof(int));
    return 0;
}