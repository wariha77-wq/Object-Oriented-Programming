#include <iostream>
#include<string>
using namespace std;

class Question {
protected:
    int QuestionID;
    string statement;
    float maxMarks;
public:
    Question() {
        QuestionID = 0;
        maxMarks = 0;
    }

    virtual void readQuestion() = 0;
    virtual void displayQuestion() = 0;
    virtual bool isMCQ() {
        return false;
    }
    virtual float calculateScore(string Ans) = 0;

    float getMarks() {
        return maxMarks;
    }

    virtual ~Question() {

    }


};

class DescriptiveQuestion :public Question {
private:
    int blankLines;
    string modelAns;
    string keywords[20];
    int totalKeywords;
public:
    DescriptiveQuestion() {
        blankLines = 0;
        totalKeywords = 0;
    }
    void readQuestion() {
        cout << "Enter Question ID: ";
        cin >> QuestionID;
        cin.ignore();
        cout << "Enter Statement: ";
        getline(cin, statement);
        cout << "Enter Max Marks: ";
        cin >> maxMarks;
        cout << "Enter No of Blank Lines: ";
        cin >> blankLines;
        cin.ignore();
        cout << "Enter Model Answer: ";
        getline(cin, modelAns);
        cout << "Enter no of Keywords: ";
        cin >> totalKeywords;
        while (totalKeywords < 1 || totalKeywords > 20) {
            cout << "Enter a number between 1 and 20: ";
            cin >> totalKeywords;
        }
        for (int i = 0;i < totalKeywords;i++) {
            cout << "Enter Keyword: ";
            cin >> keywords[i];
        }

        
    }
    void displayQuestion() override {
        cout << "Question Statement: " << statement << endl;
        cout << "Allocated Answer Space: " << blankLines << endl;
        cout << "Maximum Marks: " << maxMarks << endl;
    }

    float calculateScore(string Ans) override {
        float score=0;
        float marksPerKeyword = maxMarks / totalKeywords;
        for (int i = 0;i < totalKeywords;i++) {
            if (Ans.find(keywords[i])!=string::npos) {
                    score += marksPerKeyword;
            }
        }
        if (score > maxMarks) {
            score = maxMarks;
        }

        return score;
    }

};

class MCQs:public Question {
private:
    string availableChoices[4];
    string correctChoice;
    int numberOfChoices;
public:
    void readQuestion()override {
        cout << "Enter Question ID: ";
        cin >> QuestionID;
        cin.ignore();
        cout << "Enter Statement: ";
        getline(cin, statement);
        cout << "Enter Max Marks: ";
        cin >> maxMarks;
        cout << "Enter number of choices: ";
        cin >> numberOfChoices;
        while (numberOfChoices < 1 || numberOfChoices>4) {
            cout << "Enter number of choices: ";
            cin >> numberOfChoices;
        }
        cout << "Enter All Choices: ";
        for (int i = 0;i < numberOfChoices;i++) {
            cin >> availableChoices[i];
        }
        cout << "Enter Correct Choice: ";
        cin >> correctChoice;
    }

    void displayQuestion() override {
        cout << "Question Statement: " << statement << endl;
        for (int i = 0;i < numberOfChoices;i++) {
            cout << static_cast<char>(97 + i) << ") " << availableChoices[i] << endl;
        }
    }
    bool isMCQ() override {
        return true;
    }
    float calculateScore(string Ans) override {
        if (Ans == correctChoice) {
            return maxMarks;
        }
        else {
            return 0;
        }
    }

};

class ExaminationManagement {
private:
    string title;
    string courseCode;
    int totalQuestions;
    Question* Q[100];
public:
    ExaminationManagement() {
        totalQuestions = 0;
        for (int i = 0;i < 100;i++) {
            Q[i] = NULL;
        }
    }

    void readExamination() {
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Course Code: ";
        cin >> courseCode;
        cout << "Enter total number of Questions: ";
        cin >> totalQuestions;
        for (int i = 0;i < totalQuestions;i++) {
            int ch;
            cout << "Enter Choice (Descriptive=1,MCQ=0): ";
            cin >> ch;
            if (ch == 0) {
                Q[i] = new MCQs;
            }
            else if (ch == 1) {
                Q[i] = new DescriptiveQuestion;
            }
            else {
                cout << "Enter Valid Choice!" << endl;
                i--;
                continue;
            }
            Q[i]->readQuestion();
        }
    }
    void displayExamination() {
        cout << "Course Title: " << title << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << " ==== Examination ==== " << endl<<endl;
        float totalMarks = 0;
        for (int i = 0;i < totalQuestions;i++) {
            cout << "Question: " << i + 1 << endl;
            Q[i]->displayQuestion();
            totalMarks += Q[i]->getMarks();
            cout << endl;
        }
        cout << "Total Marks: " << totalMarks << endl;
    }

    void assessStudents() {
        string studentID;
        float totalObtained = 0;
        float totalMaxMarks = 0;
        int correct = 0, incorrect = 0, unanswered = 0;
        cout << "Enter Student Id: ";
        cin >> studentID;
        cin.ignore();
        for (int i = 0;i < totalQuestions;i++) {
            totalMaxMarks += Q[i]->getMarks();
        }
        for (int i = 0;i < totalQuestions;i++) {
            string resp;
            cout << "Question: " << i + 1 << endl;
            Q[i]->displayQuestion();
            cout << "Enter Answer: ";
            getline(cin, resp);
            float marks = Q[i]->calculateScore(resp);
            totalObtained += marks;
            cout << "Marks Obtained: " << marks << endl;
            if (Q[i]->isMCQ()) {
                if (resp.empty()) {
                    unanswered++;
                }
                else if (marks > 0) {
                    correct++;
                }
                else {
                    incorrect++;
                }
            }

        }
        cout << "\n========== FINAL REPORT ==========\n";
        cout << "Student ID: " << studentID << "\n";
        cout << "Total Marks Obtained: " << totalObtained;
        cout << " / " << totalMaxMarks << "\n";
        cout << "Percentage: " << (totalObtained / totalMaxMarks) * 100 << " %" << endl;

        cout << "Correct MCQs: " << correct << "\n";
        cout << "Incorrect MCQs: " << incorrect << "\n";
        cout << "Unanswered MCQs: " << unanswered << "\n";
    }
    ~ExaminationManagement() {
        for (int i = 0; i < totalQuestions; i++) {
            delete Q[i];
        }
    }
};

int main()
{
    
    ExaminationManagement exam;

    exam.readExamination();
    exam.displayExamination();
    exam.assessStudents();

}
