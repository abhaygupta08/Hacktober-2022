import re
# just replace the file location in here with you file location
# also dont forget to add extra backslash where there is \ in the path
f = open(input("Input file path: "),"r")
# ex: C:\\Users\\User\\Desktop\\Example.py   or any type of file
all_text = f.read()
'''
possible phone number patterns
possible area codes  => ((\+\d{2,3})|\(\d{2,3}\)|\d{2,3})?
there can be separator or just '-' => (\s|-|\.)?
first 3 digits => (\d{2,4})?
there can be separator "-" => (\s|-|\.)
last remaining digits => \d{,8}
'''
phonePattern = re.compile(r'''(
    ((\+\d{2,3})|\(\d{2,3}\)|\d{2,3})?#area code
    (\s|-|\.)?# separator
    (\d{2,4})?# first 2-4 digits(generally 3 digits)
    (\s|-|\.)# any separator
    \d{,8}# last remaining digits
)''',re.VERBOSE)

numbers = phonePattern.findall(all_text)
if not numbers:
    print("No phone number found in the text given")
else:
    phoneNumbers = []
    for i in numbers:
        for j in i:
            if len(j)>9 and j != []:
                phoneNumbers.append(j)
    phoneNumbers = list(set(phoneNumbers)) #removes the duplicate values in the list
    print(phoneNumbers)

'''
email id pattern
<some name with numbers/letters/_/./<some extra characters>@<samerepeat>.<repeat>
<generally username/contact etc..>@<domain Name>.<end text>
[a-zA-Z0-9.]+ #username
@
[a-zA-Z0-9] #domain name
\.
[a-zA-Z0-9.]+ #the endings
'''

# [a-zA-Z0-9.]+@+[a-zA-Z0-9]+\.+[a-zA-Z0-9.]+
emailIdPattern = re.compile(r'''(
    [a-zA-Z0-9._-]+ #the username
    @ #@symbol
    [a-zA-Z0-9]+ #domain Names
    \.[a-zA-Z0-9.]+ #check for any extra extensions
)''', re.VERBOSE)

iDs = emailIdPattern.findall(all_text)
if not iDs:
    print("No email ID's Found")
else:
    iDs = list(set(iDs)) #removes the duplicate values in the list
    print(iDs)