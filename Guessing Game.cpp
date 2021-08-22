#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    cout << "********************************" << endl;
    cout << "* Welcome to the Guessing-Game *" << endl;
    cout << "********************************" << endl;

    cout << "Choose your dificult level: " << endl;
    cout << "Easy(E), Mediun(M) or  Hard(H) " << endl;

    char difficulty;
    cin >> difficulty; 

    int number_at_attempts;

    if(difficulty == 'E'){
        number_at_attempts = 15;
    }else if(difficulty == 'M'){
        number_at_attempts = 10;
    }else{
        number_at_attempts = 5;
    }

    srand(time(NULL));
    const int number_secret = rand() % 100;

    int attempts = 0;
    bool no_right = true;

    double points = 1000.0;

    for(attempts = 1; attempts <= number_at_attempts; attempts++){
        cout << "Attempt " << attempts <<":"<< endl;
        int guess;
        cout << "What's your guess? ";
        cin >> guess;

        cout << "The value of your guess is: " << guess << endl << endl;

        double lost_points = abs(guess - number_secret)/2.0;
        points -= lost_points;

        bool got_it_right = guess == number_secret;
        bool bigger = guess > number_secret;

        if(got_it_right){
            cout << "Congratulations!, You got the secret number right in " << attempts << " attempts" <<  endl << endl;
            no_right = false;
            break;
        } else if(bigger){
            cout << "Your guess was bigger than the number secret!" << endl << endl;
        }else{
            cout << "Your guess was less than the number secret" << endl << endl;
     }
    }
    cout << "Game Over, to play again!" << endl << endl;
    if(no_right){
        cout << "You lost! Try again" << endl << endl;
    }else{
        cout << "You hit the secret number in so "<< attempts << " attempts" << endl << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Your score was " << points << endl;

    }
}