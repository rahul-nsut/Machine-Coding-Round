// Machine Coding Round Prep-6

// Design of Online Examination System (Asked in Urban Company-R2)

// Can add getters,setters and constructors as per requirements

class ExamSystem{
    private:
        Candidate candidate;
        Invigilator invigilator;
        Teacher teacher;
        Exam exam;
        map<Candidate,int> candidateScores;
        map<Candidate,vector<string>> candidateResponses;
    public:
        bool registerForExam(Candidate candidate,Exam exam){
            // a candidate can register for the exam.
            if(notRegistered){
                return false;
            }
            exam.registeredStudents.push_back(candidate);
            return true;
        }
        void createQuestion(Question question, Teacher teacher){
            // to add all the details of question,as per needs
        }
        void createExam(Teacher teacher,Exam exam){
            // function where this exam will be created and all details will be update by teachers
        }
        void takeExam(Exam exam,Candidate candidate){
            // now candidate takes the exam.
            // we have considered the vector<string> stores all responses in order of questions, so no need 
            // to check for separately
            //update candidateResponses map
        }
        void checkExam(Exam exam,Teacher teacher){
            // check responses from the candidateResponse map
            // and accordingly, update the candidateScores map.
        }
        void showResult(){
            // will display the values of candidateScores map;
            for(auto i:candidateScores){
                cout<<i.first.name<<" "<<"has scored"<<i.second<<endl;
            }
        }
    
    
};

class Exam{
    private:
        Teacher teacher;
        vector<Candidate>registeredStudents;
        string startTime;
        string endTime;
        string subject;
        vector<Invigilator> invigilators;
        vector<Question>questionList;
    
    // can define getters & setters as per needed.
    
};

class Candidate{
    private:
        string name;
        int candidateKey;
        int mobileNumber;
        int age;
        bool isEligibile;  // to confirm the student is eligible for the test
};
class Invigilator{
    private:
        string name;
        int invigilatorId;
    
};
class Teacher{
    private:
        string name;
        int teacherId;
        string subjectTeaching;
}
class Question{
    private:
        int questionId;
        string questionText;
        int maximumMarks;
        vector<string>optionsText;  // to store what the options say..
        string correctOption;
    friend class ExamSystem;   // as we want that the teacher can access the correct option
};

int main() {
    
}