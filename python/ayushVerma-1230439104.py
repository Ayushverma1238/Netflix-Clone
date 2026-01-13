# Program 1
print()

salary = float(input("Enter your salary: "))
if salary < 30000:
    print("You got 20 percent increment in your salary and your current salary is: ", (salary/100) * 120)
elif salary < 60000:
    print("You got 10 percent increment in your salary and your current salary is: ", (salary/100) * 110)
else:
    print("Your salary is greater than 60000 so you don't get salary increment")

# Program 2
print()
a = int(input("Enter a no: "))
if a % 3 == 0 and a % 4 == 0:
    print(a, " is divisible by both 3 and 4")
elif a % 3 == 0:
    print(a, " is divisible by 3")
elif a % 4 == 0:
    print(a, " is divisible by 4")
else:
    print(a, " is not divisible by any of the number 3 or 4")

# Program 3
print()
bill = float(input("Enter your bill: "))
memberType = input("Enter your payment option or member type ")

if bill > 5000 and memberType == "card":
    print("You got 15 percent discount your final bill: ", (bill/100) * 85)
elif bill > 5000 and memberType == "premium":
    print("You got 10 percent discount and final bill is: ", (bill/100) * 90)
else:
    print("You have no discount")

# Program 4
print()
a = int(input("Enter a number to check range: "))
if a%2 == 0 and a >=50 and a <= 100:
    print(a , " is a even no and it is under the range of 50 to 100.")
elif a % 2 != 0 and a > 100:
    print(a, " is an odd no and greater than 100.")
else:
    print(a, " is invalid category")

# Program 5
print()
x = int(input("Enter a no: "))
x += 10
x *=2
x -=5
print("Final value of x after performing the operation is: ", x)

# Program 6
print()
a = 10
b = 20
c= 30
if a < b and b < c:
    print(a," ",b, " ", c, " are increasing")
else:
    print(a," ",b, " ", c, " are not increasing")

# Program 7
print()
username = input("Enter your username: ")
password = input("Enter your password: ")
attempt = int(input("Enter your attemption: "))
if username == "admin" and len(password) >=6 and attempt < 3:
    print("Access Granted")
else:
    print("Access Denied")

# Program 8
print()
a = int(input("Enter the value of a: "))
b = int(input("Enter the value of b: "))
c = int(input("Enter the value of c: "))
print(((a+b)**2) > (a**2 + b**2 + c))

# Program 9
print()
a = int(input("Enter a no: "))
if a % 2 == 0 and a % 5 == 0:
    print(a, " is divisible by both 2 and 5")
elif a % 2 == 0:
    print(a, " is divisible by 3")
elif a % 5 == 0:
    print(a, " is divisible by 5")
else:
    print(a, " is not divisible by any of the number 2 or 5")

# Program 1
# print()0

salary = float(input("Enter your salary in Lakh: "))
if salary <= 2.5:
    print("You are not in tax range your tax amount is: ", salary*0, "l and net amount is ", salary, "L")
elif salary <= 5:
    print("You got 5 percent tax your tax amount is: ", (salary/100)*5, "l and net amount is ", (salary/100) * 105, "L")
elif salary <10:
    print("You got 10 percent tax your tax amount is: ", (salary/100)*10, "l and net amount is ", (salary/100) * 110, "L")
else:
    print("You got 20 percent tax your tax amount is: ", (salary/100)*20, "l and net amount is ", (salary/100) * 120, "L")


#  Program 1
# print()1
mark = int(input("Enter your mark "))
if mark > 100:
    print("Invalid mark")
elif(mark >= 90):
    print("Excellent!, Grade A")
elif mark >= 75:
    print("Grade B")
elif mark >= 60:
    print("Grade C")
else:
    print("Fail")

# Program 1
# print()2
units = int(input("Enter your units: "))
netBill = 0.0;
if units > 100:
    netBill += 100 * 5
    if(units > 200):
        netBill += 100 * 7
        if units >= 201:
            netBill += (units - 200) * 10
    else:
        netBill += (units - 100) * 7
else:
    netBill += units * 5

print("After calculating all slab your final bill is: ", netBill)

# Program 1
# print()3
balance= 1000
amount = int(input("Enter the amount that you want to withdrawl: "))
if amount % 100 == 0 and amount <= balance and (balance - amount) >= 500:
    print(amount, " withdrawl successfull current amount in your account is: ", balance - amount)
elif amount % 100 != 0:
    print(amount, " amount is not a multiple of 100")
elif (balance -amount) < 500:
    print("Cannot withdrawl because money is less then 500")
else:
    print("Insufficient balance")

# Program 1
# print()4
day = int(input("Enter the weak day "))
if day == 6 or day == 7:
    print("Weekend Day")
elif day > 0 and day < 6:
    print("Weekday")
else:
    print("Invalid Day")

# program 1
# print()5
a = int(input("Enter first no: "))
b = int(input("Enter second no: "))
c = input("Enter the operater that you want to perform: ")
if c=="+":
    print("Sum is: ", a + b)
elif c == "-":
    print("Subtraction is: ", a-b)
elif c == "*":
    print("Multiplication is: ", a * b)
elif c == "/":
    print("Division is: ", a/b)
else:
    print("Invalid operator choosen")

# Program 1
# print()6
age = int(input("Enter your age: "))
salary = float(input("Enter your salary: "))
his = input("Enter your medical history: ")
if age >= 25:
    if salary >= 40000:
        if his == "clear":
            print("Eligible for insurance")
        else:
            print("You are not eligible 25 for insurance because medical history is not clear.")
    else:
        print("You are not eligible 25 for insurance because salary less than 40000.")
else:
    print("You are not eligible 25 for insurance because age is less then.")

# Program 1
# print()7
color = input("Enter the traffix signal color: ")
if color == "Red":
    print("Stop")
elif color == "Yellow":
    print("Ready")
elif color == "Green":
    print("Go")
else:
    print("Invalid light signal")

# Program 1
# print()8
s1 = int(input("Enter the length of first side of triangle: "))
s2 = int(input("Enter the length of second side of triangle: "))
s3 = int(input("Enter the length of third side of triangle: "))
if s1 + s2 > s3 or s1 + s3 > s2 or s2 + s3 > s1:
    if s1 == s2 and s2 == s3:
        print("Equilateral triangle because side are equal")
    elif (s1 == s2 and s2 != s3) or (s1 == s3 and s3 != s2) or (s2 == s3 and s3 != s1):
        print("Isosceles triangle because any two side are equal")
    else:
        print("Scalene Triangle because all side is not equal")
else:
    print("Invalid triangle")

# Program 1
# print()9
mark = int(input("Enter your mark: "))
for i in range(2):
    if(mark > 40):
        break;
    else:
        mark = int(input("R- attempt Enter your mark: "))
if mark > 40:
    print("You are passed.")
else:
    print("You dont have more attempt")

# Program 2
# print()0
password = input("Enter the password: ")

if len(password) >= 8 and (any(ch.isdigit() for ch in password)) and (any(ch.isupper() for ch in password)):
    print(password, " is Strong")
else:
    print(password, " is Weak")
