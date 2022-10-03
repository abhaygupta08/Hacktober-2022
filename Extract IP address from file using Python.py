
# importing the module
import re
  
# opening and reading the file 
with open('C:/Users/user/Desktop/New Text Document.txt') as fh:
   fstring = fh.readlines()
  
# declaring the regex pattern for IP addresses
pattern = re.compile(r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})')
  
# initializing the list object
lst=[]
  
# extracting the IP addresses
for line in fstring:
   lst.append(pattern.search(line)[0])
  
# displaying the extracted IP addresses
print(lst)



#New Text Document.txt
#000.0000.00.00
#192.168.1.1
#912.456.123.123
#192.168.4.164
#69.168.4.226
#32.89.31.164
#67.168.3.227
