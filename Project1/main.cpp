#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int get_random_number() {
    return rand() % 9 + 1;
}

void print_time_of_solution(int seconds) {
    int minutes = seconds / 60;
    int sec = seconds % 60;
    cout << (minutes < 10 ? "0" : "") << minutes << ":" << (sec < 10 ? "0" : "") << sec << endl;
}

int main() {
    srand(time(0));  

    int number_of_examples;
    cout << "Enter the number of examples: ";
    cin >> number_of_examples;

    int errors = 0;
    time_t start_time = time(NULL);

    for (int i = 0; i < number_of_examples; ++i) {
        int num1 = get_random_number();
        int num2 = get_random_number();
        int num3 = get_random_number();

        char k1 = '+';
        char k2 = '-';

        
        if (num1 < num2) {
            swap(num1, num2);
        }

        if (num1 - num2 < num3) {
            num3 = num1 - num2 + get_random_number() % (num1 - num2 + 1);
        }

        int correct_result = num1 - num2 + num3;

        int user_answer;
        cout << num1 << " " << k1 << " " << num2 << " " << k2 << " " << num3 << " = ";
        cin >> user_answer;

        if (user_answer == correct_result) {
            cout << "Very well!" << endl;
        }
        else {
            cout << "Incorrect result... Please try again." << endl;
            errors++;
        }
    }

    time_t end_time = time(NULL);
    int total_time = end_time - start_time;

    cout << "Total time of solving examples: ";
    print_time_of_solution(total_time);
    cout << "Count of errors: " << errors << endl;

    return 0;
}
