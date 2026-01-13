# x = 10
# y = 20
# print("Number are equal", x == y)
# print("Number are greater", x > y)
# print("Number are Lesser", x < y)


# a = 435
# b = 5454
# c = 65

# if a < b and a < c:
#     print("Smallest no is: ", a)
# elif b < c:
#     print("Smallest no is: ", b)
# else:
#     print("Smallest no is: ", c)

# # a = int(input("Enter the no"))
# # print(a)

# no = float(input("Enter to student no "))
# if(no >= 40):
#     print("Student is passed with no: ", no )
# else:
#     print("Student is fail:", no)

# age = int(input("Enter your age "))
# if(age >=18):
#     print("Your are eligible to vote")
# else:
#     print("You are not eligible")

# no = int(input("Enter a no to check even or odd: "))
# if(no % 2 == 0):
#     print(no, " is even.")
# else:
#     print(no, " is odd.")

# word1 = input("Enter first word ")
# word2 = input("Enter another word ")
# if word1 == word2:
#     print("Words are equal")
# else:
#     print("Words are not equal")

# salary1 = int(input("Enter employee1 salary: "))
# salary2 = int(input("Enter employee2 salary: "))
# if(salary1 > salary2):
#     print("Employee 1 salary is greater")
# else:
#     print("Employee 2 salary is greater")


# x = int(input("Enter a no to check range: "))
# if x >= 10 and x <= 50:
#     print(no, " is given range")
# else:
#     print(no, " is not given range")

year = int(input("Enter the year "))

if year % 4 == 0:
    if(year % 400 == 0):
        print("Year is leap")
    else:
        print("Year is not leap")