"""a = int(input("Enter a no to check: "))
if(a > 0):
    print(a, " is a positive no")
elif a == 0:
    print(a, " is equal to 0")
else:
    print(a, " is negative")

age = int(input("Enter your age "))
if age >= 18:
    print("You are eligible to vote")
else:
    print("You are not eligible to vote")

b = int(input("Enter a no to check even and odd "))
if b % 2 == 0:
    print(b, " is a even no")
else:
    print(b, " is not an even")

first = int(input("Enter first no "))
second = int(input("Enter second no "))
if(first > second):
    print(first, " is greater than ", second)
else:
    print(second, " is greater than ", first)
    
mul = int(input("Enter a no to check multiple of 5 or not "))
if mul % 5 == 0:
    print(mul , " is a multiple of 5")
else:
    print(mul , " is not a multiple of 5")
"""

mark = int(input("Enter your mark "))
if mark > 100:
    print("Invalid mark")
elif(mark >= 90):
    print("Grade A")
elif mark >= 75:
    print("Grade B")
elif mark >= 50:
    print("Grade C")
else:
    print("Fail")

# year = int(input("Enter the year "))

# if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0):
#     print(year , " is a leap year")
# else:
#     print(year, " is not a leap year")

# temp = int(input("Enter the temprature "))
# if temp < 0: 
#     print("freezing")
# elif temp <= 20:
#     print("Cold")
# elif temp <= 35:
#     print("Warm")
# else:
#     print("Hot")

a = int(input("Enter a no "))
if a > 0:
    if a % 2 == 0:
        print(a, " is positive even no")
    else:
        print(a, " is positive odd no")
else:
    if a % 2 == 0:
        print(a, " is negative even no")
    else:
        print(a, " is negative odd no")

pass1 = input("Enter the password: ")
if pass1 == "ABC":
    print("Access Granted")
else:
    print("Access Denied")

s1 = int(input("Enter first side of triangle: "))
s2 = int(input("Enter second side of triangle: "))
s3 = int(input("Enter third side of triangle: "))

if s1 + s2 > s3 and s2 + s3 > s1 and s1 + s3 > s2:
    print("This is a valid triangle")
else:
    print("Triangle is not valid")



mark1 = int(input("Enter the first subject "))
mark2 = int(input("Enter the first subject "))
mark3 = int(input("Enter the first subject "))

if mark1 >= 35 and mark2 >= 35 and mark3 >= 35:
    print("Passed")
else:
    print("Failed")


a = input("Enter the charector")
a= a.lower()
if(int(a) < 97 and int(a) > 123):
    print("No is not alphabet")
if a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u':
    print(a, " is a vowel")
else:
    print(a, " is not consonent")