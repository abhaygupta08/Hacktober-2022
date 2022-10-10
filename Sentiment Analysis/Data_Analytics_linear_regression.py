#LAB To perform simple linear regression
# import all the lib
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('D:\PSIT\IT-3\Data Analytics\LAB\Salary_Data.csv')
x = data['YearsExperience']
y = data['Salary']

data.head()
data.info()
data.describe()

def linear_regression(x, y):     
    N = len(x)
    x_mean = x.mean()
    y_mean = y.mean()
    
    B1_num = ((x - x_mean) * (y - y_mean)).sum()
    B1_den = ((x - x_mean)**2).sum()
    B1 = B1_num / B1_den
    
    B0 = y_mean - (B1*x_mean)
    
    reg_line = 'y = {} + {}β'.format(B0, round(B1, 3))
    
    return (B0, B1, reg_line)

def corr_coef(x, y):
    N = len(x)    
    num = (N * (x*y).sum()) - (x.sum() * y.sum())
    den = np.sqrt((N * (x**2).sum() - x.sum()**2) * (N * (y**2).sum() - y.sum()**2))
    R = num / den
    return R

B0, B1, reg_line = linear_regression(x, y)
print('Regression Line: ', reg_line)
R = corr_coef(x, y)
print('Correlation Coef.: ', R)
print('"Goodness of Fit": ', R**2)

plt.figure(figsize=(12,5))
plt.scatter(x, y, s=300, linewidths=1, edgecolor='black')
text = '''X Mean: {} Years \nY Mean: ${} \nR: {} R^2: {} \ny = {} + {}X'''.format(round(x.mean(), 2), 
                       round(y.mean(), 2), 
                       round(R, 4), 
                       round(R**2, 4),
                       round(B0, 3),
                       round(B1, 3))
plt.text(x=1, y=100000, s=text, fontsize=12, bbox={'facecolor': 'grey', 'alpha': 0.2, 'pad': 10})
plt.title('How Experience Affects Salary')
plt.xlabel('Years of Experience', fontsize=15)
plt.ylabel('Salary', fontsize=15)
plt.plot(x, B0 + B1*x, c = 'r', linewidth=5, alpha=.5, solid_capstyle='round')
plt.scatter(x=x.mean(), y=y.mean(), marker='*', s=10**2.5, c='r') # average point

def predict(B0, B1, new_x):
    y = B0 + B1 * new_x
    return y
print("Salary at desired experience= $",round(predict(B0,B1, 20),2))












'''
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score,mean_squared_error

data = pd.read_csv('D:\PSIT\IT-3\Data Analytics\LAB\Salary_Data.csv')
data.head()
data.info()
data.describe()

plt.figure(figsize=(12,6))
sns.pairplot(data,x_vars=['YearsExperience'],y_vars=['Salary'],height=7,kind='scatter')
plt.xlabel('Years')
plt.ylabel('Salary')
plt.title('Salary Prediction')
plt.show()

X = data['YearsExperience']
X.head()

y = data['Salary']
y.head()

X_train,X_test,y_train,y_test = train_test_split(X,y,train_size=0.7,random_state=100)
# Create new axis for x column
X_train = X_train[:,np.newaxis]
X_test = X_test[:,np.newaxis]

lr = LinearRegression()
lr.fit(X_train,y_train)

# Predicting the Salary for the Test values
y_pred = lr.predict(X_test)

# Plotting the actual and predicted values

c = range(1,len(y_test)+1)
plt.plot(c,y_test,color='r',linestyle='-')
plt.plot(c,y_pred,color='b',linestyle='-')
plt.ylabel('Salary')
plt.xlabel('Experience')
plt.title('Prediction')
plt.show()

# calculate Mean square error
mse = mean_squared_error(y_test,y_pred)

# Calculate R square value
rsq = r2_score(y_test,y_pred)

print('mean squared error :',mse)
print('r square :',rsq)

# Intecept and coeff of the line
print('Intercept of the model:',lr.intercept_)
print('Coefficient of the line:',lr.coef_)

"""
Then it is said to form a line with
y = 25202.8 + 9731.2x
"""
'''
