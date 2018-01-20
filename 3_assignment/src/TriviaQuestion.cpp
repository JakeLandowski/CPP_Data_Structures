#include <time.h>
#include <stdlib.h>

#include "TriviaQuestion.h"
#include "Utilities.h"

using namespace std;

TriviaQuestion::TriviaQuestion(string data)
{
    srand(time(0));
    setup(data);  
}
            
void TriviaQuestion::setup(string data)
{
    if(data.empty()) return;

    answerIndex = 0;

    vector<string> components = Utilities::split(data, " :: ", 5);

    question   = components[0];
    answers[0] = components[1];
    answers[1] = components[2];
    answers[2] = components[3];
    answers[3] = components[4];
}

int TriviaQuestion::askQuestion()
{
    if(question.empty()) cerr << "Question not setup yet." << endl;

    shuffleQuestions();
    
    cout << question << endl;

    for(int i = 0; i < NUM_ANSWERS; i++)
    {
        cout << "\t" + i << ". " << answers[i] << endl;
    }

    cout << endl << "Your Answer >> ";
    cout.flush(); // force print

    int userAnswer;

    cin >> userAnswer;
    cin.ignore(); // ignore remaining whitespace 

    bool isIncorrect = userAnswer - 1 != answerIndex;

    if(isIncorrect)
    {
        cout << endl << "~~ Incorrect! ~~" << endl
             << "Answer : " << answers[answerIndex] << endl << endl;
        return 0;
    }

    cout << endl << "~~ Correct! ~~" << endl << endl;
    return 1; 
}

/**
 *  Linear in-place fisher yates shuffle
 *  Random index 0 => 3 | Swap picked with 3
 *  Random index 0 => 2 | Swap picked with 2
 *  Random index 0 => 1 | Swap picked with 1
*/
void TriviaQuestion::shuffleQuestions()
{
    int picked;
    string temp;

    for(int i = NUM_ANSWERS; i > 0; i--)
    {
        picked = rand() % i; 
        temp   = answers[picked];
        answers[picked] = answers[i - 1];
        answers[i - 1] = temp;
        
        if(picked == answerIndex)
        {
            answerIndex = i - 1;
        } 
    }
}