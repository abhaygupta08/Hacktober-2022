from tkinter import *
from tkinter import ttk
from tkinter import filedialog
from tkinter import messagebox
import pandas as pd
import numpy as np
import random
import ast
from sklearn.svm import SVC
import os
from threading import Thread
import time

# os.chdir("D:\COLLEGE CLASSES\project\em2")
# os.chdir("D:\\COLLEGE CLASSES\\temp")
# GLOBAL VARIABLES
email_frames_LF2_dict = {}
all_pages_dict = {}
email_files_dict = {}
obj_dict={}
flag=0
screen_geometry = []

all_page_names = ["p1", "p2", "p3", "p4"]
email_frame_names = ["All emails", "Ham emails", "Spam emails", "Stared emails", "Trash emails", ]
# page_names=["ALL EMAILS", "PRIMARY EMAILS", "SOCIAL EMAILS", "Promotion emails", "Good emails","Spam emails", "Trash emails"]
colours = ["white", "pink", "light green", "SeaGreen", "orange", "Mediumpurple1", "yellow", "gold", "grey", "snow3",
           "SteelBlue",
           "cyan", "salmon", "sandy brown"]
bgclr_f1 = "light green"
bgclr_f2 = "light gray"
bgclr_pag3 = "SeaGreen"
bgclr_bf1 = "light goldenrod"


class basic_structure(Tk):
    def __init__(self):
        super().__init__()

        self.w = self.winfo_screenwidth()
        self.h = self.winfo_screenheight()
        self.geometry(f"{self.w}x{self.h}")
        screen_geometry.append(self.w)
        screen_geometry.append(self.h)
        self.title("Email Classifier")

        container = Frame(self)
        container.pack(side="top", fill="both", expand=True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        for F in all_page_names:
            p = Frame(container, )
            p.grid(row=0, column=0, sticky="nsew")
            all_pages_dict.update({F: p})

        # all_pages_dict["p1"].tkraise()

class page1(Thread):
    # def __init__(self):
    def run(self):
        frame = all_pages_dict["p1"]
        v="green"
        b="WHITE"
        frame.config(bg=v)
        global pi2
        l2 = Label(frame, image=pi2, )
        l2.pack(side="top", pady=20)
        l = Label(frame,bd=5, text="WELCOME  OPENING", font="comicsansns 50 bold", fg=b, bg=v)        # l.pack()
        # l.place(x=460, y=440)
        l.pack()
        l2 = Label(frame, text="PLEASE  WAIT...", font="comicsansns 50 bold", fg=b, bg=v)  # l.pack()
        # l.place(x=500, y=580)
        l2.pack()
        frame.tkraise()
        def task():
            time.sleep(4)
            # frame.destroy()
            all_pages_dict["p1"].destroy()
            all_pages_dict["p2"].tkraise()
        frame.after(2000, task)
        return

class ML_model:
    def __init__(self):#,p2):
        Thread(target=self.init).start()

    def init(self):
        self.svm = SVC()

        # ----reading vocabulary from saved data--
        file = open("vocabulary2.txt", "r")
        content = file.read()
        file.close()
        self.vocabulary = ast.literal_eval(content)

        # ---reading training data for naive probability classifier,from saved data AND traing naive with that
        xytrain_naive = np.load("XYtrain_naive.npy", )
        self._fit_naivebayes(xytrain_naive)

        # ---reading TRAINING data for SVM MODEL form SAVED data and training svm with that
        Xtrain_svm = np.load("Xtrain_svm_.npy")
        Ytrain_svm = np.load("ytrain_svm_.npy")
        self.svm.fit(Xtrain_svm, Ytrain_svm)

    def vector(self, x):
        vocabulary = self.vocabulary
        j = 0
        for i in x:
            j = j + 1
        vec = np.zeros((j, len(vocabulary)))
        # for i in range(len(vocabulary)):

        for item in range(j):
            word_list = re.findall(r'\w+', x[item])

            for word in word_list:
                word = word.lower()
                if word in vocabulary:
                    vec[item, vocabulary[
                        word]] += 1  # if word is present then 1 otherwise 0 --OR --do count frequency of word occur.
        return vec

    def _fit_naivebayes(self, x):
        vocabulary = self.vocabulary  # making local vocabulary for fn, from vocabulary read in inint method
        # counting total words in spam and ham
        wsum_ham = 0
        wsum_spam = 0
        for i in range(len(vocabulary)):
            wsum_ham += x[1, i]
            wsum_spam += x[0, i]
        total_words_trainig_data = wsum_ham + wsum_spam

        # ----calculating probability spam and ham
        self.p_spam = wsum_spam / total_words_trainig_data
        self.p_ham = wsum_ham / total_words_trainig_data

        # array contains probability of each word wi
        self.p_wi = np.zeros((1, len(vocabulary)))

        # array contains probability of p(wi/ci) c=category
        self.p_cc = np.zeros((2, len(vocabulary)))

        # smothing factor
        alpha = 0.0000001
        n_voc = len(vocabulary)
        for i in range(len(vocabulary)):
            # prob of wi
            total_wi = x[0, i] + x[1, i] + 1
            # pb=float(total_wi/total_words_trainig_data)
            pb = (total_wi / total_words_trainig_data)
            self.p_wi[0, i] = pb

            # prob of p(wi/ci)
            pb1 = (x[0, i] + alpha) / (wsum_spam + alpha * n_voc)
            pb2 = (x[1, i] + alpha) / (wsum_ham + alpha * n_voc)

            self.p_cc[0, i] = pb1
            self.p_cc[1, i] = pb2
        self.w_ham = wsum_ham
        self.w_spam = wsum_spam

    def _predict_vectorized_BYnaive(self, x_test):  # standard wala ,xtest is vector data counting of words
        vectorized_data = np.zeros((x_test.shape[0], 2))

        for j in range(x_test.shape[0]):
            prbs = 0
            prbh = 0
            for i in range(len(self.vocabulary)):
                if x_test[j, i] == 0:
                    pass
                else:
                    prbs += (np.log(self.p_cc[0, i]) + np.log(x_test[j, i]))

                    prbh += (np.log(self.p_cc[1, i]) + np.log(x_test[j, i]))

            p_sum_spam = prbs + np.log(self.p_spam)
            p_sum_ham = prbh + np.log(self.p_ham)

            # -----creating vectorized data for SVM
            vectorized_data[j, 0] = p_sum_spam
            vectorized_data[j, 1] = p_sum_ham
        return vectorized_data

    def predict_emails(self, new_emails):  # takes raw emails as list, return 1d array of emboolen values 1=spam, 0=ham
        # vectorizing emails----counting each word occurance
        vec_emails = self.vector(new_emails)
        # vectorizing using naive bayes----calculating probabilities--for svm model
        vectorized_emails = self._predict_vectorized_BYnaive(
            vec_emails)  # this gives data that is to be used to train svm
        # ---classifiying baesd on probabilities using SVM-----
        res = self.svm.predict(vectorized_emails)
        return res


def event_in_out(wid, clr):
    wid.bind('<Leave>', lambda e: e.widget.config(bg=clr))
    wid.bind('<Enter>', lambda e: e.widget.config(bg="light blue"))

class page2_mainpage:
    def __init__(self, p3,ml):  # ml):
        obj_dict.update({"p2":self})
        self.obj_p3 = p3
        self.ml_obj=ml

        # 1--------LF1--------------------
        w1 = LabelFrame(all_pages_dict["p2"], width=150, bg="red")
        w1.pack(fill="both", side=LEFT, padx=10, pady=10)

        c = Canvas(w1, width=150, borderwidth=0, highlightthickness=0)
        c.pack(side=LEFT, fill=BOTH, expand="yes")
        # c.bind('<Configure>', lambda e: c.configure(scrollregion=c.bbox('all')))

        f = Frame(c, bg=bgclr_f1, )
        c.create_window((0, 0), anchor="nw", window=f, width=150, height=screen_geometry[1])
        self.lf1 = f

        # 2----------LF2-----------------------------------------------
        w2 = LabelFrame(all_pages_dict["p2"], width=200)
        w2.pack(fill=BOTH, expand=1, padx=10, pady=10)

        c = Canvas(w2, borderwidth=0, highlightthickness=0, bg=bgclr_f2)
        c.pack(side=LEFT, fill=BOTH, expand="yes")

        vs = ttk.Scrollbar(w2, orient=VERTICAL, command=c.yview)
        vs.pack(side=RIGHT, fill=Y)

        c.configure(yscrollcommand=vs.set)
        self.lf2canvas=c
        f1 = Frame(c, bd=0, bg=bgclr_f2)
        c.create_window((0, 0), anchor="nw", window=f1, width=screen_geometry[0] - 215, )  # height=5000)
        def onframeconfigure(canvas):
            canvas.configure(scrollregion=canvas.bbox("all"))
        f1.bind("<Configure>",lambda event,canvas=c:onframeconfigure(canvas))
        self.lf2 = f1

        # 3------------creating emails frame in LF2---------------
        # def create_email_frames_in_lf2(self):
        container = Frame(self.lf2)
        container.pack(side="top", fill="both", expand=True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)
        self.container_lf2 = container
        # frames={}
        i = 0;
        for F in email_frame_names:
            f = Frame(container, bg=bgclr_f2)
            f.grid(row=0, column=0, sticky="nsew")

            Label(f, text=F, fg="red", bg=bgclr_f2, font=2).grid(row=0, column=0, sticky=W,
                                                                 padx=10)  # place(x=0,y=0)#grid(row=0,column=0)
            email_frames_LF2_dict.update({F: f})
            i = i + 1
        email_frames_LF2_dict[email_frame_names[0]].tkraise()
        # return  frames

    def yes(self):
        print("yes it is working")

    def add_new_emails(self):
        # __________reading new emails from files______________
        global flag
        if  flag==0:
            messagebox.showinfo("INFORMATION","You can select 2 types of files only. one is of 'TXT' type , in which "
                                "emails must be seperated by  '***###/n/n'  . 2nd is 'csv' type file having only 1 column for emails"   )
            flag+=1
        file_name = filedialog.askopenfilename()
        print(file_name)
        if len(file_name)!=0:
            email_lis=[]
            if ".csv" in file_name:
                try:
                    ds1 = pd.read_csv(file_name)
                except:
                    messagebox.showerror("FILE ERROR", " ACCEPT ONLY 'csv' or 'txt' FILE,  ALL NEW EMAILS TO BE ADDED MUST BE IN THE 'csv' or 'txt'FILE ")
                    # messagebox.showerror("FILE ERROR", " ACCEPT ONLY 'CSV' FILE,  ALL NEW EMAILS TO BE ADDED MUST BE IN THE 'CSV' FILE ")
                    return
                r,c=ds1.shape
                if c==1:
                    for i in range(r):
                        email_lis.append(ds1.iloc[i, 0])
                    Thread(target=self.call_predict,args=(email_lis,)).start()
                else:
                    messagebox.showerror("ERROR","csv file must have only one column of emails")
            #------txt file-------------------
            elif ".txt" in file_name:
                try:
                    new_emails = open(file_name, "r")
                except:
                    messagebox.showerror("FILE ERROR", " ACCEPT ONLY 'csv' or 'txt' FILE,  ALL NEW EMAILS TO BE ADDED MUST BE IN THE 'csv' or 'txt'FILE ")
                    return
                email_lis2 = new_emails.read().split("***###\n\n")
                email_lis2.pop()
                new_emails.close()
                #-----calling ml algo to predict emails-----------
                # self.call_predict(email_lis2)
                Thread(target=self.call_predict, args=(email_lis2,)).start()
            else:
                messagebox.showerror("FILE ERROR",
                                     " ACCEPT ONLY 'csv' or 'txt' FILE,  ALL NEW EMAILS TO BE ADDED MUST BE IN THE 'csv' or 'txt'FILE ")

    def call_predict(self,email_list):
        res=self.ml_obj.predict_emails(email_list)
        count = 0
        for item in email_list:
            self.write_email("All emails", item)
            if res[count] == 0.0:
                self.write_email("Ham emails", item)
            if res[count]==1.0:
                self.write_email("Spam emails", item)
            count += 1
        self.replace("All emails")
        self.replace("Ham emails")
        self.replace("Spam emails")

    # 4------------------
    def label_frame1_content(self):
        l = Label(self.lf1, text="ALL  LABELS", font=(",5,bold"), bg=bgclr_f1)
        l.grid(row=0, column=0, pady=15, padx=15, sticky=W)

        pad = 15;
        pad_x = 15;
        bl = bgclr_bf1
        row_no = 2

        self.lf1_buttons = {}
        for F in email_frame_names:
            f = email_frames_LF2_dict[F]
            b = Button(self.lf1, text=F, bg=bl, command=lambda wid=f: wid.tkraise())
            b.grid(row=row_no, column=0, pady=pad, padx=pad_x, sticky=W)
            event_in_out(b, bl)
            self.lf1_buttons.update({F: b})
            row_no = row_no + 1

        b1 = Button(self.lf1, text="EXIT", bg=bl, command=self.exit_fun)
        b1.place(x=10, y=600)
        event_in_out(b1, bl)

        b2 = Button(self.lf1, text="Add emails", bg=bl,command=self.add_new_emails)
        b2.place(x=10, y=450)
        event_in_out(b2, bl)

        b3 = Button(self.lf1, text="write emails", bg=bl,command=lambda:all_pages_dict["p4"].tkraise())
        b3.place(x=10, y=500)
        event_in_out(b3, bl)
    def exit_fun(self):
        for F in email_frame_names:  # this writes emails in their respective pages..... but before this al file must have their data
            f=email_files_dict[F]
            f.close()
            exit()
    def replace(self, frame_name):
        email_frames_LF2_dict[frame_name].destroy()  # destroying existing 'stared eamils' frame
        del email_frames_LF2_dict[frame_name]  # deleting same from dict of all frames

        f = Frame(self.container_lf2, bg=bgclr_f2)  # creating new frame in same 'container' of deleted frame
        f.grid(row=0, column=0, sticky="nsew")
        Label(f, text=frame_name, fg="red", bg=bgclr_f2, font=2).grid(row=0, column=0, sticky=W,
                                                                      padx=10)  # place(x=0,y=0)#grid(row=0,column=0)

        self.lf1_buttons[frame_name].config(command=lambda
            fr=f: fr.tkraise())  # updating button of lf1, so that 'stared emails' button in lf2 on pressing open newly created 'stared emails' frame not earlier wchich is deleted  .

        email_frames_LF2_dict.update({
                                         frame_name: f})  # after destroying stared eamils frame,new frame created so updating that in dict of all frames    .
        self.label_frame2_content(email_frames_LF2_dict[frame_name], email_files_dict[frame_name])  # writing all emails of frash file in newly created 'stared emails'frame   .
        # frame.tkraise()  # raising the frame passed in argument of function or frame from where email hs been stared
        email_frames_LF2_dict["All emails"].tkraise()
    def del_email(self, file, email):
        file.seek(0)
        email_list = file.read().split("***###\n\n")
        file.seek(0)
        file.truncate()
        for item in email_list:
            if len(item) <= 10:
                break
            if item != email:
                file.write(item)
                file.write("***###\n\n")
        file.seek(0)

    def write_email(self, frame_name, email):
        email_files_dict[frame_name].seek(0,1)
        email_files_dict[frame_name].write(email)
        email_files_dict[frame_name].write("***###\n\n")
        email_files_dict[frame_name].seek(0,0)

    # 8-----------
    def label_frame2_content(self, frame, file, **kwargs):

        def cir(char, fr):
            x = 20;
            y = 23;
            r = 20
            n = random.randint(0, 12)

            c = Canvas(fr, width=45, height=45, bg=bgclr_f2, borderwidth=0,
                       highlightthickness=0)  # generate random colours
            c.place(x=20, y=zl)
            c.bind('<Button- 1>', lambda event, email=item: self.obj_p3.raise_frame(event, email))
            event_in_out(c, bgclr_f2)

            c.create_oval(x - r, y - r, x + r, y + r, width=1, fill=colours[n])
            c.create_text(x, y, text=char, font="comicsansns 20 bold")

        def star(star_email, fr):
            def change(event, wid):
                i = wid["background"]  # this gives background colour of widget wid.here wid is star
                if (i == "white"):
                    wid.config(bg="yellow")
                    self.write_email("Stared emails", star_email)
                    # -----updating stared frame---------------------------------------------------------------------------
                    self.replace("Stared emails")
                    frame.tkraise()  # raising the frame passed in argument of function or frame from where email hs been stared

                else:
                    wid.config(bg="white")
                    # -------deleting UNSTARED email from STARED file---------
                    self.del_email(email_files_dict["Stared emails"], star_email)
                    # ----------calling replace to update frame-------------
                    self.replace("Stared emails")
                    frame.tkraise()  # raising the frame passed in argument of function or frame from where email hs been stared

            c = Canvas(fr, bg="white", height=41, width=41)#,bd=0 borderwidth=0, highlightthickness=0)
            c.place(x=750, y=zl)
            c.bind('<Button- 1>', lambda event, wid=c: change(event, wid))
            # event_in_out(c,bgclr_f2)
            w = 2
            col = "black"
            c.create_line(20, 3, 40, 30, width=w, fill=col)
            c.create_line(20, 3, 3, 30, width=w, fill=col)
            c.create_line(3, 30, 40, 30, width=w, fill=col)

            c.create_line(3, 10, 40, 10, width=w, fill=col)
            c.create_line(3, 10, 20, 40, width=w, fill=col)
            c.create_line(40, 10, 20, 40, width=w, fill=col)
            c.create_text(21, 20, text="star", fill="red")

        # --------0 reading splitting all emails from file and listinh them------------
        file.seek(0,0)
        email_list = file.read().split("***###\n\n")
        z = 1;
        zl = 20
        for item in email_list:

            # ------2 break outermost loop if eamil in file has end up---------------
            if len(item) <=3:
                break;

            # -----1 creating smaller frame to fit circle, label ,star, button--------------------
            fr = Frame(frame, height=90, width=1100, bg=bgclr_f2)
            fr.grid(row=z, column=0, pady=10)
            z = z + 1


            # ------3 getting first character of email---------------
            char = 'l'
            for i in item:
                if (i) != ' ':
                    char = i.upper();
                    break;

            # ------------4 creates circle with first letter of email--------
            cir(char, fr)

            # ------------5 create star option for emails---------------
            if frame != email_frames_LF2_dict["Stared emails"]:  # or frame!=self.page_frames_inlf2["Trash emails"]:
                star(item, fr)

            # ------------6 making label for emails------------------------------------------------------------
            tex=item[0:0+60]
            # if all are captial letters then make the smaller
            tex=tex.lower()
            tex = tex + " ..."
            l = Label(fr, text=tex, font=("arial 15 bold"), bg=bgclr_f2)
            l.place(x=80, y=zl + 5)
            l.bind('<Button- 1>', lambda event, email=item: self.obj_p3.raise_frame(event, email))
            event_in_out(l, bgclr_f2)

            # ----------7 delete button for emails--------------------------------------
            global pi
            b2 = Button(fr, text="delete", bg="white", fg="red",image=pi,relief=GROOVE)
            b2.place(x=900, y=zl-1)
            b2.config(command=lambda email=item, pge=frame, fle=file, wid=fr: self.delete(email, pge, fle, wid))

            def onframeconfigure(canvas):
                canvas.configure(scrollregion=canvas.bbox("all"))
            self.lf2.bind("<Configure>", lambda event, canvas=self.lf2canvas: onframeconfigure(canvas))

    # 9-------------------
    def delete(self, email, frame, file, wid):
        wid.destroy()
        # -------deleting email from file---------
        self.del_email(file, email)

        # ----copying deleted email in the trash file--------------
        if file != email_files_dict["Trash emails"]:
            self.write_email("Trash emails", email)
            # -----updating trash frame---adding deleted email in that----
            self.replace("Trash emails")
            frame.tkraise()


class page3_email_open:
    def __init__(self):
        p3 = all_pages_dict["p3"]
        c = Canvas(p3, bg=bgclr_pag3)
        c.pack(side="left", fill="both", expand=1)
        # c.yview_moveto('1.0')

        s = Scrollbar(p3, command=c.yview)
        s.pack(side="right", fill="y")

        c.configure(yscrollcommand=s.set)
        # c.bind('<Configure>', lambda e: c.configure(scrollregion=c.bbox('all')))

        frame = Frame(c, bg=bgclr_pag3)
        c.create_window((0, 0), anchor="nw", window=frame, width=1345,)# height=3000)
        self.mf = frame

        def onframeconfigure(canvas):
            canvas.configure(scrollregion=canvas.bbox("all"))
        frame.bind("<Configure>", lambda event, canvas=c: onframeconfigure(canvas))

        Label(frame, bg=bgclr_pag3, text="  EMAIL OPENED", font="comicsansns 40 bold").pack(fill=X)

    def raise_frame(self, event, email):
        i = 0
        text = ""
        for x in email:
            text = text + x
            if i >= 100 and x == ' ':
                text = text + '\n'
                i = 0
            i = i + 1
        f = Frame(self.mf, bg=bgclr_pag3)
        f.pack(fill="both")
        # f.grid(row=2,column=0)
        l = Label(f, bg=bgclr_pag3, text=text, font="comicsansns 15 bold", fg="white")
        l.pack(pady=20, )
        b = Button(f, text="goto back", bg=bgclr_bf1,)  # ,command=lambda:f.destroy())
        b.pack(anchor="nw", padx=10, pady=10)  # grid(row=1,column=0)
        # b.place(x=5,y=100)
        b.bind('<Button- 1>', lambda event, wid=f,: self.back(event, wid, ))
        all_pages_dict["p3"].tkraise()

    def back(self, event, wid):
        all_pages_dict["p2"].tkraise()
        wid.destroy()

class page4_write_email:
    def __init__(self,ml):
        self.obj_ml=ml
        frame=all_pages_dict["p4"]
        frame.config(bg=bgclr_pag3)

        # t = Text(frame, bg="white", width=screen_geometry[0], height=(screen_geometry[1]-10))
        l=Label(frame,text="WRITE  EMAIL  HERE",font="comicsansns 20 bold",bg=bgclr_pag3,fg="black")
        l.pack(fill=X,side="top",pady=20)

        s=Scrollbar(frame,)
        s.pack(fill=Y,side="right")

        fac=169/1366
        w=int(fac*(screen_geometry[0]))
        t = Text(frame, bg="white",fg="black",yscrollcommand=s.set,width=w-10,height=30)#,padx=10,pady=10 ,height=30)
        t.pack(padx=10,pady=10,)
        # t.place(x=0,y=0)
        s.config(command=t.yview)

        Button(frame,text="Save email",bg=bgclr_bf1,command=lambda t=t:save_email(t)).place(x=50,y=30)
        Button(frame,text="Goto back",bg=bgclr_bf1,command=lambda:all_pages_dict["p2"].tkraise()).place(x=150,y=30)
        def save_email(t):
            input=t.get("1.0",END)
            print(input)
            if len(input)>3:
                email_list=[]
                email_list.append(input)

                p2=obj_dict["p2"]
                p2.call_predict(email_list)

# ---------------------------------------MAIN STARTS HERE------------------------------------------------------------
if __name__ == "__main__":
    for F in email_frame_names:  # opening emails files
        file_name = "file_" + F
        f = open(file_name, "a+")
        f.seek(0,0)
        email_files_dict.update({F: f})

    ml = ML_model()
    bs = basic_structure()
    #----pasting image in welcome window and delete button
    pi = PhotoImage(file="del_logo2.png")
    pi2 = PhotoImage(file="logo3.png")
    p1 = page1().start()

    p3 = page3_email_open()
    p4=page4_write_email(ml)

    p2 = page2_mainpage(p3,ml)

    p2.label_frame1_content()

    for F in email_frame_names:  # this writes emails in their respective pages.
        file_name = email_files_dict[F]
        frame = email_frames_LF2_dict[F]
        p2.label_frame2_content(frame, file_name)

    bs.mainloop()