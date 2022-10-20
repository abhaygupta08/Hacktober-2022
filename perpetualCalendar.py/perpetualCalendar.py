# Author: Luzia Thomas
# Description: This program is a perpetual calender that allows the user to input a date, and then calculates fun facts about the date, like what day of the week it fell on, and what day of the week Thanksgiving fell on that specific year.


# This function tells whether or not a year is a leap year.
# Parameters: Year, which is the year value
# Returns: Returns True if the year is a leap year, and False if it is not.
def is_leap(year):
    if year % 4 == 0 and year % 100 != 0:
        return True
    elif year % 100 == 0 and year % 400 == 0:
        return True
    else:
        return False

    
# This is a helper function that gives each month a numeric value based on the number of days that have past by it's first date. 
# Parameters: Month is the 1-12 month value
# Returns: The number of days that have gone by in a year on the first of any month (assuming it's not a leap year)  
def magic_month(month):
    if month == 1:
        return 0
    elif month == 2:
        return 31
    elif month == 3:
        return 59
    elif month == 4:
        return 90 
    elif month == 5:
        return 120
    elif month == 6:
        return 151
    elif month == 7:
        return 181
    elif month == 8:
        return 212
    elif month == 9:
        return 243
    elif month == 10:
        return 273
    elif month == 11:
        return 304 
    elif month == 12:
        return 334
    else:
        return("Error")
    

#This function tells what day of the year any given date is on. 
#Parameters: Month is the 1-12 month value, day is the day value, year is the year value
#Returns: The day of year (1-366) that the date occurs on
def day_of_year(month, day, year):
    leap_test = is_leap(year)
    month_value = magic_month(month)
    if leap_test and month >= 3:
        final_day_of_year = (month_value + day) + 1
    else:
        final_day_of_year = month_value + day
    return final_day_of_year
    

#This function calculates the day of the week number for any January 1 in history
#Parameters: Year is the year 
#Returns: An integer (0-6) that corresponds to a day of the week 
def new_years_day(year):
    new_years_calc = (year + (year // 4)) - (year // 100) + (year // 400) 
    if is_leap(year):
        new_years_calc -= 1
    new_years_day_num = new_years_calc % 7 
    return new_years_day_num
    
    
#This function computes the day of the week for any day of any year
#Parameters: Month is the 1-12 month value, day is the 1-31 day value, year is the year value
#Returns: The numeric day of week value (0-6) for a specific date
def day_of_week(month, day, year):
    day_calc = day_of_year(month, day, year)
    new_years_calc = new_years_day(year)
    final_day_of_the_week = ((day_calc + new_years_calc) - 1) % 7 
    return final_day_of_the_week


#This function takes the numeric day_of_week value and translates it into the actual name for that day of the week
#Parameters: Month is the 1-12 month value, day is the 1-31 day value, year is the year value
#Returns: The name for the numeric day of the week calculated in the day_of_week function
def day_of_week_str(month, day, year):
    day_calc = day_of_week(month, day, year)
    if day_calc == 0:
        return("Sunday")
    elif day_calc == 1:
        return("Monday")
    elif day_calc == 2:
        return("Tuesday")
    elif day_calc == 3:
        return("Wednesday")
    elif day_calc == 4:
        return("Thursday")
    elif day_calc == 5:
        return("Friday")
    elif day_calc == 6:
        return("Saturday")
    

#This function tells the day of November that Thanksgiving falls on in a given year by calculating what day of the week November 1st was
#Parameters: Year, the year as an integer
#Returns: The day of the month (1-31) that Thanksgiving falls on
def find_thanksgiving(year):
    nov_first = day_of_week(11, 1, year)
    if nov_first == 0:
        thanksgiving = 26
    elif nov_first == 1:
        thanksgiving = 25
    elif nov_first == 2: 
        thanksgiving = 24                           
    elif nov_first == 3: 
        thanksgiving = 23
    elif nov_first == 4:
        thanksgiving = 22
    elif nov_first == 5:
        thanksgiving = 28
    else: 
        thanksgiving = 27
    return thanksgiving 
  
    
#This function asks the user if they want to run the program again after completing the first run through
def again():
    ask = input("Would you like to try this program with another date? Yes or No? ")
    if ask == "Yes" or ask == "yes":
        main()
    elif ask == "No" or ask == "no":
        print("Goodbye!")
    else:
        print("Please run this program again, and enter either 'yes' or 'no'")

        
def main():
    print("Pick a date! It can be any date, like your birthday, Christmas, or New Year's Day!")
    month = int(input("What is the month? Enter its number (1-12): "))
    day = int(input("What is the day: "))
    year = int(input("What is the year: "))
    day_number = day_of_year(month, day, year)
    print("This is day number ", day_number, " of ", year, ".", sep='')
    day_name = day_of_week_str(month, day, year)
    print("This date falls on a ", day_name, ".", sep='')
    name_in_2020 = day_of_week_str(month, day, 2020)
    print("In 2020, this date falls on a ", name_in_2020, ".", sep='')
    specific_ny = day_of_week_str(1, 1, year)
    print("In ", year, ", New Year's Day falls on a ", specific_ny, ".", sep='')
    specific_thanks = find_thanksgiving(year)
    print("In ", year, ", Thanksgiving falls on November ", specific_thanks, ".", sep='')
    print()
    again()                              
    
    
main()