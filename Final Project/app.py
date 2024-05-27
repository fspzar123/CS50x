import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Config app
app = Flask(__name__)
# ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Config cs50 Lib to use sqlite3 db
db = SQL("sqlite:///email.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods = ["GET","POST"])
def index():
     #if user submits the form
     if request.method == "POST":
        email = request.form.get('email')
        #ensure email is submitted
        if not request.form.get("email"):
            return ("MUST PROVIDE", 400)
     # Add the user's entry into the database
        db.execute("INSERT INTO email (email) VALUES(?)",email)
     # Go back to homepage
        return redirect("/")

     else:
          return render_template("index.html")

