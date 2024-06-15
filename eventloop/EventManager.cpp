#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

class EventManager {
private:
    std::map<std::string, std::vector<void (*)(int)> > events;

public:
    EventManager() {}
    EventManager* eventRegist(std::string event_name, void (*callback)(int)) {
        std::vector<void (*)(int)>* listeners = &events[event_name];
        // if this listener is already registered, we wont add it again
        if (std::find(listeners->begin(), listeners->end(), callback) !=  listeners->end()) 
        {
            return this;
        }
        listeners->push_back(callback);
        return this;
    }
    bool emit(std::string event_name, int arg) {
        std::vector<void (*)(int)> listeners = events[event_name];
        if (listeners.size() == 0) return false;
        for (int idx = 0; idx < listeners.size(); idx += 1) {
            listeners[idx](arg);
        }
        return true;
    }
};

void callback1(int num) {
    std::cout << "callback1-" << num << std::endl;
}
void callback2(int num) {
    std::cout << "callback2-" << num << std::endl;
}

int main() {
    EventManager* event_manager = new EventManager();
    //注册回调函数
    event_manager->eventRegist("event1", callback1);
    event_manager->eventRegist("event2", callback2);
    //执行回调函数
    int eventA = event_manager->emit("event1", 10);
    int eventB = event_manager->emit("event2", 20);
    return 0;
}