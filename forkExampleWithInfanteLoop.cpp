#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <cassert>

using namespace std;

int main() {
        pid_t pid = fork();
        int i = 1;
        switch(pid) {
                case -1:
                        cout << "Error occurred" << endl;
                        return -1;
                case 0:
			while(i);
                        cout << "Child process" << endl;
                        break;
                default:
                        cout << "Parent process" << endl;
        }
        return 0;
}
