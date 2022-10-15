print("Employee Salary Calcultion")
basic_pay=int(input("Enter the basic pay of the employee : "))
if(basic_pay<0):
    print("Invalid input")
else:
    HRA=0.10*basic_pay
    TA=0.05*basic_pay
    tax=0.02*basic_pay
    net_salary=basic_pay+HRA+TA-tax
    print("The net salary of an employee is = "," (HRA)",HRA,"+ (TA) ",TA,"- (tax) ",tax," = ",net_salary)