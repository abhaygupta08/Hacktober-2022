
from flask import Flask,render_template,request,flash,redirect
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager

app=Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI']='sqlite:///mydb.db'
app.config['SECRET_KEY']='thisissecret'
db=SQLAlchemy(app)
login_manager=LoginManager
login_manager.init_app(app)

class User(db.Model):
    id=db.Column(db.Integer,primary_key=True)
    username=db.Column(db.String(80),unique=True,nullable=False)
    email=db.Column(db.String(120),unique=True,nullable=False)
    fname=db.Column(db.String(120),nullable=False)
    lname=db.Column(db.String(120),nullable=False)
    password=db.Column(db.String(120),nullable=False)
    def __repr__(self):
        return '<User %r>' %self.username

@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(id))


@app.route("/")
def index():
    return render_template("index.html")



@app.route('/main')
def main():
    return render_template("main.html")



@app.route('/register',methods=['GET','POST'])
def register():
    if request.method=='POST':
        email=request.form.get('email')
        password=request.form.get('password')
        firstname=request.form.get('firstname')
        lastname=request.form.get('lastname')
        username=request.form.get('username')
        # print(email,lastname)
        user=User(email=email,password=password,fname=firstname,lname=lastname,username=username)
        db.session.add(user)
        db.session.commit()
        flash('user has been registered successfully','success')
        return redirect('/login')



    
    return render_template("register.html")

@app.route('/login',methods=['GET','POST'])
def login():
    if request.method=='POST':
        username=request.form.get('username')
        password=request.form.get('password')

    return render_template("login.html")   
if __name__=="__main__":
    app.run(debug=True)