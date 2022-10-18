public class CakeNumberExample1  
{  
// a method that finds the value of b ^ e  
int pow(int b, int e)  
{  
// anything whose power is 0 is 1  
if(e == 0)  
{  
return 1;  
}  
  
// it will store the result  
int ans = 1;  
while(true)  
{  
  
if(e % 2 == 1)  
{  
e = e - 1;  
ans = ans * b;  
if(e == 0)  
{  
return ans;  
}  
}  
b = b * b;  
e = e / 2;  
}  
}  
public int findCakeNo(int n)  
{  
// finding n ^ 3  
int x = pow(n, 3);  
// finding 5 * n  
int y = 5 * n;  
// finding the cake number  
// computing (n ^ 3 + 5 * n + 6) / 6  
int no = (x + y + 6) / 6;  
return no;  
}  
// main method  
public static void main(String argvs[])  
{  
// creating an object of the class CakeNumberExample1  
CakeNumberExample1 obj = new CakeNumberExample1();  
System.out.println("The first 30 cake numbers are: ");  
for(int i = 0; i < 30; i++)  
{  
// invoking the method findCakeNo()  
int num = obj. findCakeNo(i);  
System.out.print(num + " ");  
}  
}  
}  
