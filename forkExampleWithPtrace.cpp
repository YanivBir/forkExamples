#include <cstdint>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>

using namespace std;

int main() {
        pid_t pid = fork();
        uint32_t temp = 0;
        switch(pid) {
                case -1:
                        cout << "Error occurred" << endl;
                        return -1;
                case 0:
                        temp = 1;
                        ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
                        raise(SIGSTOP);
                        cout << "Child process" << endl;
                        break;
                default:
                        temp = 2;
                        cout << "Parent process" << endl;
                        waitpid(pid, nullptr, 0);

                        ptrace(PTRACE_ATTACH, pid, nullptr, nullptr);
                        uint32_t child_temp = ptrace(PTRACE_PEEKDATA, pid, &temp, nullptr);
                        cout << "Child's temp value is: " << child_temp << endl;
                        ptrace(PTRACE_DETACH, pid, nullptr, nullptr);
        }
        return 0;
}
