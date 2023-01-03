#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdio>
#include<iomanip>

using namespace std;

// Quiz structure----------------------------------------------------------------------------
struct Quiz {
	string question;
	string answer_1;
	string answer_2;
	string answer_3;
	string correct_answer;
};

// Count existing no of question in quiz-----------------------------------------------------
int ExsistingNoOfQuiz() {

	int count = -1;
	ifstream file;
	file.open("MyQuestionPaper.txt", ios::app);
	string read;
	while (!file.eof()) {
		for (int i = 0; i <= 4; i++) {
			getline(file, read);
		}
		count++;
	}
	return count;
}

// Build Quiestions--------------------------------------------------------------------------
void MyQuiz(Quiz quiz) {
	
	ofstream file;
	file.open("MyQuestionPaper.txt",ios::app);

	cout << " Enter the question   : "; getline(cin,quiz.question);
	file  << quiz.question << endl;
	cout << " Enter first answer   : "; getline(cin,quiz.answer_1);
	file << " 1." << quiz.answer_1 << endl;
	cout << " Enter second answer  : "; getline(cin,quiz.answer_2);
	file << " 2." << quiz.answer_2 << endl;
	cout << " Enter third answer   : "; getline(cin,quiz.answer_3);
	file << " 3." << quiz.answer_3 << endl;
	cout << " Enter correct answer : "; getline(cin,quiz.correct_answer);
	file << quiz.correct_answer << endl;
	cout << " total no of questions : " << ExsistingNoOfQuiz() << endl;
	cout << endl;
	file.close();
}

// Print Quiestions--------------------------------------------------------------------------
void PrintQuiz() {
	vector<string> correct_answer;
	string choice;
	double count = 0;

	ifstream file;
	file.open("MyQuestionPaper.txt", ios::app);
	string read;
	for (int i = 0; i < ExsistingNoOfQuiz(); i++) {
		cout << " Question " << i + 1 << endl << "------------" << endl;
		for (int i = 0; i <= 4; i++) {
			if (i == 4) {
				getline(file, read);
				correct_answer.push_back(read);
			}
			else {
				getline(file, read);
				cout << read << endl;
			}
		}

		cout << " Type your answer : ";
		cin >> choice;

		if (choice == correct_answer[0]) {
			cout << " Your answer is correct. " << endl << endl;
			count++;
		}
		else {
			cout << " Your aswer is incorrect. " ;
			cout << "Corrct answer is \" " << correct_answer[0] << " \"." << endl << endl;
		}

		correct_answer.clear();
	}
	cout << "		 --------------------------------------" << endl;
	cout << "		| Your final mark is "<< fixed << setprecision(2) << (count * 10 / ExsistingNoOfQuiz()) << " out of 10 . |" << endl;
	cout << "		 --------------------------------------" << endl;
}

// Clear File--------------------------------------------------------------------------------
void ClearFile() {
	ofstream file;
	file.open("MyQuestionPaper.txt");
	file << "";
}

// Main function-----------------------------------------------------------------------------
int main() {

	int option;
	double noofquestions;
	Quiz quiz;

	cout << " 1. Build a new Quiz  \n 2. Continue with existing Quiz \n 3. Add to existing Quiz \n Select your option : ";
	cin >> option;

	if (option == 1) {
		system("pause");
		system("cls");
		ClearFile();

		// ask required no of quiestion to build
		cout << " Enter the number of questions : ";
		cin >> noofquestions;
		cin.ignore();

		// call for MyQuiz function build questions
		for (int i = 0; i < noofquestions; i++) {
			MyQuiz(quiz);
		}

		// clear console
		system("pause");
		system("cls");

		// call for PrintQuiz function for print quiestions to console
		PrintQuiz();

	}

	else if (option == 2) {
		// clear console
		system("pause");
		system("cls");

		// call for PrintQuiz function for print quiestions to console
		PrintQuiz();
	}

	else if (option == 3) {
		system("pause");
		system("cls");
		fstream file;
		file.open("MyQuestionPaper.txt");

		cout << " Already you have " << ExsistingNoOfQuiz() << " quistions. \n How many questions do you want to add more :";
		cin >> noofquestions;
		cin.ignore();

		// call for MyQuiz function build questions
		for (int i = 1; i <= noofquestions; i++) {
			if (i == noofquestions ) {
				MyQuiz(quiz);
				//file << endl;
			}
			else {
				MyQuiz(quiz);
			}
			
		}

	
		// clear console
		system("pause");
		system("cls");


		// call for PrintQuiz function for print quiestions to console
		PrintQuiz();
	}

	else {
		cout << " Invalid input !!! " << endl;
	}
	

	return 0;
	
}