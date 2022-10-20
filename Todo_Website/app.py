from datetime import datetime
from turtle import title
from flask import Flask,render_template,request,redirect
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app=Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI']="sqlite:///todo.db"
app.config['SQLALCHEMY_TRACK_MODIFICATIONS']=False
db=SQLAlchemy(app)

class Todo(db.Model):
    sno=db.Column(db.Integer,primary_key=True)
    title=db.Column(db.String(200),nullable=False)
    desc=db.Column(db.String(400),nullable=True)
    date_created=db.Column(db.DateTime,default=datetime.utcnow)

    def __repr__(self) -> str:
        return f"{self.sno}- {self.title}"

@app.route('/',methods=['GET','POST'])
def hello_world():
    if request.method=='POST':
        print("posted")
        print(request.form['title'])
        todo=Todo(title=request.form['title'],desc=request.form['desc'])
        db.session.add(todo)
        db.session.commit()

    # todo=Todo(title="First todo",desc="START IT")
    # db.session.add(todo)
    # db.session.commit()
    allTodo=Todo.query.all()
    print(allTodo)
    return render_template('index.html',allTodo=allTodo)
    # return 'Hello world'
@app.route('/show')
def name():
    allTodo=Todo.query.all()
    print(allTodo)
    return "this is hsow"


@app.route('/delete/<int:sno>')
def delete(sno):
    todo=Todo.query.filter_by(sno=sno).first()
    db.session.delete(todo)
    db.session.commit()
    return redirect('/')


@app.route('/update/<int:sno>',methods=['GET','POST'])
def update(sno):
    if request.method=='POST':
        title=request.form['title']
        desc=request.form['desc']
        todo=Todo.query.filter_by(sno=sno).first()
        todo.title=title
        todo.desc=desc
        db.session.add(todo)
        db.session.commit()
        return redirect('/')


    todo=Todo.query.filter_by(sno=sno).first()
    return render_template('update.html',todo=todo)




# @app.route('/name')
# def name():
#     return 'Vaishnavi tripathi'
if __name__=="__main__":
    app.run(debug=True)
     
