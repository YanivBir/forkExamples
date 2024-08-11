#include <cstdint>
#include <iostream>
#include <unistd.h>
#include <signal.h>

using namespace std;

int main() {
        pid_t pid = fork();
        switch(pid) {
                case -1:
                        cout << "Error occurred" << endl;
                        return -1;
                case 0:
                        cout << "Child process" << endl;
                        raise(SIGTRAP);
                        break;
                default:
                        cout << "Parent process" << endl;
        }
        return 0;
}
