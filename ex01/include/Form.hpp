#ifndef __FORM_H__
#define __FORM_H__

#include <string>

using std::string;

class Bureaucrat;

class Form {
 private:
  const string _name;
  const size_t _executionRequiredGrade;
  const size_t _signRequiredGrade;
  bool _isSigned;

  // Disabled Constructor
  Form();
  // Disabled Operators
  Form& operator=(const Form& assign);

 protected:
  // Methods
  void validateGradeInRange(int grade) const;

 public:
  enum FormGradeRange { HIGHEST_GRADE = 1, LOWEST_GRADE = 150 };
  // Constructors & Destructor
  Form(const string& name, int execGrade, int signGrade);
  Form(const Form& other);
  virtual ~Form();

  // Getters
  const string& getName() const;
  size_t getSignRequiredGrade() const;
  size_t getExecutionRequiredGrade() const;
  bool getIsSigned() const;

  // Methods
  void beSigned(const Bureaucrat& bureaucrat);

  // Exceptions
  class GradeTooHighException;
  class GradeTooLowException;
};

class Form::GradeTooHighException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
 public:
  virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif  // __FORM_H__
